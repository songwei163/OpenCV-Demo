#include <opencv2/opencv.hpp>
#include <iostream>
#include <imgproc/types_c.h>

using namespace cv;
using namespace std;

// ���ı�ͼ���С
Mat imgTranslate(Mat& srcImg, int xOffset, int yOffset);
// �ı�ͼ���С
Mat imgTranslate2(Mat& srcImg, int xOffset, int yOffset);

int main()
{
	Mat img = imread("girl.jpg");
	Mat dst;
	// ��С
	// resize(img, dst, Size(), 0.5, 0.5, CV_INTER_AREA);
	// imshow("dst", dst);

	// ƽ��
	// ���ı�ͼ���С
	// dst = imgTranslate(img, 100, 100);
	// �ı�ͼ���С
	// dst = imgTranslate2(img, 100, 100);
	// imshow("dst", dst);

	// transpose(img, dst);	// ת��
	flip(img, dst, 1);	// ����

	// ͼ����ת
	// Point2f center = Point2f(img.cols / 2, img.rows / 2);
	// double angle = 30;
	// double scale = 0.5;
	// Mat roateM = getRotationMatrix2D(center, angle, scale);
	// warpAffine(img, dst, roateM, Size(1000, 800));
	
	
	// int rows = img.rows;
	// int cols = img.cols;
	//
	// Mat xMapImg = Mat::zeros(img.size(), CV_32FC1);  //map1
	// Mat yMapImg = Mat::zeros(img.size(), CV_32FC1);  //map2
	//
	// for (int i = 0; i < rows; i++)
	// {
	// 	for (int j = 0; j < cols; j++)
	// 	{
	// 		xMapImg.at<float>(i, j) = j;  //�����в���
	// 		//yMapImg.at<float>(i, j) = i + 5 * sin(j/10.0);
	// 		yMapImg.at<float>(i, j) = rows - i;
	// 	}
	// }
	// remap(img, dst, xMapImg, yMapImg, CV_INTER_LINEAR);

	imshow("img", img);
	imshow("dst", dst);
	
	waitKey(0);
	return 0;
}

Mat imgTranslate(Mat& srcImg, int xOffset, int yOffset)
{
	int rows = srcImg.rows;
	int cols = srcImg.cols;
	Mat dstImg = Mat::zeros(srcImg.size(), srcImg.type());  //����ȫ��ͼ��
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int x = j + xOffset;
			int y = i + yOffset;
			if (x >= 0 && y >= 0 && x < cols && y < rows)
			{
				dstImg.at<Vec3b>(y, x) = srcImg.at<Vec3b>(i, j);
			}
		}
	}
	return dstImg;
}

Mat imgTranslate2(Mat& srcImg, int xOffset, int yOffset)
{
	int rows = srcImg.rows + yOffset;
	int cols = srcImg.cols + xOffset;
	Mat dstImg = Mat::zeros(rows, cols, srcImg.type());  //����ȫ��ͼ��
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int x = j + xOffset;
			int y = i + yOffset;
			if (x >= 0 && y >= 0 && x < cols && y < rows)
			{
				dstImg.at<Vec3b>(y, x) = srcImg.at<Vec3b>(i, j);
			}
		}
	}
	return dstImg;
}