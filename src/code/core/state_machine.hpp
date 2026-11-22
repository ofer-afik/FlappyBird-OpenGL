#pragma once

enum class GAME_STATE
{
    PLAYING
};

class GameState
{
public:
    virtual ~GameState() = default;

    virtual void Update(double deltaTime) = 0;
    virtual void Draw() = 0;

    int initialScreenWidth;
    int initialScreenHeight;
};

class Playing : public GameState
{
public:
    Playing();
    ~Playing();

    void Update(double deltaTime) override;
    void Draw() override;
};