#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <limits>
using namespace std;

struct Book {
	string title;
	string author;
	int publicationYear;
};

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

void displayMenu() {
	cout << "Library System Menu:" << endl;
	cout << "1. Add books" << endl;
	cout << "2. Search for an author" << endl;
	cout << "3. Search for by book title" << endl;
	cout << "4. Display books" << endl;
	cout << "5. Quit" << endl;
}

void getChoice(int &userChoice) {
	cout << "Enter your choice: ";
	cin >> userChoice;
}

void displayBooks(vector<Book> books) {
	cout << "Sorted books by author's last name: " << endl;
	int i = 1;
	for (auto& a : books) {
		cout << i << ". " << a.title << ", "
			<< a.author << ", "
			<< a.publicationYear << endl;
		i++;
	}
	cout << endl;
}

void addBooks(vector<Book>& books) {
	string inputTitle, inputAuthor;
	int inputYear;
	Book newBook;
	cout << "Enter the new book details: " << endl;
	cout << "Enter book's title: ";
	cin.ignore();

	getline(cin, inputTitle);

	cout << "Enter book's author: ";
	getline(cin, inputAuthor);

	cout << "Enter book's publication year: ";
	cin >> inputYear;
	cin.ignore();

	newBook.title = inputTitle;
	newBook.author = inputAuthor;
	newBook.publicationYear = inputYear;
	books.push_back(newBook);
}

void insertionSort(vector<Book> &books) {
	sort(books.begin(), books.end(), [](const Book& book1, const Book& book2) {
		string lastName1 = book1.author.substr(book1.author.find_last_of(" ") + 1);
		string lastName2 = book2.author.substr(book2.author.find_last_of(" ") + 1);
		if (ToLower(lastName1) != ToLower(lastName2)) {
			return ToLower(lastName1) < ToLower(lastName2);
		}
		else {
			return ToLower(book1.title) < ToLower(book2.title);
		}
	});
}

void searchByAuthor(vector<Book>& books) { //the binary search algorithm to search for a book by the author
	string inputAuthor;
	cout << "Enter the author of the book you want to search for: ";
	cin.ignore();
	getline(cin, inputAuthor);

	int l = 0;
	int r = books.size()-1;
	int pos = -1;
	while (l <= r) {
		int m = l + (r - 1) / 2;
		
		if (m >= books.size()) {
			break;
		}
		// books[m].author.substr(books[m].author.find_last_of(" ") + 1)
		if (ToLower(books[m].author.substr(books[m].author.find_last_of(" ") + 1)) == ToLower(inputAuthor.substr(inputAuthor.find_last_of(" ") + 1))) {
			pos = m;
			break;
		}

		if (ToLower(books[m].author.substr(books[m].author.find_last_of(" ") + 1)) < ToLower(inputAuthor.substr(inputAuthor.find_last_of(" ") + 1))) {
			l = m + 1;
		}

		else {
			r = m - 1;
		}
	}
	if (pos == -1) {
		cout << "No books were found." << endl;
	}
	else {
		cout << "Books by " << inputAuthor.substr(inputAuthor.find_last_of(" ") + 1) << ":" << endl;
		while ( pos < books.size() && ToLower(books[pos].author) == ToLower(inputAuthor)) {
			cout << "Title: " << books[pos].title << ", Publication Year: " << books[pos].publicationYear << ", Position: " << pos+1;
			cout << endl;
			pos++;
		}
	}
}

void searchByTitle(vector<Book>& books) { //linear search algorithm to search by title
	string inputTitle;
	cout << "Enter the title of the book you want to search for: ";
	cin.ignore();
	getline(cin, inputTitle);
	
	cout << "Books matching the title \"" << inputTitle << "\":" << endl;
	bool found = false;
	int pos = 0;

	for (int i = 0; i < books.size(); i++) {
		if (ToLower(books[i].title) == ToLower(inputTitle)) {
			pos = i;
			found = true;
			break;
		}
	}
	
	if (found == false) {
		cout << "No books were found." << endl;
	}
	else {
		while (pos < books.size() && ToLower(books[pos].title) == ToLower(inputTitle)) {
			cout << "Title: " << books[pos].title << ", Author: " << books[pos].author << ", Publication Year: " << books[pos].publicationYear << ", Position: " << pos+1 << endl;
			pos++;
		}
	}
}

int main() {
	vector<Book> books = {
{"The Great Gatsby", "F Scott Fitzgerald", 1925},
{"Moby Dick", "Herman Melville", 1851},
{"To Kill a Mockingbird", "Harper Lee", 1960},
{"Pride and Prejudice", "Jane Austen", 1813},
{"Burmese Days", "George Orwell", 1934},
{"Brave New World", "Aldous Huxley", 1932},
{"Animal Farm", "George Orwell", 1945}
	};
	
	int userChoice = 0;
	do {

		insertionSort(books);
		displayMenu();
		getChoice(userChoice);
		if (cin.fail() || userChoice < 1 || userChoice > 5) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid choice, please try again." << endl;
		}
		else {	
			if (userChoice == 1) { //done
				addBooks(books);
			}
			else if (userChoice == 2) { //done
				searchByAuthor(books);
			}
			else if (userChoice == 3) {
				searchByTitle(books);
			}
			else if (userChoice == 4) { // done
				displayBooks(books); 
			}
		}
	} while (userChoice != 5);
	cout << "Goodbye!";

	return 0;
}
