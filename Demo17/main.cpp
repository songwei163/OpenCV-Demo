#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat src;
Mat dst;

int min_thres = 1;
int max_thres = 1;

void onThreshold(int,void*)
{
	Canny(src, dst, min_thres, max_thres);
	imshow("Canny", dst);
}

int main()
{
	// src = imread("girl.jpg",0);
	// namedWindow("Canny");
	// // adaptiveThreshold(src, src, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 5);
	// imshow("src", src);
	// createTrackbar("min_thres", "Canny", &min_thres, 255, onThreshold, 0);
	// createTrackbar("max_thres", "Canny", &max_thres, 255, onThreshold, 0);
	//
	//
	// onThreshold(min_thres, 0);
	// onThreshold(max_thres, 0);
	
	// Mat dst;
	// blur(src, dst, Size(5, 5));
	// 关于2个阈值参数：
	//
	// 	低于阈值1的像素点会被认为不是边缘；
	// 	高于阈值2的像素点会被认为是边缘；
	// 	在阈值1和阈值2之间的像素点, 若与第2步得到的边缘像素点相邻，则被认为是边缘，否则被认为不是边缘。
	// Canny(src, dst, 30, 80);
	// imshow("dst", dst);

		///Sobel±ßÔµ¼ì²â
	/*Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y, dst;

	Mat src = imread("1.jpg", 0);
	imshow("src", src);

	Sobel(src, grad_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);
	imshow("X·½Ïò", abs_grad_x);

	Sobel(src, grad_y, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);
	imshow("Y·½Ïò", abs_grad_y);

	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst);
	imshow("ºÏ²¢Ð§¹û", dst);

	waitKey(0);
	destroyAllWindows();*/

	///Laplacian±ßÔµ¼ì²â
	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y, dst;
	Mat abs_dst;

	Mat src = imread("1.jpg", 0);
	imshow("src", src);

	Laplacian(src, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(dst, abs_dst);

	imshow("Laplacian", abs_dst);

	waitKey(0);
	destroyAllWindows();
	
	waitKey(0);
	return 0;
}