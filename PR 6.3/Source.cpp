// PR 6.3
// ����������� ����������� ������ �� ��������� ��������� ������� �� �������
// ������ 7
// ����������� ����� ������ �������
// ������� ³�����

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
template <typename I>

void Create(I* a, const I size, const I Low, const I High)
{
	for (I i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}

template <typename I>
void Print(I* a, const I size)
{
	for (I i = 0; i < size; i++)
		cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
	cout << endl;
}

template <typename I>
int Min(I* a, const I size)
{
	int min;               // ��������� �������
	int imin = -1;         // ������ ���������� ��������
	for (I i = 0; i < size; i++)
		if (a[i] % 2 == 1)
		{
			min = a[i];    // ������ �������, ��
			imin = i;      // ����������� ���� �
			break;         // ������� ���������
		}
	if (imin == -1)
	{
		cerr << "���� ��������, �� ������������� ����" << endl;
		return 0; 
	} 

	for (I i = imin + 1; i < size; i++)
		if (a[i] < min && a[i] % 2 == 1)
			min = a[i];
	return min;
}

int main()
{
	srand((unsigned)time(NULL));       // ����������� ���������� ���������� �����
	const int n = 10;
	int a[n];
	int Low = 12;
	int High = 70;
	Create(a, n, Low, High);
	Print(a, n);
	cout << "min = " << Min(a, n) << endl;
	return 0;
}