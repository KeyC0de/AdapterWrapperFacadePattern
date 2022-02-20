#include "adapter.h"


int main()
{
	std::unique_ptr<IRectangle> pRect = std::make_unique<Rectangle>( 120, 200, 60, 40 );
	pRect->draw();
	std::cout << "\n\n";

	Rectangle rect{10, 20, 40, 80};
	rect.draw();

#if defined _DEBUG && !defined NDEBUG
	while ( !getchar() );
#endif
	return EXIT_SUCCESS;
}