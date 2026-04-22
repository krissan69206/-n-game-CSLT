#include "Map.h"
#include <iostream>

cmap::cmap() {
    // Constructor không cần làm gì nếu chỉ dùng ảnh nền
}

bool cmap::LoadTexturemap(int mapIndex, const std::string& filename) {
    std::string folder = "img/map" + std::to_string(mapIndex) + "/";
    std::string path = folder + filename;

    if (!backgroundTexture.loadFromFile(path)) {
        std::cerr << "Không thể load background map từ: " << path << std::endl;
        return false;
    }

    backgroundSprite.setTexture(backgroundTexture);
    useBackground = true;
    return true;
}

void cmap::draw(sf::RenderWindow& window) {
    if (useBackground) {
        window.draw(backgroundSprite);
    }
}

void cmap::setTowerPlacements(const std::vector<sf::Vector2f>& positions) {
    towerPlacements = positions;
    isPlaced.resize(positions.size(), false);
}

void cmap::resetTowers() {
    std::fill(isPlaced.begin(), isPlaced.end(), false);
}

const std::vector<sf::Vector2f>& cmap::getTowerPlacements() const {
    return towerPlacements;
}

bool cmap::isOccupied(int index) const {
    if (index >= 0 && index < isPlaced.size())
        return isPlaced[index];
    return true;
}

void cmap::placeTower(int index) {
    if (index >= 0 && index < isPlaced.size())
        isPlaced[index] = true;
}
