#pragma once

#include <iostream>
#include <memory>

// Legacy component
class LegacyRectangle
{
	int m_x1;
	int m_y1;
	int m_x2;
	int m_y2;
public:
	LegacyRectangle(int x1, int y1, int x2, int y2)
	{
		m_x1 = x1;
		m_y1 = y1;
		m_x2 = x2;
		m_y2 = y2;
		std::wcout << L"LegacyRectangle:  create.  (" << m_x1 << L',' << m_y1 << L") => ("
			 << m_x2 << L',' << m_y2 << L')' << L'\n';
	}

	void draw() const
	{
		std::wcout << L"LegacyRectangle:  oldDraw.  (" << m_x1 << L',' << m_y1 << L") => (" << m_x2 << L',' << m_y2 << L')' << L'\n';
	}
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
	explicit RectangleWrapper( int x,
		int y,
		int w,
		int h)
		:
		LegacyRectangle( x,
			y,
			x + w,
			y + h )
	{
		std::wcout << L"RectangleWrapper: create.  ("
			<< x
			<< L','
			<< y
			<< L"), width = "
			<< w
			<< L", height = "
			<< h
			<< L'\n';
	}

	void draw() const noexcept override
	{
		std::wcout << L"RectangleWrapper: draw.\n";
		LegacyRectangle::draw();
	}
};
