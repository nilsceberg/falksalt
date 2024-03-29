#pragma once

#include "Collision.hpp"

#include <SFML/Graphics.hpp>

namespace falksalt
{
	class Block final
	{
	public:
		Block();
		Block(int layer, int index);

		static const int Layers = 8;
		static const int LayerWidth = 16;
		static const constexpr float Width = 2.f/LayerWidth;
		static const constexpr float Height = Width / 2.f;
		static const constexpr float TopBlock = Height * 2.f - 3/4.f;

		float getY() const;
		float getX() const;
		int getLayer() const;
		int getIndex() const;
		
		bool isDestroyed() const;
		int destroy();
		int getScore() const;
		
		Collision collides(glm::vec2 start, glm::vec2 end) const;
		
	private:
		float layerToY(int layer) const;
	
		int m_layer;
		int m_index;
		bool m_isDestroyed;
	};
}

