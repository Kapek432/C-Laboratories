#include "enemy.h"

Enemy::Enemy(const Position& pos, int maxHp): Object(ObjectType::OBJECT_ENEMY,pos),hp_(maxHp), maxHp_(maxHp) {}
int Enemy::lifePercent() const {return static_cast<int>(static_cast<float>(hp_) / maxHp_ * 100);}
bool Enemy::isAlive() const { return hp_ > 0;}
void Enemy::decreaseLife(int damage){ hp_ -= damage; if(hp_ < 0) hp_ = 0;}


bool Enemy::shouldIMoveThisTime() const
{   /// you can change the function
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastMoveTime_);
    return elapsedTime >= moveInterval_;
}
