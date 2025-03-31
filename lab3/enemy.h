#ifndef ENEMY_H
#define ENEMY_H

#include <chrono>
#include "object.h"

class Enemy : public Object {
public:
    Enemy(const Position& pos, int maxHp = 100);
    int lifePercent() const;
    bool isAlive() const;
    void decreaseLife(int damage);


    bool shouldIMoveThisTime() const;
private:
    static constexpr std::chrono::milliseconds moveInterval_{500};

    mutable std::chrono::steady_clock::time_point lastMoveTime_;

    int hp_;
    const int maxHp_;
};

#endif // ENEMY_H
