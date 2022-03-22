#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Square {
public:
	int operator() (const int value) const {
		return value * value;   //возводим в квадрат
	}
};

void test_cases1() {
	Square sq;
	cout << sq(10) << '\n';     // 10 * 10 = 100
	cout << sq(20) << '\n';     // 20 * 20 = 400
}

class Descend {          //сам класс не объект, он не функтор
public:
	bool operator() (const int left, const int right) {     //а для его будущего объекта перегружена (), объект будет функтором
		return left > right;
	}
};

void test_cases2() {
	int arr[] = { 1,2,3,4,5 };

	Descend d;      //создаём объект, который благодаря перегруженным круглым скобкам — функциональный объект, т. е. функтор
	std::sort(std::begin(arr), std::end(arr), d);   //передаём функтор в алгоритм сортировки
}

template<typename T>
void printVector(const std::vector<T>& vec) {
	for (auto v : vec) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
}
bool compare_greather(const int left, const int right) {      //сама функция не функтор, потому что она в терминах С++ не объект
	return left > right;            //если left меньше right, вернётся true, иначе вернётся false
}

void test_cases3() {
	std::vector<int> a{ 1,2,3,4,5 };
	std::vector<int> b{ 2,3,4,5,6 };
	std::vector<int> c{ 3,4,5,6,7 };
	std::vector<int> d{ 4,5,6,7,8 };

	bool(*p)(int, int) = compare_greather; //p — указатель на функцию, направлен на compare

	auto lambda_less = [](int left, int right) {return left > right; }; //lambda-функция

	std::sort(a.begin(), a.end(), Descend());
	std::sort(b.begin(), b.end(), p);
	std::sort(c.begin(), c.end(), lambda_less);
	std::sort(d.begin(), d.end(), [](int left, int right) {return left > right; });
	printVector(a);
	printVector(b);
	printVector(c);
	printVector(d);
}

#ifdef EXAMPLE
void foo(void(*)()) {                     //функция принимает указатель на функцию с пустым списком параметров
	std::cout << "foo\n";
}

void f1() {
	cout << "f1\n";
}

struct Functor {
	void operator() () {}
};

void test_cases_dontCompile() {
	foo(f1);        //OK, имя f1 неявно привелось к указателю (функция f1 не задействована)

	void(*ptr)() = f1; //создали явный указатель на функцию и направали его на foo
	foo(ptr);           //передали созданный указатель функции, OK

	Functor functor;
	foo(functor);       //объект класса не умеет преобразовываться к указателю, ошибка компиляции
}
#endif //EXAMPLE

template<typename T>
void print(const T i) {        //для вывода на экран функторов в functional нет, 
	cout << i << ' ';           //используем свою функцию
}

void test_cases4() {
	int arr[] = { 1,2,3,4,5 };

	std::sort(std::begin(arr), std::end(arr), std::greater<decltype(*arr)>());   //функтор сравнения, if (x > y) - перестановка
	std::for_each(begin(arr), end(arr), print<decltype(*arr)>);       //используем имя своей функции в качестве функтора

	cout << '\n';

	std::sort(begin(arr), end(arr), std::less<decltype(*arr)>());      //функтор сравнения, if (x < y) - перестановка
	std::for_each(begin(arr), end(arr), print<decltype(*arr)>);
}

class EvenOddFunctor {
	int even_;
	int odd_;
public:
	EvenOddFunctor() : even_(0), odd_(0) {}
	void operator()(int x) {
		if (x % 2 == 0) even_ += x;
		else odd_ += x;
	}
	int even_sum() const { return even_; }
	int odd_sum() const { return odd_; }
};

void test_cases5() {
	EvenOddFunctor evenodd;

	int my_list[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//Здесь экземпляр EvenOddFunctor передается в for_each. 
	//for_each итерируется по каждому элементу в my_list и вызывает функтор. 
	//После этого он возвращает копию функтора evenodd, который содержит сумму чётных и нечётных элементов.
	evenodd = std::for_each(std::begin(my_list), std::end(my_list), evenodd);

	std::cout << "Сумма чётных: " << evenodd.even_sum() << "\n";
	std::cout << "Сумма нечётных: " << evenodd.odd_sum() << std::endl;
}

#include<string>
int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "Enter case: ";
	switch (char(std::cin.get()))
	{
		case '1': 
		{
			test_cases1();
			break;
		}

		case '2':
		{
			test_cases2();
			break;
		}

		case '3':
		{
			test_cases3();
			break;
		}

		case '4':
		{
			test_cases4();
			break;
		}

		case '5':
		{
			test_cases5();
			break;
		}

		default:
			break;
	}
}