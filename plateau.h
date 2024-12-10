#include <iostream>
#include <vector>
#include <string>

typedef struct{
    std::string pos;
    char piece;
} Case ;

class Plateau {
    public:
        Plateau(){
            plateau.resize(8, std::vector<Case>(8));
        }

        void afficher(){
            for(auto& ligne : plateau){
                for(auto& c : ligne){
                    std::cout << c.piece;
                }
            }
        }

    private:
        std::vector<std::vector<Case>> plateau;

        void initTab(){

        }
};
