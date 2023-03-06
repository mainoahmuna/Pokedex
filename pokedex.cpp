/********************************************************************
 ** Program Filename: asm1.cpp
 ** Author: Mainoah-Zander Muna
 ** Date: 10/23/2022
 ** Description: Pokedex that takes a file with pokemon and allows user
 search through by type, name, or dex number. 
 ** Input: 
 ** Output
*********************************************************************/
#include <iostream>
#include <string>
#include <fstream>

#include "pokedex.h"

using namespace std;


/*********************************************************************
** Function: create_pokemons()
** Description: Returns a pointer that points to the array of pokemon.
** Parameters: an integer
** Pre-Conditions: There has to be a integer that is established. 
** Post-Conditions: the pokemon array is created
*********************************************************************/
Pokemon* create_pokemons(int size)
{
    Pokemon* ptr = new Pokemon[size];
    return ptr;    
}


/*********************************************************************
** Function: create_moves()
** Description: Creates a pointer pointing to an array depending 
on the number of moves a pokemon has.
** Parameters: integers
** Pre-Conditions: There needs to be an integer of number of moves. 
** Post-Conditions: An aray with number of pokemon moves.
*********************************************************************/
string* create_moves(int moves)
{
    string* ptr = new string[moves];
    return ptr;
}


/*********************************************************************
** Function: populate_moves()
** Description: Populates the moves array with the pokemons moves in 
the file.
** Parameters: string pointer, integer, and ifstream file
** Pre-Conditions: There has to be a string pointer established and an 
open input file.
** Post-Conditions: Ther array will have pokemon moves in it. 
*********************************************************************/
void populate_moves(string* moves, int size, ifstream& file)
{
    for (int i = 0; i < size; i++)
    {
        file >> moves[i];
    }
    
}

/*********************************************************************
** Function: populate_pokemon()
** Description: Populates the array of pokemon with pokemon from the 
file. 
** Parameters: Pokemon struct, integer, and input file
** Pre-Conditions: There has to be a pokemon struct established and an 
open input file.
** Post-Conditions: Ther pokemon struct will be populated with 
pokemon attributes from file. 
*********************************************************************/
void populate_pokemon(Pokemon& stats, int size, ifstream &inputfile)
{

    inputfile >> stats.dex_num >> stats.name >> stats.type >> stats.num_moves;
    stats.moves = create_moves(stats.num_moves);
    populate_moves(stats.moves, stats.num_moves, inputfile);
     
}

/*********************************************************************
** Function: populate_pokedex_data()
** Description: populate the pokedex struct with the total number of 
pokemon and populates the array of pokemon with pokemon. 
** Parameters: pokedex struct, and ifstream file
** Pre-Conditions: There has to be a pokedex struct established and an 
open input file.
** Post-Conditions: Ther array will have pokemon in it. 
*********************************************************************/
void populate_pokedex_dat(Pokedex &poke_encyclo , ifstream &inputfile)
{
    inputfile >> poke_encyclo.num_pokemon;
    poke_encyclo.dex = create_pokemons(poke_encyclo.num_pokemon);
    for (int i = 0; i < poke_encyclo.num_pokemon; i++)
    {
        populate_pokemon(poke_encyclo.dex[i],poke_encyclo.num_pokemon ,inputfile);
    }

}

/*********************************************************************
** Function: print_pokemon()
** Description: For testing to see if my pokemon are in the array
** Parameters: pokedex struct
** Pre-Conditions: a pokedex struct
** Post-Conditions: array will print to screen.
*********************************************************************/
void print_pokemon(Pokedex& poke_encyclo)
{
    for (int i = 0; i < poke_encyclo.num_pokemon; i++)
    {
        cout << "-----------" << endl;
        cout << poke_encyclo.dex[i].dex_num << " " << poke_encyclo.dex[i].name << " " << poke_encyclo.dex[i].type;
        cout << endl;
        for (int i = 0; i < poke_encyclo.dex->num_moves; i++)
        {
            cout << poke_encyclo.dex[i].moves[i] << " ";
        }
        cout << endl;
    }
    
}

/*********************************************************************
** Function: display_option()
** Description: Asks how the user would like the information displayed
and returns the option. 
** Parameters: none
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/
int display_options()
{
    int display;
    cout << "How would you like information displayed:" << endl;
    cout << "1: To the screen." << endl;
    cout << "2: To an output file" << endl;
    cin >> display;
    while (display != 1 && display != 2){
        cout << "Error not an option, please pick an option on screen..." << endl;
        cin >> display;
    }
    return display;
}

/*********************************************************************
** Function: search_add_quit()
** Description: Asks user how they would like to search. Returns 
the option chosen.
** Parameters: none
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/
int search_add_quit()
{
    int option;
    cout << "What would you like to do with pokedex:" << endl;
    cout << "1: Search by name" << endl;
    cout << "2: Search by dex number" << endl;
    cout << "3: Search by type " << endl;
    cout << "4: Add new Pokemon " << endl;
    cout << "5: Quit " << endl;
    cin >> option;
    while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5){

        cout << "Error not an option, please pick an option on screen..." << endl;
        cin >> option;
    }
    return option;
}

/*********************************************************************
** Function: get_file_name()
** Description:Get the name of file so it can be open. 
** Parameters: none
** Pre-Conditions:
** Post-Conditions: 
*********************************************************************/
string get_file_name()
{
    string file_name;
    cout << "Name of file:";
    cin >> file_name;
    return file_name;
}

