// pair::pair example
#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout

class Point2D : protected std::pair<float, float>
{
public:
    Point2D(double x, double y) : std::pair<float, float>(x, y) {}
    float& x() {return this->first;}
    float& y() {return this->second;}
};

int main () {
  std::pair <std::string,double> product1;                     // default constructor
  std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
  std::pair <std::string,double> product3 (product2);          // copy constructor

  product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

  product2.first = "shoes";                  // the type of first is string
  product2.second =  39.90;                   // the type of second is double

  std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
  std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
  std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';

  Point2D point(10, 3);
  point.x() = 5;
  std::cout << point.x() << std::endl;
  std::cout << point.y() << std::endl;

  return 0;
}