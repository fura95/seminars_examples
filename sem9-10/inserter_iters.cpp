#include <algorithm>
#include <iostream>
#include <list>
#include <iterator>

using namespace std;
int main(void)
{
	setlocale(LC_ALL, "Russian");

	int Arr[] = { 0, 0 }; //Начальный массив
	int Arr1[] = { 3, 2, 1 }; //Массив для первой вставки
	int Arr2[] = { 1, 2, 3 }; //Массив для второй вставки
	int Arr3[] = { 1, 1, 1 }; //Массив для третей вставки
	list<int> l(2); //список в два элемента

	std::copy(Arr, Arr + 2, l.begin()); //копируем в список начальный массив
	std::copy(l.begin(), l.end(), ostream_iterator<int>(cout, " ")); //выводим список на экран
	cout << " - Список перед вставкой в голову " << endl;

	//вставка в голову
	std::copy(Arr1, Arr1 + 3, front_inserter(l)); //вставляем в голову массив первой вставки
	std::copy(l.begin(), l.end(), ostream_iterator<int>(cout, " ")); //выводим массив на экран
	cout << " - Список перед вставкой в Хвост" << endl;

	//вставка в хвост
	std::copy(Arr2, Arr2 + 3, back_inserter(l));//вставляем в хвост массив второй вставки
	std::copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));//выводим список на экран
	cout << " - список перед вставкой в середину" << endl;

	//вставка в середину
	list<int>::iterator it = l.begin(); //Объявляем новый итератор и указываем на начало вектора как на точку старта
	std::advance(it, l.size()/2); //специальной операцией advance делаем приращение переменной итератора так, чтобы она указывала на середину в цепочке данных списка
	std::copy(Arr3, Arr3 + 3, inserter(l, it));//вставляем в середину массив третей вставки
	std::copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));//выводим список на экран
	cout << endl;

	return 0;
}