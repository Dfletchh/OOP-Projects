#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int counter = 0;

int walk()
{

    srand(time(NULL));
    int num = rand() % 8 + 1;
    ofstream output_file;
    output_file.open("items.txt", ios::app);

    ifstream input_file;
    input_file.open("wizard_all_items.txt");
    if (input_file)
    {
        string line;
        char response;
        int c = 0;
        while (getline(input_file, line) && c != num)
        { // might have to do eof and fail check
            c++;
        }
        cout << endl;

        cout << "While walking down a path, you see " << line << endl;
        cout << "Do you want to grab it? (y/n): ";
        cin >> response;
        if (response == 'n')
        {
            cout << "You kept walking\n";
        }
        else
        {
            if (counter < 4)
            {
                output_file << line << "\n";
                cout << "You picked up " << line << endl;
                counter++;
                // cout << counter;
            }
            else
            {
                cout << "You can't carry any more items. Drop something first.\n";
            }
        }
    }
    else
    {
        cout << "File failed to open";
    }

    input_file.close();
    output_file.close();

    return 0;
}

int drop()
{
    int num;
    cout << "Number: ";
    cin >> num;
    string line;
    int c = 1;
    ifstream input_file;
    input_file.open("items.txt");
    ofstream output_file;
    output_file.open("temp.txt");
    if (input_file)
    {
        while (getline(input_file, line))
        {
            if (c < 1 && c > counter)
            {
                cout << "Invalid Request\n";
            }
            if (c != num)
            {
                output_file << line << endl;
                c++;
            }
            else
            {
                cout << "You dropped " << line << endl;
                counter--;
                // cout << counter;
                c++;
            }
        }
    }
    else
    {
        cout << "File failed to open";
        return 0;
    }
    output_file.close();
    input_file.close();
    remove("items.txt");
    rename("temp.txt", "items.txt");
    return 0;
}
int show()
{

    int c = 1;
    ifstream input_file;
    input_file.open("items.txt");
    string line;
    if (input_file)
    {
        while (getline(input_file, line))
        {
            cout << endl;
            cout << c << ". " << line;
            c++;
        }
    }
    else
    {
        cout << "File failed to open";
        return 0;
    }

    cout << endl
         << endl;

    return 0;
}

int main()
{

    string command;
    cout << "Wizard Inventory\n\n";
    cout << "COMMAND MENU\n";
    cout << "walk - Walk down the path\n";
    cout << "show - Show all items\n";
    cout << "drop - Drop an item\n";
    cout << "exit - Exit program\n\n";
    while (command.compare("exit") != 0)
    {
        cout << "Command: ";
        cin >> command;
        if (command.compare("walk") == 0)
        {
            walk();
        }
        else if (command.compare("show") == 0)
        {
            show();
        }
        else if (command.compare("drop") == 0)
        {
            drop();
        }
    }

    cout << "Bye!";
    return 0;
}