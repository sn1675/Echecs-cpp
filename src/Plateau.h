#ifndef PLATEAU_H
#define PLATEAU_H

#include <SFML/Graphics.hpp>

class Plateau{
    public:
        int tailleCase = 90;
        int posPlatX = 50;
        int posPlatY = 40;

        std::string board[8] = {
            "rnfkqfnr", // Ligne des pièces noires
            "pppppppp", // Pions noirs
            "........", // Cases vides
            "........",
            "........",
            "........",
            "PPPPPPPP", // Pions blancs
            "RNFKQFNR"  // Ligne des pièces blanches
        };


        Plateau(){}


        void dessinePlateau(sf::RenderWindow& fen) {
            for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                    sf::RectangleShape rectangle(sf::Vector2f(tailleCase + 0.f, tailleCase+ 0.f));
                    (i+j)%2 == 0 ? rectangle.setFillColor(colBlue) : rectangle.setFillColor(sf::Color::White);
                    rectangle.setPosition(posPlatX + (i*tailleCase), posPlatY + j*(tailleCase));
                    fen.draw(rectangle);
                }
            }
        }

    private:
        sf::Color colBlue = sf::Color (42, 113, 176);

};

#endif // PLATEAU_H
