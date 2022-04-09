#include <chrono>
#include <execution>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
#include <thread>

/***PARALLEL ACCUMULATE***/
template < typename Iterator, typename T >
struct accumulate_block
{
	void operator()(Iterator first, Iterator last, T & result)
	{
		result = std::accumulate(first, last, result); // !
	}
};

template < typename Iterator, typename T >
T parallel_accumulate(Iterator first, Iterator last, T init)
{
	const std::size_t length = std::distance(first, last);

	if (!length)
		return init;

	const std::size_t min_per_thread = 25;
	const std::size_t max_threads =
		(length + min_per_thread - 1) / min_per_thread;

	const std::size_t hardware_threads =
		std::thread::hardware_concurrency();

	std::cout << "Hardware threads:" << hardware_threads << std::endl;

	const std::size_t num_threads =
		std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);

	std::cout << "Num threads:" << hardware_threads << std::endl;

	const std::size_t block_size = length / num_threads;

	std::cout << "Block size:" << block_size << std::endl;

	std::vector < T > results(num_threads);
	std::vector < std::thread > threads(num_threads - 1);

	Iterator block_start = first;

	for (std::size_t i = 0; i < (num_threads - 1); ++i)
	{
		Iterator block_end = block_start;
		std::advance(block_end, block_size);

		threads[i] = std::thread(
			accumulate_block < Iterator, T >(),
			block_start, block_end, std::ref(results[i])); // !

		block_start = block_end;
	}

	accumulate_block < Iterator, T >()(block_start, last, results[num_threads - 1]);

	std::for_each(threads.begin(), threads.end(),
		std::mem_fn(&std::thread::join));

	return std::accumulate(results.begin(), results.end(), init);
}
/***END OF PARALLEL ACCUMULATE***/


int main(int argc, char ** argv)
{
	std::vector < double > v;

	std::cout << "Enter vector size:";
	unsigned long int size; std::cin >> size;
	if(size >= v.max_size())
	{
		std::cout << "Too large\n";
		return 1;
	}
	v.resize(size);
	std::iota(v.begin(), v.end(), 1); //fill 1, 2, 3, 4
	{
		auto t1 = std::chrono::high_resolution_clock::now();
		double result = std::accumulate(v.begin(), v.end(), 0.0);
		auto t2 = std::chrono::high_resolution_clock::now();

		std::cout << std::setw(16) << std::left << std::fixed << "std::accumulate " << result <<
			" took " << std::chrono::duration_cast <std::chrono::milliseconds> (t2 - t1).count() << " (ms)\n";
	}

	{
		auto t1 = std::chrono::high_resolution_clock::now();
		double result = std::reduce(std::execution::par, v.begin(), v.end());
		auto t2 = std::chrono::high_resolution_clock::now();

		std::cout << std::setw(16) << std::left << std::fixed << "std::reduce " << result <<
			" took " << std::chrono::duration_cast <std::chrono::milliseconds> (t2 - t1).count() << " (ms)\n";
	}

	{
		auto t1 = std::chrono::high_resolution_clock::now();
		double result = parallel_accumulate(v.begin(), v.end(), 0);
		auto t2 = std::chrono::high_resolution_clock::now();

		std::cout << std::setw(16) << std::left << std::fixed << "parallel_accumulate " << result <<
			" took " << std::chrono::duration_cast <std::chrono::milliseconds> (t2 - t1).count() << " (ms)\n";
	}

	return 0;
}