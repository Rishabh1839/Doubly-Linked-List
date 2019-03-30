/*

Rishabh Singh
Doubly Linked List
CSC382

*/

#include <iostream>

using namespace std;

template <class Data>

class Node
{
	//setting it to public for access purposes (private by default)
public:
	Node *prev;
	Node *next;
	Data myData;

	//constructors
	Node(Data data_passed)
	{
		myData = data_passed;
		prev = nullptr;
		next = nullptr;
	}

	//constructor 2
	Node(Data passedin_data, Node *prev_node, Node *next_node)
	{
		myData = passedin_data;
		prev = prev_node;
		next = next_node;
	}

	//destructor
	~Node()
	{
		prev = nullptr;
		next = nullptr;
	}

};

//creating template class for mny object
template <class myObj>

class List
{
	Node <myObj> *first = nullptr;

public:
	Node <myObj>* getFirst()
	{
		return first;
	}

	//find data
	Node <myObj>* find(myObj data_to_find)
	{
		if (first == nullptr)
		{
			// Nothing has been added to the list yet
			return nullptr;
		}
		else
		{
			// There is already something in the list
			Node <myObj>* tempNode = first;

			//loops until it finds NODE
			while (tempNode != nullptr)
			{
				if (tempNode->myData == data_to_find)
				{
					return tempNode;
				}

				tempNode = tempNode->next;

			}
			
			return nullptr;

		}
	}
	//insert data
	void insert(myObj data_to_insert)
	{
		Node <myObj>* myNewNode = new Node <myObj> (data_to_insert);

		if (first == nullptr)
		{
			// Nothing has been added to the list yet
			first = myNewNode;
			return;
		}
		else
		{
			// There is already something in the list
			Node <myObj>* tempNode = first;

			//loops until it finds NODE
			while (tempNode->next != nullptr)
			{
				tempNode = tempNode->next;
			}

			tempNode->next = myNewNode;
			myNewNode->prev = tempNode;
		}
	}

	//delete data
	void Delete(myObj data_to_delete)
	{
		//finds the node if they exist
		Node <myObj>* tempNode = find(data_to_delete);
		//if tempNode is equal to nullptr then return it
		if (tempNode == nullptr)
		{
			return;
		}

		else
		{
			//sets the previous node to the old prev node
			if (tempNode->next != nullptr)
			{
				tempNode->next->prev = tempNode->prev;
			}
			
			//sets the next node to the old next node
			if (tempNode->prev != nullptr)
			{
				tempNode->prev->next = tempNode->next;
			}

			//setting first node to the next node  
			if (tempNode == first)
			{
				first = tempNode->next;
			}


			delete tempNode;
		}
	}
};

int main()
{
	//create the list
	List <int> myList;
	//inserting certain node values
	myList.insert(7);
	myList.insert(18);
	myList.insert(9);
	//finding nodes
	Node<int>* node7 = myList.find(7);
	Node<int>* node18 = myList.find(18);
	Node<int>* node9 = myList.find(9);
	//checking if Node7 is inserted as first otherwise its not
	if (myList.getFirst() == node7)
	{
		cout << "Success - Node 7 inserted as first" << endl;
	}
	else
	{
		cout << "Failed - Node 7 is not first." << endl;
	}
	//Checking if Node7 is set to nullptr when previous otherwise not
	if (node7->prev == nullptr)
	{
		cout << "Success - Node 7 previous is nullptr" << endl;
	}
	else
	{
		cout << "Failed - Node 7 previous is not nullptr" << endl;
	}

	//testing if the middle node is either set to next or previous is correct or not
	if (node18->prev == node7 && node18->next == node9)
	{
		cout << "Success - Node18 is equal to Node7 when set to previous, and Node18 is equal to Node9 when set to next" << endl;
	}
	else
	{
		cout << "Failed to set next and previous pointers for the following nodes" << endl;
	}

	//deleting nodes
	myList.Delete(18);
	myList.Delete(7);
	myList.Delete(9);
	system("pause");
}



