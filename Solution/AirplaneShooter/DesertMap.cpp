#include "DesertMap.h"

#include "Categories.h"

#include <Render\Brush.h>
#include <Utility.h>

#include <SFML\Graphics\Texture.hpp>
#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\Rect.hpp>

#include <string>

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

// HELPER FUNCTIONS
void DesertMap::updateCurrent(Time dt) {
	// Scroll the Map
	_view.move(_scrollVelocity * dt.asSeconds());
	_player->velocity = Vector2f(0.f, 0.f);

	// Do updates in response to Commands
	updateOnCommands(dt);
	
	spawnEnemies();

	// Do "normal" updates
	adjustPlayer(dt);
}
void DesertMap::drawCurrent(RenderTarget& target, RenderStates states) const {
	_window.setView(_view);
}
void DesertMap::loadResources() {
	// Get resource directories
	string currDir    = Utility::currentWorkingDirectory();
	string textureDir = currDir + "\\Resources\\Textures\\";
	string shaderDir  = currDir + "\\Resources\\Shaders\\";
	string soundDir   = currDir + "\\Resources\\Sounds\\";
	string fontDir	  = currDir + "\\Resources\\Fonts\\";

	// Load textures
	_textures.load(TextureId::Desert,  textureDir + "Desert.png");
	_textures.load(TextureId::Eagle,   textureDir + "Eagle.png");
	_textures.load(TextureId::Raptor,  textureDir + "Raptor.png");
	_textures.load(TextureId::Avenger, textureDir + "Avenger.png");

	// Load fonts
	_fonts.load(FontId::Main, fontDir + "Sansation.ttf");
}
void DesertMap::buildScene() {
	// Add each scene layer to the layer collection
	for (size_t L = 0; L < _sceneLayers.size(); ++L) {
		SceneNode::Ptr layer(new Game2D::SceneNode());
		_sceneLayers[L] = layer.get();
		_sceneTree.attachChild(move(layer));
	}

	// Add a node for the background, and tile its texture
	Texture& desertTexture = _textures[TextureId::Desert];
	IntRect desertBounds(_worldBounds);
	desertTexture.setRepeated(true);
	Brush::Ptr background(new Brush(desertTexture, desertBounds));
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
void DesertMap::addEnemy(Aircraft::Type type, float x, float y) {
	SpawnPoint spawn(type, _playerSpawn.x + x, _playerSpawn.y - y);
	_spawnPoints.push_back(spawn);
}
void DesertMap::addEnemies() {
	// Define spawn points for all enemies
	addEnemy(Aircraft::Type::Raptor, 0.f, 500.f);
	addEnemy(Aircraft::Type::Raptor, 0.f, 1000.f);
	addEnemy(Aircraft::Type::Raptor, +100.f, 1100.f);
	addEnemy(Aircraft::Type::Raptor, -100.f, 1100.f);
	addEnemy(Aircraft::Type::Avenger, -70.f, 1400.f);
	addEnemy(Aircraft::Type::Avenger, -70.f, 1600.f);
	addEnemy(Aircraft::Type::Avenger, 70.f, 1400.f);
	addEnemy(Aircraft::Type::Avenger, 70.f, 1600.f);

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
void DesertMap::adjustPlayer(Time dt) {
	// Reduce the playerAircraft's velocity if they are moving diagonally
	Vector2f playerV = _player->velocity;
	if (playerV.x != 0 && playerV.y != 0)
		_player->velocity = playerV / sqrt(2.f);
	
	// Adjust the playerAircraft's position if they cross the View's boundary
	Vector2f pos = _player->getPosition();
	FloatRect viewBounds(
		_view.getCenter() - _view.getSize() / 2.f,
		_view.getSize());
	pos.x = max(pos.x, viewBounds.left + BORDER_OFFSET);
	pos.x = min(pos.x, viewBounds.left + viewBounds.width - BORDER_OFFSET);
	pos.y = max(pos.y, viewBounds.top  + BORDER_OFFSET);
	pos.y = min(pos.y, viewBounds.top  + viewBounds.height - BORDER_OFFSET);
	_player->setPosition(pos);
}
