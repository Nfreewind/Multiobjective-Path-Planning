#include"function_declare.h"
/**
* @function main
*/
int main(int argc, char** argv)
{
	vector<Point>  Points;
	vector<Point>  Points_checked;
	Mat src;
	get_Random_points(Points);  ///��ȡ�����
	src = get_centroid(Points, Points_checked);  ///����,��ȡ����

#ifdef Method1
	int64 st1, et1;
	st1 = cvGetTickCount();
	////////////////////////��һ��////////////////////////////////////////
	vector<Point> path1 = Method_of_exhaustion(Points_checked);
	////////////////////////��һ��////////////////////////////////////////
	et1 = cvGetTickCount();
	cout << "times cost:" << (et1 - st1) / (double)cvGetTickFrequency() / 1000.0 << "milliseconds\n\n";
	
	//2017-10-31����,����ƫ�ã�������������
	//Mat Method_of_exhaustion_src = src.clone();
	//line(Method_of_exhaustion_src, Point(0, 0), path1[0], Scalar(255, 0, 0), 1, 8);
	//for (int i = 0; i < path1.size() - 1; i++)
	//{
	//	line(Method_of_exhaustion_src, path1[i], path1[i + 1], Scalar(255, 0, 0), 1, 8);
	//}
	Mat Method_of_exhaustion_src = src.clone();
	line(Method_of_exhaustion_src, Point(0 + window_width / 2, 0 + 0), Point(path1[0].x + window_width / 2, path1[0].y + 0), Scalar(255, 0, 0), 1, 8);
	for (int i = 0; i < path1.size() - 1; i++)
	{
		line(Method_of_exhaustion_src, Point(path1[i].x + window_width / 2, path1[i].y+0), Point(path1[i+1].x + window_width / 2, path1[i+1].y + 0), Scalar(255, 0, 0), 1, 8);
	}
	//2017-10-30�Ķ�������ԭ�㣬ע���������
	//line(Method_of_exhaustion_src, path1[path1.size() - 1], Point(0, 0), Scalar(255, 0, 0), 1, 8);
	imshow("[3]path1:Method_of_exhaustion", Method_of_exhaustion_src);
#endif
	
#ifdef Method2
	int64 st2, et2;
	st2 = cvGetTickCount();
	////////////////////////�ڶ���////////////////////////////////////////
	vector<Point> path2 = Greedy_Algorithm(Points_checked);
	////////////////////////�ڶ���////////////////////////////////////////
	et2 = cvGetTickCount();
	cout << "times cost:" << (et2 - st2) / (double)cvGetTickFrequency() / 1000.0 << "milliseconds\n\n";

	//2017-10-31����,����ƫ�ã�������������
	//Mat Greedy_Algorithm_src = src.clone();
	//line(Greedy_Algorithm_src, Point(0, 0), path1[0], Scalar(255, 0, 0), 1, 8);
	//for (int i = 0; i < path1.size() - 1; i++)
	//{
	//	line(Greedy_Algorithm_src, path1[i], path1[i + 1], Scalar(255, 0, 0), 1, 8);
	//}
	Mat Greedy_Algorithm_src = src.clone();
	line(Greedy_Algorithm_src, Point(0 + window_width / 2, 0 + 0), Point(path2[0].x + window_width / 2, path2[0].y + 0), Scalar(0, 0, 255), 1, 8);
	for (int i = 0; i < path2.size() - 1; i++)
	{
		line(Greedy_Algorithm_src, Point(path2[i].x + window_width / 2, path2[i].y + 0), Point(path2[i + 1].x + window_width / 2, path2[i + 1].y + 0), Scalar(0, 0, 255), 1, 8);
	}
	//2017-10-30�Ķ�������ԭ��
	//line(Greedy_Algorithm_src, path2[path2.size() - 1], Point(0, 0), Scalar(0,0,255), 1, 8);
	//2017-11-1�Ķ���ͼ����
	cv::flip(Greedy_Algorithm_src, Greedy_Algorithm_src, 0);
	imshow("[4]path2:Greedy_Algorithm", Greedy_Algorithm_src);
#endif
	
	vector<double> rho;  //����
	vector<double> theta; //���ǻ�����
	vector<double> angle; //���ǽǶ���

	// //2017.11.23���
	// /*�߽���*/
	//if (path2.size() > 2 )//3�����3��������
	//{
	//	vector<double> distance;
	//	vector<double> alpha;
	//	for (int i = 0; i < 2; i++)//ȡ3����
	//	{
	//		distance[i] = sqrt((path2[i].x)*(path2[i].x) + (path2[i].y)*(path2[i].y));
	//		alpha[i] = acos((path2[i].x - 0) / distance[i]);	
	//	}
	//	for (int i = 0; i < 2; i++)//ȡ3����
	//	{
	//		distance[i] = sqrt((path2[i].x)*(path2[i].x) + (path2[i].y)*(path2[i].y));
	//		alpha[i] = acos((path2[i].x - 0) / distance[i]);
	//		alpha[i] = 180 * alpha[i] / Pi;  //ת���Ƕ���

	//	}
	//}

	movement(path2, rho, theta, angle);


	waitKey(0);
	return 0;
}