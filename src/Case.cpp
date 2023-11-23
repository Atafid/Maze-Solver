#include "Case.h"
#include <SFML/Graphics.hpp>

Case::Case() {
	_size = 10;
	_isWall = false;
	_distance = 0;
	_isPassed = false;

	_x = 0;
	_y = 0;

	_firstLine = false;
	_lastLine = false;
	_firstRow = false;
	_lastRow = false;

	_appearance = sf::RectangleShape(sf::Vector2f(_size, _size));
	_color = sf::Color(230, 230, 230);
}

Case::Case(double size) {
	_size = size;
	_isWall = false;
	_distance = 0;
	_isPassed = false;

	_x = 0;
	_y = 0;

	_firstLine = false;
	_lastLine = false;
	_firstRow = false;
	_lastRow = false;

	_appearance = sf::RectangleShape(sf::Vector2f(_size, _size));
	_color = sf::Color(230, 230, 230);
}

Case::Case(double size, bool wall) {
	_size = size;
	_isWall = wall;
	_distance = 0;
	_isPassed = false;

	_x = 0;
	_y = 0;

	_firstLine = false;
	_lastLine = false;
	_firstRow = false;
	_lastRow = false;

	_appearance = sf::RectangleShape(sf::Vector2f(_size, _size));
	_color = sf::Color(50, 50, 50);
}

//destroy a wall
void Case::destroy() {
	_isWall = false;
	_color = sf::Color(230, 230, 230);
	_appearance.setFillColor(_color);
}

//prepare the case to be drawn
void Case::drawCase(double x, double y) {
	_appearance.setFillColor(_color);
	_appearance.setPosition(sf::Vector2f(x, y));

	_x = x;
	_y = y;
}

