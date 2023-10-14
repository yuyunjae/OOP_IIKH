#include "Recipe.h"


Recipe::Recipe(string name) {
    recipe_name = name;
}

Recipe::Recipe(string name, vector<pair<string, string>> grocery_list, string method) {
    recipe_name = name;
    grocery = grocery_list;
    cooking_method = method;
}

Recipe::Recipe(string name, vector<pair<string, string>> grocery_list, string method, string notes) {
    recipe_name = name;
    grocery = grocery_list;
    cooking_method = method;
    user_notes = notes;
}

void Recipe::set_recipe_name(string name) {
    recipe_name = name;
}

string Recipe::get_recipe_name() {
    return recipe_name;
}

void Recipe::add_grocery_item(string item, string quantity) {
    grocery.push_back(make_pair(item, quantity));
}

vector<pair<string, string>> Recipe::get_grocery() {
    return grocery;
}

void Recipe::remove_grocery_item(string item_name) {
    for (int i = 0; i < grocery.size(); i++) {
        if (grocery[i].first == item_name) {
            grocery.erase(grocery.begin() + i);
            break;  // 일치하는 첫 번째 항목을 삭제한 후 for 루프 종료
        }
    }
}

void Recipe::set_cooking_method(string method) {
    cooking_method = method;
}

string Recipe::get_cooking_method() {
    return cooking_method;
}

void Recipe::set_user_notes(string notes) {
    user_notes = notes;
}

string Recipe::get_user_notes() {
    return user_notes;
}

void Recipe::display_recipe() {
    cout << "--------------------------------------------------------------------------------\n";
    cout << "|| Recipe Name: " << recipe_name << " ||\n";
    cout << "Grocery Items:\n";
    for (int i = 0; i < grocery.size(); i++) {
        cout << " - " << grocery[i].first << ": " << grocery[i].second << "\n";
    }
    cout << "Cooking Method:\n" << cooking_method << "\n";
    if (user_notes != "") {
        cout << "Notes:\n" << user_notes << "\n";
    }
    cout << "--------------------------------------------------------------------------------\n";
}