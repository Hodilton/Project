#pragma once
#include "stdafx.h"
#include "Console.h"

class MenuItem { 
public:
    virtual const vector<string>& GetText() const = 0;
    virtual const vector<function<void()>>& GetMethods() const = 0;
};

class Menu {
public:
    static void Display(const MenuItem& menu_item) {
        const vector<string>& text = menu_item.GetText();
        const vector<function<void()>>& methods = menu_item.GetMethods();

        while (true) {
            _choice = Console<int>::MenuReadNumber(text, cin, 1, text.size() - 2);

            if (_choice == text.size() - 2) {
                break;
            }

            system("cls");
            methods[_choice - 1]();
        }
    }

private:
    static unsigned short _choice;
};

unsigned short Menu::_choice = 0;