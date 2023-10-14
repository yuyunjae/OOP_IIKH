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
    vector<Date> dates; // list of Date objects.
    string filename; // name of the file to save and load plans.
    Recipe_db* recipe_db; // pointer to the recipe database to use.

    static bool compareDates(Date a, Date b); // sort dates based on Date class's date value(string). ->  return ((int)(a.get_date() < b.get_date()));

public:
    Plan_manager(Recipe_db* db); // default constructor. filename = "plan.txt"
    Plan_manager(string custom_filename, Recipe_db* db); // filename to save and load plan.

    int find_date_index(string date_str); // find a Date index in dates

    void sort_dates();  // sorts the 'dates' vector based on the Date class's date value("yyyy-mm-dd"). -> sort(dates.begin(), dates.end(), compareDates);

    void add_date(Date date); // add a Date to the plan.
    void add_date(string date, Recipe_db* db); // make date and add to plan (vector<Date> dates)
    void add_date(string date, string date_name, Recipe_db* db); // make date and add to plan (vector<Date> dates)

    void remove_date(string date_str); // remove a Date from the plan.
    Date get_date(string date_str); // get a Date based on date.
    void modify_date(string date_str, Date new_date); // modify a Date in the plan

    void dates_without_plans(); // lists all the dates without any meal plans.

    void display_plan_simple(); // display all dates (date, name) in the plan.
    void display_plan_simple(string start_date, string end_date); // displays a summary of meals planned for a range of dates.
    void display_plan_simple(int start_date_index, int end_date_index); // displays a summary of meals from dates[start_date_index] to dates[end_date_index];

    void display_plan_details(); // display all dates details(all) in the plan.
    void display_plan_details(string start_date, string end_date); // display all about meals planned for a range of dates.
    void display_plan_details(int start_date_index, int end_date_index); // display all about meals from dates[start_date_index] to dates[end_date_index];

    void copy_meals_to_another_date(string from_date, string to_date); // copies meals from one date to another date.

    vector<pair<string, string>> generate_grocery_list_for_period(string start_date, string end_date); // generates a combined grocery list for all meals planned in a range of dates.
    vector<pair<string, string>> generate_grocery_list_for_period(int start_date_index, int end_date_index); // using index not date_name.

    void load_plan(); // load the plan from the file.
    void save_plan(); // save the plan to the file.
    
    void delete_all_plans(); // deletes all meals in plan.
};

#endif
