#include"function_declare.h"

/// Function definitions  
/**
* @function initMap
*/
/************************    �� ͼ   ***********************************************/
//��ʼ����ͼ�����꣨begin_x, begin_y��=1 ����ʼ�㣬����(end_x, end_y) = 2;�ǽ����㣬��������ǽ�ڻ����ϰ�  
void initMap(int table[][HEIGHT])
{
	table(begin_x, begin_y) = 1;
	table(end_x, end_y) = 2;
	table(5, 2) = -1;
	table(5, 3) = -1;
	table(5, 4) = -1;
	table(5, 5) = -1;
	table(5, 6) = -1;
	table(5, 7) = -1;

	table(5, 9) = -1;
	table(5, 10) = -1;
	table(5, 11) = -1;
	table(5, 12) = -1;
	table(5, 13) = -1;
	table(5, 14) = -1;
	table(5, 15) = -1;

	table(1, 20) = -1; table(2, 20) = -1; table(3, 20) = -1; table(4, 20) = -1; table(5, 20) = -1; table(6, 20) = -1; table(7, 20) = -1; table(8, 20) = -1;

}
/****************************************************************************************/

/**
* @function initList
*/
//��ʼ���б����еĸ��Ӷ�����  
void initList(struct param list[][HEIGHT])
{
	for (int i = 0; i<WIDTH; i++)
	{
		for (int j = 0; j<HEIGHT; j++)
		{
			//ȫ������  
			list[i][j].state = 1;
			//�����ʼ��  
			list[i][j].dir = -1;
			list[i][j].h = 10 * (abs(i - end_x) + abs(j - end_y));
			list[i][j].g = 0x7ffffff;
		}
	}
	//��ʼ�㵽�Լ��ľ�����0  
	list[begin_x][begin_y].g = 0;

}
/**
* @function search
*/
void search(int table[][HEIGHT], struct param list[][HEIGHT], int i, int j)
{
	int tempi, tempj;
	//��ʼ��minΪ����  
	int min = 0x7ffffff, minIndex;

	list[i][j].state = 0;

	for (int k = 0; k<NEIGHBOUR; k++)
	{
		tempi = i + m[k];
		tempj = j + n[k];
		//����߽����⣬�ϰ����⣬�Լ����б������  
		if (tempi >= 0 && tempi<WIDTH&&tempj >= 0 && tempj<HEIGHT&&table[tempi][tempj] != -1 && list[tempi][tempj].state == 1 && table[i][tempj] != -1 && table[tempi][j] != -1)
		{
			if (table[tempi][tempj] == 2)
			{
				list[i][j].dir = k;
				return;
			}
			else
			{
				/***************************************�����޸�***************************************/
				//�Խ��ϵľ�����1.4��,�ж��Ƿ������Gֵ�½�  
				if (k<4)
				{
					if (list[i][j].g + 10<list[tempi][tempj].g)
						list[tempi][tempj].g = list[i][j].g + 10;
					else
						list[tempi][tempj].state = 0;
				}
				else
				{
					if (list[i][j].g + 14<list[tempi][tempj].g)
						list[tempi][tempj].g = list[i][j].g + 14;

					else
						list[tempi][tempj].state = 0;
				}
				/**************************************************************************************/

				list[tempi][tempj].f = list[tempi][tempj].g + list[tempi][tempj].h;

				if (list[tempi][tempj].f<min)
				{
					min = list[tempi][tempj].f;
					minIndex = k;
				}
			}
		}
	}
	list[i][j].dir = minIndex;
	search(table, list, i + m[minIndex], j + n[minIndex]);
}
/**
* @function display
*/
//���������ݵ���Ļ  
//void display(struct param list[][HEIGHT], int i, int j)
//{
//	int tempi, tempj;
//	if (list[i][j].dir<0)
//		return;
//	tempi = i + m[list[i][j].dir];
//	tempj = j + n[list[i][j].dir];
//	cout << tempi + 1 << "," << tempj + 1 << endl;
//	display(list, tempi, tempj);
//}
/**
* @function display
*/
//�����Ǹ��ݹ麯������⿪���������������ȡ·�����ݵ����Path
void display2path(struct param list[][HEIGHT], int i, int j, vector<Point>&path)
{
	while (list[i][j].dir + 1 > 0)
	{	

		int tempi, tempj;
		tempi = i + m[list[i][j].dir];
		tempj = j + n[list[i][j].dir];
		path.push_back(Point(tempi + 1, tempj + 1));
		i = tempi;
		j = tempj;
	}
}

/**
* @function A_star
*/
vector<Point> A_star(int table[][HEIGHT], struct param list[][HEIGHT])
{
	vector<Point> path;
	initMap(table);
	initList(list);
	search(table, list, begin_x, begin_y);
	//display(list, begin_x, begin_y);
	display2path(list, begin_x, begin_y, path);

	return path;
}
