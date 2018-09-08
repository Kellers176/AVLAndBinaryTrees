/***        Author:  Kelly Herstine and Walter Hill
*         Class:  CSI-281-01
*    Assignment: PA 7
* Date Assigned: November 9, 2017
*      Due Date: November 16, 2017, 09:30
*
* Description:
*      AVL Rotation

* Certification of Authenticity:
*    I certify that this is entirely my own work, except where I have given
* fully-documented references to the work of others.I understand the definition and
* consequences of plagiarism and acknowledge that the assessor of this assignment may, for
* the purpose of assessing this assignment:
* - Reproduce this assignment and provide a copy to another member of academic staff; and/or
* - Communicate a copy of this assignment to a plagiarism checking service(which may then
*   retain a copy of this assignment on its database for the purpose of future plagiarism
*   checking)
********************************************************************************************/
/* ***        Author:  Wei Kian Chen
*   Modified by:
*         Class:  CSI-281
*      Filename:  avl.h
*    Assignment: PA7
* Date Assigned: November 9, 2017
*      Due Date: November 16, 2017
*
*  Description:
*      This is the template AVL definition.
*
*  Certification of Authenticity:
*     I certify that this assignment is entirely my own work.
********************************************************************/

#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class AVL
{
private:
	template <typename R>
	struct Node
	{
		R       mData;
		int     mHeight;
		Node<R> *mLeft, *mRight;

		/*      Pre:  None
		*     Post:  This object is initialized using default values
		*  Purpose:  To intialize date object
		*************************************************************************/
		Node()
		{
			mData = R();
			mHeight = 1;
			mLeft = NULL;
			mRight = NULL;
		}


		/*      Pre:  None
		*     Post:  This object is initialized using specified data
		*  Purpose:  To intialize date object
		*************************************************************************/
		Node(R data)
		{
			mData = data;
			mHeight = 1;
			mLeft = NULL;
			mRight = NULL;
		}
	};

	Node<T> *mRootNode;

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
	/*      Pre:  Needs the node
	*     Post:  This function returns the balance of the current node
	*  Purpose:  returns the balance
	*************************************************************************/
	int  getBalance(Node<T> *node);
	/*      Pre:  Needs the node
	*     Post:  This function returns the height of the current node
	*  Purpose:  returns the height
	*************************************************************************/
	int  getHeight(Node<T> *node);
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
	/*      Pre:  Needs the node
	*     Post:  This function checks the balance of the tree and then rotates it to the left
	*  Purpose:  rotates the tree left
	*************************************************************************/
	void rotateLeft(Node<T> *&node);
	/*      Pre:  Needs the node
	*     Post:  This function checks the balance of the tree and then rotates it to the left and then right
	*  Purpose:  rotates the tree left and then right
	*************************************************************************/
	void rotateLeftRight(Node<T> *&node);
	/*      Pre:  Needs the node
	*     Post:  This function checks the balance of the tree and then rotates it to the right
	*  Purpose:  rotates the tree right
	*************************************************************************/
	void rotateRight(Node<T> *&node);
	/*      Pre:  Needs the node
	*     Post:  This function checks the balance of the tree and then rotates it to the right and then left
	*  Purpose:  rotates the tree right and then left
	*************************************************************************/
	void rotateRightLeft(Node<T> *&node);
	/*      Pre:  Needs the integer of the min and the max of the tree
	*     Post:  returns the max number of the tree
	*  Purpose:  returns the max
	*************************************************************************/
	int max(int min, int max);
	/*      Pre:  Needs the node
	*     Post:  Updates the height of the tree
	*  Purpose:  returns the new height
	*************************************************************************/
	int updateHeight(Node<T> *&node);
	/*      Pre:  Needs the node
	*     Post:  Balances tree after insertion
	*  Purpose:  Checks balance of tree after insertion
	*************************************************************************/
	void insertBalance(Node<T> *&node);
	/*      Pre:  Needs the node
	*     Post:  Balances tree after removal
	*  Purpose:  Checks balance of tree after removal
	*************************************************************************/
	void removeBalance(Node<T> *&node);


public:
	/*      Pre:  None
	*     Post:  This object is initialized using specified data
	*  Purpose:  To intialize data object
	*************************************************************************/
	AVL();
	/*      Pre:  None
	*     Post:  This object is deinitialized using specified data
	*  Purpose:  To deintialize data object
	*************************************************************************/
	~AVL();

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

};


