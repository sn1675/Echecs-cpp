#include <cstddef>
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

        void deplacerPiece(const std::string &depart, const std::string &arrive){
            auto [x1, y1] = convertirPosition(depart);
            auto [x2, y2] = convertirPosition(arrive);

            plateau[x2][y2].piece = plateau[x1][y1].piece;
            plateau[x2][y2].col = plateau[x1][y1].col;

            plateau[x1][y1].piece = '\0';
            plateau[x1][y1].col = AUCUNE;
        }

        int verifPosition(std::string pos){
            if(pos.size() != 4 ? 1 : 0){ return 0; }

            std::string c1 = std::string()+ pos[0] + pos[1];
            std::string c2 = std::string()+ pos[2] + pos[3];


            if(c1[0] < 'a' || c1[0] > 'h' || c1[1] < '1' || c1[1] > '8') { return 0; }
            if(c2[0] < 'a' || c2[0] > 'h' || c2[1] < '1' || c2[1] > '8') { return 0; }

            return 1;
        }

    private:
        std::vector<std::vector<Case>> plateau;

        int p[8][8];

        void initTab(){
            std::string ordrepieces = "TCFRDFCT";

            for(int i=2; i<6; i++){
                for(int j=0; j<8; j++){
                    plateau[i][j].pos = std::to_string('a'+ j) + std::to_string(8 - i);
                    plateau[i][j].piece = '\0';
                    plateau[i][j].col = AUCUNE;
                }
            }

            for(int i=0; i<8; i++){
                plateau[1][i].piece = 'P';
                plateau[1][i].col = NOIR;

                plateau[6][i].piece = 'P';
                plateau[6][i].col = BLANC;

                plateau[0][i].piece = ordrepieces[i];
                plateau[0][i].col = NOIR;

                plateau[7][i].piece = ordrepieces[i];
                plateau[7][i].col = BLANC;
            }
        }

        std::pair<int, int> convertirPosition(std::string pos){
            int x = 8 - (pos[1] - '0');
            int y = pos[0] - 'a';
            return {x, y};
        }
};
