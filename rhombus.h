#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"

class Rhombus: Figure {
    public:
        void Print(std::ostream& os);
        double Area();
        size_t VertexesNumber();
        Rhombus();
        Rhombus(Point a_, Point b_, Point c_, Point d_);
        Rhombus(std::istream& is);
    private:
        Point a;
        Point b;
        Point c;
        Point d;
};

#endif