template <typename T>
AVL<T>::AVL()
{
	mRootNode = NULL;
}


template <typename T>
AVL<T>::~AVL()
{
	destroySubtree(mRootNode);
}


template <typename T>
void AVL<T>::destroySubtree(Node<T> *node)
{
	if (node == NULL)
		return;

	destroySubtree(node->mLeft);
	destroySubtree(node->mRight);

	// Delete the node at the root.
	delete node;
}


template <typename T>
void AVL<T>::displayInOrder(Node<T> *node)
{
	if (node != NULL)
	{
		displayInOrder(node->mLeft);
		cout << node->mData << "  ";
		displayInOrder(node->mRight);
	}
}


template <typename T>
void AVL<T>::displayPreOrder(Node<T> *node)
{
	if (node != NULL)
	{
		cout << node->mData << "  ";
		displayPreOrder(node->mLeft);
		displayPreOrder(node->mRight);
	}
}


template <typename T>
void AVL<T>::displayPostOrder(Node<T> *node)
{
	if (node != NULL)
	{
		displayPostOrder(node->mLeft);
		displayPostOrder(node->mRight);
		cout << node->mData << "  ";
	}
}


template <typename T>
void AVL<T>::displayTree(Node<T> *node, int tab)
{
	int i;

	if (node != NULL)
	{
		for (i = 0; i < tab; i++)
			cout << "  ";

		cout << node->mData << "(H: " << node->mHeight << ", B:  " << getBalance(node) << ")\n";

		displayTree(node->mLeft, tab + 1);
		displayTree(node->mRight, tab + 1);
	}
}


// Balance is defined as H(R) - H(L)
template <typename T>
int AVL<T>::getBalance(Node<T> *node)
{
	if (node == NULL)
		return 0;
	else
		return getHeight(node->mRight) - getHeight(node->mLeft);
}


template <typename T>
int AVL<T>::getHeight(Node<T> *node)
{
	if (node == NULL)
		return 0;
	else
	{
		return node->mHeight;
	}
}


template <typename T>
void AVL<T>::insert(T data)
{
	insert(mRootNode, data);
}



template <typename T>
void AVL<T>::insertBalance(Node<T> *&node)
{
	if (getBalance(node) > 1)
	{
		if (getBalance(node->mLeft) > 1)
		{
			rotateRightLeft(node);
		}
		else
		{
			rotateLeft(node);
		}
	}
	if (getBalance(node) < -1)
	{
		if (getBalance(node->mRight) < -1)
		{
			rotateLeftRight(node);
		}
		else
		{
			rotateRight(node);
		}
	}


}

template <typename T>
void AVL<T>::insert(Node<T> *&node, const T &data)
{
	// If the tree is empty, make a new node and make it 
	// the root of the tree.
	if (node == NULL)
	{
		node = new Node<T>(data);
		return;
	}

	// If num is already in tree: return.
	if (node->mData == data)
		return;

	// The tree is not empty: insert the new node into the
	// left or right subtree.
	if (data < node->mData)
	{
		insert(node->mLeft, data);
		insertBalance(node);
	}
	else
	{
		insert(node->mRight, data);
		insertBalance(node);
	}

	//  adjust the height of the current node
	updateHeight(node);
}


template <typename T>
bool AVL<T>::isEmpty()
{
	return (mRootNode == NULL);
}


template <typename T>
bool AVL<T>::isExists(T searchKey)
{
	Node<T> *tmp = mRootNode;

	while (tmp != NULL)
	{
		if (tmp->mData == searchKey)
			return true;
		else if (tmp->mData > searchKey)
			tmp = tmp->mLeft;
		else
			tmp = tmp->mRight;
	}
	return false;
}


