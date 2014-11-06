#include "ImageManager.h"

#include <vector>
#include <fstream>
#include <string>

#include "rapidxml.hpp"

using namespace rapidxml;

ImageManager::ImageManager()
{
}


ImageManager::~ImageManager()
{
}


void ImageManager::setTileSize(sf::Uint16 tileSize)
{
	this->tileSize = tileSize;
}

void ImageManager::AddImage(sf::Image& image, sf::Int8 id)
{
	imageList.push_back(image);

	imageIDs[id] = imageList.size() - 1;
}

sf::Image& ImageManager::GetImage(sf::Int8 id)
{
	return imageList[imageIDs[id]];
}

void ImageManager::LoadTileset(std::string& filename)
{
	std::ifstream inFile(filename);

	if (!inFile) throw "Could not load tileset: " + filename;

	std::string xmlContents;

	{
		std::string line;

		while (std::getline(inFile, line))
			xmlContents += line;
	}

	std::vector<char> xmlData = std::vector<char>(xmlContents.begin(), xmlContents.end());
	xmlData.push_back('\0');

	xml_document<> doc;
	doc.parse<parse_no_data_nodes>(&xmlData[0]);

	xml_node<>* root = doc.first_node();

	std::string imagePath;
	sf::Image tileset;

	xml_node<>* imagefile = root->first_node("imagefile");

	while (imagefile)
	{
		imagePath = imagefile->first_attribute("path")->value();
		tileset.loadFromFile(imagePath);

		xml_node<>* tile = imagefile->first_node("tile");

		while (tile)
		{
			sf::Int16 x = atoi(tile->first_attribute("x")->value());
			sf::Int16 y = atoi(tile->first_attribute("y")->value());
			sf::Int16 frames = atoi(tile->first_attribute("frame")->value());
			sf::Int16 id = atoi(tile->first_attribute("id")->value());

			sf::Image tileImage;
			tileImage.create(tileSize, tileSize);
			tileImage.copy(tileset, 0, 0, sf::IntRect(x * tileSize, y * tileSize, frames * tileSize, tileSize), true);

			AddImage(tileImage, id);

			tile = tile->next_sibling();
		}

		imagefile = imagefile->next_sibling();
	}
}