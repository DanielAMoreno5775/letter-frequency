/*
This program reads a file. Then, it outputs the most and least common letters in that file.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <limits>
using namespace std;

void openInputFile(fstream&);
void countLettersInFile(fstream&, int[]);
void printMostCommon(int[], const int);
void printLeastCommon(int[], const int);

int main() {
	const int NUM_OF_LETTERS = 26;
	fstream dataFile;
	int letterCount[NUM_OF_LETTERS] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //element 0 for A, element 1 for B, ..., element 25 for Z

	openInputFile(dataFile);

	countLettersInFile(dataFile, letterCount);

	cout << endl << "======================" << endl;
	printMostCommon(letterCount, NUM_OF_LETTERS);
	printLeastCommon(letterCount, NUM_OF_LETTERS);

	return 0;
}

void openInputFile(fstream& inFile) {
	string filename = "";
	cout << "Please enter the filename and/or the filepath: ";
	cin >> filename;
	inFile.open(filename, ios::in);

	//run if and until the user enters a valid filename/filepath
	while (inFile.fail()) {
		cout << endl << "======================" << endl << "That filename/filepath was invalid." << endl;
		cout << "Please enter the filename and/or the filepath: ";
		cin >> filename;
		inFile.open(filename, ios::in);
	}
}

void countLettersInFile(fstream& file, int letterCount[]) {
	string line = "";
	char letter = '0';

	getline (file, line, '\n');
	while (file) {                                   //run while there are more lines in the file
		for (int i = 0; i < line.length(); i++) {    //iterate through each character in the line string
			letter = line[i];
			if (isalpha(letter)) {            //ensure that character is a letter
				letter = toupper(letter);
				letterCount[letter - 'A'] = (letterCount[letter - 'A'] + 1);
			}
		}
		getline(file, line, '\n');
	}
}

void printMostCommon(int arr[], const int SIZE) {
	const int CHAR_CODE_OF_A = 65;
	int largestValue = INT_MIN;
	int largestIndex = -1;

	for (int index = 0; index < SIZE; index++) {
		if (largestValue < arr[index]) {
			largestValue = arr[index];
			largestIndex = index;
		}
	}
	cout << "The most common letter is " << static_cast<char>(CHAR_CODE_OF_A + largestIndex) << " with " << largestValue << " occurences." << endl;
}

void printLeastCommon(int arr[], const int SIZE) {
	const int CHAR_CODE_OF_A = 65;
	int smallestValue = INT_MAX;
	int smallestIndex = -1;

	for (int index = 0; index < SIZE; index++) {
		if (smallestValue > arr[index]) {
			smallestValue = arr[index];
			smallestIndex = index;
		}
	}
	cout << "The least common letter is " << static_cast<char>(CHAR_CODE_OF_A + smallestIndex) << " with " << smallestValue << " occurences." << endl;
}