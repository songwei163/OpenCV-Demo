#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat img1 = imread("1.jpg");
	Mat img2 = imread("2.jpg");
	Mat dst;
	imshow("img1", img1);
	imshow("img2", img2);
	cout << "img1  " << int(img1.at<Vec3b>(10, 10)[0]) << endl;
	cout << "img2  " << int(img2.at<Vec3b>(10, 10)[0]) << endl;

	//dst  = img1 + img2;
	// add(img1, img2, dst);
	addWeighted(img1, 0.5, img2, 0.5, 0, dst);

	//dst = img1 - img2;
	//subtract(img1, img2, dst);
	//减完取绝对值，差异，相似度比较高的情况下做缺陷检测
	// absdiff(img1, img2, dst);

	//dst = 5 * img1 ;
	//dst = img1 / 5;

	// bitwise_and(img1, img2, dst);
	// bitwise_or(img1, img2, dst);
	// bitwise_not(img1, dst);
	// bitwise_xor(img1, img2, dst);

	// cout << "dst  " << int(dst.at<Vec3b>(10, 10)[0]) << endl;
	imshow("dst", dst);
	waitKey(0);
	return 0; 
}