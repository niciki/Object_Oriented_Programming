#include "figure.h"
#include "trapezoid.h"
#include <cmath>

Trapezoid::Trapezoid(): a(Point()), b(Point()), c(Point()), d(Point()) {
}

Trapezoid::Trapezoid(Point a_, Point b_, Point c_, Point d_): a(a_), b(b_), c(c_), d(d_) {
}

Trapezoid::Trapezoid(std::istream& is) {
    is >> a >> b >> c >> d;
}

void Trapezoid::Print(std::ostream& os) {
    os << a << " " << b << " " << c << " " << d << "\n";
}

size_t Trapezoid::VertexesNumber() {
    return (size_t)(4);
}

double Trapezoid::Area(){
    double ax = a.X() - c.X();
    double bx = b.X() - d.X();
    double ay = a.Y() - c.Y();
    double by = b.Y() - d.Y();
    double COS = (ax*bx + ay*by)/(sqrt(ax*ax+ay*ay)*sqrt(bx*bx+by*by));
    return double(a.dist(c) * b.dist(d) * 0.5 *sin(acos(COS)));
}

std::istream &operator>>(std::istream &is, Trapezoid &figure){
    is >> figure.a >> figure.b >> figure.c >> figure.d;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Trapezoid &figure){
    os << "Trapezoid: " << figure.a << " " << figure.b << " " << figure.c << " " << figure.d << std::endl;
    return os;
}
