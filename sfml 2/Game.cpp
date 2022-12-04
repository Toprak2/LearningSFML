#include "Game.h"


//Private functions

void Game::InitVariables()
{
	this->window = nullptr;
}

void Game::InitWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new sf::RenderWindow(this->videoMode, "This Is a Window", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::InitEnemies()
{
	this->enemy.setPosition(350.f, 250.f);
	this->enemy.setSize(sf::Vector2f(100.f , 100.f ));
	this->enemy.setFillColor(sf::Color::Cyan);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.f);
}

//Constructors /Destructor
Game::Game() 
{
	InitVariables();
	InitWindow();
	InitEnemies();

}


Game::~Game() 
{
	delete this->window;
}

//Accessors
const bool Game::running()
{
	return this->window->isOpen();
}

//Functions

void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev)) {
		switch (this->ev.type) {

		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape) {
				this->window->close();
				break;
			}

		}
	}
}

void Game::update() {

	this->pollEvents();
	

	//Update mouse position
	
	//Relative to the screen
	//std::cout << "Mouse Position: " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << std::endl;
	
	//Relative to window
	std::cout << "Mouse Position: " 
		<< sf::Mouse::getPosition(*this->window).x << " " 
		<< sf::Mouse::getPosition(*this->window).y << std::endl;
}

void Game::render()
{
	/*
		@return void
	
		-clear old frame
		-render objects
		-display frame in window
		
		Renders the game objects
	*/
	this->window->clear();

	//Draw game objects
	this->window->draw(this->enemy);
	this->window->display(); 

}
