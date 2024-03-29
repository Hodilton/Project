#pragma once
#include "stdafx.h"
#include "MenuItem.h"

class OutputTableMenu : public MenuItem {
public:
    virtual const bool& GetMenuReplay() const override {
        static bool replay = false;
        return replay;
    }

    const vector<string>& GetText() const override {
        static const vector<string> text = { "Select:\n",
                                             "1) ����� ������ ��������;\n",
                                             "2) ����� ������ ����� ��������� �����;\n",
                                             "3) ��������� �����.\n",
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
        OutputTable::DisplayCustomer();
        system("pause");
    }

    void Method_2() const {
        OutputTable::DisplayFund();
        system("pause");
    }

    void Method_3() const {
        // ����������� �����
    }
};