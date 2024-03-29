#pragma once

#include "Uncopiable.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <glm/glm.hpp>


namespace falksalt
{
	class Ball;
	class Block;
	class Pad;
	class Renderer final : Uncopiable
	{
	public:
		Renderer();
		~Renderer();

		sf::Window& getWindow();

		void beginRender();
		void finishRender();

		void render(Pad const& pad);
		void render(Block const& block);
		void render(Ball const& ball);

	private:
		sf::RenderWindow m_window;
		std::vector<sf::Texture> m_blockTextures;
		std::vector<sf::Sprite> m_blockSprites;
		sf::Texture m_ballTexture;
		sf::Sprite m_ballSprite;

		float unitsToPixelsX(float x) const;
		float unitsToPixelsY(float y) const;

		float worldToScreenX(float x) const;
		float worldToScreenY(float y) const;
		sf::Vector2f worldToScreen(glm::vec2 const& vec) const;

		sf::Color getBlockColor(int layer) const;
		sf::Sprite& getBlockSprite(int layer);
	};
}

