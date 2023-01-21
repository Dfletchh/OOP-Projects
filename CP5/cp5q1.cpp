
/*   Authors: Kenroy Morgan, Seth Feldhouse, Vu Le, Mayank Pandey
 *   Purpose: Create a program that keeps track of the items a wizard can carry.
 *          The Wizard cna carry a maximum of four items; will have to drop an item
 *          if capacity is reached. 
 */

#include <iostream>
#include <fstream>
#include <vector>
#include<ctime>
#include <cstring>
#include <algorithm>

using namespace std;

vector<string>magic_items;
vector<string>already_selected;
vector<string>items_collected;

//get input file
getInputFile(){
    string item, str; 
    ifstream iFile("wizard_all_items.txt");
    if(iFile.is_open()){
    while(getline (iFile, item))
    { 
    magic_items.push_back(item); //inser each item into a vector
    }//end of while
    } else
    {
    cout<<"Could not find file: wizard_inventory.txt\n"   
        <<"Exiting program.  Bye!\n";
    exit(EXIT_FAILURE);  //exit program if file is not found
    }
}

checkOutFile(){
    string inv;
    ifstream inventory("wizard_inventory.txt");
    if(inventory.is_open()){
    while(getline (inventory, inv))
    { 
    items_collected.push_back(inv); //insert each item into a vector of alreayd collected items
    }//end of while
    } 
    else
    {
    cout<<"Could not find file: wizard_inventory.txt\n"
        <<"Wizard is starting with no inventory.\n"<<endl; 
    }
    inventory.close();
}

//update items in output file
void updateItems(){
    size_t i;
    ofstream oFile("wizard_inventory.txt");
    if(oFile.is_open())
    {
    for(i = 0; i<items_collected.size(); i++)
    {
    oFile<<items_collected.at(i)<<endl;
    }
    oFile.close();
}
}

//selects a random number
int getRandom(){
   int randomNumber;
    srand(time(NULL));
    randomNumber =rand() % magic_items.size();
    return randomNumber >=0? randomNumber : 0; //return ranNumber and zero if undefined
}

//select a random magic item
string getItem(){
   string chosen;
   int x;
    bool status = true; //if item not already selected
    if(magic_items.size()==already_selected.size())
    {
    already_selected.clear();  //clear selected items list. All items must be selected once before repitition
    }
    while(status)
    {
    x = getRandom();
    chosen = magic_items[x]; //select a random item from magic items list;
        if(std::find(already_selected.begin(), already_selected.end(), chosen) ==already_selected.end())
        {  //if item not already selected
        already_selected.push_back(chosen);  //add item to selected items vector
        status = false;
        }
        else 
        {
        status = true;
        }
    }
    return chosen; //return item
}

//walk path and select and item
void walkPath(){
    string item_choice = getItem();
    char x;
    cout<<"While walking down a path, you see "<<item_choice<<"."<<endl;
    cout<<"Do you want to grab it? (y/n): ";
    cin>>x;
        if(x=='y') {
        if(items_collected.size()>=4){
        cout<<"You can't carry any more items. Drop something first."<<endl;
        }
        else{
        items_collected.push_back(item_choice);
        cout<<"You picked up "<<item_choice<<"."<<endl;
        updateItems(); //update possession items
        }

    }
}

//drop item from current stack
void dropItem(){
    int z, x;
        x = items_collected.size();
        cout<<"Number: "; cin>>z;
        if(!(z>=1 && z<=x)){
        cout<<"Invalid item number.\n";
        }
        else{
        cout<<"You droped "<<items_collected.at(z-1)<<"."<<endl;
        items_collected.erase(items_collected.begin()+(z-1));
        updateItems(); //call update items
    }
}

//show item in posession
void showItems(){
    size_t i=0;
    for(i = 0; i<items_collected.size(); i++)
    {
    cout<<i+1<<". "<<items_collected.at(i)<<endl;
    }
}


int main()
{
        string str; 
    getInputFile();
    cout<<"COMMAND MENU\n"
        <<"walk - walk down the path\n"
        <<"show - Show all items\n"
        <<"drop - Drop an item\n"
        <<"exit - Exit Program\n\n";

        checkOutFile();

    while(true){
        cout<<endl<<"Command: "; cin>>str;
        if(str=="walk")
        walkPath();
        else if(str=="drop")
        dropItem();
        else if(str=="show")
        showItems();
        else if(str=="exit")
        break;
        else
        cout<<"Invalid selection. Options are 'walk', 'drop', 'show', 'exit'"<<endl;
        }
        cout<<"Bye!\n\n";

    return 0;
}