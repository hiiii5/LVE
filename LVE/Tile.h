#ifndef _Tile_INCLUDED_H_
#define _Tile_INCLUDED_H_

#include <SFML\Graphics.hpp>

class Tile
{
private:
	sf::Sprite baseSprite;

protected:


public:
	Tile(sf::Image& image);
	~Tile();

	void Draw(sf::Int16 x, sf::Int16 y, sf::RenderWindow* rw);
};

#endif // !_Tile_INCLUDED_H_