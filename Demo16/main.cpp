#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	// 膨胀腐蚀是基于高亮部分操作的
	// 建议原图像为二值图
	// 膨胀->求局部最大值，高亮区域变多
	// 腐蚀->求局部最小值，高亮区域减少
	// Mat src = imread("text.png", 0);
	// Mat dst;
	 
	// MORPH_RECT = 0, 
	// MORPH_CROSS = 1, 
	// MORPH_ELLIPSE = 2
	 
	// Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
	// cout << element << endl;
	// 膨胀 连接相邻区域 放大离散噪点
	// dilate(src, dst, element,Point(-1,-1),3);	// 第五个参数，代表膨胀次数
	 
	// 腐蚀 分割相邻区域 去除离散噪点
	// erode(src, dst, element,Point(-1, -1), 2);

	// 开运算：先腐蚀后膨胀，消除小物体，纤细处分离物体
	// morphologyEx(src, dst, MORPH_OPEN,element);

	// 闭运算：先膨胀后腐蚀，消除小型黑洞
	// morphologyEx(src, dst,MORPH_CLOSE, element);

	// 形态学梯度，提取轮廓
	// morphologyEx(src, dst, MORPH_GRADIENT, element);
	
	// 顶帽：闭运算和原图像做差
	// morphologyEx(src, dst, MORPH_TOPHAT, element);
	
	// 黑帽：开运算和原图像做差
	// morphologyEx(src, dst, MORPH_BLACKHAT, element);
	
	// imshow("src", src);
	// imshow("dst", dst);

	Mat img1 = imread("A.bmp");
	Mat img2 = imread("B.bmp");
	Mat diff_img = img1 - img2;
	imshow("Diff", diff_img);
	Mat gray;
	// 将差转为灰度图
	cvtColor(diff_img, gray, COLOR_BGR2GRAY);
	// 自适应阈值做二值化
	adaptiveThreshold(gray, gray, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 15, 3);
	imshow("adapt", gray);

	Mat k0 = getStructuringElement(MORPH_RECT, Size(21, 21));
	Mat k1 = getStructuringElement(MORPH_RECT, Size(11, 11));
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));
	//进行形态学操作
	// 开运算：先腐蚀，后膨胀
	morphologyEx(gray, gray, MORPH_OPEN, element);
	// 中值滤波 去除噪点
	medianBlur(gray, gray, 9);
	// 膨胀
	dilate(gray, gray, k0);
	imshow("dst", gray);

	waitKey(0);
	
	waitKey(0);
	return 0;
}