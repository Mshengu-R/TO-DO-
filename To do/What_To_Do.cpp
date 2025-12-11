// THIS IS A TO DO LIST CREATED BY I RISIMA CHABALALA
//
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
#include <cstdio>
#include <algorithm>
// #include <wtd.rc>
// #include <windows.h>

// int WINAPI WinMain(HINSTANCE HInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
// HICON hIcon = LoadIcon(HInstance, MAKEINTRESOURCE(IDI_ICON1));
// }    // Still a junior, no one taught me how to add an icon to my application

class TODO {
public:
    static void printMenu() {
        std::cout << "\n\t\t\t\t\t\t\t___WELCOM TO___\n";

        std::cout << "\n\t\t\t\t\t\t___A WHAT TO DO LIST SIMULATION___\n";
        std::cout << std::uppercase
                  << "\n\t\t\t\t\t\t1. Add to list \n"
                  << "\t\t\t\t\t\t2. View list \n"
                  << "\t\t\t\t\t\t3. Clear list \n"
                  << "\t\t\t\t\t\t4. Delete from list \n"
                  << "\t\t\t\t\t\t5. What this is \n"
                  << "\t\t\t\t\t\t6. Exit \n"
                  << "\t\t\t\t\t\tChoose option: ";
    } // The options will be in the middle of the application
};

class User {
    std::vector<std::string> things;
    const std::string filename = "UserList.txt"; //To use filename for this file instead of always having to write "UserList.txt"

public:
    User() { loadFromFile(); }

    void loadFromFile() { //to load from the file
        things.clear();

        std::ifstream in(filename);

        if (!in.is_open()) return;
        std::string line;

        while (std::getline(in, line)) {
            if (!line.empty()) things.push_back(line);
        }
    }

    void saveToFile() const {
        std::ofstream out(filename, std::ios::trunc);
        for (const auto &s : things) out << s << '\n';
    }

    void addToList() { //Adding to the list

        int num = 0;
        std::cout << std::setw(70) << "Please enter the number of things you wish to add: ";
        if (!(std::cin >> num) || num <= 0) {
            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Clear the buffer

            std::cout << "\n\t\t\tPlease enter a valid positive number\n";
            return;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // consume newline

        for (int i = 0; i < num; ++i) {
            std::string item;
            std::cout << std::setw(70) << "Write thing to add to your list " << (i + 1) << ": ";
            std::getline(std::cin, item);
            if (!item.empty()) things.push_back(item);
        }

        saveToFile(); // Calling the function which deals with saving the lists
        std::cout << "\n\t\t\t** Your items have been successfully stored. Use option 2 to view them.\n";
    }

    void viewList() const {

        if (things.empty()) { //Viewing what is in the list
            std::cout << "\n\t\t\tYour list is empty.\n";
            return;
        }
        std::cout << "\n\t\t\tTo-Do List:\n";
        for (size_t i = 0; i < things.size(); ++i) {
            std::cout << "\t\t\t" << (i + 1) << ". " << things[i] << '\n';
        }
    }

    void clearList() { //Clearing whats in the list
        things.clear();
        std::remove(filename.c_str());
        std::cout << "\n\t\t\tList cleared and file deleted (if it existed).\n";
    }

    void remove_an_opt_from_list(){
        viewList();  

        int O = 0; //O for option
        std::printf("\n\t\t\t\t Which option do you wish to remove from your list: ");
        

        if( !(std::cin >> O) || O <= 0) std::cout << "\n\t\t\t\t/Please enter a valid positive number \n"; 
        

        else { std::ifstream in(filename); 
            
            if(in.is_open()) things.at(O - 1).erase();
            in.close();
            
            std::ofstream out(filename); 
            if(out.is_open()) for(const auto &s : things) out << s << '\n'; //To save what remains
            out.close();

            std::cout<<"\n\t\t\t\t***The option has succesfully been deleted from the list***";}
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    }

};


int main() {
    User ui;
    int choice = 0;

    do {

        TODO::printMenu();

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            std::cout << "\n\t\t\tInvalid input. Enter a number 1-4.\n";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // consume rest of line
        switch (choice) {

            case 1:

                ui.addToList();
                break;

            case 2:

                ui.viewList();
                break;

            case 3:

                ui.clearList();
                break;

            case 4:

                ui.remove_an_opt_from_list();
            break;

            case 5:

std::printf("This is a comand line to do list which is made for any person who wishes to set what to do at times to times.\n");

            break;

            case 6:

                std::cout << "Exiting...\n";
            break;

            default:
                std::cerr << "\t\tInvalid value. Choose 1-4.\n";
                break;
        }
        
    } while (choice != 6);

    return 0;
}