#include<iostream>
using namespace std;


void  make(double**& as, int a, int b)  // 2������� ����� �Լ�
{  
	as = new double* [a];
	for (int i = 0; i < a; i++) {
		as[i] = new double[b];
	}

}

void plusa(double**& pl, double**& a, double**& b, int q, int w) 
// ���ϱ� ���� ���� �ΰ��� ��� ���ο� ���, ��,�� �� �μ��� �޾� ���ο� ��Ŀ� 
//�� ����� ���� �������ִ� �Լ�
{

	for (int i = 0; i < q; i++) {
		for (int e = 0; e < w; e++) {
			pl[i][e] = a[i][e] + b[i][e];

		}
	}
}

void minusa(double**& pl, double**& a, double**& b, int q, int w)
// ���� ���� ���� �ΰ��� ��� ���ο� ���, ��,�� �� �μ��� �޾� ���ο� ��Ŀ� 
//�� ����� ���� �������ִ� �Լ�
{

	for (int i = 0; i < q; i++) {
		for (int e = 0; e < w; e++) {
			pl[i][e] = a[i][e] - b[i][e];

		}
	}
}

void deletall(double**& arr, int i) 
//�Ҹ�����ֱ����� ���� �Լ�
{
	for (int n = 0; n < i; n++) {
		delete[] arr[i];
	}
	delete[] arr;
}


int main() {
	int a = 0, b = 0;
	cout << "���� ũ�⸦ �Է��ϼ���:";
	cin >> a;
	cout << "���� ũ�⸦ �Է��ϼ��� : ";
	cin >> b;

	double** arra;
	cout << "ù��° ��� A�� �Է��ϼ���." << "\n";
	make(arra, a, b); // ��� arra ����

	for (int i = 0; i < a; i++) {
		for (int e = 0; e < b; e++) {
			int x;
			cout << "A" << "(" << i << "," << e << ")" << "=";
			cin >> x;
			arra[i][e] = x;
			cout << "\n";
		}
	} // ��� arra ����

	double** arrb;
	cout << "�� ��° ��� b�� �Է��ϼ���." << "\n";
	make(arrb, a, b); // ��� arrb ����

	for (int i = 0; i < a; i++) {
		for (int e = 0; e < b; e++) {
			int x;
			cout << "b" << "(" << i << "," << e << ")" << "=";
			cin >> x;
			arrb[i][e] = x;
			cout << "\n";
		}
	} //��� arrb ����
	double** plus;
	make(plus, a, b); // �� ����� ���� �� ���ο� ��� ����

	double** minus;
	make(minus, a, b); // �� ����� ���� �� ���ο� ��� ����


	plusa(plus, arra, arrb, a, b);
	cout << "A+B = " << "\n";
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout << plus[i][j] << " ";
		}
		cout << "\n";
	} // �� ����� ���� �����༭ ��3�� ��Ŀ� �������ִ� �Լ� ����

	cout << "\n";

	cout << "A-B = " << "\n";
	minusa(minus, arra, arrb, a, b);
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cout << minus[i][j] << " ";
		}
		cout << "\n";
	}// �� ����� ���� �����༭ ��3�� ��Ŀ� �������ִ� �Լ� ����


	deletall(arra, a);
	deletall(arrb, a);
	deletall(minus, a);
	deletall(plus, a);
	// �Ҵ����� �Լ� ����
}


