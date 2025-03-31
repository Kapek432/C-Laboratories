#include <algorithm>
#include "engine.h"
#include "player.h"
#include "stage.h"
#include "bullet.h"
#include "enemy.h"


namespace
{
inline auto signum(int x)
{
    return (x > 0) - (x < 0);
}

Direction randDirection()
{
    auto randEdge = rand() % static_cast<uint8_t>(Direction::UPPER_LEFT);
    return static_cast<Direction>(randEdge);
}
} // namespace


Position generateNewEnemyPosition(int width, int height)
{
    Position position2Generate = Position(rand() % width, rand() % height);

    switch (randDirection()) {
        case Direction::UP:
            position2Generate.y_ = height-1;
            break;
        case Direction::DOWN:
            position2Generate.y_ = 0;
            break;
        case Direction::LEFT:
            position2Generate.x_ = 0;
            break;
        case Direction::RIGHT:
            position2Generate.x_ = width-1;
            break;
        default:
            break;
    }
    return position2Generate;
}


Engine::~Engine() = default;


Engine::Engine(std::size_t stageWidth, std::size_t stageHeight):
    stage_(stageWidth, stageHeight)
{
    const decltype(Position::x_) middleX = stage_.width() / 2;
    const decltype(Position::y_) middleY = stage_.height() / 2;

    player_ = Player(Position(middleX, middleY));

}

void Engine::update()
{
    updateBullets();
    updateEnemies();
    randEnemies();
}

void Engine::updateBullets()
{
    for (auto it = bullets_.begin(); it != bullets_.end();)
    {
        auto& bullet = *it;

        switch (bullet.direction())
        {
        case Direction::UP:           bullet.position().moveUp(); break;
        case Direction::DOWN:         bullet.position().moveDown(); break;
        case Direction::LEFT:         bullet.position().moveLeft(); break;
        case Direction::RIGHT:        bullet.position().moveRight(); break;
        case Direction::UPPER_LEFT:   bullet.position().moveLeft().moveUp(); break;
        case Direction::UPPER_RIGHT:  bullet.position().moveRight().moveUp(); break;
        case Direction::DOWNER_LEFT:  bullet.position().moveLeft().moveDown(); break;
        case Direction::DOWNER_RIGHT: bullet.position().moveRight().moveDown(); break;
        case Direction::CENTER:
        case Direction::INMOVABLE:
        case Direction::UNKNOWN:
        default:
            break;
        }

        if (bullet.position().y_ > stage_.height() || bullet.position().x_ > stage_.width())
        {
            it = bullets_.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Engine::updateEnemies()
{
    for (auto it = enemies_.begin(); it != enemies_.end();) {
        if (!(*it)->isAlive()) {
            it = enemies_.erase(it); // Usuwamy i pobieramy nowy iterator na poprawne miejsce // w it będzie itrator
            // na następny
        } else {
            ++it; // Przechodzimy do następnego elementu
        }
    }
    for (auto& enemy : enemies_) {
        if (enemy->shouldIMoveThisTime()) {
            auto playerPos = player_.position();
            auto enemyPos = enemy->position();

            if (playerPos.x_ > enemyPos.x_ && playerPos.y_ > enemyPos.y_) {
                enemy->moveRight().moveUp();
            }
            else if (playerPos.x_ > enemyPos.x_ && playerPos.y_ < enemyPos.y_) {
                enemy->moveRight().moveDown();
            }
            else if (playerPos.x_ < enemyPos.x_ && playerPos.y_ > enemyPos.y_) {
                enemy->moveLeft().moveUp();
            }
            else if (playerPos.x_ < enemyPos.x_ && playerPos.y_ < enemyPos.y_) {
                enemy->moveLeft().moveDown();
            }
            else if (playerPos.x_ > enemyPos.x_) {
                enemy->moveRight();
            }
            else if (playerPos.x_ < enemyPos.x_) {
                enemy->moveLeft();
            }
            else if (playerPos.y_ > enemyPos.y_) {
                enemy->moveUp();
            }
            else if (playerPos.y_ < enemyPos.y_) {
                enemy->moveDown();
            }
        }
    }
}


void Engine::movePlayerUp()
{
    player_.moveUp();
}

void Engine::movePlayerDown()
{
    player_.moveDown();
}

void Engine::movePlayerLeft()
{
    player_.moveLeft();
}
void Engine::movePlayerRight()
{
    player_.moveRight();
}

void Engine::playerShoots()
{
    Bullet bullet(player_.direction(), moveInDirection(player_.position(), player_.direction()));
    bullets_.push_back(bullet);
}

Position Engine::playerPosition() const
{
    return player_.position();
}

Direction Engine::playerDirection() const
{
    return player_.direction();
}

bool Engine::isPlayerAlive() const
{
    return player_.isAlive();
}

std::size_t Engine::stageWidthCells() const
{
    return stage_.width();
}
std::size_t Engine::stageHeightCells() const
{
    return stage_.height();
}

void Engine::randEnemies(Position (*positionGenerator)(int,int))
{
    if (enemies_.size() < maxEnemies_)
    {
        Position pos = positionGenerator(stage_.width(), stage_.height());
        auto enemy = std::make_shared<Enemy>(pos);
        enemies_.push_back(enemy);
    }
}
Position Engine::moveInDirection(const Position& pos, Direction dir)
{
    Position newPos = pos;
    switch (dir)
    {
    case Direction::UP:
        newPos.moveUp();
        break;
    case Direction::DOWN:
        newPos.moveDown();
        break;
    case Direction::LEFT:
        newPos.moveLeft();
        break;
    case Direction::RIGHT:
        newPos.moveRight();
        break;
    case Direction::UPPER_LEFT:
        newPos.moveUp().moveLeft();
        break;
    case Direction::UPPER_RIGHT:
        newPos.moveUp().moveRight();
        break;
    case Direction::DOWNER_LEFT:
        newPos.moveDown().moveLeft();
        break;
    case Direction::DOWNER_RIGHT:
        newPos.moveDown().moveRight();
        break;
    case Direction::CENTER:
            break;
    case Direction::INMOVABLE:
            break;
    case Direction::UNKNOWN:
            break;
    }
    return newPos;
}
