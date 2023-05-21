#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;


string ToLower(string s)
// postcondition: s all lower case     
{
	int len = s.length();
	for (int k = 0; k < len; k++)
	{
		s[k] = tolower(s[k]);
	}
	return s;
}

bool isValidSource(string s)
// if not any character in string other than white space and digit
{
	// update the for loop
	/*
	for (char c : s) {
		int asciiCode = static_cast<int>(c);
		if (!(asciiCode == 32) && !(asciiCode > 47 && asciiCode < 58) && !(asciiCode > 64 && asciiCode < 91) && !(asciiCode > 96 && asciiCode < 123)) {
			return false;
		}

	}
	*/
	for (int i = 0; i < s.length(); i++) {
		if (!(s[i] == 32) && !(s[i] > 47 && s[i] < 58) && !(s[i] > 64 && s[i] < 91) && !(s[i] > 96 && s[i] < 123)) {
			return false;
		}
	}
	return true;
}



bool isValidSearch(string s)
{
	if (!(s.substr(0, s.length() - 1).empty()) && (s.back() == "+"[0] || s.back() == "."[0] || s.back() == "*"[0])) {
		return true;
	}
	else {
		return false;

	}
}

void searchAlgorithm(string source, string search) {
	string s;
	int pos = 0;
	string src;
	int wordLong = 0;
	int lastSpace = 0;
	int afterSpace = 0;
	if (search.substr(search.length() - 2, 2) == "**") {
		src = search.substr(0, search.length() - 2);
	}
	else {
		src = search.substr(0, search.length() - 1);
	}
	if (search.back() == "+"[0]) {

		s = " " + source;
		pos = s.find(src);
		wordLong = source.find(" ", pos - 1);
		if (pos >= 0 && s.substr(pos - 1, 1) == " ") {
			cout << "index: " << pos - 1 << " word: " << source.substr(pos - 1, wordLong - pos + 1) << endl;
		}
		while (s.find(src, pos + 1) != string::npos) {
			pos = s.find(src, pos + 1);
			wordLong = source.find(" ", pos);
			if (s.substr(pos - 1, 1) == " ") {
				cout << "index: " << pos - 1 << " word: " << source.substr(pos - 1, wordLong - pos + 1) << endl;
			}
		}
		pos = 0;
		wordLong = 0;
		lastSpace = 0;
		afterSpace = 0;
	}
	else if (search.back() == "."[0]) {
		pos = source.find(src);
		for (int k = 0; k < pos; k++) {
			if (source.substr(k, 1) == " ") {
				lastSpace = k;
			}
		}
		if (source.substr(pos + src.length(), 1) == " " && pos >= 0) {
			//source.substr();
			if (lastSpace == 0) {
				cout << "index: " << pos << " word: " << source.substr(0, pos + src.length()) << endl;

			}
			else {
				cout << "index: " << pos << " word: " << source.substr(lastSpace + 1, pos - lastSpace + src.length()) << endl;

			}
		}
		while (pos != string::npos && pos >= 0) {
			pos = source.find(src, pos + 1);
			for (int k = 0; k < pos; k++) {
				if (source.substr(k, 1) == " ") {
					lastSpace = k;
				}
			}
			if (source.substr(pos + src.length(), 1) == " " && pos >= 0) {
				//source.substr();
				if (lastSpace == 0) {
					cout << "index: " << pos << " word: " << source.substr(0, pos+ src.length()) << endl;

				}
				else {
					cout << "index: " << pos << " word: " << source.substr(lastSpace + 1, pos - lastSpace + src.length()) << endl;

				}
			}
		}
		pos = 0;
		wordLong = 0;
		lastSpace = 0;
		afterSpace = 0;
	}
	else if ((search.back() == "*"[0]) && (search.substr(search.length() - 2) != "**")) {

		s = " " + source;
		pos = s.find(src) - 1;
		for (int k = 0; k < pos; k++) {
			if (source.substr(k, 1) == " ") {
				lastSpace = k;
			}
		}
		if (pos == 0) {
			pos += 2;
		}
		afterSpace = source.find(" ", lastSpace + 1);
		if (!(source.substr(pos - 1, 1) == " ") && !(source.substr(pos + 1, 1) == " ") && source.substr(afterSpace - src.length(), src.length()) != src) {
			if (lastSpace == 0) {
				lastSpace = -1;
			}
			if (pos != string::npos && (source.substr(lastSpace + 1, src.length()) != src)) {
				cout << "index: " << pos << " word: " << source.substr(lastSpace + 1, afterSpace - lastSpace) << endl;

			}
		}
		pos = s.find(src, pos + 2) - 1;
		/**/
		while (pos != string::npos && pos >= -1) {

			for (int k = 0; k < pos; k++) {
				if (source.substr(k, 1) == " ") {
					lastSpace = k;
				}
			}

			afterSpace = source.find(" ", lastSpace + 1);

			if (!(source.substr(pos - 1, 1) == " ") && !(source.substr(pos + 1, 1) == " ") && source.substr(afterSpace - src.length(), src.length()) != src) {
				if (pos != string::npos && (source.substr(lastSpace + 1, src.length()) != src)) {
					cout << "index: " << pos << " word: " << source.substr(lastSpace + 1, afterSpace - lastSpace) << endl;

				}
			}
			pos = source.find(src, pos + 2);

		}
		pos = 0;
		wordLong = 0;
		lastSpace = 0;
		afterSpace = 0;
	}
	else {
		s = " " + source;
		pos = s.find(src);
		int k = 0;
		while (k < pos) {
			if (isspace(s[k])) {
				lastSpace = k - 1;
			}
			k++;
		}
		afterSpace = s.find(" ", pos) - 1;
		if (pos != string::npos) {
			cout << "index: " << pos - 1 << " word: " << source.substr(lastSpace + 1, afterSpace - lastSpace) << endl;

		}

		pos = s.find(src, pos + 1);
		while (pos != string::npos) {
			while (k < pos) {
				if (isspace(s[k])) {
					lastSpace = k - 1;
				}
				k++;
			}
			afterSpace = s.find(" ", pos) - 1;
			if (pos != string::npos) {
				cout << "index: " << pos - 1 << " word: " << source.substr(lastSpace + 1, afterSpace - lastSpace) << endl;
			}
			pos = s.find(src, pos + 1);
		}
		pos = 0;
		wordLong = 0;
		lastSpace = 0;
		afterSpace = 0;
	}

}

