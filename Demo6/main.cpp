#include <opencv2/opencv.hpp>

#include <iostream>

using namespace cv;
using namespace std;

Mat img = imread("girl.jpg");
Mat temp;
Mat ROI;
Point pt;
bool flag = false;

void onMouse(int event, int x, int y, int flag, void* param)
{
	switch(event)
	{
	case EVENT_LBUTTONDOWN:
		flag = true;
		pt.x = x;
		pt.y = y;
		break;
	case EVENT_MOUSEMOVE:
		if (flag == true)
		{
			temp.copyTo(img);
			rectangle(img, pt, Point(x, y), Scalar(0, 255, 0), 2, 8);
		}
		break;
	case EVENT_LBUTTONUP:
		flag = false;
		// 用temp的原因是去掉ROI的矩形框
		ROI = temp(Rect(pt.x, pt.y, x - pt.x, y - pt.y));
		imshow("ROI", ROI);
		imwrite("ROI.bmp", ROI);
		break;
	default:
		break;
	}
}

int main()
{
	namedWindow("mouse", WINDOW_AUTOSIZE);
	setMouseCallback("mouse", onMouse, 0);

	if (img.empty())
	{
		cout << "载入图片失败" << endl;
		exit(EXIT_FAILURE);
	}

	temp = img.clone();
	
	while(true)
	{
		imshow("mouse", img);
		if(27==waitKey(10))
		{
			break;
		}
	}
	
	return 0;
}