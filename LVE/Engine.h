#pragma once

#include <SFML\Graphics.hpp>
#include "ImageManager.h"
#include "Tile.h"
#include "Camera.h"

class Engine
{
private:
	sf::RenderWindow* window;
	ImageManager imageManager;

	sf::Vector2u videoSize;
	sf::Uint8 bitsPerPixel;

	Camera* camera;

	sf::Int16 tileSize;

	bool Init();
	void MainLoop();
	void RenderFrame();
	void ProcessInput();
	void Update();

	bool mouseDown;

protected:

public:
	Engine(sf::Uint8 w, sf::Uint8 h, sf::Uint8 bitsPerPixel, sf::Int16 tileSize);
	~Engine();

	void Start();
};