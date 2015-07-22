#include <cassert>

// CONSTRUCTORS / DESTRUCTOR
template<typename Resource>
ResourceManager<Resource>::ResourceManager() {

}
template<typename Resource>
ResourceManager<Resource>::~ResourceManager() { }


// FUNCTIONS
template<typename Resource>
void ResourceManager<Resource>::load(ResourceId res, const std::string& filePath) {
	// Try to load the resource from the provided file
	Ptr resource(new Resource());
	bool loadSuccess = resource->loadFromFile(filePath);
	if (!loadSuccess)
		throw new std::runtime_error("ResourceManager::load() failed to load " + filePath);

	// Associate the resource with the given ID (make sure that ID wasn't already used)
	auto insertSuccess = _resources.insert(
		std::make_pair(res.getId(), std::move(resource)));
	assert(insertSuccess.second);
}
template<typename Resource>
template<typename Param>
void ResourceManager<Resource>::load(ResourceId res, const std::string& filePath, Param p) {
	// Try to load the resource from the provided file
	Ptr resource = new Resource();
	bool loadSuccess = resource->loadFromFile(filePath, p);
	if (!loadSuccess)
		throw new std::runtime_error("ResourceManager::load() failed to load " + filePath);

	// Associate the resource with the given ID (make sure that ID wasn't already used)
	auto insertSuccess = _resources.insert(
		std::make_pair(res.getId(), std::move(resource)));
	assert(insertSuccess.second);
}
template<typename Resource>
Resource& ResourceManager<Resource>::operator[](ResourceId res) const {
	// Try to retrieve the resource (make sure the ID is present in the std::map)
	auto pos = _resources.find(res.getId());
	assert(pos != _resources.end());
	return *(pos->second);
}
