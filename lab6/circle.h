//
// Created by ACER on 08.04.2025.
//

#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

namespace Shapes {

class Circle: public Shape
{
    int xCenter, yCenter;
    int radius_;
public:
    Circle(int x, int y, int r): xCenter(x), yCenter(y), radius_(r){}
    bool isIn(int x, int y) const override
    {
        return (x-xCenter)*(x-xCenter)+(y-yCenter)*(y-yCenter)<=radius_*radius_;
    }
    int x() const { return xCenter; }
    int y() const { return yCenter; }
    int radius() const { return radius_; }

};

} // shapes

#endif //CIRCLE_H
