#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

class Fenetre {
    public:
        Fenetre() {
            if(!chargerSprites()){
                std::cout << "erreur sprites" << std::endl;
                return;
            }
            render();
        }

    private:
        sf::RenderWindow fen;
        sf::Texture sprites[12];
        std::map<char, sf::Sprite> piecesSprites;

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

                dessineGame();

                fen.display();
            }
        }

        bool chargerSprites(){

            std::string ordrePiece = "PpRrNnFfQqKk";

            std::string nomFichiers[12] = {
                "/home/airfiel/Documents/code/cpp/Echecs-cpp/sprites/Pw.png", "/home/airfiel/Documents/code/cpp/Echecs-cpp/sprites/Pb.png",
                "/home/airfiel/Documents/code/cpp/Echecs-cpp/sprites/Rw.png", "/home/airfiel/Documents/code/cpp/Echecs-cpp/sprites/Rb.png",
                "/home/airfiel/Documents/code/cpp/Echecs-cpp/sprites/Nw.png", "/home/airfiel/Documents/code/cpp/Echecs-cpp/sprites/Nb.png",
                "/home/airfiel/Documents/code/cpp/Echecs-cpp/sprites/Fw.png", "/home/airfiel/Documents/code/cpp/Echecs-cpp/sprites/Fb.png",
                "/home/airfiel/Documents/code/cpp/Echecs-cpp/sprites/Qw.png", "/home/airfiel/Documents/code/cpp/Echecs-cpp/sprites/Qb.png",
                "/home/airfiel/Documents/code/cpp/Echecs-cpp/sprites/Kw.png", "/home/airfiel/Documents/code/cpp/Echecs-cpp/sprites/Kb.png",
            };

            for(int i=0; i<12; i++){
                if(!sprites[i].loadFromFile(nomFichiers[i])){
                    return false;
                }
                piecesSprites[ordrePiece[i]] = sf::Sprite(sprites[i]);
            }

            return true;
        }

        void dessinePlateau() {
            for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                    sf::RectangleShape rectangle(sf::Vector2f(90.f, 90.f));
                    (i+j)%2 == 0 ? rectangle.setFillColor(sf::Color (100, 100, 100)) : rectangle.setFillColor(sf::Color::White);
                    rectangle.setPosition(50 + (i*90), 40 + j*(90));
                    fen.draw(rectangle);
                }
            }
        }

        void dessinePieces(){
            std::string plateau[8] = {
                "rnfqkfnr", // Ligne des pièces noires
                "pppppppp", // Pions noirs
                "........", // Cases vides
                "........",
                "........",
                "........",
                "PPPPPPPP", // Pions blancs
                "RNFQKFNR"  // Ligne des pièces blanches
            };

            for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                    char piece = plateau[j][i];
                    if(piece != '.'){
                        sf::Sprite& sprite = piecesSprites[piece];
                        sprite.setPosition(50 + (i*90), 40 + j*(90));
                        sprite.setScale(90/sprite.getTexture()->getSize().x, 90/sprite.getTexture()->getSize().y);
                        fen.draw(sprite);
                    }
                }
            }
        }

        void dessineGame(){
            dessinePlateau();
            dessinePieces();
        }

        void FenetreMenu() {
        }
};
