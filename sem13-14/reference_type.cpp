#include <algorithm>
#include <list>
#include <vector>
#include <iostream>
#include <numeric>
#include <random>
#include <functional>

using namespace std;

void print(auto const rem, std::ranges::range auto const& v) {
    for (std::cout << rem; auto const& e : v)
        std::cout << e << ' ';
    std::cout << '\n';
}

int main()
{
    int x=5, y=7, z=8;
    //int& arr[] {x,y,z};    // error: declaration of 'arr' as array of references
    
    std::reference_wrapper<int> arr[] {x,y,z};
    for (auto a: arr)
        cout << a << " ";
    
    std::cout << "\n";

    std::list<int> l(10);
    std::iota(l.begin(), l.end(), -4);
 
    // can't use shuffle on a list (requires random access), but can use it on a vector
    std::vector<std::reference_wrapper<int>> v(l.begin(), l.end());
 
    std::ranges::shuffle(v, std::mt19937{std::random_device{}()}); // std::shuffle(v.begin(), v.end(), std::mt19937{std::random_device{}()});
 
    print("Contents of the list: ", l);
    print("Contents of the list, as seen through a shuffled vector: ", v);
 
    std::cout << "Doubling the values in the initial list...\n";
    std::ranges::for_each(l, [](int& i) { i *= 2; });
 
    print("Contents of the list, as seen through a shuffled vector: ", v);
}