#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img(imread("girl.jpg"));
	if (img.empty())
	{
		cout << "打开图片失败，程序退出！！！" << endl;
		exit(EXIT_FAILURE);
	}
	namedWindow("img");
	imshow("img", img);
	// 0代表一直等待，27表示按下ESC键，窗口退出
	if(27== waitKey(0))
	{
		return 0;
	}
	// return 0;
}