#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "Enemy.h"
//#include "Bullet.h"

class ctower {
private:
    sf::Vector2f position;                          // Vị trí đặt tháp
    float range;                                    // Tầm bắn
    float fireRate;                                 // Tốc độ bắn (giây/phát)
    float fireTimer;                                // Thời gian đếm để bắn
    int damage;                                     // Sát thương

    std::shared_ptr<sf::Texture> texture;           // Texture dùng chung hoặc riêng
    sf::Sprite sprite;

public:
    ctower(sf::Vector2f pos, float range, float fireRate, int damage);
    bool loadTexture(const std::string& file, int frameW = 32, int frameH = 32);
    void setTexture(std::shared_ptr<sf::Texture> tex, int frameW = 32, int frameH = 32);
    //    std::vector<cBullet> update(float deltaTime, const std::vector<cenemy*>& enemies);
    void draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
    sf::Vector2f getPosition();
};
