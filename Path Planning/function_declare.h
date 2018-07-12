#ifndef FUNCTION_DECLARE_H
#define FUNCTION_DECLARE_H

#include "include_all.h"

/// Global Variables  
const int NUMBER = 10;//点数
const int radius = 7; //网球半径3.5cm
const int k = 2.1;  //形态学处理，球的膨胀系数，0.1为补偿
const int kk = 3;  //网球车的比例，车：网球=K
const int window_width = 360;//图宽
const int window_height = 300;//图高
#define MIN_SIZE 20

/// Function headers 

#define Method1
#ifdef Method1
vector<Point> Method_of_exhaustion(vector<Point>&center_points);
#endif

#define Method2
#ifdef Method2
vector<Point> Greedy_Algorithm(vector<Point>&center_points);
#endif

/* 模拟视觉提供的网球物理坐标 */
void get_Random_points(vector<cv::Point>& Random_points);
/* 获取新的几何形心 */
Mat get_centroid(vector<Point> & Points, vector<Point> & Points_checked);
/*  */
Point each_getCentroid(vector<Point> list);


#endif // !FUNCTION_DECLARE_H

