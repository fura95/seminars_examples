#include <algorithm>
#include <thread>
#include <vector>
#include <iostream>

/*
void f(int i) {
	std::cout << i << " ";
}

int main(int argc, char ** argv)
{
	std::vector < std::thread > threads;
	
	std::cout << "hardware_concurrency=" << std::thread::hardware_concurrency() << std::endl;;
	for (std::size_t i = 0; i < std::thread::hardware_concurrency(); ++i)
	{
		threads.push_back(std::thread(f, i));
	}

	std::for_each(threads.begin(), threads.end(),
		std::mem_fn(&std::thread::join)); //для каждого треда, вызвать join 
	//(Шаблон функции std::mem_fn генерирует объекты-оболочки для указателей на методы)

	return 0;
} */

 //C++20
#include <functional>
#include <iostream>

struct Foo {
	void display_greeting() {
		std::cout << "Hello, world.\n";
	}
	void display_number(int i) {
		std::cout << "number: " << i << '\n';
	}
	int data = 7;
};

int main() {
	Foo f;

	auto greet = std::mem_fn(&Foo::display_greeting);
	greet(f);

	auto print_num = std::mem_fn(&Foo::display_number);
	print_num(f, 42);

	auto access_data = std::mem_fn(&Foo::data);
	std::cout << "data: " << access_data(f) << '\n';
}
