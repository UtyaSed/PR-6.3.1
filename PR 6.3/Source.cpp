// PR 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів
// Варіант 7
// ітераційний спосіб окремої функції
// Обухова Віктора

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
	int min;               // мінімальний елемент
	int imin = -1;         // індекс мінімального елемента
	for (I i = 0; i < size; i++)
		if (a[i] % 2 == 1)
		{
			min = a[i];    // перший елемент, що
			imin = i;      // задовольняє умові –
			break;         // вважаємо мінімальним
		}
	if (imin == -1)
	{
		cerr << "немає елементів, які задовольняють умові" << endl;
		return 0; 
	} 

	for (I i = imin + 1; i < size; i++)
		if (a[i] < min && a[i] % 2 == 1)
			min = a[i];
	return min;
}

int main()
{
	srand((unsigned)time(NULL));       // ініціалізація генератора випадкових чисел
	const int n = 10;
	int a[n];
	int Low = 12;
	int High = 70;
	Create(a, n, Low, High);
	Print(a, n);
	cout << "min = " << Min(a, n) << endl;
	return 0;
}