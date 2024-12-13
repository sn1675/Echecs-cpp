#include <SFML/Graphics.hpp>
#include <iostream>

class Fenetre {
    public:
        Fenetre() {
            render();
        }

    private:
        sf::RenderWindow fen;

        void render() {
            sf::VideoMode mode = sf::VideoMode::getDesktopMode();
            fen.create(sf::VideoMode(1200, 800), "airChess");

            bool pleinEcran = false;
            while (fen.isOpen()) {
                sf::Event event;
                while (fen.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        fen.close();
                    }

                    if (event.type == sf::Event::KeyPressed) {
                        if (event.key.code == sf::Keyboard::F11) {
                            pleinEcran = !pleinEcran;
                            fen.close();
                            if (pleinEcran) {
                                fen.create(mode, "airChess", sf::Style::Fullscreen);
                            } else {
                                fen.create(sf::VideoMode(800, 800), "airChess");
                            }
                        }
                    }
                }
                fen.clear(sf::Color::Black);

                dessine();

                fen.display();
            }
        }

        void dessine() {
            sf::RectangleShape rectangle(sf::Vector2f(200.f, 100.f));
            rectangle.setFillColor(sf::Color::Green);
            rectangle.setPosition(100, 100);
            fen.draw(rectangle);
        }

        void FenetreMenu() {
        }
};
