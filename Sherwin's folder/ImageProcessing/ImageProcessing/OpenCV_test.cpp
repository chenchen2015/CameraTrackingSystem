#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;



int main(int argc, char** argv)
{
	VideoCapture cap("../../../Data/Test-Image/Imgs/image%03d.bmp");
	//Mat img = imread("../../../Data/Test-Image/Imgs_copy/left_top_corner1.bmp", 0); //load img from target directory
	
	/*
	if (img.empty()) //check whether the image is loaded or not
	{
		cout << "Error : Image cannot be loaded..!!" << endl;
		system("pause"); //wait for a key press
		return -1;
	}
	*/
	while (cap.isOpened())
	{
		Mat img;
		cap.read(img);
		Mat cimg;
		medianBlur(img, img, 5);
		cvtColor(img, cimg, COLOR_GRAY2BGR);
		vector<Vec3f> circles;
		HoughCircles(img, circles, HOUGH_GRADIENT, 1, 10,
			100, 15, 0, 100 // change the last two parameters
						   // (min_radius & max_radius) to detect larger circles
		);

		/* original plotting */
		//for (size_t i = 0; i < circles.size(); i++)
		//{
		//	Vec3i c = circles[i];
		//	circle(cimg, Point(c[0], c[1]), c[2], Scalar(0, 0, 255), 3, LINE_AA);
		//	circle(cimg, Point(c[0], c[1]), 2, Scalar(0, 255, 0), 3, LINE_AA);
		//}


		//SELECTING LOWEST 3 CIRCLES 
		Vec<float, 3> lowest;
		Vec<float, 3> secondlowest;
		Vec<float, 3> thirdlowest;

		for (int j = 0; j < circles.size(); j++)
		{
			if (circles[j][1] > lowest[1])
				lowest = circles[j];

			for (int i = 0; i < circles.size(); i++)
			{
				if (circles[i][1] > secondlowest[1] && circles[i][1] < lowest[1])
					secondlowest = circles[i];

				for (int z = 0; z < circles.size(); z++)
				{
					if (circles[z][1] > thirdlowest[1] && circles[z][1] < secondlowest[1])
						thirdlowest = circles[z];
				}
			}
		}

		//Output Data from Sorting loop above
		cout << "lowest circle is value is circle no. " << lowest << endl;
		cout << "second lowest circle is value is circle no. " << secondlowest << endl;
		cout << "third lowest circle is value is circle no. " << thirdlowest << endl;

		//Plotting the lowest three circles on the image
		Vec3i c = lowest;
		Vec3i d = secondlowest;
		Vec3i e = thirdlowest;
		circle(cimg, Point(c[0], c[1]), c[2], Scalar(0, 0, 255), 3, LINE_AA);
		circle(cimg, Point(c[0], c[1]), 2, Scalar(0, 255, 0), 3, LINE_AA);
		circle(cimg, Point(d[0], d[1]), d[2], Scalar(0, 0, 255), 3, LINE_AA);
		circle(cimg, Point(d[0], d[1]), 2, Scalar(0, 255, 0), 3, LINE_AA);
		circle(cimg, Point(e[0], e[1]), e[2], Scalar(0, 0, 255), 3, LINE_AA);
		circle(cimg, Point(e[0], e[1]), 2, Scalar(0, 255, 0), 3, LINE_AA);


		//Centroid

		Vec<float, 3> centroid;
		//cout.precision(10); // ERROR GETTING DECIMAL POINTS IN OUTPUT ANSWER
		centroid[0] = (lowest[0] + secondlowest[0] + thirdlowest[0]) / 3;
		centroid[1] = (lowest[1] + secondlowest[1] + thirdlowest[1]) / 3;
		centroid[2] = (lowest[2] + secondlowest[2] + thirdlowest[2]) / 3;

		cout << "Centroid is" << centroid << endl;


		namedWindow("detected circles", WINDOW_NORMAL);
		imshow("detected circles", cimg);
		waitKey();
		getchar();
		namedWindow("MyWindow", WINDOW_NORMAL); //create a window with the name "MyWindow"
		imshow("MyWindow", img); //display the image which is stored in the 'img' in the "MyWindow" window

		//waitKey(0); //wait infinite time for a keypress

		//destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"
	}

	return 0;
}