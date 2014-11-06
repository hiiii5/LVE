#ifndef _ImageManager_INCLUDED_H_
#define _ImageManager_INLCUDED_H_

#include <SFML\Graphics.hpp>

#include <vector>
#include <map>
#include <string>

class ImageManager
{
private:
	std::vector<sf::Image> imageList;
	std::map<sf::Int16, sf::Int16> imageIDs;

	sf::Int16 tileSize;

protected:


public:
	ImageManager();
	~ImageManager();

	void setTileSize(sf::Uint16 tileSize);

	void AddImage(sf::Image& image, sf::Int8 id);
	sf::Image& GetImage(sf::Int8 id);

	void LoadTileset(std::string& filename);
};

#endif // !_ImageManager_INCLUDED_H_