/*********************************************************************
** Function: search_by_name_outputfile()
** Description: Searches through pokemon and writes to an output file 
the results.
** Parameters: Pokedex struct and integer
** Pre-Conditions: Struct must have allocated memory.
** Post-Conditions: Output file should have results.
*********************************************************************/
void search_by_name_outputfile(Pokedex& poke_encyclo, int size)
{
    string name;
    cout << "What name:";
    cin >> name;

    for (int i = 0; i < size; i++)
    {
        if (poke_encyclo.dex[i].name == name)
        {
            ofstream fileoutput;
            fileoutput.open("output.txt", ios::out | ios::app);
            fileoutput << "--------------" << endl;
            fileoutput <<  poke_encyclo.dex[i].dex_num << " " << poke_encyclo.dex[i].name << " " << poke_encyclo.dex[i].type << endl;
            for (int i = 0; i < poke_encyclo.dex->num_moves; i++)
            {
                fileoutput << poke_encyclo.dex[i].moves[i] << " ";
            }
            fileoutput << endl;
        }
    }
}

/*********************************************************************
** Function: search_by_dex_num_outputfile()
** Description: Searches through pokemon and writes to an output file 
the results.
** Parameters: Pokedex struct and integer
** Pre-Conditions: Struct must have allocated memory.
** Post-Conditions: Output file should have results.
*********************************************************************/
void search_by_dex_num_outputfile(Pokedex& poke_encyclo, int size)
{
    int dex_num;
    cout << "What dex number:";
    cin >> dex_num;

    for (int i = 0; i < size; i++)
    {
        if (poke_encyclo.dex[i].dex_num == dex_num)
        {
            ofstream fileoutput;
            fileoutput.open("output.txt", ios::out | ios::app);
            fileoutput << "--------------" << endl;
            fileoutput <<  poke_encyclo.dex[i].dex_num << " " << poke_encyclo.dex[i].name << " " << poke_encyclo.dex[i].type << endl;
            for (int i = 0; i < poke_encyclo.dex->num_moves; i++)
            {
                fileoutput << poke_encyclo.dex[i].moves[i] << " ";
            }
            fileoutput << endl;
        }
    }
}

/*********************************************************************
** Function: search_by_type_outputfile()
** Description: Searches through pokemon and writes to an output file 
the results.
** Parameters: Pokedex struct and integer
** Pre-Conditions: Struct must have allocated memory.
** Post-Conditions: Output file should have results.
*********************************************************************/
void search_by_type_outputfile(Pokedex& poke_encyclo, int size)
{
    string type;
    cout << "What type:";
    cin >> type;

    for (int i = 0; i < size; i++)
    {
        if (poke_encyclo.dex[i].type == type)
        {
            ofstream fileoutput;
            fileoutput.open("output.txt", ios::out | ios::app);
            fileoutput << "--------------" << endl;
            fileoutput <<  poke_encyclo.dex[i].dex_num << " " << poke_encyclo.dex[i].name << " " << poke_encyclo.dex[i].type << endl;
            for (int i = 0; i < poke_encyclo.dex->num_moves; i++)
            {
                fileoutput << poke_encyclo.dex[i].moves[i] << " ";
            }
            fileoutput << endl;
        }
    }
}

/*********************************************************************
** Function: choice_outputfile()
** Description: Searches depending on which option is chosen. 
** Parameters: Pokedex struct and integer
** Pre-Conditions: functions should be defined above.
** Post-Conditions: Output file should have results.
*********************************************************************/
void choice_outputfile(Pokedex& poke_encyclo, int option)
{
    if (option == 1)
    {
        search_by_name_outputfile(poke_encyclo, poke_encyclo.num_pokemon);
    }

    if (option == 2)
    {
        search_by_dex_num_outputfile(poke_encyclo,poke_encyclo.num_pokemon);
    }

    if (option == 3)
    {
        search_by_type_outputfile(poke_encyclo,poke_encyclo.num_pokemon);
    }

    if (option == 4)
    {
        /* code */
    } 
}

