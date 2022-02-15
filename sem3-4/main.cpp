#include <iostream>
#include <memory>

template<typename T>
class Auto_ptr 
{
public:
    Auto_ptr(T* data) : m_data(data) {}
    ~Auto_ptr() 
    {
        if(m_data != nullptr)
            delete m_data;
    }

    T operator*() { return *m_data;}
    T* operator->() {return m_data;}

private:
    T* m_data;
};

class Foo {
public:
    int a = 4;

    Foo() {std::cout << "Foo created\n";}
    ~Foo() {std::cout << "Foo deleted\n";}
};

int function(Auto_ptr<Foo> a) 
{
    return 0;
}

void close_file(std::FILE* fp)
{
    std::fclose(fp);
}
 
 //void(*)(std::FILE*) -> decltype(close_fine)

int main() 
{
    std::cout << "Starting program\n";
    Foo* foo = new Foo();
    std::shared_ptr<Foo> ptr1(foo);
    {
        //std::shared_ptr<Foo> ptr2(ptr1); // WORKING
        std::shared_ptr<Foo> ptr2(foo); // NOT WORKING
        std::cout << "Kill one shared ptr\n";
    }
    std::cout << ptr1->a << std::endl;
    std::cout << "Kill another shared ptr\n"; 
}