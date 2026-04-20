#include "Enemy.h"
#include <fstream>
#include <cmath>

cenemy::cenemy(float spd) : speed(spd) {}

bool cenemy::loadTexture(const std::string& filename, int size, int frame) {
    if (!texture.loadFromFile(filename)) return false;
    sprite.setTexture(texture);
    frameSize = sf::Vector2i(size, size);
    frameCount = frame;
    sprite.setTextureRect(sf::IntRect(0, 0, frameSize.x, frameSize.y));
    sprite.setOrigin(size / 2.0f, size / 2.0f); // Giúp enemy xoay hoặc di chuyển mượt hơn
    return true;
}

bool cenemy::loadPathFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;

    path.clear();
    float row, col;
    // Đọc tọa độ từ path.txt
    while (file >> row >> col) {
        // Chuyển đổi tọa độ ô (grid) sang tọa độ Pixel
        path.push_back(sf::Vector2f(col * 64.f, row * 64.f));
    }

    if (!path.empty()) sprite.setPosition(path[0]);
    return true;
}

void cenemy::update(float deltaTime) {
    if (currentTarget >= path.size()) return;

    sf::Vector2f targetPos = path[currentTarget];
    sf::Vector2f currentPos = sprite.getPosition();
    sf::Vector2f direction = targetPos - currentPos;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance < 2.0f) {
        currentTarget++; // Chuyển sang điểm tiếp theo trong file path.txt
    } else {
        // Di chuyển
        sf::Vector2f velocity = (direction / distance) * speed;
        sprite.move(velocity * deltaTime);
    }

    // Cập nhật Animation đơn giản
    frameTimer += deltaTime;
    if (frameTimer >= frameDuration) {
        frameTimer = 0.0f;
        currentFrame = (currentFrame + 1) % frameCount;
        sprite.setTextureRect(sf::IntRect(currentFrame * frameSize.x, 0, frameSize.x, frameSize.y));
    }
}

void cenemy::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}