/*********************************************************************
** Function: search_by_name_to_screen()
** Description: Searches through pokemon and prints results on screen
** Parameters: Pokedex struct and integer
** Pre-Conditions: Struct must have allocated memory.
** Post-Conditions: Output file should be on screen.
*********************************************************************/
void search_by_name_to_screen(Pokedex& poke_encyclo, int size)
{

    string name;
    cout << "What name:";
    cin >> name;

    for (int i = 0; i < size; i++){
        if (poke_encyclo.dex[i].name == name)
        {
            cout << "--------------" << endl;
            cout << poke_encyclo.dex[i].dex_num << " " << poke_encyclo.dex[i].name << " " << poke_encyclo.dex[i].type;
            cout << endl;
            for (int i = 0; i < poke_encyclo.dex->num_moves; i++)
            {
                cout << poke_encyclo.dex[i].moves[i] << " ";
            }
            cout << endl;
            cout << "--------------";
            cout << endl;
        }
    }
}

/*********************************************************************
** Function: search_by_dex_num_to_screen()
** Description: Searches through pokemon and prints results on screen
** Parameters: Pokedex struct and integer
** Pre-Conditions: Struct must have allocated memory.
** Post-Conditions: Output file should be on screen.
*********************************************************************/
void search_by_dex_num_to_screen(Pokedex& poke_encyclo, int size)
{
    int num;
    cout << "What dex number:";
    cin >> num;

    for (int i = 0; i < size; i++){
        if (poke_encyclo.dex[i].dex_num == num)
        {
            cout << "--------------" << endl;
            cout << poke_encyclo.dex[i].dex_num << " " << poke_encyclo.dex[i].name << " " << poke_encyclo.dex[i].type;
            cout << endl;
            for (int i = 0; i < poke_encyclo.dex->num_moves; i++)
            {
                cout << poke_encyclo.dex[i].moves[i] << " ";
            }
            cout << endl;
            cout << "---------------";
            cout << endl;
        }
    }
}

/*********************************************************************
** Function: search_by_type_to_screen()
** Description: Searches through pokemon and prints results on screen
** Parameters: Pokedex struct and integer
** Pre-Conditions: Struct must have allocated memory.
** Post-Conditions: Output file should be on screen.
*********************************************************************/
void search_by_type_to_screen(Pokedex& poke_encyclo, int size)
{
    string type;
    cout << "What type:";
    cin >> type;

    for (int i = 0; i < size; i++){
        if (poke_encyclo.dex[i].type == type)
        {
            cout << "--------------" << endl;
            cout << poke_encyclo.dex[i].dex_num << " " << poke_encyclo.dex[i].name << " " << poke_encyclo.dex[i].type;
            cout << endl;
            for (int i = 0; i < poke_encyclo.dex->num_moves; i++)
            {
                cout << poke_encyclo.dex[i].moves[i] << " ";
            }
            cout << endl;
            cout << "--------------";
            cout << endl;
        }
    }
}

/*********************************************************************
** Function: add_pokemon_new_dex()
** Description: Asks user for the new pokemons new dex.
** Pre-Conditions: Must be a dex number.
** Post-Conditions: Returns dex number.
*********************************************************************/
int add_pokemon_new_dex()
{
    int new_dex;
    cout << "What is dex number of new pokemon: ";
    cin >> new_dex;
    return new_dex;
}

/*********************************************************************
** Function: add_pokemon_new_name()
** Description: Asks user for the new pokemons name.
** Pre-Conditions: Must be a string.
** Post-Conditions: Returns new pokemons name.
*********************************************************************/
string add_pokemon_new_name()
{
    string name;
    cout << "What is pokemons new name: ";
    cin >> name;
    return name;
}

/*********************************************************************
** Function: choice_outputfile()
** Description: Searches depending on which option is chosen. 
** Parameters: Pokedex struct and integer
** Pre-Conditions: functions should be defined above.
** Post-Conditions: screen should have results.
*********************************************************************/
void choice_to_screen(Pokedex& poke_encyclo, int option)
{
    if (option == 1)
    {
        search_by_name_to_screen(poke_encyclo, poke_encyclo.num_pokemon);
    }

    if (option == 2)
    {
        search_by_dex_num_to_screen(poke_encyclo,poke_encyclo.num_pokemon);
    }

    if (option == 3)
    {
        search_by_type_to_screen(poke_encyclo,poke_encyclo.num_pokemon);
    }

    if (option == 4)
    {
        /* code */
    } 
}

/*********************************************************************
** Function: delete_info()
** Description: Frees the memory allocated to the heap.
** Pre-Conditions: Memory must be allocated to the heap.
** Post-Conditions: Zero memory leaks.
*********************************************************************/
void delete_info(Pokedex& poke_encyclo)
{
   
    for (int i = 0; i < poke_encyclo.num_pokemon; i++)
    {
        delete[] poke_encyclo.dex[i].moves;
        poke_encyclo.dex[i].moves = NULL;
    }
    delete[] poke_encyclo.dex;
    poke_encyclo.dex = NULL;
    
}
