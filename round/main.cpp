#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
	Mat src = imread("rim.png", 0);
	Mat dist;
	Mat proc;
	Mat proc1;
	Mat labelmat;
	Mat statsmat;
	Mat centermat;
	Mat dstImage;
	threshold(src, dist, 125, 255, THRESH_BINARY_INV);
	//int nComp = connectedComponentsWithStats(dist, labelmat, statsmat, centermat, 8, CV_32S);
	//cout << "圆的个数为:" << nComp - 1 << endl;
	//imshow("ss", proc1);
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(dist, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
//	RotatedRect rbox = minAreaRect(contours);
	for (int i = 0; i < contours.size(); i++)
	{
		RotatedRect rbox = minAreaRect(contours[i]);
		float width = rbox.size.width;
		float height = rbox.size.height;
		float test = width / height;
		if (test>0.9&&test<1.1) {
			drawContours(src, contours, i, Scalar(255, 255, 0), FILLED, 8, hierarchy);
		}
	}
	//【7】显示最后的轮廓图
	imshow("轮廓图", src);

	waitKey(0);
}