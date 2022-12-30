#include <iostream>
// #include <stdlib.h>
#include <time.h>
#include <pokemon.h>
#include <backpack.h>
#include <chrono>
#include <thread>
using namespace std;

class Battle{
    // INICIALIZAR ATRIBUTOS
    private:
        Pokemon pokemon_1;
        Pokemon pokemon_2;
        int turn;
    // INICIALIZAR METODOS
    public:
        Battle(Pokemon,Pokemon);
        bool miss_attack(Pokemon);
        void attack(Pokemon, Pokemon, int); //tipo de variable que es, en este caso es de la clase Pokemon
        void play();
};

//CONSTRUCTOR
Battle::Battle(Pokemon pokemon_1, Pokemon pokemon_2){
    pokemon_1 = pokemon_1;
    pokemon_2 = pokemon_2;
    turn = 0;
}

//METODOS
bool Battle::miss_attack(Pokemon _pokemon){
    srand(time(NULL));
    int miss_probability = rand()%10;
    bool miss = false;
    if(miss_probability<2){
        cout<<_pokemon.getName()<<"fallo el ataque"<<endl;
        bool miss = true;
    }
    return miss;
}

void Battle::attack(Pokemon attacker, Pokemon defender, int selector){
    
    int damage_selector = selector - 1;
    int damage = attacker.damage;{damage_selector;};
    string attack_name = attacker.attack;{damage_selector;};

    if (attacker.getType() == defender.getType()) {
    damage = damage / 2;
    }
    else if ((attacker.getType() == "Fuego") && (defender.getType() == "Planta")) {
        damage = damage * 2;
    }
    else if ((attacker.getType() == "Fuego") && (defender.getType() == "Agua")) {
        damage = damage / 2;
    }
    else if ((attacker.getType() == "Agua") && (defender.getType() == "Planta")) {
        damage = damage / 2;
    }
    else if ((attacker.getType() == "Agua") && (defender.getType() == "Fuego")) {
        damage = damage * 2;
    }
    else if ((attacker.getType() == "Planta") && (defender.getType() == "Fuego")) {
        damage = damage / 2;
    }
    else if ((attacker.getType() == "Planta") && (defender.getType() == "Agua")) {
        damage = damage * 2;
    }

    defender.setHealth(defender.getHealth()-damage);
    cout<<attacker.getName()<<"uso"<<attack_name<<"!"<<endl;
    cout<<"Causo"<<damage<<"de daño a "<<defender.getName()<<endl;

    if (defender.getHealth() <= 0) {
        cout << "\n\n\n\n\n\n\n\n\n\n" << defender.getName() << " fue derrotado!" << endl;
    }
    else {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n" << defender.getName() << " tiene " << defender.getHealth() << " de vida" << endl;
    }

    turn += 1;
}
void Battle::play() {
    Backpack backpack_1 = Backpack(pokemon_1);
    Backpack backpack_2 = Backpack(pokemon_2);
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n¡A luchar contra el campeon GARY!" << endl;
        this_thread::sleep_for(chrono::seconds(3));
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << pokemon_1.getName() << "¡Es el POKEMON enviado por GARY!" << endl;
        this_thread::sleep_for(chrono::seconds(3));
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n¡Adelante" << pokemon_1.getName() << "!" << endl;
        this_thread::sleep_for(chrono::seconds(3));
        while ((pokemon_1.getHealth() > 0) && (pokemon_2.getHealth() > 0)) {
            int i = 0;
            if((turn%2) == 0 and (turn!=-1)) {
                i = 0;
                while(i==0) {
                    cout << "\n\n\n\n\n\n\n\n\nEs el turno de" << pokemon_1.name << "!" << endl;
                    cout << "\n\n\n\n\n\n\n\n\n" << pokemon_1.getName() << endl;
                    cout << "HP =" << pokemon_1.getHealth() << endl;
                    cout << "----------------MENU----------------" << endl;
                    cout << "\n1 = LUCHA" << endl;
                    cout << "\n2 = MOCHILA" << endl;
                    cout << "\n3 = HUIDA" << endl;
                    int option;
                    cout << "¿Que deberia hacer" << pokemon_1.getName() << "?: " << endl;
                    cin >> option;
                    if(option == 1) {
                        cout << "\n\n\n\n\n\n\n\n\n" << pokemon_1.getName() << endl;
                        cout << "HP =" << pokemon_1.getHealth() << endl;                                                            //LUCHAR
                        cout << "----------------MENU ATAQUES----------------" << endl;
                        cout << "1" << pokemon_1.getAttack();{0} ({self.pokemon_1.damage[0]})\t\t\t2.{self.pokemon_1.attack[1]} ({self.pokemon_1.damage[1]})")
                        print(f"disponibles: {self.pokemon_1.uses[0]}\t\t\tdisponibles: {self.pokemon_1.uses[1]}")
                        print(f"\n3.{self.pokemon_1.attack[2]} ({self.pokemon_1.damage[2]})\t\t\t4.{self.pokemon_1.attack[3]} ({self.pokemon_1.damage[3]})")
                        print(f"disponibles: {self.pokemon_1.uses[2]}\t\t\tdisponibles: {self.pokemon_1.uses[3]}")
                        select = int(input("\nSeleccione el ataque a usar: ")) }

                    }
                }
        }
}