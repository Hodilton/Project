#pragma once
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <limits>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <fstream>
#include<functional>

#define E 2.71828
#define PI 3.14159

#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define IS_ODD(num) ((num) & 1)
#define IS_EVEN(num) (!IS_ODD((num)))

template<typename T> inline void Swap(T a, T b) { T temp = a; a = b; b = temp; }
template<typename T> inline void Swap(T* a, T* b) { T temp = *(a); *(a) = *(b); *(b) = temp; }

using namespace std;

template<typename T> inline void ReadAfterColon(istream& fin, T& value)
{
	char ch;
	while (fin >> ch && ch != ':');
	fin >> value;
}

//void CinClear()
//{
//	std::cin.clear();
//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//}