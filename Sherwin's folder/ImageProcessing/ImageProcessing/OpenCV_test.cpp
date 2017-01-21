#include <iostream>
#include <string>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat img = imread("../../../Data/Test-Image/Imgs/left_top_corner1.bmp", 0); //load img from target directory
	if (img.empty()) //check whether the image is loaded or not
	{
		cout << "Error : Image cannot be loaded..!!" << endl;
		system("pause"); //wait for a key press
		return -1;
	}

	Mat cimg;
	medianBlur(img, img, 5);
	cvtColor(img, cimg, COLOR_GRAY2BGR);
	vector<Vec3f> circles;
	HoughCircles(img, circles, HOUGH_GRADIENT, 1, 10,
		100, 15, 0, 100 // change the last two parameters
					   // (min_radius & max_radius) to detect larger circles
	);
	for (size_t i = 0; i < circles.size(); i++)
	{
		Vec3i c = circles[i];
		circle(cimg, Point(c[0], c[1]), c[2], Scalar(0, 0, 255), 3, LINE_AA);
		circle(cimg, Point(c[0], c[1]), 2, Scalar(0, 255, 0), 3, LINE_AA);
	}
	namedWindow("detected circles", WINDOW_NORMAL);
	imshow("detected circles", cimg);
	waitKey();
	//namedWindow("MyWindow", WINDOW_NORMAL); //create a window with the name "MyWindow"
	//imshow("MyWindow", img); //display the image which is stored in the 'img' in the "MyWindow" window

	//waitKey(0); //wait infinite time for a keypress

	//destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

	return 0;
}