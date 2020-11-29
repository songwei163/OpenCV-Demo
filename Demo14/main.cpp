#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int SSize = 1;
Mat src = imread("lena.jpg");
Mat dst;

void onChange(int, void* param)
{
	boxFilter(src, dst, src.depth(), Size(SSize, SSize), Point(-1, -1), true);	// true��������һ��
	imshow("dst", dst);
	imshow("src", src);
}


int main()
{


	// imshow("src", src);

	namedWindow("dst");
	createTrackbar("SSize", "dst", &SSize, 50, onChange, 0);

	onChange(SSize, 0);

	// 线性滤波

		// 方框滤波
		// boxFilter(src, dst, src.depth(), Size(3, 3), Point(-1, -1), true);	// true代表做归一化

		// 均值滤波
		// blur(src, dst, Size(3, 3), Point(-1, -1));

		// 高斯滤波
	GaussianBlur(src, dst, Size(3, 3), 1);

	// 非线性滤波

		// 中值滤波	滤除椒盐噪声，雪花噪声
	medianBlur(src, dst, 3);

	// 双边滤波
	bilateralFilter(src, dst, 3, 10.0, 2.0);
	waitKey(0);

	return 0;
}