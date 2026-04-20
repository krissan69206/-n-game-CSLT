#ifdef __APPLE__
    #include "FixMac.h"
#endif
#include <SFML/Graphics.hpp>
#include "Enemy.h"

int main() {
    // SFML 2.6.1 dùng constructor (width, height)
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Enemy Movement Test");

    cenemy duck(100.0f); // Tốc độ 120
    duck.loadTexture("img/map1/duck.png", 64, 4); 
    
    // Nạp file path.txt bạn đã đính kèm
    if (!duck.loadPathFromFile("path.txt")) {
        return -1; // Thoát nếu không tìm thấy file path
    }

    sf::Clock clock;
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        duck.update(deltaTime);

        window.clear(sf::Color(50, 50, 50)); // Nền xám cho dễ nhìn
        duck.draw(window);
        window.display();
    }
    return 0;
}