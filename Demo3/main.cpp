#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;


void main()
{
	VideoCapture cap;
	cap.open("1.flv"); //����Ƶ

	//cap.open(0); //����Ƶ
	//VideoCapture cap("E:\\2.avi");
	//cap.open("http://www.laganiere.name/bike.avi");
	if (!cap.isOpened())
	{
		cout << "�ļ���ʧ�ܣ�����" << endl;
		return;
	}

	int width = cap.get(CAP_PROP_FRAME_WIDTH);  //֡���
	int height = cap.get(CAP_PROP_FRAME_HEIGHT); //֡�߶�
	int frameRate = cap.get(CAP_PROP_FPS);  //֡�� x frames/s
	int totalFrames = cap.get(CAP_PROP_FRAME_COUNT); //��֡��

	cout << "��Ƶ���=" << width << endl;
	cout << "��Ƶ�߶�=" << height << endl;
	cout << "��Ƶ��֡��=" << totalFrames << endl;
	cout << "֡��=" << frameRate << endl;

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