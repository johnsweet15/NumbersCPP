//
//  solution.cpp
//
//  Created by Roberto Flores on 12/21/16.
//  Copyright © 2016 Roberto Flores. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string ones[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
string teens[] = { "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
string tens[] = { "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

string helper(unsigned long number) {
	if (number < 10 && number >= 0) {
		return ones[number];
	}
	else if (number < 20 && number != 10) {
		return teens[number - 11];
	}
	else if (number % 10 == 0 && number < 100) {
		return tens[number / 10 - 1];
	}
	else if (number % 10 != 0 && number < 100) {
		return tens[number / 10 - 1] + "-" + ones[number % 10];
	}
	else if (number >= 100 && number < 1000) {
		if (number % 100 == 0) {
			return ones[number / 100] + " hundred";
		}
		else {
			return ones[number / 100] + " hundred and " + helper(number % 100);
		}
	}
	else if (number >= 1000 && number < 1000000) {
		if (number % 1000 == 0) {
			return helper(number / 1000) + " thousand";
		}
		else if (number < 1000000) {
			if (number % 1000 < 100) {
				return helper(number / 1000) + " thousand and " + helper(number % 1000);
			}
			else {
				return helper(number / 1000) + " thousand, " + helper(number % 1000);
			}
		}
	}
	else if (number >= 1000000 && number <= 1000000000) {
		if (number % 1000000 == 0) {
			return helper(number / 1000000) + " million";
		}
		else if (number < 1000000000) {
			if (number % 1000000 < 100) {
				return helper(number / 1000000) + " million and " + helper(number % 1000000);
			}
			else {
				return helper(number / 1000000) + " million, " + helper(number % 1000000);
			}
		}
	}
}

vector<string>* process(vector<unsigned long>& input) {
	vector<string>* numbers = new vector<string>();
	if (input.size() == 0) {
		return new vector<string>;
	}
	for (unsigned long i = 0; i < input.size(); i++) {
		numbers->push_back(helper(input[i]));
	}
	return numbers;
}
