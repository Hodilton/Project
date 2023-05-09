#pragma once
#include "stdafx.h"

#if defined(max)
#undef max
#endif

#if defined(min)
#undef min
#endif

template<typename T>
class Console {
public:
	static T MenuReadNumber(const vector<string>& text, istream& in = cin, T min = numeric_limits<T>::min(), T max = numeric_limits<T>::max()) {
		T input;

		while (true) {
			system("cls");
			copy(text.begin(), text.end(), ostream_iterator<string>(cout));

			if ((in >> input).good() && (min <= input) && (input <= max))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return input;
			}
			else
			{
				cin.clear();
				cout << "Please enter a number from the acceptable range of values." << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("pause");
				system("cls");

				/*if (!cin.eof())*/
			}

			/*if (cin.fail())*/

		}
	}

	static void ReadNumber(vector<string>& text, istream& in = cin, T min = numeric_limits<T>::min(), T max = numeric_limits<T>::max()) {
		T input;

		while (true) {
			system("cls");
			copy(text.begin(), text.end(), ostream_iterator<string>(cout));

			if ((in >> input).good() && (min <= input) && (input <= max))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				text.push_back(to_string(input));
				break;
			}
			else
			{
				cin.clear();
				cout << "Please enter a number from the acceptable range of values." << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				system("pause");
				system("cls");

				/*if (!cin.eof())*/
			}

			/*if (cin.fail())*/

		}
	}

	static void ReadNumberFund(vector<string>& text, istream& in = cin) {
		
	}

	static string ReadString(vector<string>& text, istream& in = cin) {
		string str;

		system("cls");
		copy(text.begin(), text.end(), ostream_iterator<string>(cout));

		//cin.ignore();
		getline(in, str);

		text.push_back(str);
		text.push_back("\n");
		return str;
	}

private:
	Console() = delete;
	Console(const Console&) = delete;
	Console& operator=(const Console&) = delete;
};