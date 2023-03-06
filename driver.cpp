#include <iostream>
#include <string>
#include <fstream>

#include "pokedex.h"

using namespace std;

int main()
{
    //Creates Pokedex Struct
    Pokedex original;

    //gets file name.
    string file_name = get_file_name();

    //opening file and gets number 
    ifstream inputfile;
    inputfile.open(file_name.c_str(), ios::in);
    if (!inputfile.is_open()){
        cout << "Error opening the file..." << endl;
        return 1;
    }
    
    //Populate the pokedex and create the pokemon.
    populate_pokedex_dat(original, inputfile);

    //ask for display option 
    int display = display_options();

    //ask for what they want to do with pokedex.
    int search_or_add_or_quit = search_add_quit();

    //testing array
    //print_pokemon(original);

    //Execute search for screen display
    if (display == 1){
        while(search_or_add_or_quit !=5)
        {
            choice_to_screen(original,search_or_add_or_quit);
            search_or_add_or_quit = search_add_quit();
        }
    }

    //Execute search for outputfile
    if (display == 2)
    {
        while(search_or_add_or_quit != 5){
            choice_outputfile(original, search_or_add_or_quit);
            search_or_add_or_quit = search_add_quit();
        }
    }

    //delete arrays
    delete_info(original);

    return 0;
}