#ifndef POKEDEX_H
#define POKEDEX_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


struct Pokemon {
    int dex_num;
    string name;
    string type;
    int num_moves;
    string* moves;
};


struct Pokedex {
    int num_pokemon;
    Pokemon* dex;
}; 

Pokemon* create_pokemons(int);
string* create_moves(int);
void populate_moves(string*, int, ifstream&);
void populate_pokemon(Pokemon&, int,ifstream&);
void populate_pokedex_dat(Pokedex&, ifstream&);
int display_options();
int search_add_quit();
string get_file_name();
void search_by_name_outputfile(Pokedex&, int);
void search_by_dex_num_outputfile(Pokedex&, int);
void search_by_type_outputfile(Pokedex&, int);
void choice_outputfile(Pokedex&, int);
void search_by_name_to_screen(Pokedex&, int);
void search_by_dex_num_to_screen(Pokedex&, int);
void search_by_type_to_screen(Pokedex&, int);
void choice_to_screen(Pokedex&, int);
string add_pokemon_new_name();
int add_pokemon_new_dex();
void delete_info(Pokedex&);

#endif
