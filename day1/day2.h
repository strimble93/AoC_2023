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
	int power = 0;
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
			power = power + (red*green*blue);
			if (red <= max_red && green <= max_green && blue <= max_blue) {
				cout << "Game " << g << " is possible" << '\n';
				output = output + g;
			}
		}
		day_file.close();
	}
	cout << "The final output is: " << output << '\n';
	cout << "The total power is: " << power << '\n';
}


 // Get the game number
int game(string str) {
	int output = 0;

	for (int i = 0; i < str.length(); i++) {
		if (isdigit(str[i])) {
			output = output * 10 + str[i] - '0';
		}
		else if (str[i] == ':') {
			i = str.length();
		}
	}
	return output;
}

int high_red(string str) {
	int output = 0;
	int ti = 0;
	string ts;

	for (int i = 0; i <= str.length(); i++) {
		if (isdigit(str[i])) {
			ti = ti * 10 + str[i] - '0';
		}
		else if (str[i] == 'r' && str[i+1] == 'e' && str[i+2] == 'd') {
			ts = "red";
		}
		else if (str[i] == ':' || str[i] == ',' || str[i] == ';' || i == str.length()) {
			if (ti > output && ts == "red") {
				output = ti;
			}
			ti = 0;
			ts.clear();
		}
	}

	return output;
}

int high_green(string str) {
	int output = 0;
	int ti = 0;
	string ts;

	for (int i = 0; i <= str.length(); i++) {
		if (isdigit(str[i])) {
			ti = ti * 10 + str[i] - '0';
		}
		else if (str[i] == 'g' && str[i + 1] == 'r' && str[i + 2] == 'e' && str[i + 3] == 'e' && str[i + 4] == 'n') {
			ts = "green";
		}
		else if (str[i] == ':' || str[i] == ',' || str[i] == ';' || i == str.length()) {
			if (ti > output && ts == "green") {
				output = ti;
			}
			ti = 0;
			ts.clear();
		}
	}

	return output;
}

int high_blue(string str) {
	int output = 0;
	int ti = 0;
	string ts;

	for (int i = 0; i <= str.length(); i++) {
		if (isdigit(str[i])) {
			ti = ti * 10 + str[i] - '0';
		}
		else if (str[i] == 'b' && str[i + 1] == 'l' && str[i + 2] == 'u' && str[i + 3] == 'e') {
			ts = "blue";
		}
		else if (str[i] == ':' || str[i] == ',' || str[i] == ';' || i == str.length()) {
			if (ti > output && ts == "blue") {
				output = ti;
			}
			ti = 0;
			ts.clear();
		}
	}

	return output;
}