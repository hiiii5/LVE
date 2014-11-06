#ifndef _Camera_INCLUDED_H_
#define _Camera_INCLUDED_H_

#include <SFML\Graphics.hpp>
#include "Tile.h"

class Camera
{
private:
	sf::Vector2f position;

	sf::Vector2f target;

	sf::Vector2i size;

	float speed;

protected:


public:
	Camera(sf::Int8 w, sf::Int8 h, float speed);
	~Camera();

	void Move(sf::Int8 x, sf::Int8 y);
	void MoveCenter(sf::Int8 x, sf::Int8 y);

	void GoTo(sf::Int8 x, sf::Int8 y);
	void GoToCenter(sf::Int8 x, sf::Int8 y);

	void Update();

	sf::Vector2i GetPosition() { return sf::Vector2i((int)position.x, (int)position.y); }

	sf::Vector2i GetTileOffset(sf::Int16 tileSize) { return sf::Vector2i((int)(position.x) % tileSize, (int)(position.y) % tileSize); }

	sf::IntRect GetTileBounds(sf::Int16 tileSize);
};

#endif // !_Camera_INCLUDED_H_