#include<iostream>
using namespace std;


void  make(double**& as, int a, int b)  // 2차원행렬 만드는 함수
{  
	as = new double* [a];
	for (int i = 0; i < a; i++) {
		as[i] = new double[b];
	}

}

void plusa(double**& pl, double**& a, double**& b, int q, int w) 
// 더하기 위해 만든 두개의 행렬 새로운 행렬, 행,열 을 인수로 받아 새로운 행렬에 
//두 행렬의 합을 대입해주는 함수
{

	for (int i = 0; i < q; i++) {
		for (int e = 0; e < w; e++) {
			pl[i][e] = a[i][e] + b[i][e];

		}
	}
}

void minusa(double**& pl, double**& a, double**& b, int q, int w)
// 빼기 위해 만든 두개의 행렬 새로운 행렬, 행,열 을 인수로 받아 새로운 행렬에 
//두 행렬의 차를 대입해주는 함수
{

	for (int i = 0; i < q; i++) {
		for (int e = 0; e < w; e++) {
			pl[i][e] = a[i][e] - b[i][e];

		}
	}
}

void deletall(double**& arr, int i) 
//소멸시켜주기위해 만든 함수
{
	for (int n = 0; n < i; n++) {
		delete[] arr[i];
	}
	delete[] arr;
}


int main() {
	int a = 0, b = 0;
	cout << "행의 크기를 입력하세요:";
	cin >> a;
	cout << "열의 크기를 입력하세요 : ";
	cin >> b;

	double** arra;
	cout << "첫번째 행렬 A를 입력하세요." << "\n";
	make(arra, a, b); // 행렬 arra 생성

	for (int i = 0; i < a; i++) {
		for (int e = 0; e < b; e++) {
			int x;
			cout << "A" << "(" << i << "," << e << ")" << "=";
			cin >> x;
			arra[i][e] = x;
			cout << "\n";
		}
	} // 행렬 arra 대입

	double** arrb;
	cout << "두 번째 행렬 b를 입력하세요." << "\n";
	make(arrb, a, b); // 행렬 arrb 생성

	for (int i = 0; i < a; i++) {
		for (int e = 0; e < b; e++) {
			int x;
			cout << "b" << "(" << i << "," << e << ")" << "=";
			cin >> x;
			arrb[i][e] = x;
			cout << "\n";
		}
	} //행렬 arrb 대입
	double** plus;
	make(plus, a, b); // 두 행렬의 합이 들어갈 새로운 행렬 생성

	double** minus;
	make(minus, a, b); // 두 행렬의 차가 들어갈 새로운 행렬 생성


	plusa(plus, arra, arrb, a, b);
	cout << "A+B = " << "\n";
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout << plus[i][j] << " ";
		}
		cout << "\n";
	} // 두 행렬의 합을 구해줘서 제3의 행렬에 대입해주는 함수 실행

	cout << "\n";

	cout << "A-B = " << "\n";
	minusa(minus, arra, arrb, a, b);
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout << minus[i][j] << " ";
		}
		cout << "\n";
	}// 두 행렬의 차를 구해줘서 제3의 행렬에 대입해주는 함수 실행


	deletall(arra, a);
	deletall(arrb, a);
	deletall(minus, a);
	deletall(plus, a);
	// 할당해제 함수 실행
}


