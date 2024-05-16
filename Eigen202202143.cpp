#include<iostream>
#include <Eigen/Dense>


using namespace std;
using namespace Eigen;


int main() {
	cout << "행의 크기를 입력하세오 :";
	int c,e;
	cin >> c ;
	cout << "열의 크기를 입력하세요 :";
	cin >> e;
	MatrixXd A(c, e);

	cout << "첫 번째 행렬 A를 입력하세요." << "\n";
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < e; j++) {
			double f;
			cout << "A" << "(" << i << "," << j << ")" << "=" << " ";
			cin >> f;
			A(i, j) = f;
		}
	}

	MatrixXd B(c, e);

	cout << "첫 번째 행렬 B를 입력하세요." << "\n";
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
