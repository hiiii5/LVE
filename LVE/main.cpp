#include <SFML/Graphics.hpp>
#include "Engine.h"

int main()
{
	Engine* engine = new Engine(640, 480, 32, 32);

	try{
		engine->Start();
	} catch (char* e) {}

	return EXIT_SUCCESS;
}