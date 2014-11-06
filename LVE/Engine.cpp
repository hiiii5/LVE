#include "Engine.h"


Engine::Engine(sf::Uint8 w, sf::Uint8 h, sf::Uint8 bitsPerPixel, sf::Int16 tileSize)
{
	this->videoSize = sf::Vector2u(w, h);
	this->bitsPerPixel = bitsPerPixel;
	this->tileSize = tileSize;
	imageManager.setTileSize(tileSize);
}


Engine::~Engine()
{
}

bool Engine::Init()
{
	window = new sf::RenderWindow(sf::VideoMode(this->videoSize.x, this->videoSize.y, this->bitsPerPixel), "Main Window");
	window->setActive(true);

	this->mouseDown = false;

	if (!window) return false;

	return true;
}

void Engine::RenderFrame()
{
	window->clear();

	// Do Stuff

	window->display();
}

void Engine::ProcessInput()
{
	sf::Event evt;

	while (window->pollEvent(evt))
	{
		if (evt.type == sf::Event::Closed)
			window->close();

		if ((evt.type == sf::Event::MouseButtonPressed) && (this->mouseDown == false))
		{
			this->mouseDown = true;
		}

		if (evt.type == sf::Event::MouseButtonReleased)
			this->mouseDown = false;
	}
}

void Engine::Update()
{
	// Update camera
}

void Engine::MainLoop()
{
	while (window->isOpen())
	{
		ProcessInput();
		Update();
		RenderFrame();
	}
}

void Engine::Start()
{
	if (!Init())
		throw "Could not initialize Engine";

	MainLoop();
}