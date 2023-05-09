#pragma once
#include "stdafx.h"
#include "MenuItem.h"

class SetBehaviorSearchCustomer : public MenuItem {
public:
    virtual const bool& GetMenuReplay() const override {
        static bool replay = false;
        return replay;
    }

    const vector<string>& GetText() const override {
        static const vector<string> text = { "Select:\n",
                                             "1) Поиск по ФИО;\n",
                                             "2) Поиск по Фамилии и Имени;\n",
                                             "3) Поиск по Имени;\n",
                                             "4) Поиск по Фамилии;\n",
                                             "5) Поиск по Отчеству;\n",
                                             "6) Поиск по Пасспорту;\n",
                                             "Your choice: "
        };
        return text;
    }

    virtual const vector<function<void()>>& GetMethods() const override {
        static const vector<function<void()>> methods = { [this] { Method_1();  },
                                                          [this] { Method_2();  },
                                                          [this] { Method_3();  },
                                                          [this] { Method_4();  },
                                                          [this] { Method_5();  },
                                                          [this] { Method_6();  }
        };
        return methods;
    }

private:
    void Method_1() const { Compare::SwitchState("lfm"); }
    void Method_2() const { Compare::SwitchState("lf"); }
    void Method_3() const { Compare::SwitchState("f"); }
    void Method_4() const { Compare::SwitchState("l"); }
    void Method_5() const { Compare::SwitchState("m"); }
    void Method_6() const { Compare::SwitchState("p"); }
};

class CustomerMenu : public MenuItem {
public:
    virtual const bool& GetMenuReplay() const override {
        static bool replay = true;
        return replay;
    }

    const vector<string>& GetText() const override {
        static const vector<string> text = { "Select:\n",
                                             "1) Добавить клиента;\n",
                                             "2) Освободить номер;\n",
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
        vector<string> text;
        text.push_back("Введите номер: ");
        int input;

        while (true) {
            system("cls");
            OutputTable::Fund();
            copy(text.begin(), text.end(), ostream_iterator<string>(cout));

            bool input_flag = false;
            if ((cin >> input).good())
            {
                Fund fund_search;
                fund_search.id = input;

                Tree<Fund> tree_search;
                tree_fund.SearchNode(tree_search, fund_search);

                const Node<Fund>* root = tree_search.GetRoot();

                if (root) {
                    input_flag = true;
                    Fund fund_delete = tree_fund.ReplaceUnit(fund_search);

                    vector<size_t> passports = {
                        fund_delete.passport_1,
                        fund_delete.passport_2,
                        fund_delete.passport_3
                    };

                    Compare::SwitchState("p");
                    for (auto& passport : passports) {
                        Customer customer_delete;
                        customer_delete.passport = passport;
                        tree_customer.DeleteNode(customer_delete);
                    }

                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    text.push_back(to_string(input));
                    break;
                }
            }
            
            if (!input_flag)
            {
                cin.clear();
                cout << "Please enter a number from the acceptable range of values." << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("pause");
                system("cls");
            }
        }

        // Обнволение списков
        //system("pause");
    }

    void Method_3() const {
        const SetBehaviorSearchCustomer set_behavior_search_customer;
        Menu::Display(set_behavior_search_customer);

        Customer customer_search;
        customer_search.ReadForSearch();

        Tree<Customer> tree_search;
        tree_customer.SearchNode(tree_search, customer_search);
        tree_search.Print(cout);

        system("pause");
    }

    void Method_4() const {
        // Возвращение назад
    }
};