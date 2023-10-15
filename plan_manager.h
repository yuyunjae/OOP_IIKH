#ifndef PLAN_MANAGER_H
#define PLAN_MANAGER_H

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Date.h"
#include "Recipe_db.h"

using namespace std;

// manages a list of Date objects.
class Plan_manager {
private:
    string plan_name; // plan name. default name is filename.
    vector<Date> dates; // list of Date objects.
    string filename; // name of the file to save and load plans.
    Recipe_db* recipe_db; // pointer to the recipe database to use.

    static bool compareDates(Date a, Date b); // sort dates based on Date class's date value(string). ->  return ((int)(a.get_date() < b.get_date()));

public:
    Plan_manager(Recipe_db* db); // default constructor. filename = "plan.txt"
    Plan_manager(string custom_filename, Recipe_db* db); // filename to save and load plan.
    Plan_manager(string custom_filename, Recipe_db* db, string plan_name); //set also plan_name.
    Plan_manager(string custom_filename, Recipe_db* db, string plan_name); 

    int find_date_index(string date_str); // find a Date index in dates

    void sort_dates();  // sorts the 'dates' vector based on the Date class's date value("yyyy-mm-dd"). -> sort(dates.begin(), dates.end(), compareDates);

    void set_plan_name(string new_date); // set the plan_name
    string get_plan_name(); // get the plan_name
    string get_date_name(); // get the date_name

    void add_date(Date date); // add a Date to the plan.
    void add_date(string date, Recipe_db* db); // make date and add to plan (vector<Date> dates)
    void add_date(string date, string date_name, Recipe_db* db); // make date and add to plan (vector<Date> dates)

    void remove_date(string date_str); // remove a Date from the plan.
    Date get_date(string date_str); // get a Date based on date name.
    void modify_date(string date_str, Date new_date); // modify a Date in the plan 
    string get_all_date_name(); // return all date name parsing by '?' ex> 2023-08-23?2023-08-24?Yunjae's birthday

    void dates_without_plans(); // display all the dates without any meal plans.

    void display_plan_simple(); // display all dates (name, date) in the plan.
    void display_plan_simple(string start_date, string end_date); // displays a summary of meals planned for a range of dates.
    void display_plan_simple(int start_date_index, int end_date_index); // displays a summary of meals from dates[start_date_index] to dates[end_date_index];

    void display_plan_details(); // display all dates details(all) in the plan.
    void display_plan_details(string start_date, string end_date); // display all about meals planned for a range of dates.
    void display_plan_details(int start_date_index, int end_date_index); // display all about meals from dates[start_date_index] to dates[end_date_index];

    void copy_meals_to_another_date(string from_date, string to_date); // copies meals from one date to another date.

    vector<pair<string, string>> generate_grocery_list_for_period(string start_date, string end_date); // generates a combined grocery list for all meals planned in a range of dates.
    vector<pair<string, string>> generate_grocery_list_for_period(int start_date_index, int end_date_index); // using index not date_name.

    void set_other_recipe_db(Recipe_db* recipe_db); // change the recipe database to use.

    void add_meal_to_date(); // add a meal to a specific date. input is received inside the method.
    void delete_meal_from_date(string meal_name); // delete a meal from a specific date. input is received inside the method. this method just give meal_name to date.

    void delete_all_plans(); // deletes all meals in plan.

    void load_plan(); // load the plan from the file.
    void save_plan(); // save the plan to the file.
    // save plan like this. we can distinguish details using '----------' '\n' ':', ',' '@' '#' '_'.
    // annotations and notes may not just 1 sentence. so we use @ and # before every sentence.
    // recipe's details can be find in recipe_db by using recipe_name. so, just save recipe_name.
    /*
    
    plan_name\n
    ----------\n
    date1 : date_name1\n
    @(annotations)
    @(annotations)
    @(annotations)\n
    __________\n
    meal_name1-1 : num_people1-1 : prepare_time1-1\n
    recipe_name1, recipe_name2, ...\n
    #(notes)
    #(notes)
    #(notes)\n
    __________\n
    meal_name1-2 : num_people1-2 : prepare_time1-2\n
    recipe_name1, recipe_name2, ...\n
    #(notes)
    #(notes)
    #(notes)\n
    ----------\n
    date2 : date_name2\n
    @(annotations)
    @(annotations)
    @(annotations)\n
    __________\n
    meal_name2-1 : num_people2-1 : prepare_time2-1\n
    recipe_name1, recipe_name2, ...\n
    #(notes)
    #(notes)
    #(notes)\n
    __________\n
    meal_name2-2 : num_people2-2 : prepare_time2-2\n
    recipe_name1, recipe_name2, ...\n
    #(notes)
    #(notes)
    #(notes)\n
    
    */
};

#endif
