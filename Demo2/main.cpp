#include <iostream>
#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;

void main()
{
	Mat img = imread("girl.jpg");
	imshow("ԭʼͼ", img);
	Mat DstPic, edge, grayImage;

	//������srcͬ���ͺ�ͬ��С�ľ���
	DstPic.create(img.size(), img.type());

	//��ԭʼͼת��Ϊ�Ҷ�ͼ
	cvtColor(img, grayImage, COLOR_BGR2GRAY);

	//��ʹ��3*3�ں�������
	blur(grayImage, edge, Size(3, 3));

	//����canny����
	Canny(edge, edge, 3, 9, 3);

	imshow("��Ե��ȡЧ��", edge);

	waitKey(0);
}
