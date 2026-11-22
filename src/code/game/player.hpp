#include <glm/glm.hpp>

class Player
{
public:
    void Update(double deltaTime);
    void Draw();

    glm::vec2 position = glm::vec2(0.1f, 0.5f);
    float velocityX = 0.25f;
    float impulseY = 0.1;

    bool alive = true;

private:
    void UpdatePos(double deltaTime);
    bool CheckCollisionWithPipes();    
};