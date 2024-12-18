#ifndef FENETRE_H
#define FENETRE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>

#include "Piece.h"
#include "Plateau.h"

class Fenetre {
    public:
        sf::RenderWindow fen;
        Plateau Plat;
        Piece P;

        Fenetre(): clicDepart(-1, -1) {
            render();
        }

    private:

        sf::Vector2i clicDepart;

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

                    switchToGrandEgrand(event, mode, pleinEcran);

                    click(event);
                }

                fen.clear(sf::Color (45, 45, 45));

                dessineGame();

                fen.display();
            }
        }

        void switchToGrandEgrand(sf::Event event, sf::VideoMode mode, bool pleinEcran){
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F11) {
                pleinEcran = !pleinEcran;
                fen.close();
                if (pleinEcran) {
                    fen.create(mode, "airChess", sf::Style::Fullscreen);
                } else {
                    fen.create(sf::VideoMode(1200, 800), "airChess");
                }
            }

        }

        void click(sf::Event event){
            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
                int x = (event.mouseButton.x - Plat.posPlatX) / Plat.tailleCase;
                int y = (event.mouseButton.y - Plat.posPlatY) / Plat.tailleCase;

                if (x >= 0 && x < 8 && y >= 0 && y < 8) {
                    if (clicDepart.x == -1) {
                        clicDepart = sf::Vector2i(x, y);

                    } else {
                        int xArrivee = x;
                        int yArrivee = y;

                        P.deplacerPiece(Plat, clicDepart.x, clicDepart.y, xArrivee, yArrivee);
                        clicDepart = sf::Vector2i(-1, -1);
                    }
                }
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
