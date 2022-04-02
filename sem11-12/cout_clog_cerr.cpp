#include <iostream>


int main() 
{
    /*stdin — стандартный ввод (клавиатура),
      stdout — стандартный вывод (экран),
      stderr — стандартная ошибка (вывод ошибок на экран).
    */
    std::cout << "Message\n"; // > file.txt
    std::clog << "Log message\n"; //2> file.txt or &>
    std::cerr << "Error message\n"; //2> file.txt or &>
}