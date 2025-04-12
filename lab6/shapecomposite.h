//
// Created by ACER on 08.04.2025.
//

#ifndef SHAPECOMPOSITE_H
#define SHAPECOMPOSITE_H
#include <memory>

#include "shape.h"

namespace Shapes {

enum class ShapeOperation{ INTERSECTION, SUM, DIFFERENCE };

class ShapeComposite: public Shape
{
    std::shared_ptr<Shape> shape1, shape2;
    ShapeOperation operation;
public:
    ShapeComposite(std::shared_ptr<Shape>& s1, std::shared_ptr<Shape>& s2, ShapeOperation op)
        : shape1(s1), shape2(s2), operation(op) {}
    bool isIn(int x, int y) const override;

};

} // shapes

#endif //SHAPECOMPOSITE_H
