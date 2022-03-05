#include <iostream>
#include <stack>
#include <random>
#include <chrono>

void printStack(std::stack<int>& s) 
{   
    std::cout << "PRINTING STACK:\n";
    while(!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }

}

int main() 
{
    std::stack<int> s;
    for(int i = 0; i < 1000; i++)
        s.push(std::rand() % 20);

    auto begin = std::chrono::steady_clock::now();
    printStack(s);
    auto end = std::chrono::steady_clock::now();

    std::cout << "Print time " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " ms.\n";
    printStack(s);
}