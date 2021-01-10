#pragma once

#include <iostream>


// Legacy component
class LegacyRectangle
{
	int m_x1;
	int m_y1;
	int m_x2;
	int m_y2;
public:
	LegacyRectangle( int x1, int y1, int x2, int y2 );
	void draw() const;
};


// desired interface
class Rectangle
{
public:
	virtual void draw() const noexcept = 0;
};

// Adapter/Wrapper/Facade class
class RectangleWrapper
	: public Rectangle,
	private LegacyRectangle
{
public:
	explicit RectangleWrapper( int x, int y, int w, int h );
	void draw() const noexcept override;
};
