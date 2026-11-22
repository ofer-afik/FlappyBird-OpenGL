#include "player.hpp"

void Player::Update(double deltaTime)
{
    UpdatePos(deltaTime);
    if (CheckCollisionWithPipes())
    {
        alive = false;
    }
}

void Player::Draw()
{
    if (!alive)
    {
        return;
    }

    
}

void Player::UpdatePos(double deltaTime)
{

}

bool Player::CheckCollisionWithPipes()
{
    return false;
}