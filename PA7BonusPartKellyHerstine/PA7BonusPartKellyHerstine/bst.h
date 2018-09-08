/*
Author: Kelly Herstine
Class: Data Structures & Algorithims (CSI 281-01)
Assignment: PA6 part 1
Date Assigned: 10/26/17
Due Date: 11/2/17

Program Description: Binary Search Tree algorithms

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may,
for the purpose of assessing this assignment:- Reproduce this assignment and provide a copy to another member of
academic staff; and/or - Communicate a copy of this assignment to a plagiarism checking service
(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/

#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

template <class T>
class BST
{
private:
	template <class T>
	struct Node
	{
		T       mData;
		Node<T> *mLeft, *mRight;

		/*      Pre:  None
		*     Post:  This object is initialized using default values
		*  Purpose:  To intialize date object
		*************************************************************************/
		Node()
		{
			mData = T();
			mLeft = NULL;
			mRight = NULL;
		}

		/*      Pre:  None
		*     Post:  This object is initialized using specified data
		*  Purpose:  To intialize date object
		*************************************************************************/
		Node(T data)
		{
			mData = data;
			mLeft = NULL;
			mRight = NULL;
		}

		/*      Pre:  None
		*     Post:  This object is initialized using specified data with the
		*            specified children attached
		*  Purpose:  To intialize date object
		*************************************************************************/
		Node(T data, Node<T> *left, Node<T> *right)
		{
			mData = data;
			mLeft = left;
			mRight = right;
		}
	};

	Node<T> *mRootNode;

	/*      Pre:  None
	*     Post:  This object is initialized using specified data
	*  Purpose:  To intialize data object
	*************************************************************************/
	BST(T data, Node<T> *left = NULL, Node<T> *right = NULL);

	/*      Pre:  Needs the node of the tree
	*     Post:  Destroys the subtree that the user gives
	*  Purpose:  Destroys the subtree
	*************************************************************************/
	void destroySubtree(Node<T> *node);

	/*      Pre:  Needs the node of the tree
	*     Post:  Displays the order of the tree InOrder
	*  Purpose:  displays the order
	*************************************************************************/
	void displayInOrder(Node<T> *node);
	/*      Pre:  Needs the node of the tree
	*     Post:  Displays the order of the tree PreOrder
	*  Purpose:  displays the order
	*************************************************************************/
	void displayPreOrder(Node<T> *node);
	/*      Pre:  Needs the node of the tree
	*     Post:  Displays the order of the tree PostOrder
	*  Purpose:  displays the order
	*************************************************************************/
	void displayPostOrder(Node<T> *node);
	/*      Pre:  Needs the node of the tree and the tab that the user will include
	*     Post:  Displays the tree in the order which it would look like written down
	*  Purpose:  displays the tree
	*************************************************************************/
	void displayTree(Node<T> *node, int tab);
	/*      Pre:  None
	*     Post:  Calls the overloaded display tree function
	*  Purpose:  displays the tree
	*************************************************************************/
	void displayTree();
	/*      Pre:  Needs the node of the tree and the data the user would like to enter
	*     Post:  inserts the data into the node
	*  Purpose:  inserts data
	*************************************************************************/
	void insert(Node<T> *&node, const T &data);
	/*      Pre:  Needs the node of the tree
	*     Post:  delets the node
	*  Purpose:  deletes the node
	*************************************************************************/
	void makeDeletion(Node<T> *&node);
	/*      Pre:  Needs the node of the tree and the data the user would like to delete
	*     Post:  deletes the data from the tree
	*  Purpose:  deletes data
	*************************************************************************/
	void remove(Node<T> *&node, const T &searchKey);



