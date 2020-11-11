#include <io.h>
#include <fcntl.h>
#include "adapter.h"

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