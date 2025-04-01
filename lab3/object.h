#ifndef OBJECT_H
#define OBJECT_H

#include "position.h"

enum class ObjectType
{
    OBJECT_PLAYER,
    OBJECT_BULLET,
    OBJECT_ENEMY,
    OBJECT_WALL,
    OBJECT_UNKNOWN
};


class Object
{
public:
    Object(ObjectType obj, Position pos = Position(0, 0));
    ObjectType type() const;
    Position position() const;
    void setPosition(const Position& pos);
    Object &moveUp();
    Object &moveDown();
    Object &moveLeft();
    Object &moveRight();

protected:
    ObjectType object_;
    Position position_;
};

#endif // OBJECT_H
