#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("girl.jpg");
	// Mat imgROI = img(Rect(20, 20, 200, 200));
	// Mat imgROI = img(Range(20, 220), Range(20, 220);
	Mat logo = imread("1.jpg");
	// Mat mask = imread("mask.jpg", 0);	// mask 一般用二值图
	// 手动创建二值图
	Mat mask = Mat::zeros(logo.size(),CV_8UC1);
	circle(mask, Point(mask.cols / 2+50, mask.rows / 2-25),100,Scalar(255),-1,8);
	
	Mat imgROI = img(Rect(20, 20, logo.cols, logo.rows));
	logo.copyTo(imgROI, mask);
	// addWeighted(imgROI, 0.5, logo, 0.3, 0, imgROI
	imshow("dst", img);
	
	imshow("ROI", imgROI);
	waitKey(0);
	return 0;
}