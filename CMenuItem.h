#pragma once
#include"stdafx.h"

class CMenuItem {
public:
    virtual const vector<string>& GetText() const = 0;

    virtual const vector<function<void()>>& GetMethods() const {
        static const vector<function<void()>> methods = { [this] { Method_1(); },
                                                          [this] { Method_2(); },
                                                          [this] { Method_3(); },
                                                          [this] { Method_4(); },
                                                          [this] { Method_5(); },
                                                          [this] { Method_6(); },
                                                          [this] { Method_7(); }
        };
        return methods;
    }

private:
    void virtual Method_1() const = 0;
    void virtual Method_2() const = 0;
    void virtual Method_3() const = 0;
    void virtual Method_4() const = 0;
    void virtual Method_5() const = 0;
    void virtual Method_6() const = 0;
    void virtual Method_7() const = 0;
};

class CMainMenu : public CMenuItem {
public:
    const vector<string>& GetText() const override {
        static const vector<string> text = { "Select\n",
                                             "Method 1\n",
                                             "Method 2\n",
                                             "Method 3\n",
                                             "Your choice: "
        };
        return text;
    }

private:
    void Method_1() const override {
        cout << "Method 1 called" << endl;
    }

    void Method_2() const override {
        cout << "Method 2 called" << endl;
    }

    void Method_3() const override {
        cout << "Method 3 called" << endl;
    }

    void Method_4() const override { cout << "Method 4 called" << endl; }
    void Method_5() const override { cout << "Method 5 called" << endl; }
    void Method_6() const override { cout << "Method 6 called" << endl; }
    void Method_7() const override { cout << "Method 7 called" << endl; }
};

class CMenu {
public:
    static void Display(const CMenuItem& menu_item) {
        const vector<string>& text = menu_item.GetText();
        const vector<function<void()>>& methods = menu_item.GetMethods();

        copy(text.begin(), text.end(), ostream_iterator<string>(cout));
        cin >> _choice;

        if (_choice < 1 || _choice > text.size() - 2) {
            cout << "Invalid choice." << endl;
            return;
        }

        methods[_choice - 1]();
    }

private:
    static unsigned short _choice;
};

unsigned short CMenu::_choice = 0;

class CMenuItems {
public:
    const CMainMenu main;
};
