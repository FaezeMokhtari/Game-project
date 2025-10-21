// Triangle.cpp

#include "Triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle(double na,double nb,double nc) : a (na), b(nb) , c(nc)  {
   if(!(na + nb < nc && na + nc < nb && nc + nb < na && a > 0 && b > 0 && c > 0)){
    a = 0.0;
    b = 0.0;
    c = 0.0;
    std::cout << "Invalid triangle dimensions" << std::endl;
   }
}

double Triangle::perimeter() {
   if(a == 0.0){
    return 0.0;
   }else
    return (a + b + c);
}

double Triangle::area() {
    if(a != 0.0){
     double s = (a + b + c) / 2.0;
     double radicand = s * (s - a) * (s - b) * (s - c);
     if(radicand>= 0){
     return (std::sqrt(radicand));
     }
    }
   return 0.0;
}



void Triangle::display() {
    std::cout << "a: " << a << std::endl
              << "b: " << b << std::endl
              << "c: " << c << std::endl
              << "prematers: " << perimeter() << std::endl
              << "area: " << area() << std::endl;
}

double Triangle::geta() const { return a; }
double Triangle::getb() const { return b; }
double Triangle::getc() const { return c; }


