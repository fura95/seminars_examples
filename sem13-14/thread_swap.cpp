#include <iostream>
#include <thread>
#include <chrono>

void foo()
{
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "Task foo executed by: " << std::hex << std::this_thread::get_id() << std::endl;
}

void bar()
{
	std::this_thread::sleep_for(std::chrono::seconds(4));
	std::cout << "Task bar executed by: " << std::hex << std::this_thread::get_id() << std::endl;
}

int main()
{
		std::thread t1(foo);
		std::thread t2(bar);

	std::cout << "thread 1 id: " << std::hex << t1.get_id() << '\n'
		<< "thread 2 id: " << std::hex << t2.get_id() << '\n';

	/*std::swap(t1, t2);

	std::cout << "after std::swap(t1, t2):" << '\n'
		<< "thread 1 id: " << std::hex << t1.get_id() << '\n'
		<< "thread 2 id: " << std::hex << t2.get_id() << '\n'; */

	t1.swap(t2);

	std::cout << "after t1.swap(t2):" << '\n'
		<< "thread 1 id: " << std::hex << t1.get_id() << '\n'
		<< "thread 2 id: " << std::hex << t2.get_id() << '\n';

	std::cout << "Waiting t1:\n";
	t1.join();
	std::cout << "Waiting t2:\n";
	t2.join();
}