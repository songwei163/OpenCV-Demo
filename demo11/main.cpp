#include <opencv2/opencv.hpp>

#include <iostream>
#include <vector>
using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("girl.jpg");

	vector<Mat> channels;

	split(img, channels);

	Mat red_channels = channels.at(2);
	Mat green_channels = channels.at(1);
	Mat blue_channels = channels.at(0);

	imshow("src", img);
	imshow("red", red_channels);
	imshow("green", green_channels);
	imshow("blue", blue_channels);

	// 对每个通道做二值化处理
	threshold(blue_channels, blue_channels, 200, 255, THRESH_BINARY);
	threshold(green_channels, green_channels, 200, 255, THRESH_BINARY);
	threshold(red_channels, red_channels, 200, 255, THRESH_BINARY);

	Mat dst;
	merge(channels, dst);
	
	imshow("dst", dst);
	waitKey(0);
	return 0;
}