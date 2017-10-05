//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/core/core.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//int main(int argc, const char** argv)
//{
//	Mat img = imread("Abdul_kalam.JPG", CV_LOAD_IMAGE_UNCHANGED); //read the image data in the file "MyPic.JPG" and store it in 'img'
//
//	if (img.empty()) //check whether the image is loaded or not
//	{
//		cout << "Error : Image cannot be loaded..!!" << endl;
//		//system("pause"); //wait for a key press
//		return -1;
//	}
//
//	//cv::flip(img, img, 0);
//	cv::circle(img, // destination image
//		cv::Point(155, 110), // center coordinate
//		65, // radius
//		0, // color (here black)
//		3); // thickness
//
//	cv::putText(img, // destination image
//		"This is a dog.", // text
//		cv::Point(40, 200), // text position
//		cv::FONT_HERSHEY_PLAIN, // font type
//		2.0, // font scale
//		255, // text color (herewhite)
//		2); // text thickness
//
//	namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
//	imshow("MyWindow", img); //display the image which is stored in the 'img' in the "MyWindow" window
//
//	waitKey(0); //wait infinite time for a keypress
//
//	destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"
//
//	return 0;
//}



//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include "opencv2/imgproc/imgproc.hpp"
//#include "Source.h"
//using namespace cv;
//
//int main()
//{
//	// Create black empty images
//	Mat image = Mat::zeros(400, 400, CV_8UC3);
//
//	// Draw a rectangle ( 5th argument is not -ve)
//	rectangle(image, Point(15, 20), Point(70, 50), Scalar(0, 55, 255), +1, 4);
//	imshow("Image1", image);
//	// Draw a filled rectangle ( 5th argument is -ve)
//	rectangle(image, Point(115, 120), Point(170, 150), Scalar(100, 155, 25), -1, 8);
//	imshow("Image2", image);
//
//	waitKey(0);
//	return(0);
//}
//
//
//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/core/core.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//int main(int argc, const char** argv)
//{
//	Mat img = imread("Abdul_kalam.JPG", CV_LOAD_IMAGE_UNCHANGED); //read the image data in the file "MyPic.JPG" and store it in 'img'
//
//	if (img.empty()) //check whether the image is loaded or not
//	{
//		cout << "Error : Image cannot be loaded..!!" << endl;
//		//system("pause"); //wait for a key press
//		return -1;
//	}
//
//	//cv::flip(img, img, 0);
//	cv::circle(img, // destination image
//		cv::Point(155, 110), // center coordinate
//		65, // radius
//		0, // color (here black)
//		3); // thickness
//
//	cv::putText(img, // destination image
//		"This is a dog.", // text
//		cv::Point(40, 200), // text position
//		cv::FONT_HERSHEY_PLAIN, // font type
//		2.0, // font scale
//		255, // text color (herewhite)
//		2); // text thickness
//	void onMouse(int event, int x, int y, int flags, void*
//		param)
//	{cv::Mat *im = reinterpret_cast<cv::Mat*>(param);
//		switch (event) { // dispatch the event
//		case cv::EVENT_LBUTTONDOWN: // left mouse button down event
//// display pixel value at (x,y)
//			std::cout << "at (" << x << "," << y << ") value is:" << static_cast<int>(im->at<uchar>(cv::Point(x, y))) <<td::endl;
//			break;
//		}
//	
//	};
//	namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
//	imshow("MyWindow", img); //display the image which is stored in the 'img' in the "MyWindow" window
//
//	waitKey(0); //wait infinite time for a keypress
//
//	destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"
//
//	return 0;
//}



//#include <iostream>
//#include <opencv2/core.hpp>
//#include <opencv2/highgui.hpp>
//// test function that creates an image
//cv::Mat function() {
//	// create image
//	cv::Mat ima(500, 500, CV_8U, 50);
//	// return it
//	return ima;
//}
//int main() {
//	// create a new image made of 240 rows and 320 columns
//	cv::Mat image1(240, 320, CV_8U, 100);
//	cv::imshow("Image", image1); // show the image
//	cv::waitKey(0); // wait for a key pressed
//					// re-allocate a new image
//	image1.create(200, 200, CV_8U);
//	image1 = 200;
//	cv::imshow("Image", image1); // show the image
//	cv::waitKey(0); // wait for a key pressed
//					// create a red color image
//					// channel order is BGR
//	cv::Mat image2(240, 320, CV_8UC3, cv::Scalar(0, 0, 255));
//	// or:
//	// cv::Mat image2(cv::Size(320,240),CV_8UC3);
//	// image2= cv::Scalar(0,0,255);
//	cv::imshow("Image", image2); // show the image
//	cv::waitKey(0); // wait for a key pressed
//					// read an image
//	cv::Mat image3 = cv::imread("Abdul_kalam.jpg");
//	// all these images point to the same data block
//	cv::Mat image4(image3);
//	image1 = image3;
//	// these images are new copies of the source image
//	image3.copyTo(image2);
//	cv::Mat image5 = image3.clone();
//	// transform the image for testing
//	cv::flip(image3, image3, 1);
//	// check which images have been affected by the processing
//		cv::imshow("Image 3", image3);
//	cv::imshow("Image 1", image1);
//	cv::imshow("Image 2", image2);
//	cv::imshow("Image 4", image4);
//	cv::imshow("Image 5", image5);
//	cv::waitKey(0); // wait for a key pressed
//					// get a gray-level image from a function
//	cv::Mat gray = function();
//	cv::imshow("Image", gray); // show the image
//	cv::waitKey(0); // wait for a key pressed
//					// read the image in gray scale
//	image1 = cv::imread("Abdul_kalam.jpg", CV_LOAD_IMAGE_GRAYSCALE);
//	image1.convertTo(image2, CV_32F, 1 / 255.0, 0.0);
//	cv::imshow("Image", image2); // show the image
//	cv::waitKey(0); // wait for a key pressed
//	return 0;
//}
