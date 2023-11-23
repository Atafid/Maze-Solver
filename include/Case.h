#pragma once

#ifndef DEF_CASE
#define DEF_CASE

#include <SFML/Graphics.hpp>

//define a case
class Case
{
public:

	double _size;
	bool _isWall;
	double _distance;
	bool _isPassed;

	double _x;
	double _y;

	bool _firstLine;
	bool _lastLine;
	bool _firstRow;
	bool _lastRow;

	sf::RectangleShape _appearance;
	sf::Color _color;


	Case();
	Case(double size);
	Case(double size, bool wall);
	void destroy();
	void drawCase(double x, double y);

};

#endif
