//
// Created by ACER on 08.04.2025.
//

#include "shapecomposite.h"

namespace Shapes {

bool ShapeComposite::isIn(int x, int y) const
{
    switch (operation)
    {
        case ShapeOperation::INTERSECTION:
            return shape1->isIn(x, y) && shape2->isIn(x, y);
        case ShapeOperation::SUM:
            return  shape1->isIn(x, y) || shape2->isIn(x, y);
        case ShapeOperation::DIFFERENCE:
            return shape1->isIn(x, y) && !shape2->isIn(x, y);
        default:
            return false;
    }
}


} // shapes