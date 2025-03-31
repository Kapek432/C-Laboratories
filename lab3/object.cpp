#include "object.h"

using namespace std;

Object::Object (ObjectType obj, Position pos): object_(obj), position_(pos) {}
ObjectType Object::type() const{ return object_; }
Position Object::position() const{ return position_; }
void Object::setPosition(const Position& pos){ position_ = pos; }
Object &Object::moveUp() { position_.y_ ++; return *this; }
Object &Object::moveDown() {position_.y_ --; return *this; }
Object &Object::moveLeft() {position_.x_ --; return *this; }
Object &Object::moveRight(){position_.x_ ++; return *this; }