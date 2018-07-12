#ifndef FUNCTION_DECLARE_H
#define FUNCTION_DECLARE_H

#include "include_all.h"

/// Global Variables  
const int NUMBER = 3;//随机点数
const int radius = 7; //网球半径3.5cm
const int bigball_ball = 2;  //处理，球的膨胀系数, big_ball:ball=bigball_ball
const int car_ball = 3;  //网球车的比例， 车：网球=car_ball
const int window_width = 360;//图宽X
const int window_height = 300;//图高Y
#define MIN_SIZE 20
//2017-10-31更新
#define Pi 3.1415926

/// Function headers 

//#define Method1
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
/* 转换为机器人极坐标动作组 */
void movement(vector<cv::Point>& path, vector<double> & rho, vector<double> & theta, vector<double> & angle);


#endif // !FUNCTION_DECLARE_H

