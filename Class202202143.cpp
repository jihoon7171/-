#include<iostream>
#include<cstring>
using namespace std;
#pragma warning(disable:4996)


class matrixXD
{
private:

	double  ** b;
	int aa, bbb;
	char * name;

public:
	matrixXD(int c, int d) 
		// 덧셈,뺄셈을 저장하는 행렬 생성시 실행되는 생성자
	{
		b = new double* [c];
		for (int i = 0; i < c; i++) {
			b[i] = new double[d];
		}
	}
	matrixXD(int a, int bb,char *matrixname) 
		//행렬 A,B를 생성할때 실행되는 생성자
	{
		aa = a;
		bbb = bb;
		int len = strlen(matrixname)+1;
		name = new char[len];
		strcpy(name, matrixname);
		b = new double* [a];
		for (int i = 0; i < a; i++) {
			b[i] = new double[bb];
		}



		for (int i = 0; i < a; i++) {
			for (int j = 0; j < bb; j++) {
				cout << name << "(" << i << "," << j << ")" << "=";
				int x;
				cin >> x;
				b[i][j] = x;
			}
		}
	}
	matrixXD operator+ (const matrixXD& rhs)
	//연산자 오버로딩을 통한 덧셈 함수
	{
		char resultp[] = "result";
		matrixXD result(aa, bbb);
		for (int i = 0; i < aa; i++) {
			for (int j = 0; j < bbb; j++) {
				result.b[i][j] = this->b[i][j] + rhs.b[i][j];

			}
		}
		return result;
	
	}

	matrixXD operator- (const matrixXD& rhs) 
	//연산자 오버로딩을 통한 뺄셈 함수
	{
		char resultm[] = "resultm";
		matrixXD resultmi(aa, bbb);
		for (int i = 0; i < aa; i++) {
			for (int j = 0; j < bbb; j++) {
				resultmi.b[i][j] = this->b[i][j] - rhs.b[i][j];

			}
		}
		return resultmi;

	}
	double getmatrix(int i, int j) 
	//행렬를을 불러오기위한 함수
	{

		return  b[i][j];
	}
	~matrixXD()
		//소멸자 함수
	{
		for (int i = 0; i < aa; i++) {

			delete[] b[i];
		}
		delete[] b;

	}


};

int main() {
	int a, b;
	cout << "행의 크기를 입력하세요 :";
	cin >> a;
	cout << "열의 크기를 입력하세요 : ";
	cin >> b;
	cout << "첫 번째 행렬 A를 입력하세요. \n";
	char matrixnameA[] = "A";
	matrixXD A(a,b,matrixnameA);
	cout << "첫 번째 행렬 B를 입력하세요. \n";
	char matrixnameB[] = "B";
	matrixXD B(a, b, matrixnameB);
	matrixXD sum = A + B;
	matrixXD dif = A - B;
	cout << "A+B =  \n";
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout<<sum.getmatrix(i,j)<<" ";
		}
		cout << "\n";
	}
	cout << "\n";
	cout << "A-B =  \n";
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout << dif.getmatrix(i, j)<<" ";
		}
		cout << "\n";
	}
}