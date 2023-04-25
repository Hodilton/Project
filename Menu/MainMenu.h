#pragma once
#include "stdafx.h"
#include "MenuItem.h"
#include "CustomerMenu.h"
#include "OutputTableMenu.h"

class MainMenu : public MenuItem {
public:
    const vector<string>& GetText() const override {
        static const vector<string> text = { "Select:\n",
                                             "1) Работа с клиентами;\n",
                                             "2) Вывод списков клиентов и фонда;\n",
                                             "3) Бронирование номера.\n",
                                             "4) Выйти.\n",
                                             "Your choice: "
        };
        return text;
    }

    virtual const vector<function<void()>>& GetMethods() const override {
        static const vector<function<void()>> methods = { [this] { Method_1();  },
                                                          [this] { Method_2();  },
                                                          [this] { Method_3();  },
                                                          [this] { Method_4();  }
        };
        return methods;
    }

private:
    void Method_1() const {
        const CustomerMenu customer_menu;
        Menu::Display(customer_menu);
    }

    void Method_2() const {
        const OutputTableMenu output_table_menu;
        Menu::Display(output_table_menu);
    }

    void Method_3() const {
        cout << "Бронирование номера" << endl;
        system("pause");
    }

    void Method_4() const {
        // Выход
    }
};