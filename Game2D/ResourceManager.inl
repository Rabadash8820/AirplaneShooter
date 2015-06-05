#include <cassert>

// CONSTRUCTORS / DESTRUCTOR
template<typename Id, typename Resource>
ResourceManager<Id, Resource>::ResourceManager() {

}
template<typename Id, typename Resource>
ResourceManager<Id, Resource>::~ResourceManager() { }


// FUNCTIONS
template<typename Id, typename Resource>
void ResourceManager<Id, Resource>::load(Id id, const std::string& filePath) {
	// Try to load the resource from the provided file
	ResPtr resource(new Resource());
	bool loadSuccess = resource->loadFromFile(filePath);
	if (!loadSuccess)
		throw new std::runtime_error("ResourceHolder::load() failed to load " + filePath);

	// Associate the resource with the given ID (make sure that ID wasn't already used)
	auto insertSuccess = _resources.insert(
		std::make_pair(id, std::move(resource)));
	assert(insertSuccess.second);
}
template<typename Id, typename Resource>
template<typename Param>
void ResourceManager<Id, Resource>::load(Id id, const std::string& filePath, Param p) {
	// Try to load the resource from the provided file
	ResPtr resource = new Resource();
	bool loadSuccess = resource->loadFromFile(filePath, p);
	if (!loadSuccess)
		throw new std::runtime_error("ResourceHolder::load() failed to load " + filePath);

	// Associate the resource with the given ID (make sure that ID wasn't already used)
	auto insertSuccess = _resources.insert(
		std::make_pair(Id, std::move(resource)));
	assert(insertSuccess.second);
}
template<typename Id, typename Resource>
Resource& ResourceManager<Id, Resource>::operator[](Id id) const {
	// Try to retrieve the resource (make sure the ID is present in the std::map)
	auto findSuccess = _resources.find(id);
	assert(findSuccess != _resources.end());
	return *(findSuccess->second);
}