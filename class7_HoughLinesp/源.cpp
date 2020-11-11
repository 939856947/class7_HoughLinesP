#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{

	//载入原始图
	Mat srcImage = imread("D:\\18.jpg");
	Mat midImage, dstImage;

	//canny检测边缘转化为灰度图
	Canny(srcImage, midImage, 50, 200, 3);
	cvtColor(midImage, dstImage, CV_GRAY2BGR);

	//进行霍夫变换
	std::vector<cv::Vec4i> lines;
	HoughLinesP(midImage, lines,3, CV_PI /180,55, 15,5);

	//一次在图中绘制出每条线段
	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0];
		float theta = lines[i][1];
		Point pt1, pt2;
		pt1.x = lines[i][0];
		pt1.y = lines[i][1];
		pt2.x = lines[i][2];
		pt2.y = lines[i][3];
		line(srcImage, pt1, pt2, Scalar(0, 0, 255), 2, LINE_AA);

	}


	//边缘检测之后的图
	imshow("【边缘检测后的图】", midImage);
	//显示效果图
	imshow("【效果图】", srcImage);
	waitKey(0);
	return 0;
}