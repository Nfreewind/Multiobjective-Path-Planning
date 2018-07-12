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
	//��ʱ�Ż�
	int64 st1, et1;
	st1 = cvGetTickCount();
	////////////////////////��һ��////////////////////////////////////////
	vector<Point> path1 = Method_of_exhaustion(Points_checked);
	////////////////////////��һ��////////////////////////////////////////
	//ʱ����ʾ
	et1 = cvGetTickCount();
	cout << "times cost:" << (et1 - st1) / (double)cvGetTickFrequency() / 1000.0 << "milliseconds\n\n";
	
	//���߼��
	Mat Method_of_exhaustion_src = src.clone();//���
	line(Method_of_exhaustion_src, Point(0, 0), path1[0], Scalar(255, 0, 0), 1, 8);
	for (int i = 0; i < path1.size() - 1; i++)
	{
		line(Method_of_exhaustion_src, path1[i], path1[i + 1], Scalar(255, 0, 0), 1, 8);
	}
	line(Method_of_exhaustion_src, path1[path1.size() - 1], Point(0, 0), Scalar(255, 0, 0), 1, 8);
	imshow("[3]path1:Method_of_exhaustion", Method_of_exhaustion_src);
#endif
	
#ifdef Method2
	//��ʱ�Ż�
	int64 st2, et2;
	st2 = cvGetTickCount();
	////////////////////////�ڶ���////////////////////////////////////////
	vector<Point> path2 = Greedy_Algorithm(Points_checked);
	////////////////////////�ڶ���////////////////////////////////////////
	//ʱ����ʾ
	et2 = cvGetTickCount();
	cout << "times cost:" << (et2 - st2) / (double)cvGetTickFrequency() / 1000.0 << "milliseconds\n\n";

	//���߼��
	Mat Greedy_Algorithm_src = src.clone();
	line(Greedy_Algorithm_src, Point(0, 0), path2[0], Scalar(0,0,255), 1, 8);
	for (int i = 0; i < path2.size() - 1; i++)
	{
		line(Greedy_Algorithm_src, path2[i], path2[i + 1], Scalar(0,0,255), 1, 8);
	}
	line(Greedy_Algorithm_src, path2[path2.size() - 1], Point(0, 0), Scalar(0,0,255), 1, 8);
	imshow("[4]path2:Greedy_Algorithm", Greedy_Algorithm_src);
#endif

	waitKey(0);
	return 0;
}