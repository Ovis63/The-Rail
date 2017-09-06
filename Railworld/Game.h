#pragma once
#include "ResourceHolder.h"

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
	TextureHolder m_textures;
	FontHolder m_fonts;
	sf::Sprite m_player;
	sf::Text m_fpsCounter;
	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
};