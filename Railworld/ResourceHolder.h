#pragma once
#include <memory>

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	void load(Identifier id, const std::string& filename);
	template <typename Parameter>
	void load(Identifier id, const std::string& filename, const Parameter& secondParam);

	Resource& get(Identifier id);
	const Resource& get(Identifier id) const;

private:
	std::map<Identifier, std::unique_ptr<Resource>> m_resourceMap;
};



//IDs for all of the resources. This will get big. 
//TODO: Separate these into a different header
namespace Textures
{
	enum class ID
	{
		Train,
	};
}

namespace Fonts
{
	enum class ID
	{
		Arial,
	};
}

//Typedefs for all resource containers.
typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;

#include "ResourceHolder.inl"