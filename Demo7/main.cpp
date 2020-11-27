#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

double Fps;
int value;
int framePos;

void Onchange(int, void* param)
{
	VideoCapture cap = *(VideoCapture*)param;
	cap.set(CAP_PROP_POS_FRAMES, value);  //设置视频帧位置
}

int main()
{
	VideoCapture cap("1.flv");
	if (!cap.isOpened())
	{
		cout << "载入失败";
		exit(EXIT_FAILURE);
	}

	Fps = cap.get(CAP_PROP_FPS);	// 获得帧率
	char strFps[20];
	sprintf_s(strFps, "Fps:%.1f/s", Fps);

	int FrameCount = cap.get(CAP_PROP_FRAME_COUNT);	// 获得总帧数
	
	Mat frame;
	namedWindow("video");
	//	创建滑动条
	createTrackbar("Frame", "video", &value, FrameCount, Onchange, &cap);
	while(true)
	{
		framePos = cap.get(CAP_PROP_POS_FRAMES);	// 获取视频帧位置
		// 设置滑动条位置
		setTrackbarPos("Frame", "video", framePos);
		cap >> frame;
		if(frame.empty())
		{
			cout << "取帧失败" << endl;
			exit(EXIT_FAILURE);
		}

		putText(frame, strFps, Point(5, 30), FONT_HERSHEY_COMPLEX_SMALL, 1, Scalar(0, 255, 0), 1, 8);
		imshow("video", frame);

		if(27==waitKey(1000/Fps))
		{
			break;
		}
	}

	cap.release();
	destroyAllWindows();
	
	return 0;
}