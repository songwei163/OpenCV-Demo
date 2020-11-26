#include <iostream>
#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;

void main()
{
	Mat img = imread("girl.jpg");
	imshow("原始图", img);
	Mat DstPic, edge, grayImage;

	//创建与src同类型和同大小的矩阵
	DstPic.create(img.size(), img.type());

	//将原始图转化为灰度图
	cvtColor(img, grayImage, COLOR_BGR2GRAY);

	//先使用3*3内核来降噪
	blur(grayImage, edge, Size(3, 3));

	//运行canny算子
	Canny(edge, edge, 3, 9, 3);

	imshow("边缘提取效果", edge);

	waitKey(0);
}
