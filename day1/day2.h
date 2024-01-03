#include "pch.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

constexpr auto max_red = 12;
constexpr auto max_green = 13;
constexpr auto max_blue = 14;

void day2();
int game(string str);
int high_red(string str);
int high_green(string str);
int high_blue(string str);

void day2()
{
	int output = 0;
	fstream day_file;
	day_file.open("day2.txt", ios::in);

	if (day_file.is_open()) {
		string tp;
		int g;
		int red;
		int green;
		int blue;
		while (getline(day_file, tp)) {
			g = game(tp);
			red = high_red(tp);
			green = high_green(tp);
			blue = high_blue(tp);
			if (red <= max_red && green <= max_green && blue <= max_blue) {
				cout << "Game " << g << "is possible" << '\n';
				output = output + g;
			}
		}
		day_file.close();
	}
	cout << "The final output is: " << output << '\n';
}

int game(string str) {
	return 0;
}

int high_red(string str) {
	return 0;
}

int high_green(string str) {
	return 0;
}

int high_blue(string str) {
	return 0;
}