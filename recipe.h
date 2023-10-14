#ifndef RECIPE_H
# define RECIPE_H
# include <string>
# include <vector>
#include <iostream>

using namespace std;

// infomation of a single recipe.
class Recipe {
private:
    // variables to store recipe details.
    string recipe_name; // recipe name
    vector<pair<string, string>> grocery; // list of grocerys and their amounts.
    string cooking_method; // cooking instructions.
    string user_notes; // user notation
    int cooking_time; // how much time it takes to cook. if time == -1, it means we don't know how long it takes to cook.

public:
    Recipe(string r_name); // give just the recipe name.
    Recipe(string r_name, vector<pair<string, string>> gro_name, string cook_method); // constructor with name, grocerys list, and cooking method. but don't know how much time it takes. time = -1;
    Recipe(string r_name, vector<pair<string, string>> gro_name, string cook_method, string notes); //give all variables. but don't know how much time it takes. time = -1;
    Recipe(string r_name, vector<pair<string, string>> gro_name, string cook_method, int cook_time); 
    Recipe(string r_name, vector<pair<string, string>> gro_name, string cook_method, string notes, int cook_time); //give all variables.

    //setter getter
    void set_recipe_name(string name); // set the name of the recipe.
    string get_recipe_name(); // get the name of the recipe.
    
    void add_grocery_item(string gorcery_name, string quantity); // add an grocery and its amount to the recipe.
    vector<pair<string, string>> get_grocery(); // get the full list of grocery and their amounts.
    void remove_grocery_item(string gorcery_name); // delete an grocery and its amount to the recipe.
    
    void set_cooking_method(string method); // set cooking instructions.
    string get_cooking_method(); //get cooking instructions.
    
    void set_user_notes(string notes); // set the user's notes.
    string get_user_notes(); // get the user's notes.

    void set_cooking_time(int cook_time); // set cooking time.
    int get_cooking_time(); // get cooking time.
    
    void display_recipe(); // display the full recipe details.
    //display_form:
    /*
    --------------------------------------------------------------------------------
    || Recipe Name: recipe_name ||
    Grocery Items:
    - grocery_name1: amout
    - grocery_name2: amout
    ...
    Cooking Method:
    ...
    Cooking time: ~ hour ~ min
    Notes:
    ...
    --------------------------------------------------------------------------------
    */
};

#endif
