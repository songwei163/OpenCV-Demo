#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#define WIN_NAME "输出图像"

int ContraseValue = 20;
int BrightValue = 20;

Mat srcImg;
Mat dstImg;

void onChange(int, void* param)
{
	for (int i = 0; i < srcImg.rows; ++i)
	{
		for(int j=0;j<srcImg.cols;++j) {
			//saturate_cast溢出保护
			dstImg.at<Vec3b>(i, j)[0] = saturate_cast<uchar>(srcImg.at<Vec3b>(i, j)[0] * 0.01 * ContraseValue + BrightValue);
			dstImg.at<Vec3b>(i, j)[1] = saturate_cast<uchar>(srcImg.at<Vec3b>(i, j)[1] * 0.01 * ContraseValue + BrightValue);
			dstImg.at<Vec3b>(i, j)[2] = saturate_cast<uchar>(srcImg.at<Vec3b>(i, j)[2] * 0.01 * ContraseValue + BrightValue);
		}
	}
	imshow("原图", srcImg);
	imshow(WIN_NAME, dstImg);
}

int main()
{
	//	f(y) = a * f(x) + b;
	//	a->对比度 b->亮度
	// Mat的拷贝构造函数不能接收无名临时对象
	// To set all the matrix elements to
	// the particular value after the construction, use the assignment operator Mat::operator=()

	srcImg = imread("1.jpg");
	//Mat::zeros->矩阵置0，Mat::ones->矩阵置1 
	dstImg = Mat::zeros(srcImg.size(),srcImg.type());

	namedWindow(WIN_NAME);

	createTrackbar("对比度", WIN_NAME, &ContraseValue, 300, onChange, 0);
	createTrackbar("亮度", WIN_NAME, &BrightValue, 200, onChange, 0);

	onChange(ContraseValue, 0); //回调函数初始化
	onChange(BrightValue, 0);

	waitKey(0);
	
	return 0;
}
