#include "../include/GUI/Window.h"

#include "../include/GUI/Interactive.h"

namespace gui
{
	void gui::Interactive::lostFocus() {}

	const bool gui::Interactive::input(const sf::Event& event)
	{
		switch (event.type)
		{
		case sf::Event::MouseMoved:
			return contains(event.mouseMove.x, event.mouseMove.y);
		case sf::Event::MouseButtonPressed || sf::Event::MouseButtonReleased:
			return contains(event.mouseButton.x, event.mouseButton.y);
		default:
			return false;
		}
	}

	const bool gui::Interactive::contains(const float x, const float y)const
	{
		return getGlobalBounds().contains(x, y);
	}

	const bool gui::Interactive::contains(const sf::Vector2f& point)const
	{
		return contains(point.x, point.y);
	}
	
	Interactive& gui::Interactive::setPosition(const sf::Vector2f& position)
	{
		return setPosition(position.x, position.y);
	}

	const Window* const Interactive::getParent() const
	{
		return m_parent;
	}

	void Interactive::setParentToSame(const Interactive& source)
	{
		m_parent = source.m_parent;
	}

	void Interactive::setParent(const Window* const parent)
	{
		m_parent = (Window*)parent;
	}
}