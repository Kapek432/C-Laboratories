#ifndef STAGE_H
#define STAGE_H

#include "shape.h"
#include <iostream>



    class Stage {
    private:
        size_t width_;
        size_t height_;

    public:
        Stage(size_t width, size_t height)
            : width_(width), height_(height) {}

        void drawShape2Stream(const Shapes::Shape* shape, std::ostream& os) const {
            for (int y = static_cast<int>(height_); y >= 0; --y) {
                for (size_t x = 0; x < width_; ++x) {
                    if (shape->isIn(static_cast<int>(x), y)) {
                        os << "*";
                    } else {
                        os << " ";
                    }
                }
                os << "\n";
            }
        }
    };



#endif // STAGE_H
