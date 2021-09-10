#include <iostream>
#include "adapter.h"


LegacyRectangle::LegacyRectangle( int x1,
	int y1,
	int x2,
	int y2 )
{
	m_x1 = x1;
	m_y1 = y1;
	m_x2 = x2;
	m_y2 = y2;
	std::cout << "LegacyRectangle:  create.  ("
		<< m_x1 << ',' << m_y1
		<< ") => ("
		<< m_x2 << ',' << m_y2
		<< ')' << '\n';
}

void LegacyRectangle::draw() const
{
	std::cout << "LegacyRectangle:  oldDraw.  ("
		<< m_x1 << ',' << m_y1
		<< ") => ("
		<< m_x2 << ',' << m_y2
		<< ')' << '\n';
}

Rectangle::Rectangle( int x,
	int y,
	int w,
	int h )
	:
	LegacyRectangle{x, y, x + w, y + h}
{
	std::cout << "Rectangle: create.  ("
		<< x
		<< ','
		<< y
		<< "), width = "
		<< w
		<< ", height = "
		<< h
		<< '\n';
}

void Rectangle::draw() const noexcept
{
	std::cout << "Rectangle: draw.\n";
	LegacyRectangle::draw();
}
