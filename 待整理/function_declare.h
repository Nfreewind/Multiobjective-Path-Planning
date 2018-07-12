#pragma once  
#ifndef FUNCTION_DECLARE_H
#define FUNCTION_DECLARE_H

#include "include_all.h"

/// Global Variables
#define WIDTH 30
#define HEIGHT 30

#define ratio 20

#define begin_x 3
#define begin_y 3
#define end_x 8
#define end_y 6

#define NEIGHBOUR 8  //�����˷�λ
const int m[NEIGHBOUR] = { -1,1,0,0,-1,-1,1,1 };
const int n[NEIGHBOUR] = { 0,0,-1,1,-1,1,-1,1 };
#define table(i,j) *(*(table+i)+j)  

//����ÿ�����ӵĲ����б�  
struct param
{
	int f;
	int g;
	int h;
	int dir;//��¼����  
	bool state;//��¼״̬�����б�ͱ��б�  
};

/// Function headers 
/**/
void Draw_result_path(int table[][HEIGHT], struct param list[][HEIGHT],vector<Point>&path);
/**/
void show_result_path(int table[][HEIGHT], struct param list[][HEIGHT]);
/**/
vector<Point> A_star(int table[][HEIGHT], struct param list[][HEIGHT]);
/**/

#endif // !FUNCTION_DECLARE_H