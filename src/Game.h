#include <iostream>
#include "Plateau.h"

class Game {
    public:
        Game(){
            run();
        }

    private:
        bool r = true;
        Plateau P = Plateau();

        std::string choix;

        void run(){

            while (r) {
                P.afficher();

                std::cout << "Choisisez un mouvement [Dep][Arrive] :"; std::cin >> choix;

                P.deplacerPiece(std::string() + choix[0]+choix[1], std::string() + choix[2]+choix[3]);
            }

        }
};
