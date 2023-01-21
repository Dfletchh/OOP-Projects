/* Author: Group 6
 * Purpose: This program allows the user to play a game where they 
 *          have an inventory of 4 items that they can manage. Users
 *          can pick up new items if they have space, look at their
 *          inventory, and remove items.
*/

// Seems to be an issue with my code picking up 4 itmes, dropping one and picking up more. It does not replace the item on the empty line which makes it not show in current inventory properly - Sandro

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <limits>

using namespace std;

// Initialize functions used.
int walk(int num_items);
void show();
int drop(int num_items);
void update_file(string str);

int main() {
    // Seed the program.
    srand(time(nullptr));

    int num_items = 0;
    bool stop = false;
    string command;

    // Reset the inventory file if game has been played, create inventory otherwise.
    ofstream current_items;
    current_items.open("wizard_current_items.txt", ios::out);
    current_items.close();

    // Main loop of the game that checks for users commands.
    cout << "Wizard Inventory\n\nCOMMAND MENU\nwalk - Walk down the path\nshow - Show all items\ndrop - Drop an item\nexit - Exit program\n";

    while (!stop) {
        cout << "\nCommand: ";
        cin >> command;

        // Run functions based on user input. Catch error if invalid selection.
        try {
            if (command == "walk") {
                num_items = walk(num_items);
            }
            else if (command == "show") {
                show();
            }
            else if (command == "drop") {
                num_items = drop(num_items);
            }
            else if (command == "exit") {
                stop = true;
                cout << "Bye!\n\n";
            }
            else {
                throw invalid_argument("Invalid command.\n");
                continue;
            }
        }
        catch (const invalid_argument& e) {
            cout << e.what();
        }
    }
}
// The walk command allows users to pick up new items if they have space.
int walk(int num_items) {

    ifstream all_items;
    all_items.open("wizard_all_items.txt");

    ofstream current_items;
    current_items.open("wizard_current_items.txt", ios::app);

    int random_item;
    string item;
    char grab;

    random_item = (rand() % 9) + 1; // random item generator

    // Read the file up to the selected random item.
    for (int i = 0; i < random_item; i++) {
        getline(all_items, item);
    }

    // Prompt the user to take or leave the new item.
    cout << "While walking down a path, you see " << item << endl;

    do {
        // Check if selection is y or n. If not, throw error.
        try {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Do you want to grab it? (y/n): ";
            cin >> grab;

            if (grab != 'y' && grab != 'n') {
                throw invalid_argument("Invalid selection\n\n");
            }
        }
        catch (const invalid_argument& e) {
            cout << e.what();
        }
    } while (grab != 'y' && grab != 'n');

    // If the user has space and they want the item it gets put into their inventory and their item count goes up by 1. If they enter n or anything else the users leaves the item.
    switch (grab) {
        case 'y':
            // Check inventory and throw error if already full.
            try {
                if (num_items < 4) 
                {
                    cout << "You picked up " << item << endl;
                    update_file(item); // add to invetory file
                    num_items++;
                } else {
                    throw invalid_argument("You can't carry any more items. Drop something first.\n");
                }
            } catch (const invalid_argument& e) {
                cout << e.what();
            }
            break;
        case 'n':
            cout << "You didn't pick up the item." << endl;
            break;
        default:
            cout << "You didn't pick up the item." << endl;
            break;
    }
    current_items.close();
    all_items.close();

    return num_items; // Return the number of items to keep track.
}
// This function prints out all of the users inventory.
void show() {
    ifstream current_items;
    current_items.open("wizard_current_items.txt");

    for (int i = 1; i <= 4; i++) {
        string line;
        getline(current_items, line);
        cout << i << ". "<< line << endl;
    }
    current_items.close();
}
// Function removes desired item and updates the file
int drop(int num_items) {
    fstream current_items;
    current_items.open("wizard_current_items.txt", ios::in);

    int removed_item = -1;
    string item;
    vector<string> temp_items(0);

    // Determine the item to remove.
    while (removed_item > 4 || removed_item < 1) {
        cout << "Number: ";
        cin >> removed_item;

        if (removed_item > 4 || removed_item < 1) {
            cout << "Invalid item." << endl;
        }
    }
    // Add all but the removed item to a vector for temporary storage.
    int count = 0;
    string line;
    while (getline(current_items, line)) 
    {
            count++;
            if (count == removed_item) {
                cout << "You dropped " << line << endl;
            } else
                temp_items.push_back(line); // push items to keep into vector
    }
    current_items.close();

    ofstream output_file(("wizard_current_items.txt"), ios::out); // overwrite file
    for (string str : temp_items) // push vector to file 
        output_file << str << endl;

    output_file.close();
    return (num_items - 1);
}
void update_file(string str) 
{
    ofstream output_file("wizard_current_items.txt", ios::app);
    if(output_file.is_open()) {
        output_file << str << endl;
        output_file.close();
    }
}
