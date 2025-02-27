#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>

class Text {
    public:

        Text(const std::string& texte, float posX, float posY, sf::Color col = sf::Color::White, int size = 20) {
            if(!font.loadFromFile("./fonts/OpenSans-Bold.ttf")){ std::cerr << "Erreur de chargement des polices" << std::endl; };


            t.setString(texte);
            t.setCharacterSize(size);
            t.setFillColor(col);
            t.setFont(font);
            t.setPosition(posX, posY);
        }

        void changeposText(float posX, float posY){
            t.setPosition(posX, posY);

        }

        void drawText(sf::RenderWindow& fen){
            fen.draw(t);
        }

    private:
        sf::Font font;
        sf::Text t;
};

#endif
