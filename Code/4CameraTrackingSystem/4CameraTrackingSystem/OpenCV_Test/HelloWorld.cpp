//! [includes]
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>
//! [includes]

//! [namespace]
using namespace cv;
//! [namespace]

using namespace std;

int main( int argc, char** argv )
{
	//! [load]
	String imageName( "../../../../Data/Test-Image/Imgs/right_bottom_corner.bmp" ); // by default
	if ( argc > 1 )
	{
		imageName = argv[1];
	}
	//! [load]

	//! [mat]
	Mat image;
	//! [mat]

	//! [imread]
	image = imread( imageName, IMREAD_COLOR ); // Read the file
											   //! [imread]

	if ( image.empty() )                      // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	resize( image, image, Size(), 0.5, 0.5 );	// Resize Image to 50% Scale

	//! [window]
	namedWindow( "Display window", WINDOW_NORMAL ); // Create a window for display.
													  //! [window]

													  //! [imshow]
	imshow( "Display window", image );                // Show our image inside it.
													  //! [imshow]

													  //! [wait]
	waitKey( 0 ); // Wait for a keystroke in the window
				  //! [wait]
	return 0;
}