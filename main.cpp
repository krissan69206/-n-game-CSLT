#ifdef __APPLE__
#include "FixMac.h"
#endif
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Menu");
    window.setKeyRepeatEnabled(false);

    // ===== BACKGROUND =====
    sf::Texture menuBgTexture;
    sf::Sprite menuBgSprite;

    if (!menuBgTexture.loadFromFile("img/menu/menu_background.png"))
        return -1;

    menuBgSprite.setTexture(menuBgTexture);
    menuBgSprite.setScale(
        1280.f / menuBgTexture.getSize().x,
        720.f / menuBgTexture.getSize().y
    );

    // ===== BUTTON TEXTURES =====
    sf::Texture newGameTexture, loadTexture, settingsTexture, quitTexture;

    if (!newGameTexture.loadFromFile("img/menu/newgame.png")) return -1;
    if (!loadTexture.loadFromFile("img/menu/load.png")) return -1;
    if (!settingsTexture.loadFromFile("img/menu/setting.png")) return -1;
    if (!quitTexture.loadFromFile("img/menu/quit.png")) return -1;

    // ===== BUTTON SPRITES =====
    sf::Sprite newGameBtn, loadBtn, settingsBtn, quitBtn;

    newGameBtn.setTexture(newGameTexture);
    loadBtn.setTexture(loadTexture);
    settingsBtn.setTexture(settingsTexture);
    quitBtn.setTexture(quitTexture);

    // ===== POSITION ======
    sf::Vector2f buttonPositions[4] = {
        {450, 300},  // NEW GAME
        {700, 300},  // LOAD
        {450, 380},  // SETTINGS
        {700, 380}   // QUIT
    };

    newGameBtn.setPosition(buttonPositions[0]);
    loadBtn.setPosition(buttonPositions[1]);
    settingsBtn.setPosition(buttonPositions[2]);
    quitBtn.setPosition(buttonPositions[3]);

    // ===== ARRAY BUTTON =====
    sf::Sprite* buttons[4] = {
        &newGameBtn,
        &loadBtn,
        &settingsBtn,
        &quitBtn
    };

    int selectedIndex = 0;

    // ===== SELECTOR  =====
    sf::RectangleShape selector;
    selector.setFillColor(sf::Color::Transparent);
    selector.setOutlineColor(sf::Color::Yellow);
    selector.setOutlineThickness(3.f);

    // SIZE YELLOW REC
    float btnWidth = 180;
    float btnHeight = 50;

    // ===== GAME LOOP =====
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {

                // ===== MOVE =====
                if (event.key.code == sf::Keyboard::Right) {
                    if (selectedIndex % 2 == 0) selectedIndex++;
                }
                else if (event.key.code == sf::Keyboard::Left) {
                    if (selectedIndex % 2 == 1) selectedIndex--;
                }
                else if (event.key.code == sf::Keyboard::Up) {
                    if (selectedIndex >= 2) selectedIndex -= 2;
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    if (selectedIndex <= 1) selectedIndex += 2;
                }

                // ===== ENTER =====
                if (event.key.code == sf::Keyboard::Enter) {
                    switch (selectedIndex) {
                    case 0:
                        std::cout << "NEW GAME\n";
                        break;
                    case 1:
                        std::cout << "LOAD\n";
                        break;
                    case 2:
                        std::cout << "SETTINGS\n";
                        break;
                    case 3:
                        window.close();
                        break;
                    }
                }
            }
        }

        // ===== DRAW =====
        window.clear();
        window.draw(menuBgSprite);

        // ===== SELECTOR =====
        selector.setSize(sf::Vector2f(btnWidth, btnHeight));
        selector.setPosition(buttonPositions[selectedIndex].x + 10.f, buttonPositions[selectedIndex].y);
        window.draw(selector);

        // ===== BUTTON =====
        for (int i = 0; i < 4; i++) {
            window.draw(*buttons[i]);
        }

        window.display();
    }

    return 0;
}
