#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"
#include "direction.h"


class Player : public Object
{
Direction direction_ = Direction::RIGHT;
bool alive_ = true;
public:
    Player(const Position& pos = Position(0, 0),const Direction& dir = Direction::RIGHT): Object(ObjectType::OBJECT_PLAYER, pos), direction_(dir), alive_(true) {}
    void setDirection(Direction dir){ direction_ = dir; }
    Direction direction() const{ return direction_; }
    void setIsAlive(bool alive){ alive_ = alive; }
    bool isAlive() const{ return alive_; }


};

#endif // PLAYER_H
// Player::Player(const Position& pos,const Direction& dir): Object(ObjectType::OBJECT_PLAYER, pos), direction_(dir), alive_(true) {}
// void Player::setDirection(Direction dir){ direction_ = dir; }
// Direction Player::direction() const { return direction_; }
// void Player::setIsAlive(bool alive) { alive_ = alive; }
// bool Player::isAlive() const { return alive_; }
