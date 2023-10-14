#ifndef MEAL_H
#define MEAL_H

#include <string>
#include <vector>
#include <iostream>
#include "Recipe.h"
#include "Recipe_db.h"

using namespace std;

// infomation of a single Meal.
class Meal {
private:
    string meal_name; //name of the meal. example> breakfast, lunch, dinner, snack or a custom name.
    int num_people;  // number of people for the meal
    int prepare_time; // time taken to prepare a meal.
    vector<Recipe> recipes;  // recipes for the meal
    Recipe_db* recipe_db;  // pointer to the recipe database to use.

public:
    // constructors
    Meal(Recipe_db* db);// meal_name = ""; num_people = 1; db is Recipe_db object to use.
    Meal(string meal_name, Recipe_db* db); // num_people = 1;
    Meal(string meal_name, int number_people, Recipe_db* db); // constructor with meal_name, number of people, Recipe_db object to use.
    
    void set_other_recipe_db(Recipe_db* recipe_db); // change the recipe database to use.

    void set_num_people(int number_people); // set number of people for the meal
    int get_num_people(); // get number of people for the meal

    void set_prepare_time(int pre_time); // set all time to make meal.
    int get_prepare_time(); // get all time to make meal.
    void calculate_prepare_time(); // calculate all time to make meal by recipes. executes whenever a recipe is added or subtracted.

    void set_meal_name(string meal_name); // set name of the meal.
    string get_meal_name(); // get name of the meal.

    int check_already_in_meal(string recipe_name); // if there is a recipe already in meal -> return 1 // else return 0

    void select_and_add_recipe_from_db(string recipe_name);  // selects a recipe from the database and adds to the meal
    void remove_recipe_in_meal(string recipe_name); // removes a recipe from the meal by its name.

    void print_gorcery_list(vector<pair<string, string>> grocery); //print all necessory gorcery list for meal.
    vector<pair<string, string>> generate_grocery_list(); // generates and return a combined grocery list for the entire meal, considering all recipes and number of people for meal.

    void display_recipe_name_in_meal(); // display all recipes name in meal;
    void display_meal(); // display details of the meal including all recipes.
};

#endif