template <typename T>
void AVL<T>::makeDeletion(Node<T> *&node)
{
	// Used to hold node that will be deleted.
	Node<T> *nodeToDelete = node;

	// Used to locate the  point where the 
	// left subtree is attached.
	Node<T> *attachPoint;

	// Replace tree with its left subtree.	
	if (node->mRight == NULL)
	{
		node = node->mLeft;
	}
	// Replace tree with its right subtree.        
	else if (node->mLeft == NULL)
	{
		node = node->mRight;
	}
	else
	{
		// Move to right subtree.
		attachPoint = node->mRight;

		// Locate the smallest node in the right subtree
		// by moving as far to the left as possible.
		while (attachPoint->mLeft != NULL)
			attachPoint = attachPoint->mLeft;

		// Attach the left subtree of the original tree
		// as the left subtree of the smallest node 
		// in the right subtree.
		attachPoint->mLeft = node->mLeft;

		// Replace the original tree with its right subtree.
		node = node->mRight;
	}

	// Delete root of original tree
	delete nodeToDelete;
}



template <typename T>
void AVL<T>::removeBalance(Node<T> *&node)
{
	if (getBalance(node) > 1)
	{
		if (getBalance(node->mLeft) < 1)
		{
			rotateLeft(node);
		}
		else
		{
			rotateLeftRight(node);
		}
	}
	if (getBalance(node) < -1)
	{
		if (getBalance(node->mRight) > -1)
		{
			rotateRight(node);
		}
		else
		{
			rotateRightLeft(node);
		}
	}
}


template <typename T>
void AVL<T>::remove(Node<T> *&node, const T &searchKey)
{
	if (node == NULL)
		return;
	else if (node->mData > searchKey)
	{
		remove(node->mLeft, searchKey);
	}
	else if (node->mData < searchKey)
	{
		remove(node->mRight, searchKey);
	}
	else
	{
		// We have found the node to delete.
		makeDeletion(node);
		updateHeight(node);
		removeBalance(node);

	}

	updateHeight(node);
}


template <typename T>
void AVL<T>::remove(T searchKey)
{
	remove(mRootNode, searchKey);
}


template <typename T>
void AVL<T>::showInOrder()
{
	displayInOrder(mRootNode);
}


template <typename T>
void AVL<T>::showPreOrder()
{
	displayPreOrder(mRootNode);
}


template <typename T>
void AVL<T>::showPostOrder()
{
	displayPostOrder(mRootNode);
}


template <typename T>
void AVL<T>::showTree()
{
	displayTree(mRootNode, 0);
}

template<typename T>
int AVL<T>::max(int min, int max)
{
	if (min > max)
	{
		return min;
	}
	else
	{
		return max;
	}
}

template<typename T>
int AVL<T>::updateHeight(Node<T> *&node)
{
	if (node == NULL)
	{
		return 0;
	}
	else if (node->mHeight != 1 && node != NULL)
	{
		updateHeight(node->mLeft);
		updateHeight(node->mRight);
	}
	node->mHeight = max(getHeight(node->mLeft), getHeight(node->mRight)) + 1;
	return node->mHeight;
}


template <typename T>
void AVL<T>::rotateLeft(Node<T> *&node)
{
	Node<T> *tmp = node->mRight;
	node->mRight = tmp->mLeft;
	tmp->mLeft = node;
	node = tmp;
	updateHeight(node);
	tmp->mHeight = max(getHeight(tmp->mLeft), getHeight(node->mRight)) + 1;
}


template <typename T>
void AVL<T>::rotateLeftRight(Node<T> *&node)
{
	rotateLeft(node->mLeft);
	rotateRight(node);
}


template <typename T>
void AVL<T>::rotateRight(Node<T> *&node)
{
	Node<T> *tmp = node->mLeft;
	node->mLeft = tmp->mRight;
	tmp->mRight = node;
	node = tmp;
	updateHeight(node);
	tmp->mHeight = max(getHeight(tmp->mLeft), getHeight(node->mRight) + 1);
}


template <typename T>
void AVL<T>::rotateRightLeft(Node<T> *&node)
{
	rotateRight(node->mRight);
	rotateLeft(node);
}


#endif