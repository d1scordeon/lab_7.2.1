// Lab_7_2_1.cpp
// Бахмат Катерина
// Лабораторна робота № 7.2.1
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 1
// інтераційний спосіб 

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void transp(int** a, const int n, int& tmp);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -17;
	int High = 14;
	int n;

	cout << "n = "; cin >> n;
	int** a = new int* [n];

	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
	}

	Create(a, n, Low, High);
	Print(a, n);


	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
		delete[] a;
	}
	return 0;
}
void Create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			a[i][j] = Low + rand() % (High - Low + 1);
		}
	}
}
void Print(int** a, const int n)
{
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(4) << a[j][i];
		}
		cout << endl;
	}
	cout << endl;
}

void transp(int** a, int row, int col) {
	int tmp;
	int u = 0;

	for (int j = 0; j < row; j++) {
		for (int i = u; i < col; i++) {
			tmp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = tmp;
		}
		u++;
	}
}