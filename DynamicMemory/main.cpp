#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	//			new
	int n = 5;
	cout << "Размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	//Создаём буфферный массив нужного размера:
	int* buffer = new int[n + 1];
	//Копируем значения элементов исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//Удаляем исходный массив:
	delete[] arr;
	//Подменяем адрес в указателе 'arr' адресом нового массива:
	arr = buffer;
	//Только полсе всего этого можно добавить значение в конец массива:
	arr[n] = value;
	//После добавления элемента в конец массива,количество его элементов увеличивается на 1:
	n++;

	Print(arr, n);
	delete[]arr;
	//Memory leaks
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
		//Обращение к элементам массива через арифметику указателей и оператор рызаменования
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
		//Обращение к элементам массива через оператор индексирования []
	}
	cout << endl;
}