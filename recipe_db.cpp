#include "Recipe_db.h"

Recipe_db::Recipe_db(string filename) : db_filename(filename) {
    load_from_file();
}

void Recipe_db::add_recipe(Recipe recipe) {
    recipe_list.push_back(recipe);
}

void Recipe_db::add_recipe(string recipe_name, vector<pair<string, string>> grocery, string cooking_method) {
    Recipe new_recipe(recipe_name, grocery, cooking_method);
    recipe_list.push_back(new_recipe);
}

// 레시피를 추가하는 메서드 구현 (user_notes 있는 버전)
void Recipe_db::add_recipe(string recipe_name, vector<pair<string, string>> grocery, string cooking_method, string user_notes) {
    Recipe new_recipe(recipe_name, grocery, cooking_method, user_notes);
    recipe_list.push_back(new_recipe);
}

void Recipe_db::display_all_recipes() {
    for (int i = 0; i < recipe_list.size(); i++) {
        recipe_list[i].display_recipe();
    }
}

void Recipe_db::remove_recipe(string recipe_name) {
    for (size_t i = 0; i < recipe_list.size(); i++) {
        if (recipe_list[i].get_recipe_name() == recipe_name) {
            recipe_list.erase(recipe_list.begin() + i);
            break;
        }
    }
}

Recipe* Recipe_db::find_recipe(string recipe_name) {
    for (size_t i = 0; i < recipe_list.size(); i++) {
        if (recipe_list[i].get_recipe_name() == recipe_name) {
            return &recipe_list[i];
        }
    }
    return nullptr;
}

void Recipe_db::print_all_recipe_name() {
    for (Recipe recipe : recipe_list) {
        cout << recipe.get_recipe_name() << endl;
    }
}

void Recipe_db::save_to_file() {
    ofstream file(db_filename);
    
    // check if the file is open
    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
        return;
    }

    for (Recipe recipe : recipe_list) {
        file << recipe.get_recipe_name() << endl;
        for (auto grocery_item : recipe.get_grocery()) {
            file << grocery_item.first << "," << grocery_item.second << endl;
        }
        file << recipe.get_cooking_method() << endl;
        file << recipe.get_user_notes() << endl;
        file << "----" << endl;  // delimiter to separate recipes
    }

    file.close();
}

void Recipe_db::load_from_file() {
    ifstream file(db_filename);

    // check if the file is open
    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        string recipe_name = line;
        vector<pair<string, string>> grocery_list;
        string cooking_method, user_notes;

        while (getline(file, line) && line != "----") {
            size_t comma_pos = line.find(',');
            if (comma_pos != string::npos) {
                string item = line.substr(0, comma_pos);
                string quantity = line.substr(comma_pos + 1);
                grocery_list.push_back({item, quantity});
            } else {
                if (cooking_method.empty()) {
                    cooking_method = line;
                } else {
                    user_notes = line;
                }
            }
        }

        Recipe new_recipe(recipe_name, grocery_list, cooking_method, user_notes);
        recipe_list.push_back(new_recipe);
    }

    file.close();
}

vector<Recipe> Recipe_db::find_recipes_by_grocery(vector<string> grocery) {
    vector<Recipe> matched_recipes;
    
    // 모든 레시피에 대해 반복
    for (int i = 0; i < recipe_list.size(); i++) {
        bool all_grocery_found = true;

        // 주어진 재료들이 현재 레시피에 모두 있는지 확인
        for (int j = 0; j < grocery.size(); j++) {
            bool groceryfound = false;
            vector<pair<string, string>> grocery_list = recipe_list[i].get_grocery();
            for (int k = 0; k < grocery_list.size(); k++) {
                if (grocery_list[k].first == grocery[j]) {
                    groceryfound = true;
                    break;
                }
            }

            // 현재 재료가 해당 레시피에 없다면 루프를 탈출
            if (!groceryfound) {
                all_grocery_found = false;
                break;
            }
        }

        // 모든 재료들이 레시피에 있다면 matched_recipes에 추가
        if (all_grocery_found) {
            matched_recipes.push_back(recipe_list[i]);
        }
    }

    return matched_recipes;
}
