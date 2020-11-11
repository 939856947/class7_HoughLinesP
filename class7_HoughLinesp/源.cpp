#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{

	//����ԭʼͼ
	Mat srcImage = imread("D:\\18.jpg");
	Mat midImage, dstImage;

	//canny����Եת��Ϊ�Ҷ�ͼ
	Canny(srcImage, midImage, 50, 200, 3);
	cvtColor(midImage, dstImage, CV_GRAY2BGR);

	//���л���任
	std::vector<cv::Vec4i> lines;
	HoughLinesP(midImage, lines,3, CV_PI /180,55, 15,5);

	//һ����ͼ�л��Ƴ�ÿ���߶�
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


	//��Ե���֮���ͼ
	imshow("����Ե�����ͼ��", midImage);
	//��ʾЧ��ͼ
	imshow("��Ч��ͼ��", srcImage);
	waitKey(0);
	return 0;
}