#include <iostream>
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat img = imread("../../../Data/Test-Image/Imgs/right_bottom_corner.bmp", IMREAD_COLOR); //load img from target directory
	if (img.empty()) //check whether the image is loaded or not
	{
		cout << "Error : Image cannot be loaded..!!" << endl;
		system("pause"); //wait for a key press
		return -1;
	}
	namedWindow("MyWindow", WINDOW_NORMAL); //create a window with the name "MyWindow"
	imshow("MyWindow", img); //display the image which is stored in the 'img' in the "MyWindow" window

	waitKey(0); //wait infinite time for a keypress

	//destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

	return 0;
}