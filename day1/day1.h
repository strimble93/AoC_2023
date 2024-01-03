#include "pch.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void day1();
int extractIntegers(string str);
int firstDigit(int n);
int lastDigit(int n);
int firstlast(int n);

void day1()
{
	int output = 0;

	fstream day1_file;
	day1_file.open("day1.txt", ios::in);

	if (day1_file.is_open()) {
		string tp;
		int ln_num;
		while (getline(day1_file, tp)) {
			ln_num = extractIntegers(tp);
			ln_num = firstlast(ln_num);
			cout << ln_num << '\n';
			output = output + ln_num;
		}
		day1_file.close();
	}
	cout << "The final output is: " << output << '\n';
}

// Extract integers from a string.
int extractIntegers(string str)
{
	int output = 0;

	for (int i = 0; i < str.length(); i++) {
		if (isdigit(str[i])) {
			output = output * 10 + str[i] - '0';
		}
		else if (str[i] == 'o' && str[i + 1] == 'n' && str[i + 2] == 'e') {
			output = output * 10 + 1;
		}
		else if (str[i] == 't' && str[i + 1] == 'w' && str[i + 2] == 'o') {
			output = output * 10 + 2;
		}
		else if (str[i] == 't' && str[i + 1] == 'h' && str[i + 2] == 'r' && str[i + 3] == 'e' && str[i + 4] == 'e') {
			output = output * 10 + 3;
		}
		else if (str[i] == 'f' && str[i + 1] == 'o' && str[i + 2] == 'u' && str[i + 3] == 'r') {
			output = output * 10 + 4;
		}
		else if (str[i] == 'f' && str[i + 1] == 'i' && str[i + 2] == 'v' && str[i + 3] == 'e') {
			output = output * 10 + 5;
		}
		else if (str[i] == 's' && str[i + 1] == 'i' && str[i + 2] == 'x') {
			output = output * 10 + 6;
		}
		else if (str[i] == 's' && str[i + 1] == 'e' && str[i + 2] == 'v' && str[i + 3] == 'e' && str[i + 4] == 'n') {
			output = output * 10 + 7;
		}
		else if (str[i] == 'e' && str[i + 1] == 'i' && str[i + 2] == 'g' && str[i + 3] == 'h' && str[i + 4] == 't') {
			output = output * 10 + 8;
		}
		else if (str[i] == 'n' && str[i + 1] == 'i' && str[i + 2] == 'n' && str[i + 3] == 'e') {
			output = output * 10 + 9;
		}
	}

	return output;
}

// Find the first digit 
int firstDigit(int n)
{
	// Remove last digit from number 
	// till only one digit is left 
	while (n >= 10)
		n /= 10;

	// return the first digit 
	return n;
}

// Find the last digit 
int lastDigit(int n)
{
	// return the last digit 
	return (n % 10);
}

// Concatonate the first and last digit
int firstlast(int n)
{
	int output;
	output = firstDigit(n) * 10 + lastDigit(n);
	return output;
}