#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img(imread("girl.jpg"));
	if (img.empty())
	{
		cout << "��ͼƬʧ�ܣ������˳�������" << endl;
		exit(EXIT_FAILURE);
	}
	namedWindow("img");
	imshow("img", img);
	// 0����һֱ�ȴ���27��ʾ����ESC���������˳�
	if(27== waitKey(0))
	{
		return 0;
	}
	// return 0;
}