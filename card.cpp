#include <string>

using namespace std;

class Card{
    private:
        string name;
        string type;
        int mv;

    public:
        Card(string nameInput, string typeInput, int mvInput){
            name = nameInput;
            type = typeInput;
            mv = mvInput;
        }

        string getName(){
            return name;
        }

        string getType(){
            return type;
        }

        int getMv(){
            return mv;
        }

        bool isTurnOnePlay(){
            if(mv == 1 && name != "Skewer the Critics") return true;
            return false;
        }
};