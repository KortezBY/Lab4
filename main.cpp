#include <iostream> 
#include <cstdlib> 
#include <ctime> 
using namespace std; 
// Функция для создания двумерного массива 
int** createArray(int n, int m) { 
 int** array = new int* [n]; 
 for (int i = 0; i < n; i++) { 
  array[i] = new int[m]; 
  for (int j = 0; j < m; j++) { 
   array[i][j] = rand() % 201 - 100; // Заполнение случайными значениями от -100 до +100 
  } 
 } 
 return array; 
} 
 
// Функция для подсчета количества строк без нулевых элементов 
int countNonZeroRows(int** array, int n, int m) { 
 int count = 0; 
 for (int i = 0; i < n; i++) { 
  bool hasZero = false; 
  for (int j = 0; j < m; j++) { 
   if (array[i][j] == 0) { 
    hasZero = true; 
    break; 
   } 
  } 
  if (!hasZero) { 
   count++; 
  } 
 } 
 return count; 
} 
 
// Функция для обработки двумерного массива 
void processArray(int** array, int n, int m) { 
 // Реализация основной логики задания 
 // Например, вывод элементов массива 
 for (int i = 0; i < n; i++) { 
  for (int j = 0; j < m; j++) { 
   cout << array[i][j] << " "; 
  } 
  cout << endl; 
 } 
} 
 
// Функция для освобождения памяти, занятой двумерным массивом 
void deleteArray(int** array, int n) { 
 for (int i = 0; i < n; i++) { 
  delete[] array[i]; 
 } 
 delete[] array; 
} 
 
int main() { 
 setlocale(LC_ALL, ""); 
 srand(time(NULL)); 
 
  int n, m; 
 cout << "Введите размеры двумерного массива (n и m): "; 
 cin >> n >> m; 
 
 int** array = createArray(n, m); 
 processArray(array, n, m); 
 
 int nonZeroRows = countNonZeroRows(array, n, m); 
 cout << "Количество строк без нулевых элементов: " << nonZeroRows << endl; 
 
 deleteArray(array, n); 
 
 return 0; 
}