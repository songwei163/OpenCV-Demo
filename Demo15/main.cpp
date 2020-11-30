#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat src, dst;
int thres_min = 20;

int block_size = 3;
int C0 = 3;

void onAdaptiveThreshold(int,void*)
{
	// block_size 
	if (block_size%2==0) {
		++block_size;
	}
	adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, block_size, C0);
	// imshow("src", src);
	// adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 5);
	// 线条粗犷
	// adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 11, 5);
	// adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 11, 5);
	// adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_TRUNC, 11, 5);
	
	imshow("自适应阈值", dst);
}

void onThreshold(int,void*)
{
	threshold(src, dst, thres_min, 255, THRESH_BINARY);
	//threshold(src, dst, 120, 255, THRESH_BINARY_INV);
	//threshold(src, dst, 120, 255, THRESH_TRUNC);
	//threshold(src, dst, 120, 255, THRESH_TOZERO);
	//threshold(src, dst, 120, 255, THRESH_TOZERO_INV);
	imshow("src", src);
	imshow("固定阈值", dst);
}

int main() {
	// 阈值化操作，原图像一般为灰度图或二值图
	// src = imread("lena.jpg", IMREAD_GRAYSCALE);	//cvtColor也可以转
	src = imread("girl.jpg", IMREAD_GRAYSCALE);	//cvtColor也可以转
	namedWindow("固定阈值");
	namedWindow("自适应阈值");
	createTrackbar("Threshold", "固定阈值", &thres_min, 255, onThreshold, 0);
	onThreshold(thres_min, 0);
	createTrackbar("BlockSize", "自适应阈值", &block_size, 255, onAdaptiveThreshold, 0);
	createTrackbar("C","自适应阈值", &C0, 255, onAdaptiveThreshold, 0);
	onAdaptiveThreshold(block_size, 0);
	onThreshold(C0, 0);
	// 自适应阈值


	
	// imshow("src", src);
	// imshow("dst", dst);
	waitKey(0);
	return 0;
}