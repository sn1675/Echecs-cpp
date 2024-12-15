#ifndef FENETRE_H
#define FENETRE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Piece.h"
#include "Plateau.h"

class Fenetre {
    public:
        sf::RenderWindow fen;
        Plateau Plat;
        Piece P;

        Fenetre() {
            render();
        }

    private:

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
                                fen.create(sf::VideoMode(1200, 800), "airChess");
                            }
                        }
                    }
                }

                fen.clear(sf::Color (45, 45, 45));

                dessineGame();

                fen.display();
            }
        }

        void dessineGame(){
            Plat.dessinePlateau(fen);
            P.dessinePieces(fen, Plat);
        }

        void FenetreMenu() {
        }
};

#endif // FENETRE_H
