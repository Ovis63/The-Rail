#include "stdafx.h"
#include "Game.h"

Game::Game()
:m_window(sf::VideoMode(800, 600), "Railworld test")
,m_player() 
{
	m_player.setRadius(80.f);
	m_player.setPosition(100.f, 200.f);
	m_player.setFillColor(sf::Color::Cyan);
}

void Game::run()
{
	while (m_window.isOpen()) 
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}

void Game::update()
{
}

void Game::render()
{
	m_window.clear();
	m_window.draw(m_player);
	m_window.display();
}