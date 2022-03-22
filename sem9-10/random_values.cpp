#include <iostream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime> // для функции time()

unsigned int my_random()
{
	// Наше стартовое число - 4 541
	static unsigned int seed = 4541;

	// Из-за использования очень больших чисел (и переполнения) угадать следующее число исходя из предыдущего - очень сложно
	seed = (8253729 * seed + 2396403);

	// Берем стартовое число и возвращаем значение в диапазоне от 0 до 32767
	return seed % 32768;
}


void test_cases1() {
	std::cout << "My_random:\n";
	for (int count = 0; count < 100; ++count)
	{
		std::cout << my_random() << "\t";

		// Если вывели 5 чисел, то вставляем символ новой строки
		if ((count + 1) % 5 == 0)
			std::cout << "\n";
	}
}

void test_cases2() {
	std::cout << "Standart random. Seed fixed:\n";
	srand(4541);

	for (int count = 0; count < 100; ++count)
	{
		std::cout << rand() << "\t";

		if ((count + 1) % 5 == 0)
			std::cout << "\n";
	}
}

void test_cases3() {
	std::cout << "Standart random. Seed=time:\n";
	srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа

	for (int count = 0; count < 100; ++count)
	{
		std::cout << rand() << "\t";

		if ((count + 1) % 5 == 0)
			std::cout << "\n";
	}
}

// Генерируем рандомное число между значениями min и max.
// функция srand() уже была вызвана
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

	// Равномерно распределяем рандомное число в нашем диапазоне
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void test_cases4() {
	std::cout << "Standart random between:\n";
	srand(static_cast<unsigned int>(time(0)));
	for (int count = 0; count < 100; ++count)
	{
		std::cout << getRandomNumber(1, 6) << "\t";

		if ((count + 1) % 5 == 0)
			std::cout << "\n";
	}
}

//Between min and max+1
template<typename T>
T getRandomFloatingPointBetween(int min, int max) {
	return min + static_cast <T> (rand()) / (static_cast <T> (RAND_MAX / (max - min + 1)));
}

//Числа между 0 и 11
void test_cases5() {
	std::cout << "Standart float random between:\n";
	srand(static_cast<unsigned int>(time(0)));
	for (int count = 0; count < 100; ++count)
	{
		std::cout << getRandomFloatingPointBetween<float>(0, 10) << "    ";

		if ((count + 1) % 5 == 0)
			std::cout << "\n";
	}

}

#include <random>
double getRandomFloatingPointBetween_progressive(int min, int max) {
	std::random_device rd; // uniformly-distributed integer random number generator
	std::mt19937 gen(rd()); //инициализируем Вихрь Мерсенна случайным стартовым числом
	std::uniform_real_distribution<> dis(min, max);//uniform distribution between min and max
	return dis(gen);
}

void test_cases6() {
	std::cout << "Mersen float random between:\n";
	for (int count = 0; count < 100; ++count)
	{
		std::cout << getRandomFloatingPointBetween_progressive(1, 4) << "\t";

		if ((count + 1) % 5 == 0)
			std::cout << "\n";
	}

}

int main()
{
	test_cases1();
	std::cout << "\n";

	test_cases2();
	std::cout << "\n";

	test_cases3();
	std::cout << "\n";

	test_cases4();
	std::cout << "\n";

	test_cases5();
	std::cout << "\n";

	test_cases6();
	std::cout << "\n";
}

