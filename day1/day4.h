#include "pch.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

void day4();
vector<int> winning_nos(string str);
vector<int> my_nos(string str);
int get_score(vector<int> win, vector<int> cmp);

void day4() {
	string filename = "day4.txt";
	int output = 0;
	int line = 0;
	int i;
	vector<int> winners;
	vector<int> mine;
	vector<int> card;
	fstream day_file;
	day_file.open(filename, ios::in);
	if (day_file.is_open()) {
		string tp;
		while (getline(day_file, tp)) {
			winners = winning_nos(tp);
			mine = my_nos(tp);
			output = output + get_score(winners, mine);
			i = 0;
			while (i <= output) {
				if (line + i >= card.size()) {
					if (i == 0) { card.push_back(1); }
					else card.push_back(card[line]);
				}
				else {
					if (i == 0) { card[line]++; }
					else card[line + i] = card[line + i] + card[line];
				}
				i++;
			}
			line++;
			output = 0;
		}
		i = 0;
		while (i < card.size()) {
			output = output + card[i];
			i++;
		}
		day_file.close();
	}
	cout << "The scratchcards are worth: " << output << " points\n";
}

vector<int> winning_nos(string str) {
	vector<int> result;
	int no = 0;
	int i = 0;

	while (str[i] != ':') { i++; };

	while (str[i] != '|') { 
		i++;
		if (isdigit(str[i])) {
			no = no * 10 + str[i] - '0';
		}
		else if (str[i] == ' ' && isdigit(str[i - 1])) {
			result.push_back(no);
			no = 0;
		}
	};

	return result;
}

vector<int> my_nos(string str) {
	vector<int> result;
	int no = 0;
	int i = 0;

	while (str[i] != '|') { i++; };

	while (i < str.length() - 1) {
		i++;
		if (isdigit(str[i])) {
			no = no * 10 + str[i] - '0';
		}
		else if (str[i] == ' ' && isdigit(str[i - 1])) {
			result.push_back(no);
			no = 0;
		}
		if (i == str.length() - 1) {
			result.push_back(no);
			no = 0;
		}
	};

	return result;
}

int get_score(vector<int> win, vector<int> cmp) {
	int matches = 0;
	int output = 0;
	int i = 0;
	int j = 0;

	while (i < cmp.size()) {
		while (j < win.size()) {
			if (cmp[i] == win[j]) {
				matches++;
			}
			j++;
		}
		j = 0;
		i++;
	}

	if (matches == 0) { output = 0; }
	else { output = matches; }

	return output;
}
