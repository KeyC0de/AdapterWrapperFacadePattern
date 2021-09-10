#include "adapter.h"


int main()
{
	fflush( stdout );
	std::ios_base::sync_with_stdio( false );


	std::unique_ptr<IRectangle> r = std::make_unique<Rectangle>( 120, 200, 60, 40 );
	r->draw();
	std::cout << "\n\n";

	Rectangle ra{10, 20, 40, 80};
	ra.draw();

	std::system( "pause" );
	return 0;
}