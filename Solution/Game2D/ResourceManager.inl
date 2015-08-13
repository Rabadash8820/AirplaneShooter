#include <cassert>

// CONSTRUCTORS / DESTRUCTOR
template<typename Resource, typename Id>
ResourceManager<Resource, Id>::ResourceManager() {

}

// FUNCTIONS
template<typename Resource, typename Id>
void ResourceManager<Resource, Id>::load(Id id, const std::string& filePath) {
	// Try to load the resource from the provided file
	Ptr resource(new Resource());
	bool loadSuccess = resource->loadFromFile(filePath);
	if (!loadSuccess)
		throw new std::runtime_error("ResourceManager::load() failed to load " + filePath);

	// Associate the resource with the given ID (make sure that ID wasn't already used)
	auto insertSuccess = _resources.insert(
		std::make_pair(id, std::move(resource)));
	assert(insertSuccess.second);
}
template<typename Resource, typename Id>
template<typename Param>
void ResourceManager<Resource, Id>::load(Id id, const std::string& filePath, Param p) {
	// Try to load the resource from the provided file
	Ptr resource = new Resource();
	bool loadSuccess = resource->loadFromFile(filePath, p);
	if (!loadSuccess)
		throw new std::runtime_error("ResourceManager::load() failed to load " + filePath);

	// Associate the resource with the given ID (make sure that ID wasn't already used)
	auto insertSuccess = _resources.insert(
		std::make_pair(id, std::move(resource)));
	assert(insertSuccess.second);
}
template<typename Resource, typename Id>
Resource& ResourceManager<Resource, Id>::get(Id id) const {
	// Try to retrieve the resource (make sure the ID is present in the std::map)
	auto pos = _resources.find(id);
	assert(pos != _resources.end());
	return *(pos->second);
}
template<typename Resource, typename Id>
Resource& ResourceManager<Resource, Id>::operator[](Id id) const {
	return this->get(id);
}
