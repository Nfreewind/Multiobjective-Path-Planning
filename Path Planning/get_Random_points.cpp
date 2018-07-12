#include"function_declare.h"

/// Function definitions  
/**
* @function get_Random_points
*/
void get_Random_points(vector<cv::Point>& Random_points)
{
	/// create a random object (RNG)
	RNG rng;
	rng = RNG(getTickCount());   //ʹ��ϵͳʱ�Ӳ�����ͬ������,������ע�͵������ȷ���������
	Point point = Point(0, 0);
	int x_min = radius;
	int x_max = window_width - radius;
	int y_min = radius;
	int y_max = window_height - radius;

	for (int i = 0; i < NUMBER; i++)
	{
		Point center;
		center.x = rng.uniform(x_min, x_max); //rng��uniform���������޶�������ķ�Χ
		center.y = rng.uniform(y_min, y_max);
		Random_points.push_back(center);
	}
}