public:
	/*      Pre:  None
	*     Post:  This object is initialized using specified data
	*  Purpose:  To intialize data object
	*************************************************************************/
	BST();
	/*      Pre:  None
	*     Post:  This object is deinitialized using specified data
	*  Purpose:  To deintialize data object
	*************************************************************************/
	~BST();

	/*      Pre:  None
	*     Post:  This function calls the insert function
	*  Purpose:  calls the insert function so the insert function can recursively insert
	*************************************************************************/
	void insert(T data);
	/*      Pre:  None
	*     Post:  Checks to see if the binary tree is empty
	*  Purpose:  checks to see if the binary tree is empty
	*************************************************************************/
	bool isEmpty();
	/*      Pre:  needs a search key to see if the object exists
	*     Post:  Checks to see if the data exists within the subtree
	*  Purpose:  checks to see if the data exists
	*************************************************************************/
	bool isExists(T searchKey);
	/*      Pre:  None
	*     Post:  This function calls the delete function
	*  Purpose:  calls the delete function so the delete function can recursively delete
	*************************************************************************/
	void remove(T searchKey);
	/*      Pre:  None
	*     Post:  This function calls the InOrder function
	*  Purpose:  calls the InOrder function
	*************************************************************************/
	void showInOrder();
	/*      Pre:  None
	*     Post:  This function calls the PreOrder function
	*  Purpose:  calls the PreOrder function
	*************************************************************************/
	void showPreOrder();
	/*      Pre:  None
	*     Post:  This function calls the PostOrder function
	*  Purpose:  calls the PostOrder function
	*************************************************************************/
	void showPostOrder();
	/*      Pre:  None
	*     Post:  This function calls the displaytree function
	*  Purpose:  calls the displaytree function
	*************************************************************************/
	void showTree();
	/*      Pre:  Needs the node of the tree
	*     Post:  returns the minimun value of the tree
	*  Purpose:  returns the minimum value of the tree
	*************************************************************************/
	int FindMin(Node<T> *node);

};


template <class T>
BST<T>::BST()
{
	mRootNode = NULL;
}


template <class T>
BST<T>::BST(T data, Node<T> *left = NULL, Node<T> *right = NULL)
{
	//initializes data
	Node<T> *newNode;

	newNode = new Node(data, left, right);
	if (newNode != NULL)
		mRootNode = newNode;
}


template <class T>
BST<T>::~BST()
{
	//destroys the subtree
	destroySubtree(mRootNode);
}

//DONE
template <class T>
void BST<T>::destroySubtree(Node<T> *node)
{
	//if no node, no need to destroy tree
	if (node == NULL)
		return;
	else
	{
		//recursily call the destroy tree and destroy the tree
		destroySubtree(node->mLeft);
		destroySubtree(node->mRight);
		delete(node);
		node = NULL;

	}


}

//DONE
template <class T>
void BST<T>::displayInOrder(Node<T> *node)
{

	if (node == NULL)
	{
		return;
	}
	else
	{
		//prints the left subtree
		displayInOrder(node->mLeft);
		//prints the root and other values
		cout << node->mData << " ";
		//prints the right subtree
		displayInOrder(node->mRight);

	}

}

//DONE
template <class T>
void BST<T>::displayPreOrder(Node<T> *node)
{
	if (node == NULL)
	{
		return;
	}
	else
	{
		//prints the root and other values
		cout << node->mData << " ";
		//prints the left subtree
		displayInOrder(node->mLeft);
		//prints the right subtree
		displayInOrder(node->mRight);

	}
}

//DONE
template <class T>
void BST<T>::displayPostOrder(Node<T> *node)
{
	if (node == NULL)
	{
		return;
	}
	else
	{
		//prints the left subtree
		displayInOrder(node->mLeft);
		//prints the right subtree
		displayInOrder(node->mRight);
		//prints the root and other values
		cout << node->mData << " ";

	}
}
//DONE
template<class T>
void BST<T>::displayTree(Node<T>* node, int tab)
{

	if (node == NULL)
		return;
	else
	{
		//tabs the output
		for (int i = 0; i < tab; i++)
		{
			cout << "\t";
		}
		//displays the data and recursively does so
		cout << node->mData << endl;
		displayTree(node->mLeft, tab + 1);
		displayTree(node->mRight, tab + 1);
	}



}
//DONE
template<class T>
void BST<T>::displayTree()
{
	//displays the tree with the proper tabbing
	displayTree(mRootNode, 0);
}

