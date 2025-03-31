#ifndef BULLET_H
#define BULLET_H

#include "object.h"
#include "direction.h"

class Bullet : public Object
{
Direction direction_;
static constexpr int speed_ = 2;
    public:
    Bullet(const Direction& dir, const Position& pos):Object(ObjectType::OBJECT_BULLET, pos),direction_(dir){}
    Direction direction() const{  return direction_;  }
    void setDirection(const Direction& dir){direction_ = dir;}
    static int speed(){ return speed_; }
};


#endif // BULLET_H

// Bullet::Bullet(const Direction& dir, const Position& pos):Object(ObjectType::OBJECT_BULLET, pos),direction_(dir){}
// Direction Bullet::direction() const {  return direction_;  }
// void Bullet::setDirection(const Direction& dir) {direction_ = dir;}
// int Bullet::speed() { return speed_; }
