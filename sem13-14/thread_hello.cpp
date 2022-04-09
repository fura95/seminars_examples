#include <iostream>
#include <thread>
#include <string>

int main()
{
	auto func = [](const std::string& first, const std::string& second)
	{
		std::this_thread::sleep_for(std::chrono::seconds(5));
		std::cout << "\nFunction thread id=" << std::hex << std::this_thread::get_id() << std::endl;
		std::cout << first << second << "Starting hard work\n";
		for(unsigned long int i = 0; i < std::numeric_limits<unsigned long int>::max() ; i++); //hard work
		
	};

	std::cout << "Max Threads count:" << std::thread::hardware_concurrency() << std::endl;
	std::cout << "Main thread id=" << std::hex << std::this_thread::get_id() << std::endl;
	std::thread thread1(func, "Hello, ", "threads1! ");
	std::thread thread2(func, "Hello, ", "threads2! ");

	std::cout << "Thread id=" << std::hex << thread1.get_id() << std::endl;
	std::cout << "Thread id=" << std::hex << thread2.get_id() << std::endl;

	std::cout << "Max Threads count:" << std::thread::hardware_concurrency() << std::endl;

	//thread1.detach();
	//thread2.detach();

	thread1.join();
	thread2.join();
	//std::this_thread::sleep_for(std::chrono::seconds(5));
}