#include"function_declare.h"

/// Function definitions  
/**
* @function Greedy_Algorithm
*/
vector<Point> Greedy_Algorithm( vector<Point>&center_points )
{
	vector<Point> path2;

	//检查传入的中心点数和坐标
	for (int i = 0; i <center_points.size(); i++) {
		cout << center_points[i] << ' ';
	}
	cout << '\n';


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////建立权重矩阵表,,,,,二维动态数组
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//求空间，用完记得释放！
	int row = center_points.size() + 1, column = center_points.size() + 1;
	double **distances = new double*[row];
	for (int i = 0; i < row; ++i) {
		distances[i] = new double[column];
	}
	//全部初始化为0
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			distances[i][j] = 0;
		}
	}
	//计算第一行
	distances[0][0] = 0;  //角点
	for (int j = 1; j < center_points.size() + 1; j++) {
		distances[0][j] =
			sqrt((center_points[j - 1].x - 0)*(center_points[j - 1].x - 0)
				+ (center_points[j - 1].y - 0)*(center_points[j - 1].y - 0));
	}
	//计算第一列  //对称矩阵
	for (int i = 1; i < center_points.size() + 1; i++) {
		distances[i][0] = distances[0][i];
	}
	//计算其他
	for (int i = 1; i < center_points.size() + 1; i++) {
		for (int j = 1; j < center_points.size() + 1; j++) {
			distances[i][j] =
				sqrt((center_points[i - 1].x - center_points[j - 1].x)*(center_points[i - 1].x - center_points[j - 1].x)
					+ (center_points[i - 1].y - center_points[j - 1].y)*(center_points[i - 1].y - center_points[j - 1].y));
		}
	}

	////检查    权重矩阵表
	//for (int j = 0; j < center_points.size() + 1; j++) {
	//	for (int i = 0; i < center_points.size() + 1; i++) {
	//		cout << distances[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	//建立自由向量,,,,,一维动态数组//用于存储已访问过的城市
	//求空间，用完记得释放！
	int list_size = center_points.size() + 1;
	int *list = new int[list_size];
	//初始化
	for (int i = 0; i < list_size; i++) {
		list[i] = i;
	}

	int n = center_points.size() + 1;
	int i, j, k, l;
	double distances_min = 0;   //用于记算已访问过的城市的最小路径长度
	double Dtemp;               //保证Dtemp比任意两个城市之间的距离都大（其实在算法描述中更准确的应为无穷大）
	int flag;                   //最为访问的标志，若被访问过则为1，从未被访问过则为0
	i = 1;                      //i是至今已访问过的城市
	list[0] = 0;

	do {
		k = 1; Dtemp = 1000000000;
		do {
			l = 0; flag = 0;
			do {
				if (list[l] == k) {//判断该城市是否已被访问过，若被访问过，
					flag = 1;//则flag为1
					break;//跳出循环，不参与距离的比较
				}
				else
					l++;
			} while (l < i);
			if (flag == 0 && distances[k][list[i - 1]] < Dtemp) {/*D[k][S[i - 1]]表示当前未被访问的城市k与上一个已访问过的城市i-1之间的距离*/
				j = k;//j用于存储已访问过的城市k
				Dtemp = distances [ k ] [list[i - 1] ];//Dtemp用于暂时存储当前最小路径的值
			}
			k++;
		} while (k < n);
		list[i] = j;//将已访问过的城市j存入到S[i]中
		i++;
		distances_min += Dtemp;//求出各城市之间的最短距离，注意：在结束循环时，该旅行商尚未回到原出发的城市
	} while (i < n);
	distances_min += distances [0][j];//D[0][j]为旅行商所在的最后一个城市与原出发的城市之间的距离
	//传递给path
	for (i = 1; i < n; i++) {
		path2.push_back( center_points[list[i] - 1 ] );
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	////检查...输出经过的代号的路径//list里面最前面的0是无效路径
	//for (j = 0; j < n; j++) {
	//	cout << list[j] << " ";
	//}

	//检查传出的最优解坐标
	cout << '\n' << "最优路径";
	for (int i = 0; i <path2.size(); i++) {
		cout << ' ' << path2[i];
	}
	cout << '\n';

	//路径输出
	cout << "最短路径长度" << distances_min << '\n';


	//waitKey();
	//释放动态数组
	delete[]list;
	return path2;
}