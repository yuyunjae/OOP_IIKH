#ifndef RECIPE_DB_H
#define RECIPE_DB_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Recipe.h"

using namespace std;

// manage a list of recipes. (collection of recipe data)
class Recipe_db {
private:
    vector<Recipe> recipe_list; // store multiple recipes
    string db_filename; // name of the file to save and load recipes

public:
    Recipe_db(); // default constructor. filename = "recipe.txt";
    Recipe_db(string filename); // constructor with filename (file -> save and load recipes.) example> yunjae_recipe.txt

    int check_isvaild_recipe_name(string recipe_name); // if there is a recipe with the same name in the database -> return 0 // else return 1

    void add_recipe(Recipe recipe); // add a new recipe to database(recipe_list).
    void add_recipe(string recipe_name, vector<pair<string, string>> grocery, string cooking_method); // create a recipes by using parameter and add it to database.
    void add_recipe(string recipe_name, vector<pair<string, string>> grocery, string cooking_method, string user_notes); // create a recipes by using parameter and add it to database.
    void add_recipe(string r_name, vector<pair<string, string>> gro_name, string cook_method, int cook_time); 
    void add_recipe(string r_name, vector<pair<string, string>> gro_name, string cook_method, string notes, int cook_time); //give all variables.

    void print_all_recipe_name(); // print all recipe_name in database
    void display_all_recipes(); // print all recipes with details in database.


    void modify_recipe_name(string old_name, string new_name); // modify recipe name
    void modify_recipe_cooking_method(string recipe_name, string new_method); // modify cooking method
    void modify_recipe_notes(string recipe_name, string new_notes); // modify cooking method
    void modify_recipe_cooking_time(string recipe_name, int cook_time); // modify cooking time
    void add_grocery_to_recipe(string recipe_name, string grocery, string quantity); // add grocery
    void remove_grocery_from_recipe(string recipe_name, string grocery); // remove grocery
    
    void remove_recipe(string recipe_name); // remove a recipe by name

    Recipe* find_recipe(string recipe_name); // find a recipe by name
    vector<Recipe> find_recipes_by_grocery(vector<string> gro_name); // find recipes by grocery name     
    // receives one or more grocery items as parameters,
    // find recipes that use all entered grocery items from the database, and return those recipes.
    
    void load_from_file(); // load recipes from a file
    // same as save_to_file. we can parsing recipes and its details, and then, store recipes in recipe_list.

    void save_to_file(); // save recipes to a file
    // save recipes like this. we can distinguish details using '----------' '\n' ':', ',' '@' '#'.
    //time -> int value. how much time it takes to cook. (min)
    /*
    ----------\n
    recipe_name1\n
    grocery_name1-1: amout, grocery_name1-2: amout, ...\n
    time\n
    @(Cooking Method)\n
    @(Cooking Method)\n
    @(Cooking Method)\n
    #(Notes)\n
    #(Notes)\n
    #(Notes)\n
    ----------\n
    recipe_name2\n
    grocery_name2-1: amout, grocery_name2-2: amout, ...\n
    time\n
    @(Cooking Method)\n
    @(Cooking Method)\n
    @(Cooking Method)\n
    @(Cooking Method)\n
    #(Notes)\n
    #(Notes)\n
    */
};

#endif
