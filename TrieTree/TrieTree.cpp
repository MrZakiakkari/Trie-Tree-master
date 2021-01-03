// TrieTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
//#include "stdafx.h"
#include "Trie.h"
#include "windows.h"

using namespace std;

// Setting gobal variabls and methods
void addTrieFromPDF();
int displayMenu(void);
void displayBanner();
void Insert();
void Search();
void Print();
void Delete();
void Finished();

bool leaveMenu = false;
int choice;
string input;

struct TrieNode* JonathanTrie = getNode();

int main()
{
	// Setting Color
	system("Color 80");

	//Change size of cmd
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 800, 600, TRUE);

	addTrieFromPDF();
	do
	{
		choice = displayMenu();
		
		switch (choice)
		{
			case 1:
				Insert();
				break;

			case 2:
				Search();
				break;

			case 3:
				Print();
				break;

			case 4:
				Delete();
				break;

			case 5:
				Finished();
				break;

			default:
				cout << "\tNot a valid choice!";
				break;
		}
		system("pause");
	}while(!leaveMenu);

	return 0;
	
}

// Varibles from Des PDF
void addTrieFromPDF()
{
	insert(JonathanTrie, "a");
	insert(JonathanTrie, "b");
	insert(JonathanTrie, "c");
	insert(JonathanTrie, "aa");
	insert(JonathanTrie, "ab");
	insert(JonathanTrie, "ac");
	insert(JonathanTrie, "ba");
	insert(JonathanTrie, "ca");
	insert(JonathanTrie, "aba");
	insert(JonathanTrie, "abc");
	insert(JonathanTrie, "baa");
	insert(JonathanTrie, "bab");
	insert(JonathanTrie, "bac");
	insert(JonathanTrie, "cab");
	insert(JonathanTrie, "abba");
	insert(JonathanTrie, "baba");
	insert(JonathanTrie, "caba");
	insert(JonathanTrie, "abaca");
	insert(JonathanTrie, "caaba");
}
// Display Menu
int displayMenu(void)
{
	int option;
	system("cls");
	displayBanner();
	cout << " 1 -> Insert Word into a Trie.\n";
	cout << " 2 -> Search a Trie for a specific word.\n";
	cout << " 3 -> Print Words Alphabetically.\n";
	cout << " 4 -> Delete A Word.\n";
	cout << " 5 -> Exit.\n\n";
	cout << "******************************************\n";
	cout << " \n  Enter your choice and press return: \n\n";
	cout << "******************************************\n";
	cin >> option;
	return option;
}
// Display banner
void displayBanner()
{
	cout << "******************************************\n";
	cout << "                 Trie Tree                \n";
	cout << "******************************************\n\n";
}
// Insert
void Insert()
{
	system("cls");
	displayBanner();
	
	cout << "Please enter a Word to insert: (Max 10 characters long) \n\n";	
	cin >> input;

	if (!search(JonathanTrie, input))
	{
		insert(JonathanTrie, input);
	}
	else
	{
		cout << "\t\t" + input + " is allready in the trie!\n\n\n";
		system("pause");
	}

}
// Search 
void Search() 
{
	system("cls");
	displayBanner();

	cout << " Please enter a word to search: ";
	cin >> input;
	search(JonathanTrie, input);
	if (search(JonathanTrie, input)) {
		cout << "\n\t" << input << " was located in Trie Tree!\n";
	}
	else {
		cout << "\n\t" << input << " was not located in Trie Tree!\n";
	}
}
// Print 
void Print()
{
	system("cls");
	displayBanner();

	if (isEmpty(JonathanTrie))
		cout << "\n\tTrie is empty!\n" << endl;
	else
		display(JonathanTrie, myWord, 0);
}
// Delete 
void Delete()
{
	system("cls");
	displayBanner();
	cout << " Please enter a word to delete: ";
	cin >> input;
	
	if (search(JonathanTrie, input))
		remove(JonathanTrie, input);
	else
	{
		cout << "\t\tCant remove " + input + " it is not in the trie!\n\n\n";
		system("pause");
	}
	
}
// Break out of Menu 
void Finished()
{
	cout << "End of Program.\n";
	cin.get();
	leaveMenu = true;
}