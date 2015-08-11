#include "DesertMap.h"

#include "ResourceIds\Textures.h"
#include "ResourceIds\Fonts.h"
#include "Categories.h"
#include <Render/Brush.h>
#include <memory>
#include <iostream>

using namespace Shooter;
using namespace Game2D;
using namespace sf;
using namespace std;

DesertMap::SpawnPoint::SpawnPoint(Aircraft::Type inType, float inX, float inY) {
	type = inType;
	x = inX;
	y = inY;
}

// INTERFACE
DesertMap::DesertMap(RenderWindow& window) :
	Map(window),
	_view(window.getDefaultView()),
	_worldBounds(FloatRect(0.f, 0.f, _view.getSize().x, 2000.f)),
	_scrollVelocity(Vector2f(0.f, -50.f)),
	_playerSpawn(_view.getSize().x / 2.f, _worldBounds.height - _view.getSize().y / 2.f),
	_player(nullptr)
{
	_view.setCenter(_playerSpawn);
}
void DesertMap::handleEvent(const sf::Event& e) {
	Shooter::Categories* c = reinterpret_cast<Shooter::Categories*>(_categories.get());
	switch (e.type) {
	case Event::KeyPressed:
		if (e.key.code == Keyboard::P) {
			Command output;
			output.Action = [](SceneNode& s, Time) {
				cout << s.getPosition().x << "," << s.getPosition().y << endl;
			};
			output.Category = c->PlayerAircraft();
			_commands.push(output);

		}
		break;
	}
	
}
void DesertMap::handleRealtimeInput() {
	Shooter::Categories* c = reinterpret_cast<Shooter::Categories*>(_categories.get());
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		Command moveLeft;
		//moveLeft.Action = ;
		moveLeft.Category = c->PlayerAircraft();
		_commands.push(moveLeft);
	}
}
void DesertMap::drawCurrent(RenderTarget& target, RenderStates states) const {
	_window.setView(_view);
}
void DesertMap::loadResources() {
	// Load texture resources
	_textures.load(ResourceIDs::Texture::DESERT, "C:\\Dan_Programming\\DefaultCollection\\Airplane Shooter\\Solution\\AirplaneShooter\\Resources\\Textures\\Desert.png");
	_textures.load(ResourceIDs::Texture::EAGLE, "C:\\Dan_Programming\\DefaultCollection\\Airplane Shooter\\Solution\\AirplaneShooter\\Resources\\Textures\\Eagle.png");
	_textures.load(ResourceIDs::Texture::RAPTOR, "C:\\Dan_Programming\\DefaultCollection\\Airplane Shooter\\Solution\\AirplaneShooter\\Resources\\Textures\\Raptor.png");
}
void DesertMap::buildScene() {
	// Add each scene layer to the layer collection
	for (size_t L = 0; L < _sceneLayers.size(); ++L) {
		SceneNode::Ptr layer(new Game2D::SceneNode());
		_sceneLayers[L] = layer.get();
		_sceneTree.attachChild(move(layer));
	}

	// Add a node for the background, and tile its texture
	Texture& desertTexture = _textures[Textures::Desert];
	IntRect desertBounds(_worldBounds);
	desertTexture.setRepeated(true);
	Brush::Ptr background(
		new Brush(desertTexture, desertBounds, unique_ptr<Categories>(new Categories())));
	background->setPosition(_worldBounds.left, _worldBounds.top);
	_sceneLayers[Layer::Background]->attachChild(move(background));

	// Add a node for the leader Aircraft and assign it to the Player
	Aircraft::Ptr leader(new Aircraft(Aircraft::Type::Eagle, _textures, _fonts));
	leader->airSpeed = PLAYER_SPEED;
	leader->setPosition(_playerSpawn);
	_player = leader.get();
	_sceneLayers[Layer::Air]->attachChild(move(leader));

	// Add enemy Aircraft
	addEnemies();
}
void DesertMap::addEnemies() {
	// Define spawn points for all enemies
	_spawnPoints.push_back(SpawnPoint(Aircraft::Type::Avenger, 0.f, 500.f));
	_spawnPoints.push_back(SpawnPoint(Aircraft::Type::Avenger, -70.f, 1400.f));

	// Sort spawn points by y-coordinate so its easy to see which have entered the battlefield
	sort(
		_spawnPoints.begin(), _spawnPoints.end(),
		[](SpawnPoint left, SpawnPoint right) { return left.y < right.y; });
}
FloatRect DesertMap::getBattlefieldBounds() const {
	// Return the bounding Rectangle of the main View, with a little extra off-screen at the top
	FloatRect bounds = _view.getViewport();
	bounds.top -= BATTLEFIELD_OFFSET;
	bounds.height += BATTLEFIELD_OFFSET;
	return bounds;
}
void DesertMap::spawnEnemies() {
	// Loop through all spawn points that have entered the battlefield
	FloatRect bounds = getBattlefieldBounds();
	while (!_spawnPoints.empty() && _spawnPoints.back().y >= bounds.top) {

		// Define a new enemy Aircraft at this spawn point (rotated by 180°), and add it to the scene tree
		SpawnPoint sp = _spawnPoints.back();
		Aircraft::Ptr enemy(new Aircraft(sp.type, _textures, _fonts));
		enemy->setPosition(sp.x, sp.y);
		enemy->setRotation(180.f);
		_sceneLayers[Layer::Air]->attachChild(move(enemy));
		_spawnPoints.pop_back();
	}
}
void DesertMap::updateCurrent(Time dt) {
	// Scroll the map
	ScrollingMap::updateCurrent(dt);

	// Reset player's velocity
	_player->Velocity = Vector2f(0.f, 0.f);

	// Adjust the player's velocity according to keyboard input
	_player->Velocity = Vector2f(0.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
		_player->Velocity = -Vector2f(_playerSpeed, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
		_player->Velocity = Vector2f(_playerSpeed, 0.f);

	// Adjust the player's velocity according to their position in the Map
	float playerPos = _player->getPosition().x;
	if (playerPos <= _worldBounds.left + BORDER_OFFSET || _worldBounds.left + _worldBounds.width - BORDER_OFFSET <= playerPos) {
		float reverse = -_player->Velocity.x;
		_player->Velocity = Vector2f(reverse, 0.f);
	}
	string DesertMap::projectDirectory() {
		char currDir[FILENAME_MAX];
		GetCurrentDir(currDir, sizeof(currDir));
		// Make some assertion here...
		return currDir;
	}

	// Scroll the map
	ScrollingMap::updateCurrent(dt);
}