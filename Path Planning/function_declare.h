#ifndef FUNCTION_DECLARE_H
#define FUNCTION_DECLARE_H

#include "include_all.h"

/// Global Variables  
const int NUMBER = 10;//����
const int radius = 7; //����뾶3.5cm
const int k = 2.1;  //��̬ѧ�����������ϵ����0.1Ϊ����
const int kk = 3;  //���򳵵ı�������������=K
const int window_width = 360;//ͼ��
const int window_height = 300;//ͼ��
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

/* ģ���Ӿ��ṩ�������������� */
void get_Random_points(vector<cv::Point>& Random_points);
/* ��ȡ�µļ������� */
Mat get_centroid(vector<Point> & Points, vector<Point> & Points_checked);
/*  */
Point each_getCentroid(vector<Point> list);


#endif // !FUNCTION_DECLARE_H

