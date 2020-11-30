#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	// ���͸�ʴ�ǻ��ڸ������ֲ�����
	// ����ԭͼ��Ϊ��ֵͼ
	// ����->��ֲ����ֵ������������
	// ��ʴ->��ֲ���Сֵ�������������
	// Mat src = imread("text.png", 0);
	// Mat dst;
	 
	// MORPH_RECT = 0, 
	// MORPH_CROSS = 1, 
	// MORPH_ELLIPSE = 2
	 
	// Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
	// cout << element << endl;
	// ���� ������������ �Ŵ���ɢ���
	// dilate(src, dst, element,Point(-1,-1),3);	// ������������������ʹ���
	 
	// ��ʴ �ָ��������� ȥ����ɢ���
	// erode(src, dst, element,Point(-1, -1), 2);

	// �����㣺�ȸ�ʴ�����ͣ�����С���壬��ϸ����������
	// morphologyEx(src, dst, MORPH_OPEN,element);

	// �����㣺�����ͺ�ʴ������С�ͺڶ�
	// morphologyEx(src, dst,MORPH_CLOSE, element);

	// ��̬ѧ�ݶȣ���ȡ����
	// morphologyEx(src, dst, MORPH_GRADIENT, element);
	
	// ��ñ���������ԭͼ������
	// morphologyEx(src, dst, MORPH_TOPHAT, element);
	
	// ��ñ���������ԭͼ������
	// morphologyEx(src, dst, MORPH_BLACKHAT, element);
	
	// imshow("src", src);
	// imshow("dst", dst);

	Mat img1 = imread("A.bmp");
	Mat img2 = imread("B.bmp");
	Mat diff_img = img1 - img2;
	imshow("Diff", diff_img);
	Mat gray;
	// ����תΪ�Ҷ�ͼ
	cvtColor(diff_img, gray, COLOR_BGR2GRAY);
	// ����Ӧ��ֵ����ֵ��
	adaptiveThreshold(gray, gray, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 15, 3);
	imshow("adapt", gray);

	Mat k0 = getStructuringElement(MORPH_RECT, Size(21, 21));
	Mat k1 = getStructuringElement(MORPH_RECT, Size(11, 11));
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
	//������̬ѧ����
	// �����㣺�ȸ�ʴ��������
	morphologyEx(gray, gray, MORPH_OPEN, element);
	// ��ֵ�˲� ȥ�����
	medianBlur(gray, gray, 9);
	// ����
	dilate(gray, gray, k0);
	imshow("dst", gray);

	waitKey(0);
	
	waitKey(0);
	return 0;
}