//DONE
template <class T>
void BST<T>::insert(T data)
{
	insert(mRootNode, data);
}

//DONE
template <class T>
void BST<T>::insert(Node<T> *&node, const T &data)
{
	//  this is for the recursive method
	Node<T> *tmp, *newNode;
	bool    inserted = false;

	newNode = new Node<T>(data);
	//checks to see if the node exists
	if (newNode == NULL)
		return;

	//checks to see if the root is equal to node and if so, make new node the root
	if (node == NULL)
		node = newNode;
	else
	{
		//goes through lists and each time moves throughout the tree to see where the data should land
		if (data < node->mData)
		{
			insert(node->mLeft, data);
		}
		else
		{
			insert(node->mRight, data);
		}
	}
}



//DONE
template <class T>
bool BST<T>::isEmpty()
{
	return (mRootNode == NULL);
}

//DONE
template <class T>
bool BST<T>::isExists(T searchKey)
{
	Node<T> *tmp, *newNode;
	bool    exists = false;

	//checks to see if the node exists
	if (mRootNode == NULL)
		exists = false;

	tmp = mRootNode;
	while (tmp != NULL)
	{
		//checks to see if the search key is already found
		if (tmp->mData == searchKey)
		{
			exists = true;
			break;
		}
		//checks to see where the search key should be and then moves towards that direction
		else if (tmp->mData < searchKey)
		{
			tmp = tmp->mRight;
		}
		else if (tmp->mData > searchKey)
		{
			tmp = tmp->mLeft;
		}
		else
		{
			exists = false;
		}
	}

	return exists;
}


//DONT NEED TO DO
template <class T>
void BST<T>::makeDeletion(Node<T> *&node)
{

}

//DONE kinda
template <class T>
void BST<T>::remove(Node<T> *&node, const T &searchKey)
{
	Node<T> *tmp, *oneAbove, *attachPoint, *parent;

	tmp = node;


	if (tmp == NULL)
	{
		return;
	}

	if (searchKey < node->mData)
	{
		//look in left sub tree
		remove(node->mLeft, searchKey);
	}
	else if (searchKey > node->mData)
	{
		//look in right subtree
		remove(node->mRight, searchKey);
	}
	else
	{
		/*deletes the node pointed to by the tree
		At the end of this, the user data in the node that is pointed to by the tree
		is no longer in the tree. If the tree is a leaf node or doesnt have a NULL child pointer,
		the node pointed to by tree is deleted. Or else the data is replaced with its logical
		pre node and the pre's node is deleted
		*/
		if (node->mLeft == NULL && node->mRight == NULL)
		{
			delete node;
			node = NULL;
		}
		else if (node->mLeft == NULL)
		{
			node = node->mRight;
			delete tmp;
		}
		else if (node->mRight == NULL)
		{
			node = node->mLeft;
			delete tmp;
		}
		else
		{
			T temp;
			temp = FindMin(node->mRight);
			node->mData = temp;
			remove(node->mRight, temp);

		}
	}
}

template<class T>
int BST<T>::FindMin(Node<T>* node)
{
	if (node == NULL)
	{
		return 0;
	}
	if (node->mLeft != NULL)
	{
		return FindMin(node->mLeft);
	}
	return node->mData;

}



//DONE
template <class T>
void BST<T>::remove(T searchKey)
{
	remove(mRootNode, searchKey);
}


template <class T>
void BST<T>::showInOrder()
{
	displayInOrder(mRootNode);
}


template <class T>
void BST<T>::showPreOrder()
{
	displayPreOrder(mRootNode);
}


template <class T>
void BST<T>::showPostOrder()
{
	displayPostOrder(mRootNode);
}

template<class T>
void BST<T>::showTree()
{
	displayTree();

}

#endif