int main()
{
	string sourceString = "", sourceStringInput, searchString, endString, sourceStringLowered, searchStringLowered;
	int endStringPos;

	// source string input : done, updated source string does not contain "end"
	cout << "Enter source string: ";
	getline(cin, sourceStringInput);
	if (isValidSource(sourceStringInput)) {
		sourceString += sourceStringInput + " ";
		sourceStringLowered = ToLower(sourceString);
	}
	else {
		if (ToLower(sourceStringInput).find("end") != string::npos) {
			cout << "Enter source string: ";
		}
	}
	if (sourceStringLowered == "quit") {
		return 0;
	}

	while ((sourceStringLowered.find("end") > sourceString.length()) || !(isValidSource(sourceStringInput))) {
		if (sourceStringLowered == "quit") {
			return 0;
		}
		getline(cin, sourceStringInput);
		if (isValidSource(sourceStringInput)) {
			sourceString += sourceStringInput + " ";
			sourceStringLowered = ToLower(sourceString);
		}
		else {
			if (ToLower(sourceStringInput).find("end") != string::npos) {
				cout << "Enter source string: ";
			}
		}
	}
	endStringPos = sourceStringLowered.find("end");
	sourceString = sourceString.substr(0, endStringPos);

	// search string input : done
	cout << "Enter search string: ";
	getline(cin, searchString);
	if (ToLower(searchString) == "quit") {
		return 0;
	}
	if (isValidSearch(searchString)) {
		searchAlgorithm(sourceString, searchString);
	}

	while (ToLower(searchString) != "quit") {
		cout << "Enter search string: ";
		getline(cin, searchString);
		if (isValidSearch(searchString)) {
			searchAlgorithm(sourceString, searchString);
		}

	}

	return 0;
}
