#include "adapter.h"


int main()
{
	fflush( stdout );
	std::ios_base::sync_with_stdio( false );


	std::unique_ptr<Rectangle> r = std::make_unique<RectangleWrapper>( 120, 200, 60, 40 );
	r->draw();
	std::cout << "\n\n";

	RectangleWrapper ra{10, 20, 40, 80};
	ra.draw();

	std::system( "pause" );
	return 0;
}