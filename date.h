#ifndef DATE_H
#define DATE_H

#include <string>
#include <vector>
#include <iostream>
#include "Meal.h"
#include "Recipe_db.h"

using namespace std;

// information about a single date.
class Date {
private:
    string date; // format: yyyy-mm-dd example> "2023-08-25"
    string date_name; // date_name example> "Yunjae's birthday!"
    vector<Meal> meals; // meals planned for this date
    Recipe_db* recipe_db; // pointer to the recipe database to use
    string annotations; // notes or annotations about the date

public:
    // constructor
    Date(string date, Recipe_db* db); // date = yyyy-mm-dd, a recipe database to provide to its meals. default date_name is same as date.
    Date(string date, string date_name, Recipe_db* db);
    
    void set_date(string new_date); // set the date
    string get_date(); // get the date

    void set_date_name(string new_date); // set the date_name
    string get_date_name(); // get the date_name

    void add_meal(Meal meal); // add a meal to the date
    void remove_meal(string meal_name); // remove a meal based on its name example> breakfast, lunch, dinner
    Meal get_meal(string meal_name); // get the meal based on its name
    void modify_meal(string meal_name, Meal new_meal); // modify a meal (replace one meal with another)

    void set_annotation(string annotation); // set annotation for the date
    string get_annotation(); // get annotation for the date

    void set_other_recipe_db(Recipe_db* recipe_db); // change the recipe database to use.

    void print_gorcery_list(vector<pair<string, string>> grocery); //print all necessory gorcery list for meal.
    vector<pair<string, string>> generate_grocery_list_for_date(); // generate a combined grocery list for all meals planned on this date

    void display_meals(); // display all meals for this date
    void display_date_details(); // display the full details for the date
    
};

#endif
