#include"function_declare.h"

/// Function definitions  
/**
* @function Method_of_exhaustion
*/
vector<Point> Method_of_exhaustion(vector<Point>&center_points)
{
	vector<Point> path1;

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
	for (int i = 0; i < row; ++i){
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
	for (int j = 1; j < center_points.size()+1; j++) {
		distances[0][j] =
			sqrt((center_points[j-1].x - 0)*(center_points[j-1].x - 0)
				+ (center_points[j-1].y - 0)*(center_points[j-1].y - 0));
	}
	//计算第一列  //对称矩阵
	for (int i = 1; i < center_points.size()+1; i++) {
			distances[i][0] = distances[0][i];
	}
	//计算其他
	for (int i = 1; i < center_points.size()+1; i++) {
		for (int j = 1; j < center_points.size() + 1; j++) {
			distances[i][j] =
				sqrt((center_points[i-1].x - center_points[j-1].x)*(center_points[i-1].x - center_points[j-1].x)
					+ (center_points[i-1].y - center_points[j-1].y)*(center_points[i-1].y - center_points[j-1].y));
		}
	}
	////检查权重矩阵表
	//for (int i = 0; i < center_points.size() + 1; i++) {
	//	for (int j = 0; j < center_points.size() + 1; j++) {
	//		cout << distances[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//建立自由向量list,,,,,一维动态数组
	//求空间，用完记得释放！
	int list_size = center_points.size();
	int *list=new int[list_size];
	//初始化
	for (int i = 0; i < list_size; i++) {
		list[i] = i;
	}
	
	double distances_min;
	double distances_i = 0;

	//算一个初始值作为distances_min
	for (int i = 0; i < list_size - 1; i++) {
		distances_i = distances_i + distances[list[i] + 1 ][list[i + 1] + 1 ];
	}
	//加入原点作为起点终点
	distances_min = distances_i + distances[0][list[0] + 1] + distances[list[list_size - 1] + 1 ][0];





	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////进行穷举
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	cout << "permutation... " << '\n';
	vector<vector<int>> list_all;//全排列的二维数组 矩阵表
	vector<int> list_i;//排列的某一组
	sort(list, list + list_size);
	do {
		list_i.clear();
		distances_i = 0;
		for (int i = 0; i < list_size; i++) {
				list_i.push_back(list[i]);   //送入排列的某一组
			}
		list_all.push_back(list_i);		//送入全排列的二维数组 矩阵表

		//求距离//查表加和
		for (int i = 0; i < list_size - 1; i++) {
			distances_i = distances_i + distances[list_i[i] + 1][list_i[i + 1] + 1];
		}
		distances_i = distances_i + distances[0][list_i[0] + 1] + distances[list_i[list_size - 1] + 1][0];
		//判断距离是否比较小，输出路径
		if ( distances_i <= distances_min) {
			distances_min = distances_i;
			path1.clear();
			for (int i = 0; i < center_points.size(); i++) {
					path1.push_back(center_points[list[i]]);
			}
		}
	} 
	while (next_permutation(list, list + list_size));





	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	////检查全排列
	//int row_list_all = list_all.size(), col_list_all = list_all[0].size();
	//for (int i = 0; i < row_list_all; i++) {
	//	for (int j = 0; j < col_list_all; j++) {
	//		cout << list_all[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	//检查传出的最优解坐标
	cout << '\n' << "最优路径";
	for (int i = 0; i <path1.size(); i++) {
		cout << ' '<< path1[i];
	}
	cout << '\n';

	//路径输出
	cout <<"最短路径长度"<< distances_min << '\n';




	//waitKey();
	//释放动态数组
	delete[]list;

	for (int i = 0; i < row; ++i) {
		delete[]distances[i];
	}
	delete[]distances;

	return path1;
}