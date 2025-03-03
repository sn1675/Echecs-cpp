#ifndef PLATEAU_H
#define PLATEAU_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <csignal>
#include <string>

#include "Text.h"

class Plateau{
    public:
        int tailleCase = 120;
        int taillePossiblePos = 60;
        int posPlatX = 50;
        int posPlatY = 70;


        std::string board[8] = {
            "rnfqkfnr", // Ligne des pièces noires
            "pppppppp", // Pions noirs
            "........", // Cases vides
            "........",
            "........",
            "........",
            "PPPPPPPP", // Pions blancs
            "RNFQKFNR"  // Ligne des pièces blanches
        };

        Plateau(){}

        void dessinePlateau(sf::RenderWindow& fen, Plateau& Plat, int xDep, int yDep) {
            for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                    sf::RectangleShape rectangle(sf::Vector2f(tailleCase + 0.f, tailleCase+ 0.f));
                    rectangle.setPosition(posPlatX + (i*tailleCase), posPlatY + j*(tailleCase));
                    if(i != yDep || j != xDep){
                        (i+j)%2 == 0 ? rectangle.setFillColor(sf::Color::White) : rectangle.setFillColor(colBlue);
                    } else {
                        rectangle.setFillColor(sf::Color::Yellow);
                    }
                    if(xDep != -1){
                        affichePossible(fen, Plat, xDep, yDep, rectangle);
                    }

                    fen.draw(rectangle);

                    //position des cases
                    if(i == 0){
                        Text t = Text(std::to_string(8 - j), posPlatX + (i * tailleCase), posPlatY + (j * tailleCase), j%2 == 0 ? colBlue : sf::Color::White);
                        t.drawText(fen);
                    }
                    if(j == 7) {
                        Text t = Text(std::string(1, static_cast<char>(i + 97)), posPlatX + (i * tailleCase) + tailleCase - 15, posPlatY + (j * tailleCase) + tailleCase - 25,
                                      i%2 == 0 ? sf::Color::White : colBlue);
                        t.drawText(fen);
                    }
                }
            }
        }

        void affichePossible(sf::RenderWindow& fen, Plateau& Plat, int xDep, int yDep, sf::RectangleShape rect){
            if(Plat.board[xDep][yDep] != '.'){
                switch (Plat.board[xDep][yDep]) {
                    case 'p':
                    case 'P':
                        checkPion(fen, Plat, xDep, yDep, rect);
                        break;

                    case 't':
                    case 'T':
                        checkTour(fen, Plat, xDep, yDep, rect);
                        break;

                    case 'n':
                    case 'N':
                        checkChavalier(fen, Plat, xDep, yDep, rect);
                        break;

                    case 'f':
                    case 'F':
                        checkFou(fen, Plat, xDep, yDep, rect);
                        break;

                    case 'q':
                    case 'Q':
                        checkDame(fen, Plat, xDep, yDep, rect);
                        break;

                    case 'k':
                    case 'K':
                        checkRoi(fen, Plat, xDep, yDep, rect);
                        break;
                }
            }
        }

        void checkPion(sf::RenderWindow& fen, Plateau& Plat, int xDep, int yDep, sf::RectangleShape rect){
            rect.setFillColor(sf::Color::Green);
            if(Plat.board[xDep][yDep] == 'P'){
                if(xDep == 6) {
                    rect.setPosition(posPlatX + (yDep*tailleCase), posPlatY + ((xDep-2)*tailleCase));
                    fen.draw(rect);
                }
                rect.setPosition(posPlatX + (yDep*tailleCase), posPlatY + ((xDep-1)*tailleCase));
                fen.draw(rect);

                if(Plat.board[xDep-1][yDep-1] != '.'){
                    rect.setPosition(posPlatX + ((yDep-1)*tailleCase), posPlatY + ((xDep-1)*tailleCase));
                    rect.setFillColor(sf::Color::Red);
                    fen.draw(rect);
                }
                if(Plat.board[xDep-1][yDep+1] != '.'){
                    rect.setPosition(posPlatX + ((yDep+1)*tailleCase), posPlatY + ((xDep-1)*tailleCase));
                    rect.setFillColor(sf::Color::Red);
                    fen.draw(rect);
                }
            } else {
                if(xDep == 1){
                    rect.setPosition(posPlatX + (yDep*tailleCase), posPlatY + ((xDep+2)*tailleCase));
                    fen.draw(rect);
                }
                rect.setPosition(posPlatX + (yDep*tailleCase), posPlatY + ((xDep+1)*tailleCase));
                fen.draw(rect);

                if(Plat.board[xDep+1][yDep+1] != '.'){
                    rect.setPosition(posPlatX + ((yDep+1)*tailleCase), posPlatY + ((xDep+1)*tailleCase));
                    rect.setFillColor(sf::Color::Red);
                    fen.draw(rect);
                }
                if(Plat.board[xDep+1][yDep-1] != '.'){
                    rect.setPosition(posPlatX + ((yDep-1)*tailleCase), posPlatY + ((xDep+1)*tailleCase));
                    rect.setFillColor(sf::Color::Red);
                    fen.draw(rect);
                }
            }
        }


        void checkTour(sf::RenderWindow& fen, Plateau& Plat, int xDep, int yDep, sf::RectangleShape rect){}

        void checkChavalier(sf::RenderWindow& fen, Plateau& Plat, int xDep, int yDep, sf::RectangleShape rect){}

        void checkFou(sf::RenderWindow& fen, Plateau& Plat, int xDep, int yDep, sf::RectangleShape rect){}

        void checkDame(sf::RenderWindow& fen, Plateau& Plat, int xDep, int yDep, sf::RectangleShape rect){}

        void checkRoi(sf::RenderWindow& fen, Plateau& Plat, int xDep, int yDep, sf::RectangleShape rect){}

    private:
        sf::Color colBlue = sf::Color (42, 113, 176);

};

#endif // PLATEAU_H
