#ifndef GAME_H
#define GAME_H
#include <sfml/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

/*
	Class that acts as game engine.
	Wrapper class.
*/

class Game
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	//event
	sf::Event ev;
	//Private functions
	void InitVariables();
	void InitWindow();
public:
	//constructors and deconstroctors
	Game();
	~Game();

	//Accessors
	const bool running();


	//Functions
	void pollEvents();
	void update();
	void render();
	
};


#endif

