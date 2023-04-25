#pragma once
#include "stdafx.h"
#include "MenuItem.h"

class OutputTableMenu : public MenuItem {
public:
    const vector<string>& GetText() const override {
        static const vector<string> text = { "Select:\n",
                                             "1) Вывод списка клиентов;\n",
                                             "2) Вывод списка учёта номерного фонда;\n",
                                             "3) Вернуться назад.\n",
                                             "Your choice: "
        };
        return text;
    }

    virtual const vector<function<void()>>& GetMethods() const override {
        static const vector<function<void()>> methods = { [this] { Method_1();  },
                                                          [this] { Method_2();  },
                                                          [this] { Method_3();  }
        };
        return methods;
    }

private:
    void Method_1() const {
        cout << "Вывод списка клиентов" << endl;
        system("pause");
    }

    void Method_2() const {
        cout << "Вывод списка учёта номерного фонда" << endl;
        system("pause");
    }

    void Method_3() const {
        // Возвращение назад
    }
};