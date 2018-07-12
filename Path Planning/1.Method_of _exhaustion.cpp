#include"function_declare.h"

/// Function definitions  
/**
* @function Method_of_exhaustion
*/
vector<Point> Method_of_exhaustion(vector<Point>&center_points)
{
	vector<Point> path1;

	//��鴫������ĵ���������
	for (int i = 0; i <center_points.size(); i++) {
		cout << center_points[i] << ' ';
	}
	cout << '\n';


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////����Ȩ�ؾ����,,,,,��ά��̬����
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//��ռ䣬����ǵ��ͷţ�
	int row = center_points.size() + 1, column = center_points.size() + 1;
	double **distances = new double*[row];
	for (int i = 0; i < row; ++i){
		distances[i] = new double[column];
	}
	//ȫ����ʼ��Ϊ0
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			distances[i][j] = 0;
		}
	}
	//�����һ��
	distances[0][0] = 0;  //�ǵ�
	for (int j = 1; j < center_points.size()+1; j++) {
		distances[0][j] =
			sqrt((center_points[j-1].x - 0)*(center_points[j-1].x - 0)
				+ (center_points[j-1].y - 0)*(center_points[j-1].y - 0));
	}
	//�����һ��  //�Գƾ���
	for (int i = 1; i < center_points.size()+1; i++) {
			distances[i][0] = distances[0][i];
	}
	//��������
	for (int i = 1; i < center_points.size()+1; i++) {
		for (int j = 1; j < center_points.size() + 1; j++) {
			distances[i][j] =
				sqrt((center_points[i-1].x - center_points[j-1].x)*(center_points[i-1].x - center_points[j-1].x)
					+ (center_points[i-1].y - center_points[j-1].y)*(center_points[i-1].y - center_points[j-1].y));
		}
	}
	////���Ȩ�ؾ����
	//for (int i = 0; i < center_points.size() + 1; i++) {
	//	for (int j = 0; j < center_points.size() + 1; j++) {
	//		cout << distances[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//������������list,,,,,һά��̬����
	//��ռ䣬����ǵ��ͷţ�
	int list_size = center_points.size();
	int *list=new int[list_size];
	//��ʼ��
	for (int i = 0; i < list_size; i++) {
		list[i] = i;
	}
	
	double distances_min;
	double distances_i = 0;

	//��һ����ʼֵ��Ϊdistances_min
	for (int i = 0; i < list_size - 1; i++) {
		distances_i = distances_i + distances[list[i] + 1 ][list[i + 1] + 1 ];
	}
	//����ԭ����Ϊ����յ�
	distances_min = distances_i + distances[0][list[0] + 1] + distances[list[list_size - 1] + 1 ][0];





	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////�������
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	cout << "permutation... " << '\n';
	vector<vector<int>> list_all;//ȫ���еĶ�ά���� �����
	vector<int> list_i;//���е�ĳһ��
	sort(list, list + list_size);
	do {
		list_i.clear();
		distances_i = 0;
		for (int i = 0; i < list_size; i++) {
				list_i.push_back(list[i]);   //�������е�ĳһ��
			}
		list_all.push_back(list_i);		//����ȫ���еĶ�ά���� �����

		//�����//���Ӻ�
		for (int i = 0; i < list_size - 1; i++) {
			distances_i = distances_i + distances[list_i[i] + 1][list_i[i + 1] + 1];
		}
		distances_i = distances_i + distances[0][list_i[0] + 1] + distances[list_i[list_size - 1] + 1][0];
		//�жϾ����Ƿ�Ƚ�С�����·��
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


	////���ȫ����
	//int row_list_all = list_all.size(), col_list_all = list_all[0].size();
	//for (int i = 0; i < row_list_all; i++) {
	//	for (int j = 0; j < col_list_all; j++) {
	//		cout << list_all[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	//��鴫�������Ž�����
	cout << '\n' << "����·��";
	for (int i = 0; i <path1.size(); i++) {
		cout << ' '<< path1[i];
	}
	cout << '\n';

	//·�����
	cout <<"���·������"<< distances_min << '\n';




	//waitKey();
	//�ͷŶ�̬����
	delete[]list;

	for (int i = 0; i < row; ++i) {
		delete[]distances[i];
	}
	delete[]distances;

	return path1;
}