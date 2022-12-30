#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <battle.h>
#include <pokemon.h>

using namespace std;

Pokemon select_pokemon(int player)
{
cout << "\n\n\n\t\t\t\tJUGADOR " << player << ":" << endl;
cout << "\n1.Charmander" << endl;
cout << "\n2.Bulbasaur" << endl;
cout << "\n3.Squirtle" << endl;

int select;
if (player == 1)
{
    cout << "\nIngrese el Pokemon que desea usar:";
    cin >> select;
}
else
{
    select = rand() % 3 + 1;
}

if (select == 1)
{
    return Pokemon("Charmander","Fuego",{"Ascuas","Colmillo Igneo","Lanzallamas","Pirotecnia"},{20,32,45,35},{5,3,2,3});
}
else if (select == 2)
{
    return Pokemon("Bulbasaur", "Planta", {"Latigo Cepa", "Hoja Afilada", "Bomba Germen", "Doble Filo"}, {20, 32, 40, 40}, 132);
}
else if (select == 3)
{
    return Pokemon{"Squirtle", "Agua", {"Pistola Agua", "Hidro Pulso", "Acua Cola", "Hidrobomba"}, {20, 32, 35, 45}, 132};
}
else
{
    cout << "Ingrese una opcion valida" << endl;
};


}

int main()
{
srand(time(NULL));

Pokemon pokemon1 = select_pokemon(1);
Pokemon pokemon2 = select_pokemon(2);

Battle batalla = {pokemon1, pokemon2};
batalla.play();

return 0;

}


