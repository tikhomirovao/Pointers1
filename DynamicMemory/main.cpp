#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

template<typename T>T** Allocate(const int rows, const int cols);
template<typename T>void Clear(T** arr, const int rows);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(char arr[], const int n, int minRand = 0, int maxRand = 100);

void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(double** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(char** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);

template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>T* push_back(T arr[], int& n, const T value);
template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>void push_col_back(T** arr, const int rows, int& cols);

template<typename T>T* push_front(T arr[], int& n, const T value);
template<typename T>T** push_row_front(T** arr, int& rows, const int cols);
template<typename T>void push_col_front(T** arr, const int rows, int& cols);

template<typename T>T* insert(T arr[], int& n, const T value, const int index);
template<typename T>T** insert_row(T** arr, int& rows, const int cols, int position);
template<typename T>void insert_col(T** arr, const int rows, int& cols, int index);

template<typename T>T* pop_back(T arr[], int& n);
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols);
template<typename T> void pop_col_back(T** arr, const int rows, int& cols);

template<typename T>T* pop_front(T arr[], int& n);
template<typename T> T** pop_row_front(T** arr, int& rows, const int cols);
template<typename T> void pop_cols_front(T** arr, const int rows, int& cols);

template<typename T>T* erase(T arr[], int& n, const int index);
template<typename T> T** erase_row(T** arr, int& rows, const int cols, const int index);
template<typename T> void erase_cols(T** arr, const int rows, int& cols, const int index);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
//#define PERFORMANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");

	typedef double DataType;

#ifdef DYNAMIC_MEMORY_1
	//		new
	int n = 5;
	cout << "Введите размер массива: "; cin >> n;

	DataType* arr = new DataType[n];

	FillRand(arr, n);
	Print(arr, n);

	DataType value;
	cout << "Введите добавляемое значение: "; cin >> value;	//Enter a value to be added
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;	//Enter a value to be added
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите индекс добавляемого значения: "; cin >> index;
	cout << "Введите добавляемое значение: "; cin >> value;	//Enter a value to be added
	arr = insert(arr, n, value, index);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
	//Memory leaks  
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;	//Enter number of rows
	cout << "Введите количество элементов строки: "; cin >> cols;

	double** arr = Allocate<double>(rows, cols);
	/*double** arr = new double*[rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new double[cols];
	}*/

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	int index;
	cout << "Введите значение индекса для добавления строки в двумерный массив: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите значение индекса для удаления строки из массива: "; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите значение индекса для добавления столбца в двумерный массив: "; cin >> index;
	insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	pop_cols_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите значение индекса для удаления строки из двумерного массива: "; cin >> index;
	erase_cols(arr, rows, cols, index);
	Print(arr, rows, cols);
	Clear(arr, rows);
	/*for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;*/
#endif // DYNAMIC_MEMORY_2

#ifdef PERFORMANCE_CHECK
	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;	//Enter number of rows
	cout << "Введите количество элементов строки: "; cin >> cols;

	int** arr = Allocate(rows, cols);
	cout << "Memory allocated" << endl;
	//FillRand(arr, rows, cols);
	//cout << "Data loaded" << endl;
	cout << "Press any key to add row" << endl;
	system("PAUSE");
	arr = push_row_back(arr, rows, cols);
	cout << "Row added" << endl;
	cout << "To clear memory ";
	system("PAUSE");

	Clear(arr, rows);
#endif // PERFORMANCE_CHECK

#ifdef SYNTAX
	int rows = 3;
	int cols = 4;
	//1) Создаем массив указателей:
	int** arr = new int* [rows];
	//2) Выделяем память под строки:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	//1) Удаляем строки:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//2) Удаляем массив указателей:
	delete[] arr;
#endif // SYNTAX
}
template<typename T>T** Allocate(const int rows, const int cols)
{
	T** arr = new T * [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
	}
	return arr;
}
template<typename T>void Clear(T** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
		//Обращение к элементам массива через арифметику указателей и оператор разыменования
	}
}
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
		//Обращение к элементам массива через арифметику указателей и оператор разыменования
		*(arr + i) /= 100;
	}
}
void FillRand(char arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand();
		//Обращение к элементам массива через арифметику указателей и оператор разыменования
	}
}
void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void FillRand(double** arr, const int rows, const int cols, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = double(rand() % (maxRand - minRand) + minRand) / 100;
		}
	}
}
void FillRand(char** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}
template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
		//Обращение к элементам массива через оператор индексирования []
	}
	cout << endl;
}
template<typename T>void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}
template<typename T>T* push_back(T arr[], int& n, const T value)
{
	//1) Создаем буферный массив нужного мазмера:
	T* buffer = new T[n + 1];
	//2) Копируем значения элементов исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив из памяти:
	delete[] arr;
	//4) Подменяем адрес в указателе 'arr' адресом нового массива:
	int a = 2;
	int b = 3;
	//5) Только после всего этого можно добавить значение в конец массива:
	buffer[n] = value;
	//6) После добавления элемента в конец массива, кличество его элементов увеличивается на 1:
	n++;
	return buffer;
}
template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
#ifdef NEVER_DO_IN_THIS_WAY
	int** buffer = Allocate(rows + 1, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	Clear(arr, rows);
	buffer[rows++] = new int[cols];

	return buffer;
#endif // NEVER_DO_IN_THIS_WAY

	return push_back(arr, rows, new T[cols]{});
}
template<typename T>void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = push_back(arr[i], cols, T());
		cols--;
	}
	cols++;
}
template<typename T>T* push_front(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
template<typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	return push_front(arr, rows, new T[cols]{});
}
template<typename T>void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = push_front(arr[i], cols, T());
		cols--;
	}
	cols++;
}
template<typename T>T* insert(T arr[], int& n, const T value, const int index)
{
	if (index >= n)return arr;
	T* buffer = new T[n + 1];
	//for (int i = 0; i < index; i++)buffer[i] = arr[i];
	//for (int i = index; i < n; i++)buffer[i + 1] = arr[i];
	for (int i = 0; i < n; i++)
	{
		/*if (i < index)buffer[i] = arr[i];
		else buffer[i + 1] = arr[i];*/
		//i < index ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
		buffer[i < index ? i : i + 1] = arr[i];
	}
	delete[] arr;
	buffer[index] = value;
	n++;
	return buffer;
}
template<typename T>T** insert_row(T** arr, int& rows, const int cols, int index)
{
	return insert(arr, rows,new T[cols], index);
}
template<typename T>void insert_col(T** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = insert(arr[i], cols, T(), index);
		cols--;
	}
	cols++;
}
template<typename T>T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	delete[] arr[rows-1];
	return pop_back(arr, rows);
}
template<typename T> void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0; j < cols - 1; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T>T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
template<typename T> T** pop_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T * [rows - 1];
	for (int i = 0; i < rows - 1; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}
template<typename T> void pop_cols_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0; j < cols - 1; j++) buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T>T* erase(T arr[], int& n, const int index)
{
	T* buffer = new T[--n];
	//for (int i = 0; i < index; i++)buffer[i] = arr[i];
	//for (int i = index; i < n; i++)buffer[i] = arr[i + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr;
	return buffer;
}
template<typename T> T** erase_row(T** arr, int& rows, const int cols, const int index)
{
	T** buffer = new T * [rows - 1];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < rows - 1; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}
template<typename T> void erase_cols(T** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0; j < index; j++) buffer[j] = arr[i][j];
		for (int j = index; j < cols - 1; j++) buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
}
	cols--;
}