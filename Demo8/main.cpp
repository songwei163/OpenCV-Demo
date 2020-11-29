#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img(imread("1.jpg"));

	if(img.empty())
	{
		cout << "ͼ������ʧ��" << endl;
		exit(EXIT_FAILURE);
	}

	int rows = img.rows;
	int cols = img.cols;

	cout << "rows:" << rows << endl;
	cout << "cols:" << cols << endl;
	cout << "channels:" << img.channels() << endl;

	Mat dst = img.clone();
	Mat out = img.clone();
	
	// for(int i=0;i<rows;++i)
	// {
	// 	for(int j=0;j<cols;++j)
	// 	{
	// 		// OPenCV��ͨ��˳����BGR
	// 		dst.at<Vec3b>(i, j)[0] = 255;	// ��ɫͨ��
	// 		dst.at<Vec3b>(i, j)[1] = 0;		// ��ɫͨ��
	// 		dst.at<Vec3b>(i, j)[2] = 0;		// ��ɫͨ��
	// 	}
	// }

	int i,j;
	for(int k=0;k<10000;++k)
	{
		i = rand() % rows;
		j = rand() % cols;
		dst.at<Vec3b>(i, j)[0] = 255;
		dst.at<Vec3b>(i, j)[1] = 255;
		dst.at<Vec3b>(i, j)[2] = 255;
	}

	// // ָ�����
	// rows = out.rows;
	// cols = out.cols * out.channels();
	// for(int i=0;i<rows;++i)
	// {
	// 	// ��ȡÿһ���׵�ַ
	// 	uchar* data = out.ptr<uchar>(i);
	// 	for(int j=0;i<cols;++j)
	// 	{
	// 		switch(j % 3)
	// 		{
	// 		case 0:  //��ɫͨ��
	// 			data[j] = data[j] / 64 * 64 + 64/2;
	// 			break;
	// 		case 1:  //��ɫͨ��
	// 			data[j] = data[j] / 64 * 64 + 64/2;
	// 			break;
	// 		case 2:  //��ɫͨ��
	// 			data[j] = data[j] / 64 * 64 + 64/2;
	// 			break;
	// 		}
	// 	}
	// } 
	
	imshow("ԭͼ��", img);
	imshow("��ѩ��Ч��", dst);
	// imshow("��ɫЧ��", out);

	if(27==waitKey(0))
	{
		return 0;
	}

	
}
