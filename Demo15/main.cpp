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
	// ��������
	// adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 11, 5);
	// adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 11, 5);
	// adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_TRUNC, 11, 5);
	
	imshow("����Ӧ��ֵ", dst);
}

void onThreshold(int,void*)
{
	threshold(src, dst, thres_min, 255, THRESH_BINARY);
	//threshold(src, dst, 120, 255, THRESH_BINARY_INV);
	//threshold(src, dst, 120, 255, THRESH_TRUNC);
	//threshold(src, dst, 120, 255, THRESH_TOZERO);
	//threshold(src, dst, 120, 255, THRESH_TOZERO_INV);
	imshow("src", src);
	imshow("�̶���ֵ", dst);
}

int main() {
	// ��ֵ��������ԭͼ��һ��Ϊ�Ҷ�ͼ���ֵͼ
	// src = imread("lena.jpg", IMREAD_GRAYSCALE);	//cvtColorҲ����ת
	src = imread("girl.jpg", IMREAD_GRAYSCALE);	//cvtColorҲ����ת
	namedWindow("�̶���ֵ");
	namedWindow("����Ӧ��ֵ");
	createTrackbar("Threshold", "�̶���ֵ", &thres_min, 255, onThreshold, 0);
	onThreshold(thres_min, 0);
	createTrackbar("BlockSize", "����Ӧ��ֵ", &block_size, 255, onAdaptiveThreshold, 0);
	createTrackbar("C","����Ӧ��ֵ", &C0, 255, onAdaptiveThreshold, 0);
	onAdaptiveThreshold(block_size, 0);
	onThreshold(C0, 0);
	// ����Ӧ��ֵ


	
	// imshow("src", src);
	// imshow("dst", dst);
	waitKey(0);
	return 0;
}