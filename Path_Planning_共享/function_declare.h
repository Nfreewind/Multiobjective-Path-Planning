#ifndef FUNCTION_DECLARE_H
#define FUNCTION_DECLARE_H

#include "include_all.h"

/// Global Variables  
const int NUMBER = 3;//�������
const int radius = 7; //����뾶3.5cm
const int bigball_ball = 2;  //�����������ϵ��, big_ball:ball=bigball_ball
const int car_ball = 3;  //���򳵵ı����� ��������=car_ball
const int window_width = 360;//ͼ��X
const int window_height = 300;//ͼ��Y
#define MIN_SIZE 20
//2017-10-31����
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

/* ģ���Ӿ��ṩ�������������� */
void get_Random_points(vector<cv::Point>& Random_points);
/* ��ȡ�µļ������� */
Mat get_centroid(vector<Point> & Points, vector<Point> & Points_checked);
/*  */
Point each_getCentroid(vector<Point> list);
/* ת��Ϊ�����˼����궯���� */
void movement(vector<cv::Point>& path, vector<double> & rho, vector<double> & theta, vector<double> & angle);


#endif // !FUNCTION_DECLARE_H

