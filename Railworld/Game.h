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
	sf::Text m_fpsCounter;
	sf::Font m_font;
	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
};