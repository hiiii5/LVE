#include <SFML\Graphics.hpp>

#include <math.h>
#include "Camera.h"

Camera::Camera(sf::Int8 w, sf::Int8 h, float speed)
{
	size.x = w;
	size.y = h;

	if (speed < 0.0)
		speed = 0.0;
	if (speed > 1.0)
		speed = 1.0;

	this->speed = speed;
}


Camera::~Camera()
{
}

void Camera::Move(sf::Int8 x, sf::Int8 y)
{
	position.x = (float)x;
	position.y = (float)y;
	target.x = (float)x;
	target.y = (float)y;
}

void Camera::MoveCenter(sf::Int8 x, sf::Int8 y)
{
	x = x - (size.x / 2);
	y = y - (size.y / 2);

	position.x = (float)x;
	position.y = (float)y;
	target.x = (float)x;
	target.y = (float)y;
}

void Camera::GoTo(sf::Int8 x, sf::Int8 y)
{
	target.x = (float)x;
	target.y = (float)y;
}

void Camera::GoToCenter(sf::Int8 x, sf::Int8 y)
{
	x = x - (size.x / 2);
	y = y - (size.y / 2);

	target.x = (float)x;
	target.y = (float)y;
}

void Camera::Update()
{
	float x, y, d;

	float vx, vy, v;

	x = (float)(target.x - position.x);
	y = (float)(target.y - position.y);

	if ((x*x + y*y) <= 1)
	{
		position.x = target.x;
		position.y = target.y;
	}
	else
	{
		d = sqrt(x*x + y*y);

		v = (d * speed) / 60;

		if (v < 1.0f)
			v = 1.0f;

		vx = x * (v / d);
		vy = y * (v / d);

		position.x += vx;
		position.y += vy;
	}
}


sf::IntRect Camera::GetTileBounds(sf::Int16 tileSize)
{
	sf::Int16 x = (sf::Int16)(position.x / tileSize);
	sf::Int16 y = (sf::Int16)(position.y / tileSize);

	sf::Int16 w = (sf::Int16)(size.x / tileSize + 2);
	sf::Int16 h = (sf::Int16)(size.y / tileSize + 2);

	if (x % tileSize != 0)
		w++;
	if (y % tileSize != 0)
		h++;

	return sf::IntRect(x, y, w, h);
}