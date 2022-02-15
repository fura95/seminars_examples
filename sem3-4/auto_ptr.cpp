#include <iostream>
#include <memory>

template<typename T>
class AutoPtr {
public:
    AutoPtr(T* data) : m_data(data) {}
    ~AutoPtr() {
        if(m_data != nullptr)
            delete m_data;
    }
    T* operator->() {return m_data;}
    T operator*() {return *m_data;}
    
private:
    T* m_data;
};

class Student{
    std::unique_ptr<Student> partner;
public:
    Student() {std::cout << "I'm became a student\n";}
   ~Student() {std::cout << "I didnt pass exam\n";}

   std::string name = "Ivan-MIPT";
};

using stud_ptr = AutoPtr<Student>;

int main() {

    Student* s = new Student();

    std::cout << "Start program\n";
    AutoPtr<Student> ptr_student(new Student());
    
    std::cout << ptr_student->name;
    
    std::unique_ptr<Student>* array_ptr = new std::unique_ptr<Student>[10];
    
    delete[] array_ptr;
    std::cout << "Finish program\n";
}