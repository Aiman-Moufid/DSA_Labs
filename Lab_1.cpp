//  DSA_1
//  Created by Aiman Moufid on 9/2/25.
#include <iostream>
#include <vector>
#include <string>
#include <ncurses.h>
using namespace std;
class GroceryList
{
private:
    vector<string> items;
    const int MAX_ITEMS = 25;

public:
    GroceryList() {
        items = {
            "apples",
            "bananas",
            "whole milk",
            "orange juice",
            "cheddar cheese",
            "frozen peas",
            "ground beef",
            "chicken breast",
            "peanut butter",
            "wheat bread",
            
            "canned tuna",
            "almond milk",
            "chocolate chips",
            "fresh spinach",
            "tomato soup",
            "olive oil",
            "granola bars",
            "vanilla yogurt",
            "potato chips",
            "sour cream",
            "lettuce",
            "onions",
            "eggs",
            "rice",
            "sparkling water"
        };
    }
    vector<string> getItems()
    {
        return items;
    }
};



int main() {
    GroceryList groceries;
    vector<string> list = groceries.getItems();
    initscr();
    cbreak();
    keypad(stdscr, true);
    noecho();
    refresh();
    mvprintw(1, 0, "%s", "Type / to exit");
    string input;
    int inputwords=0;
    int lastrowused = 3;
    while(inputwords != 47)
    {
        inputwords = getch();
        move(0,0);
        clrtoeol();
        if ((inputwords == 127 || inputwords == KEY_BACKSPACE) && input.empty() == false)
        {
            input.pop_back();
        }
        else
        {
            if(inputwords !=47)
            {
                input += static_cast<char>(inputwords);
            }
        }
        if(input.size() >= 3)
        {
            int rows = 3;
            vector<string>::iterator it;
            for(int k = 3; k <= lastrowused;k++)
            {
                move(k,0);
                clrtoeol();
            }
            for(it = list.begin(); it != list.end(); it++)
            {
                bool same = true;
                string currentwordinv = *it;
                for(unsigned long i = 0; i != input.size(); i++)
                {
                    
                    if(input[i] != currentwordinv[i])
                    {
                        same = false;
                        break;
                    }
                }
                if(!same)
                {
                    for(unsigned long space = 0; space < currentwordinv.size(); space++)
                    {
                        if(currentwordinv[space] == ' ')
                        {
                            bool secondcheck = true;
                            for(unsigned long i = 0; i < input.size(); i++)
                            {
                                if(i+space+1 >= currentwordinv.size() || input[i] != currentwordinv[i+space+1])
                                {
                                    secondcheck = false;
                                    break;
                                }
                            }
                            if(secondcheck)
                            {
                                same = true;
                                break;
                            }
                            
                        }
                        
                    }
                }
                if(same)
                {
                    move(rows, 0);
                    mvprintw(rows, 0,"%s", currentwordinv.c_str());
                    rows++;
                }
                lastrowused = rows;
            }
        }
        else
        {
            int rows = 3;
            for(int k = 3; k <= lastrowused;k++)
            {
                move(k,0);
                clrtoeol();
            }
            vector<string>::iterator it;
            for(it = list.begin(); it != list.end(); it++)
            {
                string hold = *it;
                move(rows, 0);
                mvprintw(rows, 0,"%s", hold.c_str());
                rows++;
                lastrowused = rows;
            }
        }
        mvprintw(0,0,"%s", input.c_str());
        refresh();
    }
    endwin();
    cout << input << endl;
    return 0;
}
