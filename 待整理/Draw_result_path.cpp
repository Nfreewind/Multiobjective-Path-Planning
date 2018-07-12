#include"function_declare.h"

/// Function definitions  
/**
* @function Draw_result_path
*/
//�ڶ˿���ͼ�λ���ʾ���Ƚϲڵ�����
void show_result_path(int table[][HEIGHT], struct param list[][HEIGHT])
{
	int i, j;
	for (j = HEIGHT - 1; j >= 0; j--)
	{
		for (i = 0; i<WIDTH; i++)
		{
			if (i == begin_x && j == begin_y)
				cout << "��";
			else if (i == end_x && j == end_y)
				cout << "��";
			else if (table[i][j] == -1)
				cout << "* ";
			else if (list[i][j].dir >= 0)
				cout << "+ ";
			else cout << "- ";
		}
		cout << endl;
	}
}


void Draw_result_path(int table[][HEIGHT], struct param list[][HEIGHT],vector<Point>&path)
{
	//���path������
	for (int i = 0; i <path.size(); i++) {
		cout << path[i] << ' ';
	}
	cout << '\n';

	Mat img(WIDTH*ratio, HEIGHT*ratio, CV_8UC3, Scalar(255,255,255));//caitu

	Point center;

	int radius = ratio/2;
	int lineType = 8;

	int i, j;
	for (j = HEIGHT - 1; j >= 0; j--)
	{
		for (i = 0; i < WIDTH; i++)
		{
			if (i == begin_x && j == begin_y)//���
			{
				center.x = i * ratio;
				center.y = j * ratio;
				circle(img, center, radius, Scalar(0, 233, 0), -1, lineType);
			}
			else if (i == end_x && j == end_y)//�յ�
			{
				center.x = i * ratio;
				center.y = j * ratio;
				circle(img, center, radius, Scalar(255, 97, 0), -1, lineType);
			}
			else if (table[i][j] == -1)//�ϰ���
			{
				// Rectangle���������� ͼƬ�� ���Ͻǣ� ���½ǣ� ��ɫ�� ������ϸ�� �������ͣ�������  
				center.x = i*ratio - ratio / 2;
				center.y = j*ratio - ratio / 2;
				rectangle(img, center, Point(center.x + ratio, center.y + ratio), Scalar(0, 0, 0), 3, 4, 0);
			}
			else if (list[i][j].dir >= 0)//·����ʶ
			{
				//center.x = i*ratio - ratio / 4;
				//center.y = j*ratio - ratio / 4;
				//rectangle(img, center, Point(center.x + ratio / 2, center.y + ratio / 2), Scalar(127, 255, 121), 3, 4, 0);
			
				//..��������ʽ��ѡһ
				//center.x = i*ratio;
				//center.y = j*ratio;
				//circle(img, center, ratio / 4 , Scalar(127, 255, 121), -1, lineType);
			}
			else
			{
			}
		}
		cout << endl;
	}
	imshow("Path Planing", img);

	for (i = 0; i < path.size(); i++)//·����ʶ
	{
		waitKey(500);
		//center.x = (path[i].x-1)*ratio - ratio / 4;
		//center.y = (path[i].y-1)*ratio - ratio / 4;
		//rectangle(img, center, Point(center.x + ratio / 2, center.y + ratio / 2), Scalar(127, 255, 121), 3, 4, 0);
		center.x = (path[i].x - 1)*ratio;
		center.y = (path[i].y - 1)*ratio;
		circle(img, center, ratio / 4, Scalar(127, 255, 121), -1, lineType);
		imshow("Path Planing", img);
	}

}