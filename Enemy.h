#ifndef ENEMY_H
#define ENEMY_H

#ifdef __APPLE__
    #include "FixMac.h"
#endif

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>

class cenemy {
private:
    sf::Sprite sprite;
    sf::Texture texture;
    std::vector<sf::Vector2f> path;
    size_t currentTarget = 0;
    float speed;

    // Animation gọn nhẹ
    sf::Vector2i frameSize;
    int frameCount;
    int currentFrame = 0;
    float frameTimer = 0.0f;
    float frameDuration = 0.15f;

public:
    cenemy(float spd = 150.0f);
    bool loadTexture(const std::string& filename, int size, int frame);
    bool loadPathFromFile(const std::string& filename);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
};

#endif