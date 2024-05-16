#include<iostream>
#include <Eigen/Dense>


using namespace std;
using namespace Eigen;


int main() {
	cout << "���� ũ�⸦ �Է��ϼ��� :";
	int c,e;
	cin >> c ;
	cout << "���� ũ�⸦ �Է��ϼ��� :";
	cin >> e;
	MatrixXd A(c, e);

	cout << "ù ��° ��� A�� �Է��ϼ���." << "\n";
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < e; j++) {
			double f;
			cout << "A" << "(" << i << "," << j << ")" << "=" << " ";
			cin >> f;
			A(i, j) = f;
		}
	}

	MatrixXd B(c, e);

	cout << "ù ��° ��� B�� �Է��ϼ���." << "\n";
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < e; j++) {
			double f;
			cout << "B" << "(" << i << "," << j << ")" << "=" << " ";
			cin >> f;
			B(i, j) = f;
		}
	}

	cout << "A+B = " << "\n";
	cout << A + B;
	cout << "\n";
	cout << "A-B = " << "\n";
	cout << A - B;
}
