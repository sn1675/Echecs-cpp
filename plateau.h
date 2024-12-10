#include <iostream>
#include <vector>
#include <string>

enum Couleur{
    AUCUNE,
    BLANC,
    NOIR
};

typedef struct{
    std::string pos;
    char piece;
    Couleur col;
} Case ;

class Plateau {
    public:
        Plateau(){
            plateau.resize(8, std::vector<Case>(8));
            initTab();
        }

        void afficher(){
            for(auto& ligne : plateau){
                for(auto& c : ligne){
                    if(c.col == BLANC){
                        std::cout << "\033[37m" << c.piece << "\033[0m ";
                    } else {
                        std::cout << (c.piece == '\0' ? '.': c.piece) << " ";
                    }
                }
                std::cout << std::endl;
            }
        }

    private:
        std::vector<std::vector<Case>> plateau;

        void initTab(){
            std::string colonnes = "abcdefgh";
            for(int i=0; i<8; i++){
                for(int j=0; j<8; j++){
                    plateau[i][j].pos = colonnes[j] + std::to_string(8 - i);
                    plateau[i][j].piece = '\0';
                    plateau[i][j].col = AUCUNE;
                }
            }
            // init Pions (P)
            for(int i=0; i<8; i++){
                plateau[1][i].piece = 'P';
                plateau[1][i].col = NOIR;

                plateau[6][i].piece = 'P';
                plateau[6][i].col = BLANC;
            }

            // init tour (T)
            plateau[0][0].piece = 'T';
            plateau[0][0].col = NOIR;
            plateau[0][7].piece = 'T';
            plateau[0][7].col = NOIR;

            plateau[7][0].piece = 'T';
            plateau[7][0].col = BLANC;
            plateau[7][7].piece = 'T';
            plateau[7][7].col = BLANC;

            //init Chavaliers (C)
            plateau[0][1].piece = 'C';
            plateau[0][1].col = NOIR;
            plateau[0][6].piece = 'C';
            plateau[0][6].col = NOIR;

            plateau[7][1].piece = 'C';
            plateau[7][1].col = BLANC;
            plateau[7][6].piece = 'C';
            plateau[7][6].col = BLANC;

            // init Fous (F)
            plateau[0][2].piece = 'F';
            plateau[0][2].col = NOIR;
            plateau[0][5].piece = 'F';
            plateau[0][5].col = NOIR;

            plateau[7][2].piece = 'F';
            plateau[7][2].col = BLANC;
            plateau[7][5].piece = 'F';
            plateau[7][5].col = BLANC;

            // init Dame (D)
            plateau[0][4].piece = 'D';
            plateau[0][4].col = NOIR;

            plateau[7][4].piece = 'D';
            plateau[7][4].col = BLANC;

            // init Roi (R)
            plateau[0][3].piece = 'R';
            plateau[0][3].col = NOIR;

            plateau[7][3].piece = 'R';
            plateau[7][3].col = BLANC;
        }
};
