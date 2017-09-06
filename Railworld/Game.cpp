#include "stdafx.h"
#include "Game.h"

Game::Game()
:m_window(sf::VideoMode(800, 600), "Railworld test"),
m_fpsCounter(), m_font(), m_player() 
{
	if (!m_font.loadFromFile("Media/Fonts/arial.ttf"))
	{
		//ERROR!
	}

	m_fpsCounter.setPosition(0.f, 0.f);
	m_fpsCounter.setString("0.0 FPS");
	m_fpsCounter.setFont(m_font);

	m_player.setRadius(80.f);
	m_player.setPosition(100.f, 200.f);
	m_player.setFillColor(sf::Color::Cyan);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (m_window.isOpen()) 
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			float fps = 1.f / timeSinceLastUpdate.asSeconds();
			m_fpsCounter.setString(std::to_string(fps));
			timeSinceLastUpdate -= TimePerFrame;
			update();
			render();
		}
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
	m_window.draw(m_fpsCounter);
	m_window.display();
}