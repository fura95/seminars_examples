#include <iostream>
#include <fstream>


void write_to_file(const std::string& filename, std::string msg) 
{
    std::ofstream out;          // поток для записи
    out.open(filename, std::ios::app);     // окрываем файл для записи и перезаписывает его

    if (out.is_open())
    {
        out << msg << std::endl;
    }
     
    out.close();
};

void read_from_file(std::string filename) 
{
    std::ifstream in(filename, std::ios::in); // окрываем файл для чтения
    if (in.is_open())
    {
        std::string line;
        while (std::getline(in, line))
        {
            std::cout << line << std::endl;
        }
    }
    in.close();
}


int main()
{
    write_to_file("hello.txt", "Hello, World!");
    read_from_file("hello.txt");
    
    std::cout << "End of program" << std::endl;
    return 0;
}