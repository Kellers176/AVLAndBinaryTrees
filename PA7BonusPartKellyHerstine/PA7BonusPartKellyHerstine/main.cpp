/*
Author: Kelly Herstine
Class: Data Structures & Algorithims (CSI 281-01)
Assignment: PA7 Bonus
Date Assigned: 10/26/17
Due Date: 11/2/17

Program Description: Compare AVL and BST trees with insert, delete, and search

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may,
for the purpose of assessing this assignment:- Reproduce this assignment and provide a copy to another member of
academic staff; and/or - Communicate a copy of this assignment to a plagiarism checking service
(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/

#include <iostream>
#include "AVL.h"
#include "TimerSystem.h"
#include "bst.h"

using namespace std;

int main()
{
	TimerSystem timer;
	cout.setf(ios::scientific | ios::showpoint);
	cout.precision(7);
	BST<int> bSTtree3;
	//BST
	bool what;
	int i = 0;

	cout << endl;
	cout << "      BST      " << endl << endl;
	cout << "----------------" << endl;
	cout << endl;
	cout << "Inserting 10 integers into Binary Search Tree....." << "\n";
	timer.startClock();
	for (i = 0; i < 11; i++)
	{
		bSTtree3.insert(i);
	}
	cout << "The amount of time it takes to insert 10 integers in a BST is: " << timer.getTime() << " seconds" << endl << endl;


	cout << "Searching for integer 55....." << endl;
	timer.startClock();
	what = bSTtree3.isExists(55);
	if (what)
	{
		cout << "This integer does exist" << endl;
	}
	else
	{
		cout << "This integer doesnt exist" << endl;
	}
	cout << "The amount of time needed to search through BST is: " << timer.getTime() << " seconds" << endl << endl;



	cout << "Removing the first 10 integers of the BST....." << endl;
	timer.startClock();
	for (i = 10; i >= 0; i--)
	{
		bSTtree3.remove(i);
	}
	cout << "The amount of time to remove 10 integers is: " << timer.getTime() << " seconds" << endl;
	cout << "=====================================================================================" << endl;
	//=-------------------------------------------------------------------------
	cout << endl;
	BST<int> bSTtree;
	cout << "Inserting 100 integers into Binary Search Tree....." << "\n";
	timer.startClock();
	for (i = 0; i < 101; i++)
	{
		bSTtree.insert(i);
	}
	cout << "The amount of time it takes to insert 100 integers in a BST is: " << timer.getTime() << " seconds" << endl << endl;
	

	cout << "Searching for integer 55....." << endl;
	timer.startClock();
	what = bSTtree.isExists(55);
	if (what)
	{
		cout << "This integer does exist" << endl;
	}
	else
	{
		cout << "This integer doesnt exist" << endl;
	}
	cout << "The amount of time needed to search through BST is: " << timer.getTime() << " seconds" << endl << endl;



	cout << "Removing the first 100 integers of the BST....." << endl;
	timer.startClock();
	for (i = 100; i >= 0; i--)
	{
		bSTtree.remove(i);
	}
	cout << "The amount of time to remove 100 integers is: " << timer.getTime() << " seconds" << endl;
	cout << "=====================================================================================" << endl;
	//----------------------------------------------------------------------------
	cout << endl;
	BST<int> bSTtree2;

	cout << "Inserting 1000 integers into Binary Search Tree....." << "\n";
	timer.startClock();
	for (i = 0; i < 1001; i++)
	{
		bSTtree2.insert(i);
	}
	cout << "The amount of time it takes to insert 1000 integers in a BST is: " << timer.getTime() << " seconds" << endl << endl;
	

	cout << "Searching for integer 55....." << endl;
	timer.startClock();
	what = bSTtree2.isExists(55);
	if (what)
	{
		cout << "This integer does exist" << endl;
	}
	else
	{
		cout << "This integer doesnt exist" << endl;
	}
	cout << "The amount of time needed to search through BST is: " << timer.getTime() << " seconds" << endl << endl;



	cout << "Removing the first 1000 integers of the BST....." << endl;
	timer.startClock();
	for (i = 1000; i >= 0; i--)
	{
		bSTtree2.remove(i);
	}
	cout << "The amount of time to remove 1000 integers is: " << timer.getTime() << " seconds" << endl;

	cout << "=====================================================================================" << endl;
	//===================================================================================================================================
	cout << endl;
	AVL<int> tree3;
	//AVL
	cout << "      AVL      " << endl << endl;
	cout << "----------------" << endl;
	cout << endl;
	cout << "Inserting 10 integers into AVL Search Tree....." << "\n";
	timer.startClock();
	for (i = 0; i < 11; i++)
	{
		tree3.insert(i);
	}
	cout << "The amount of time it takes to insert 10 integers in a AVL is: " << timer.getTime() << " seconds" << endl << endl;


	cout << "Searching for integer 55....." << endl;
	timer.startClock();
	what = tree3.isExists(55);
	if (what)
	{
		cout << "This integer does exist" << endl;
	}
	else
	{
		cout << "This integer doesnt exist" << endl;
	}
	cout << "The amount of time needed to search through AVL is: " << timer.getTime() << " seconds" << endl << endl;



	cout << "Removing the first 10 integers of the AVL....." << endl;
	timer.startClock();
	for (i = 10; i >= 0; i--)
	{
		tree3.remove(i);
	}
	cout << "The amount of time to remove 10 integers is: " << timer.getTime() << " seconds" << endl;
	cout << "=====================================================================================" << endl;
	//=-------------------------------------------------------------------------
	cout << endl;
	AVL<int> tree;

	cout << "Inserting 100 integers into AVL Tree....." << "\n";
	timer.startClock();
	for (i = 0; i < 101; i++)
	{
		tree.insert(i);
	}
	cout << "The amount of time it takes to insert 100 integers in AVL is: " << timer.getTime() << " seconds" << endl << endl;


	cout << "Searching for integer 55....." << endl;
	timer.startClock();
	what = tree.isExists(55);
	if (what)
	{
		cout << "This integer does exist" << endl;
	}
	else
	{
		cout << "This integer doesnt exist" << endl;
	}
	cout << "The amount of time needed to search through AVL is: " << timer.getTime() << " seconds" << endl << endl;
	

	cout << "Removing the first 100 integers of the AVL....." << endl;
	timer.startClock();
	for (i = 100; i >= 0; i--)
	{
		tree.remove(i);
	}
	cout << "The amount of time to remove 100 integers is: " << timer.getTime() << " seconds" << endl;
	cout << "=====================================================================================" << endl;
	//----------------------------------------------------------------------------
	cout << endl;
	AVL<int> tree2;

	cout << "Inserting 1000 integers into AVL Search Tree....." << "\n";
	timer.startClock();
	for (i = 0; i < 1001; i++)
	{
		tree2.insert(i);
	}
	cout << "The amount of time it takes to insert 1000 integers in a AVL is: " << timer.getTime() << " seconds" << endl << endl;


	cout << "Searching for integer 55....." << endl;
	timer.startClock();
	what = tree2.isExists(55);
	if (what)
	{
		cout << "This integer does exist" << endl;
	}
	else
	{
		cout << "This integer doesnt exist" << endl;
	}
	cout << "The amount of time needed to search through AVL is: " << timer.getTime() << " seconds" << endl << endl;



	cout << "Removing the first 1000 integers of the AVL....." << endl;
	timer.startClock();
	for (i = 1000; i >= 0; i--)
	{
		tree2.remove(i);
	}
	cout << "The amount of time to remove 1000 integers is: " << timer.getTime() << " seconds" << endl;

	system("pause");

	return 0;
}