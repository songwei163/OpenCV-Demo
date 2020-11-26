#include <opencv2/opencv.hpp>
#include <iostream>
#include <imgproc/types_c.h>
using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap;
	// VideoCapture cap("1.avi");	// 也可以构造即初始化
	cap.open("1.flv");	// 读取本地资源

	Size size(cap.get(CAP_PROP_FRAME_WIDTH), cap.get(CAP_PROP_FRAME_HEIGHT));

	VideoWriter writer("2.avi", VideoWriter::fourcc('X', 'V', 'I', 'D'), 20, size, true);

	// cap.open("http://clips.vorwaerts-gmbh.de/big_buck_bunny.mp4");	//	读取网络资源
	// cap.open(0);

	if (!cap.isOpened())
	{
		return -1;
	}

	int width = cap.get(CAP_PROP_FRAME_WIDTH);	// 帧宽度
	int height = cap.get(CAP_PROP_FRAME_HEIGHT);	// 帧高度
	int frameRate = cap.get(CAP_PROP_FPS);	// 帧率
	int totalFrames = cap.get(CAP_PROP_FRAME_COUNT);	//	总帧数

	cout << width << endl;
	cout << height << endl;
	cout << frameRate << endl;
	cout << totalFrames << endl;

	Mat frame;
	cout << "开始写入" << endl;
	while (1)
	{
		cap >> frame;
		// cap.read(frame);
		// Canny(frame, frame, 30,100);
		// cvtColor(frame, frame, CV_BGR2HSV);
		writer << frame;
		if (frame.empty())
		{
			break;
		}

		// namedWindow("video", WINDOW_NORMAL);
		// imshow("video", frame);

		if (waitKey(20) > 0)	// 按下ESC==27退出	// > 0 表示按任何一个键都能退出，因为无按键返回-1
		{
			break;
		}
	}
	cout << "写入完成" << endl;
	cap.release();
	destroyAllWindows();
}