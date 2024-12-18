#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <map>

#include "Plateau.h"

class Piece{
    public:


        Piece(){
            if(!chargerSprites()){
                std::cout << "erreur sprites" << std::endl;
                return;
            }
        }

        void dessinePieces(sf::RenderWindow& fen, const Plateau& Plat){
            for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                    char piece = Plat.board[j][i];
                    if(piece != '.'){
                        sf::Sprite& sprite = piecesSprites[piece];
                        sprite.setPosition(Plat.posPlatX + (i*Plat.tailleCase), Plat.posPlatY + j*(Plat.tailleCase));

                        sprite.setScale((float) Plat.tailleCase/sprite.getTexture()->getSize().x + 0.45,
                                        (float) Plat.tailleCase/sprite.getTexture()->getSize().y +0.45);
                        fen.draw(sprite);
                    }
                }
            }
        }

    private:
        std::string ordrePiece = "PpRrNnFfKkQq";

        sf::Texture sprites[12];
        std::map<char, sf::Sprite> piecesSprites;


        bool chargerSprites(){

            std::string nomFichiers[12] = {
                "./sprites/Pw.png", "./sprites/Pb.png",
                "./sprites/Rw.png", "./sprites/Rb.png",
                "./sprites/Nw.png", "./sprites/Nb.png",
                "./sprites/Fw.png", "./sprites/Fb.png",
                "./sprites/Kw.png", "./sprites/Kb.png",
                "./sprites/Qw.png", "./sprites/Qb.png",
            };

            for(int i=0; i<12; i++){
                if(!sprites[i].loadFromFile(nomFichiers[i])){
                    return false;
                }
                piecesSprites[ordrePiece[i]] = sf::Sprite(sprites[i]);
            }

            return true;
        }
};

#endif // PIECE_H
