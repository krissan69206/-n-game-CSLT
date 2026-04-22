#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <cstring>
#include <fstream>  
#include <sstream>  

class cmap {
private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    bool useBackground = false;
    std::vector<sf::Vector2f> towerPlacements;  // Danh sách ô có thể đặt tower
    std::vector<bool> isPlaced;                 // Đánh dấu ô nào đã đặt tower
public:
    cmap();

    bool LoadTexturemap(int mapIndex, const std::string& filename); // Load ảnh nền
    void draw(sf::RenderWindow& window); // Vẽ ảnh nền

    void setTowerPlacements(const std::vector<sf::Vector2f>& positions);
    void resetTowers();
    const std::vector<sf::Vector2f>& getTowerPlacements() const;
    bool isOccupied(int index) const;
    void placeTower(int index);

};