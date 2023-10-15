#ifndef GREETER_H
#define GREETER_H

#include <iostream>
#include <string>
#include "Recipe_db.h"
#include "Plan_manager.h"

using namespace std;

// interacts with the user and manages the main menu.
class Greeter {
private:
    Recipe_db recipe_database; // recipe database.
    Plan_manager plan_manager; // plan manager.
    string recipedb_filename; // file name for recipe_db.
    string plan_filename; // file name for plan.

public:
    Greeter(string recipedb_file, string planfile); // constructor with two filenames for recipes and plans. make Recipe_db, Plan_manager objects by using arguments.

    void display_main_menu(); // display the main menu options.
    void process_choice(int choice); // process the user's choice.
    void manage_recipe_database(); // submenu for managing recipe database.
    void manage_plans(); // submenu for managing plans.
    int input_menu(); // get input for process_choice method.
    
    // methods related to recipe_db
    void search_recipe_by_grocery(); // search recipe based on grocery. input is received inside the method.
    void search_recipe_by_name(); // search recipe by its name. input is received inside the method.
    void display_all_recipes(); // display all the recipes.
    void add_new_recipe(); // add a new recipe to the database. input is received inside the method.
    void update_existing_recipe(string filename); // update existing recipes in database to file.
    void delete_recipe_by_name(string recipe_name); // delete a recipe in database. if recipe delete in database, it should also delete in meal.
    // so, this method first delete recipe in meal (check all dates in plan) and delete recipe in database.

    // methods related to plan
    void search_date_in_plan(); // search date by using format("yyyy-mm-dd"). input is received inside the method.
    void search_date_by_name(); // search date by its name (ex> "Yunjae's birthday!" or just "2023-10-14"). input is received inside the method.
    void display_plan(); //display all details in plan.
    void display_all_date_name(); // display all date_name in plan.
    void display_plan_for_a_date(); // display meal plan for a specific date
    void delete_date_by_name(string date_name); // delete date in plan. 
    void update_existing_plan(string filename); // update an existing plan to file.
    
    void show_help(); // display help to the user
};

#endif
