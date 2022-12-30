#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <pokemon.h>

using namespace std;


class Backpack{
    private:
        Pokemon pokemon;
        int potion_health;
        int super_potion_health;
    public:                         //Declarar metodos y variables publicas
        int potion_n, super_potion_n; // Cantidad de pociones disponibles
        Backpack(Pokemon pokemon, int potion_n, int potion_health, int super_potion_n, int super_potion_health); //declarar constructor
        void use(int select); 
        int getp_hp();
        int getsp_hp();
};

Backpack::Backpack(Pokemon pokemon, int potion_n, int potion_health, int super_potion_n, int super_potion_health){
    pokemon = pokemon;
    potion_n = 1;
    potion_health = 25;
    super_potion_n = 1;
    super_potion_health = 50;
}

int Backpack::getp_hp() {
    return potion_health;
}
int Backpack::getsp_hp() {
    return super_potion_health;
}
void Backpack::use(int select){
    select = select;
    if((select == 1) && (potion_n > 0))
    {
        cout << "\n\n\n\n\n\n\n\n\nHas usado una POCION!" << endl;
        cout << pokemon.getName() << " se ha curado " << getp_hp() << " de vida..." << endl;
        pokemon.setHealth(pokemon.getHealth()+getp_hp());
        cout << pokemon.getName() << " tiene " << pokemon.getHealth() << " de vida" << endl;
        potion_n = potion_n - 1;
        this_thread::sleep_for(chrono::seconds(3));
    }
    else if ((select == 1) && (potion_n == 0))
    {
        cout << "\n\n\n\n\n\n\n\n\n\nNo tienes mas POCIONES!" << endl;
        this_thread::sleep_for(chrono::seconds(3));
    }
    else if ((select == 2) && (super_potion_n > 0))
    {
        cout << "\n\n\n\n\n\n\n\n\nHaz usado una SUPERPOCION!" << endl;
        cout << pokemon.getName() << " se ha curado " << getsp_hp() << " de vida..." << endl;
        pokemon.setHealth(pokemon.getHealth()+getsp_hp());
        cout << pokemon.getName() << " tiene " << pokemon.getHealth() << " de vida" << endl;
        super_potion_n = super_potion_n - 1;
        this_thread::sleep_for(chrono::seconds(3));
    }
    else if ((select == 2) && (super_potion_n == 0))
    {
        cout << "\n\n\n\n\n\n\n\n\n\nNo tienes mas SUPERPOCIONES!" << endl;
        this_thread::sleep_for(chrono::seconds(3));
    }
    else
    {
        cout << "Ingrese una opcion valida!" << endl;
        this_thread::sleep_for(chrono::seconds(3));
    }
}
