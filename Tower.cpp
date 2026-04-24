#include "Tower.h"
#include <cmath>
#include <iostream>

ctower::ctower(sf::Vector2f pos, float r, float fr, int dmg)
    : position(pos), range(r), fireRate(fr), damage(dmg), fireTimer(0.f) {
    sprite.setPosition(pos);
}

bool ctower::loadTexture(const std::string& file, int frameW, int frameH) {
    texture = std::make_shared<sf::Texture>();
    if (!texture->loadFromFile(file)) {
        std::cerr << "[TOWER] Không thể load ảnh tower từ " << file << "\n";
        return false;
    }
    sprite.setTexture(*texture);
    sprite.setTextureRect(sf::IntRect(0, 0, frameW, frameH));
    sprite.setOrigin(frameW / 2.0f, frameH / 2.0f);
    return true;
    if (file == "img/map1/tower2.png") {
        sprite.setScale(0.5f, 0.5f);
    }
}

void ctower::setTexture(std::shared_ptr<sf::Texture> tex, int frameW, int frameH) {
    texture = tex;
    sprite.setTexture(*texture);
    sprite.setTextureRect(sf::IntRect(0, 0, frameW, frameH));
    sprite.setOrigin(frameW / 2.0f, frameH / 2.0f);
}

//std::vector<cBullet> ctower::update(float deltaTime, const std::vector<cenemy*>& enemies) {
//    fireTimer -= deltaTime;
//    std::vector<cBullet> newBullets;
//
//    for (auto* enemy : enemies) {
//        if (!enemy->isDead()) {
//            sf::FloatRect enemyBounds = enemy->getBounds();
//            sf::Vector2f enemyCenter(enemyBounds.left + enemyBounds.width / 2.f,
//                enemyBounds.top + enemyBounds.height / 2.f);
//
//            sf::Vector2f towerCenter = position;  // Nếu position đã là center
//            float dx = enemyCenter.x - towerCenter.x;
//            float dy = enemyCenter.y - towerCenter.y;
//            float distance = std::sqrt(dx * dx + dy * dy);
//
//            if (distance <= range && fireTimer <= 0.f) {
//                cBullet bullet(position, enemyCenter, damage, 200.f);
//                newBullets.push_back(bullet);
//                fireTimer = 1.f / fireRate;
//                break;
//            }
//        }
//    }
//    return newBullets;
//}


void ctower::draw(sf::RenderWindow& window) {
    sprite.setPosition(position);
    window.draw(sprite);
}

sf::FloatRect ctower::getBounds() const {
    return sprite.getGlobalBounds();
}

sf::Vector2f ctower::getPosition() {
    return position;
}
