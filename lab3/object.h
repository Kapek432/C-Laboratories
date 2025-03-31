#ifndef OBJECT_H
#define OBJECT_H

#include "position.h"

/**
 * Proszę o zaimplementowanie klasy `Object`, która będzie trzymała typ obiektu
 * (zdefiniowany `ObjectType`), oraz pozycje (zdefiniowany `Position`).
 * Zaimplementuj metody:
 * - Konstruktor przyjmujący `ObjectType` i `Position` (pozycja niech ma zerową wartość domyślną)
 * - gettery `type()` i `position()`
 * - następnie można usunąć: `UNIMPLEMENTED_objectWithConstructorAndGetters`
 * - setter `setPosition`, następnie można usunąć `UNIMPLEMENTED_objectSetPosition`
 * - metody do poruszania obiektem o jedną komórkę: `moveUp()`, `moveDown()`, `moveLeft()`, `moveRight()`, następnie można usunąć `UNIMPLEMENTED_movingObject`
 *    1. co zyskali byśmy gdyby `moveX()` zwracało `*this`?
 */




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
