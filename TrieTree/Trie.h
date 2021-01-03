#pragma once

//#include "stdafx.h"
#include "EntryType.h"

// For Alphabet
const int ALPHABET_SIZE = 26;
// char Word 
char myWord[10];

struct TrieNode
{
	// array of 26 pointers
	struct TrieNode* alphabet[ALPHABET_SIZE];	
	// if end of node
	bool endOfNode;								
};

struct TrieNode* getNode()
{
	struct TrieNode* myNewNode = new TrieNode;
	myNewNode->endOfNode = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		myNewNode->alphabet[i] = NULL;
	return myNewNode;
}

void insert(struct TrieNode* root, string myWord)
{
	struct TrieNode* tempNode = root;

	for (int i = 0; i < myWord.length(); i++)
	{
		int index = myWord[i] - 'a';		
			if (!tempNode->alphabet[index])
			tempNode->alphabet[index] = getNode();

		tempNode = tempNode->alphabet[index];
	}
	tempNode->endOfNode = true;
}

bool search(struct TrieNode* root, string myWord)
{
	struct TrieNode* tempNode = root;

	for (int i = 0; i < myWord.length(); i++)
	{
		int index = myWord[i] - 'a';
		if (!tempNode->alphabet[index])
			return false;
		tempNode = tempNode->alphabet[index];
	}

	return (tempNode != NULL && tempNode->endOfNode);
}
// Check if trie is empty
bool isEmpty(TrieNode* root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->alphabet[i])
			return false;
	}
	return true;
}

TrieNode* remove(TrieNode* root, string searchString, int counter = 0)
{
	// we delete the key in bottom up manner
	// using recursion
	
		// Is the letter in the Trie
		// Is the letter a leaf to another letter 
		// Does the letter have a leaf letter - delete refernce to itself
		// Is the letter empty and with no leafs - just delete
		

	// if tree is empty
	if (!root)
		return NULL;

	// checkin to see if we are on the last char of word
	if (counter == searchString.size())
	{
		// of node does not have end of node after removing key
		if (root->endOfNode)
			root->endOfNode = false;

		// if key is not a prefix to another word
		if (isEmpty(root))
		{
			delete (root);
			root = NULL;
		}

		return root;
	}

	// ascii a = 97 
	// a-a = 0 so word is at index 0 
	// b - a = 1 so word is at index 1 etc.
	int index = searchString[counter] - 'a'; 
	root->alphabet[index] = remove(root->alphabet[index], searchString, counter + 1); // calls itself with index of word

	// if the root has no child and not end of another word 
	if (isEmpty(root) && root->endOfNode == false)
	{
		delete (root);
		root = NULL;
	}

	return root;
}

void display(struct TrieNode* root, char myString[], int trieLevel)
{
	// if root is the only node
	if (root->endOfNode)
	{
		myString[trieLevel] = '\0';
		cout << "\t" << myString << endl;
	}

	int i;
	// Recursive function to go throught 26 and print root
	for (i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->alphabet[i])
		{
			myString[trieLevel] = i + 'a';
			display(root->alphabet[i], myString, trieLevel+1);
		}
	}

}