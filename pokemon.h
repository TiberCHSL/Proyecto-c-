#include <iostream>
#include <stdlib.h>
#include <list>
using namespace std;

class Pokemon{
    private: //Declarar variables
        string name;
        string type;
        int level;
        int health;
        string attack[4];
        list <int> damage[4];
        list <int> uses[4];
    public: //Declarar metodos
        Pokemon(string name, string type, int level, int health, string attack[4], list <int> damage[4], list <int> uses[4]) { //Constructor
            name = name;
            type = type;
            level = level;
            health = health;
            attack = attack;
            damage = damage;
            uses = uses; 
            }

        void setHealth(int modify) {        //Getter y setter para variables privadas requeridas
        health = modify;
        }
        int getHealth() {
        return health;
        }
        string getName() {
            return name;
        }
        string getType() {
            return type;
        }
        string getAttack() {
            return attack;
        }
    
    
};
/*Pokemon::Pokemon(string name, string type, int level, int health, string attack, int damage, int uses){ //Constructor
    name = name;
    type = type;
    level = level;
    health = health;
    attack = attack;
    damage = damage;
    uses = uses;
} */