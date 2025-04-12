//
// Created by ACER on 08.04.2025.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

namespace Shapes {

class Rectangle: public Shape
{
    int xFrom_, yFrom_;
    int xTo_, yTo_;
public:
    Rectangle(int x1, int y1, int x2, int y2): xFrom_(x1), yFrom_(y1), xTo_(x2), yTo_(y2) {}
    bool isIn(int x, int y) const override
    {
        return (x>=xFrom_) & (x<=xTo_) & (y>=yFrom_) & (y<=yTo_);
    }
    int x() const { return xFrom_; }
    int y() const { return yFrom_; }
    int xTo() const { return xTo_; }
    int yTo() const { return yTo_; }
};

} // shapes

#endif //RECTANGLE_H
