#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <vector>

using namespace std;

void show_items();
void drop_items(const char *file, int item);
void walk_command();
void update_file(string str);

int main()
{
    string command;
    string option;
    int drop_number;

    ofstream current_items("wizard_current_items.txt"); // creates a file for current items
    current_items.close();

    cout << "Wizard Inventory\n\n"
        << "COMMAND MENU\n"
        << "walk - Walk down the path\n"
        << "show - Show all items\n"
        << "drop - Drop an item\n"
        << "exit - Exit program"
        << endl;

    while (command != "exit")
    {
        try {
            cout << "\nCommand: ";
            cin >> command;
            for (char c : command) // input validation
                option += tolower(c);

            if (command == "exit")
                break;

            if (command == "show")
                show_items();

            else if (command == "drop")
            {
                cout << "Number: ";
                cin >> drop_number;
                drop_items("wizard_current_items.txt", drop_number);
            }
            else if (command == "walk")
            {
                walk_command();
            }
            else 
            {             
                throw invalid_argument("Invalid command.\n");
                    continue;
            }
        } catch (const invalid_argument& e) 
        {
            cout << e.what();
        }
    }
    cout << Bye
    return 0;
}
void show_items()
{
    int count = 0;
    ifstream input_file("wizard_current_items.txt"); // opens file
    if (input_file)                                  // if opened successfully
    {
        string line;
        while (getline(input_file, line))
        {
            count++; // number format for output
            cout << count << ". " << line << "\n";
        }
        input_file.close();
    }
}
void walk_command()
{
    char ans = 'n';
    int count = 0;
    srand(time(NULL));
    int item = (rand() % 9) + 1; // random item generator

    ifstream input_file("wizard_all_items.txt"); // opens file
    if (input_file)                              // if opened successfully
    {
        string line;
        while (getline(input_file, line))
        {
            count++;
            if (count == item)
            { // item found in file
                try {
                    cout << "\nWhile walking down a path, you see " << line << endl;
                    cout << "Do you want to grab it? (y/n): ";
                    cin >> ans;

                    ans = tolower(ans);
                    if (ans == 'y')                         // TODO // && (count <= 4))
                    { // pick up and less then for items
                        cout << "You picked up " << line << endl;
                        update_file(line); // add to invetory file
                    } 
                    else if (ans == 'n')
                        cout << "You didn't pick up the item." << endl;
                    else 
                        throw invalid_argument("Invalid selection\n");

                } catch (const invalid_argument& e) 
                {
                    cout << e.what() << endl;
                }
            }
        }
        input_file.close();
    } else
    cout << "Error opening file!" << endl;
}

void drop_items(const char *file, int item)
{
    int count = 0;
    ifstream input_file("wizard_current_items.txt"); // opens file
    vector<string> inventory;                        // vector to hold items
    if (input_file)                                  // if opened successfully
    {
        string line;
        while (getline(input_file, line))
        {
            count++;
            if (count == item)
                cout << "You dropped " << line << endl;
            else
                inventory.push_back(line); // push items to keep into vector
        }
    }
    input_file.close();

    ofstream output_file(("wizard_current_items.txt"), ios::out); // overwrite file
    for (string str : inventory) // push vector to file 
        output_file << str << endl;

    output_file.close();
}
void update_file(string str) 
{
    ofstream output_file("wizard_current_items.txt", ios::app);
    if(output_file.is_open()) {
        output_file << str << endl;
        output_file.close();
    }
}