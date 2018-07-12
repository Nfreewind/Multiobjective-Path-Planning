#include"function_declare.h"

/// Function definitions  
/**
* @function movement
*/
void movement(vector<cv::Point>& path,  vector<double> & rho, vector<double> & theta, vector<double> & angle)
{
	 //2017-11-01���£�path������ԭ������㣬�������
	 path.insert(path.begin(), Point(0,0));
	 
	 ////��鴫���path
	 //cout << '\n' << "";
	 //for (int i = 0; i <path.size(); i++) {
		// cout << ' ' << path[i];
	 //}
	 //cout << '\n';

	 vector<double> rho_;  //����
	 vector<double> theta_; //���ǻ�����
	 vector<double> angle_; //���ǽǶ���
	 double alpha1, alpha2;//��x��������н�//����
	 
	///���㼫��
	 //2017-11-01���£�path�Ѿ�������ԭ������㣬ȥ�����д���
	 //double rho_0= sqrt((path[0].x - 0)*(path[0].x - 0)
		// + (path[0].y - 0)*(path[0].y - 0));
	 //rho_.push_back(rho_0);
	 for (int i = 1; i < path.size(); i++) {
		 double rho_i = sqrt((path[i].x - path[i - 1].x)*(path[i].x - path[i - 1].x)
					 + (path[i].y - path[i - 1].y)*(path[i].y - path[i - 1].y));
		 rho_.push_back(rho_i);
	 }

	///���㼫��
	 if ( path.size() == 2)
	 {
		 alpha1 = Pi / 2;
		 alpha2 = acos((path[1].x - path[0].x) / rho_[0]);//������
		 if (path[1].y < path[0].y)
		 {
			 alpha2 = - alpha2 + Pi;
		 }
		 else {};
		 double theta_0 = alpha2 - alpha1;
		 theta_.push_back(theta_0);
	 }
	 else {
		 alpha1 = Pi / 2;
		 alpha2 = acos((path[1].x - path[0].x) / rho_[0]);
		 if (path[1].y < path[0].y)
		 {
			 alpha2 = -alpha2 + Pi;
		 }
		 else {};
		 double theta_0 = alpha2 - alpha1;
		 theta_.push_back(theta_0);

		 for (int i = 1; i < path.size()-1; i++)
		 {
			 double alpha_temp = 0;
			 alpha1 = alpha2;
			 alpha2 = acos((path[i+1].x - path[i].x )/ rho_[i]);
			 if (path[i+1].y < path[i].y)
			 {
				 alpha2 = -alpha2 + Pi;
			 }
			 else {};
			 alpha_temp = alpha2 - alpha1;

			 //��ת����ʱ�룩Ϊ��
			 if (alpha_temp > 0 && path[i + 1].y >= path[i].y   &&   path[i].y >= path[i - 1].y)
			 {
				 theta_.push_back(alpha_temp);
			 }
			 else if (alpha_temp > 0 && path[i + 1].y >= path[i].y   &&   path[i].y < path[i - 1].y)
			 {
				 theta_.push_back(-(Pi - alpha_temp));
			 }
			 else if (alpha_temp > 0 && path[i + 1].y < path[i].y   &&   path[i].y >= path[i - 1].y)
			 {
				 theta_.push_back(-(Pi - alpha_temp));
			 }
			 else if (alpha_temp > 0 && path[i + 1].y < path[i].y   &&   path[i].y < path[i - 1].y)
			 {
				 theta_.push_back(alpha_temp);
			 }
			 else if (alpha_temp < 0 && path[i + 1].y >= path[i].y   &&   path[i].y >= path[i - 1].y)
			 {
				 theta_.push_back(-(-alpha_temp));
			 }
			 else if (alpha_temp < 0 && path[i + 1].y >= path[i].y   &&   path[i].y < path[i - 1].y)
			 {
				 theta_.push_back(Pi + alpha_temp);
			 }
			 else if (alpha_temp < 0 && path[i + 1].y < path[i].y   &&   path[i].y >= path[i - 1].y)
			 {
				 theta_.push_back(Pi + alpha_temp);
			 }
			 else if (alpha_temp < 0 && path[i + 1].y < path[i].y   &&   path[i].y < path[i - 1].y)
			 {
				 theta_.push_back(-(-alpha_temp));
			 }
			 else {};
		 }
	 }
	 ///�ƶ�ת��
	 for (int i = 0; i < theta_.size(); i++) 
	 {
		 double theta_i = theta_[i];
		 angle_.push_back(180 * theta_i / Pi);
	 }

	 rho = rho_;
	 theta = theta_;
	 angle = angle_;
	 

	 //��鼫��
	 cout << '\n' << "����";
	 for (int i = 0; i <rho.size(); i++) {
		 cout << ' ' << rho[i];
	 }
	 cout << '\n';
	 //��鼫�ǻ���
	 cout << '\n' << "���ǻ���";
	 for (int i = 0; i <theta.size(); i++) {
		 cout << ' ' << theta[i];
	 }
	 cout << '\n';
	 //��鼫�ǽǶ�
	 cout << '\n' << "���ǽǶ�";
	 for (int i = 0; i <angle.size(); i++) {
		 cout << ' ' << angle[i];
	 }
	 cout << '\n';
}