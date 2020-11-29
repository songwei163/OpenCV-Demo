#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img(imread("1.jpg"));

	if(img.empty())
	{
		cout << "图像载入失败" << endl;
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
	// 		// OPenCV的通道顺序是BGR
	// 		dst.at<Vec3b>(i, j)[0] = 255;	// 蓝色通道
	// 		dst.at<Vec3b>(i, j)[1] = 0;		// 绿色通道
	// 		dst.at<Vec3b>(i, j)[2] = 0;		// 红色通道
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

	// // 指针访问
	// rows = out.rows;
	// cols = out.cols * out.channels();
	// for(int i=0;i<rows;++i)
	// {
	// 	// 获取每一行首地址
	// 	uchar* data = out.ptr<uchar>(i);
	// 	for(int j=0;i<cols;++j)
	// 	{
	// 		switch(j % 3)
	// 		{
	// 		case 0:  //蓝色通道
	// 			data[j] = data[j] / 64 * 64 + 64/2;
	// 			break;
	// 		case 1:  //绿色通道
	// 			data[j] = data[j] / 64 * 64 + 64/2;
	// 			break;
	// 		case 2:  //红色通道
	// 			data[j] = data[j] / 64 * 64 + 64/2;
	// 			break;
	// 		}
	// 	}
	// } 
	
	imshow("原图像", img);
	imshow("加雪花效果", dst);
	// imshow("减色效果", out);

	if(27==waitKey(0))
	{
		return 0;
	}

	
}
