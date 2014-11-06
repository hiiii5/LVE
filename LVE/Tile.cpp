#include "Tile.h"


Tile::Tile(sf::Image& image)
{
	sf::Texture sprImg;
	sprImg.loadFromImage(image);

	baseSprite.setTexture(sprImg, true);
}


Tile::~Tile()
{
}

void Tile::Draw(sf::Int16 x, sf::Int16 y, sf::RenderWindow* rw)
{
	baseSprite.setPosition((float)x, (float)y);
	rw->draw(baseSprite);
}