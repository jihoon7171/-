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
		// ����,������ �����ϴ� ��� ������ ����Ǵ� ������
	{
		b = new double* [c];
		for (int i = 0; i < c; i++) {
			b[i] = new double[d];
		}
	}
	matrixXD(int a, int bb,char *matrixname) 
		//��� A,B�� �����Ҷ� ����Ǵ� ������
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
	//������ �����ε��� ���� ���� �Լ�
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
	//������ �����ε��� ���� ���� �Լ�
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
	//��ĸ��� �ҷ��������� �Լ�
	{

		return  b[i][j];
	}
	~matrixXD()
		//�Ҹ��� �Լ�
	{
		for (int i = 0; i < aa; i++) {

			delete[] b[i];
		}
		delete[] b;

	}


};

int main() {
	int a, b;
	cout << "���� ũ�⸦ �Է��ϼ��� :";
	cin >> a;
	cout << "���� ũ�⸦ �Է��ϼ��� : ";
	cin >> b;
	cout << "ù ��° ��� A�� �Է��ϼ���. \n";
	char matrixnameA[] = "A";
	matrixXD A(a,b,matrixnameA);
	cout << "ù ��° ��� B�� �Է��ϼ���. \n";
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