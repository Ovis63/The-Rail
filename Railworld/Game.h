#pragma once


class Game
{
public:
	Game();
	void run();

private:
	void processEvents();
	void update();
	void render();

private:
	sf::RenderWindow m_window;
	sf::CircleShape m_player;
};