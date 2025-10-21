// TRIANGLE.h

#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle {
public:
    Triangle(double na,double nb,double nc);
    double perimeter();
    double area();
    void   display();
    
    double geta() const;
    double getb() const;
    double getc() const;
   

private:
   double a;
   double b;
   double c;
};

#endif // TRIANGLE_H
