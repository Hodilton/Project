#pragma once
#include "stdafx.h"
#include "MenuItem.h"

class CustomerMenu : public MenuItem {
public:
    const vector<string>& GetText() const override {
        static const vector<string> text = { "Select:\n",
                                             "1) Добавить клиента;\n",
                                             "2) Удалить клиента;\n",
                                             "3) Поиск клиентов;\n",
                                             "4) Вернуться назад.\n",
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
        cout << "Добавление клиента" << endl;
        system("pause");
    }

    void Method_2() const {
        cout << "Удалить клиента" << endl;
        system("pause");
    }

    void Method_3() const {
        cout << "Поиск клиентов" << endl;
        system("pause");
    }

    void Method_4() const {
        // Возвращение назад
    }
};