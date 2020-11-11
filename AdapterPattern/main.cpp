#include <iostream>
#include <memory>
#include <io.h>
#include <fcntl.h>

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


int main()
{
	fflush( stdout );
	_setmode( _fileno( stdout ), _O_U16TEXT );
	_setmode( _fileno( stderr ), _O_U16TEXT );
	_setmode( _fileno( stdin ), _O_U16TEXT );
	std::ios_base::sync_with_stdio( false );


	std::unique_ptr<Rectangle> r = std::make_unique<RectangleWrapper>( 120, 200, 60, 40 );
	r->draw();
	std::wcout << L"\n\n";

	RectangleWrapper ra{10, 20, 40, 80};
	ra.draw();

	std::system( "pause" );
	return 0;
}