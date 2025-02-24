#ifndef PLATEAU_H
#define PLATEAU_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>

#include "Text.h"

class Plateau{
    public:
        int tailleCase = 120;
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

        void dessinePlateau(sf::RenderWindow& fen) {
            for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                    sf::RectangleShape rectangle(sf::Vector2f(tailleCase + 0.f, tailleCase+ 0.f));
                    (i+j)%2 == 0 ? rectangle.setFillColor(sf::Color::White) : rectangle.setFillColor(colBlue);
                    rectangle.setPosition(posPlatX + (i*tailleCase), posPlatY + j*(tailleCase));
                    fen.draw(rectangle);
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

    private:
        sf::Color colBlue = sf::Color (42, 113, 176);

};

#endif // PLATEAU_H
