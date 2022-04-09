#include <iostream>
#include <thread>

// Пример с функцией
void foo(int a)
{
	std::cout << a << '\n';
	std::cout << "Function foo executed by: " << std::hex << std::this_thread::get_id() << std::endl;
};

//Пример с методом
class Bar {
public:
	void foo(int a)
	{
		std::cout << a << '\n';
		std::cout << "Method foo executed by: " << std::hex << std::this_thread::get_id() << std::endl;
	}
};

//Функтор
class Functor
{
public:
	void operator()(int a)
	{
		std::cout << a << '\n';
		std::cout << "Functor executed by: " << std::hex << std::this_thread::get_id() << std::endl;
	}
};


int main()
{
	// Пример с функцией
	std::thread thread1(foo, 1); 
	//thread1.join();

	//Пример с методом
	Bar bar;
	std::thread thread2(&Bar::foo, &bar, 2);
	//thread2.join();

	//Функтор
	Functor f;
	std::thread thread3(f, 3);
	//thread3.join();

	int b = 4;
	//Лямбда выражение
	std::thread thread4([&b](int a) 
	{ 
		std::cout << a << '\n'; 	
		std::cout << "Lambda executed by: " << std::hex << std::this_thread::get_id() << std::endl;
	}, 4); 
	//thread4.join();

	thread1.join();
	thread2.join();
	thread3.join();
	thread4.join();

	return 0;
}