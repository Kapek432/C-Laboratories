#ifndef BULLET_H
#define BULLET_H

#include "object.h"
#include "direction.h"


/**
 * Proszę o utworzenie klasy `Bullet`, która będzie dziedziczyć po klasie `Object`, następnie proszę zakomentować `UNIMPLEMENTED_bulletIsObject`
 * - Klasa ta powinna mieć mieć składową `direction_`, a także operujący na niej getter (`direction()`) i setter (`setDirection`)
 * - Klasa powinna mieć dwu-argumentowy konstruktor przyjmujący kierunek i pozycje początkową
 * - Po zaimplementowania tego proszę zakomentować `UNIMPLEMENTED_bulletHasDirectionAndPosition`
 * - Klasa powinna zawierać statyczny atrybut odpowiadający prędkości o wartości `2`, oraz getter `speed()`
 */



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
