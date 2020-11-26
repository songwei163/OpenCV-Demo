#include <opencv2/opencv.hpp>
#include <iostream>
#include <imgproc/types_c.h>
using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap;
	// VideoCapture cap("1.avi");	// Ҳ���Թ��켴��ʼ��
	cap.open("1.flv");	// ��ȡ������Դ

	Size size(cap.get(CAP_PROP_FRAME_WIDTH), cap.get(CAP_PROP_FRAME_HEIGHT));

	VideoWriter writer("2.avi", VideoWriter::fourcc('X', 'V', 'I', 'D'), 20, size, true);

	// cap.open("http://clips.vorwaerts-gmbh.de/big_buck_bunny.mp4");	//	��ȡ������Դ
	// cap.open(0);

	if (!cap.isOpened())
	{
		return -1;
	}

	int width = cap.get(CAP_PROP_FRAME_WIDTH);	// ֡���
	int height = cap.get(CAP_PROP_FRAME_HEIGHT);	// ֡�߶�
	int frameRate = cap.get(CAP_PROP_FPS);	// ֡��
	int totalFrames = cap.get(CAP_PROP_FRAME_COUNT);	//	��֡��

	cout << width << endl;
	cout << height << endl;
	cout << frameRate << endl;
	cout << totalFrames << endl;

	Mat frame;
	cout << "��ʼд��" << endl;
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

		if (waitKey(20) > 0)	// ����ESC==27�˳�	// > 0 ��ʾ���κ�һ���������˳�����Ϊ�ް�������-1
		{
			break;
		}
	}
	cout << "д�����" << endl;
	cap.release();
	destroyAllWindows();
}