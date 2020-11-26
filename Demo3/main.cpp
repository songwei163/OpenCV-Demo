#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;


void main()
{
	VideoCapture cap;
	cap.open("1.flv"); //打开视频

	//cap.open(0); //打开视频
	//VideoCapture cap("E:\\2.avi");
	//cap.open("http://www.laganiere.name/bike.avi");
	if (!cap.isOpened())
	{
		cout << "文件打开失败！！！" << endl;
		return;
	}

	int width = cap.get(CAP_PROP_FRAME_WIDTH);  //帧宽度
	int height = cap.get(CAP_PROP_FRAME_HEIGHT); //帧高度
	int frameRate = cap.get(CAP_PROP_FPS);  //帧率 x frames/s
	int totalFrames = cap.get(CAP_PROP_FRAME_COUNT); //总帧数

	cout << "视频宽度=" << width << endl;
	cout << "视频高度=" << height << endl;
	cout << "视频总帧数=" << totalFrames << endl;
	cout << "帧率=" << frameRate << endl;

	Mat frame;
	while (1)
	{
		cap >> frame;
		if (frame.empty())
			break;
		imshow("video", frame);
		if (waitKey(20) > 0)
			break;
	}
	cap.release();
	destroyAllWindows();
}