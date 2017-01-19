#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Treap.h"
#include "TreapNode.h"
#include "Queue.h"
using namespace std;


void displayMenu();
TreapNode treapNode(string name, string description, double price, double hitcount);
bool compare_by_name(const TreapNode& lhs, const TreapNode& rhs);

int main()
{
	string optionString = "";
	int option = 100;
	Treap treap;
	//Queue queue, secondQueue;
	vector<TreapNode> mainList;
	while (option != 0)
	{
		int option = 100;
		displayMenu();
		cin >> option;
		while (cin.fail())
		{
			cout << "Please enter an integer!" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> option;
		}
		
		if (option == 1)
		{
			string path, line, segment, name, description;
			double price;
			int hitcount, dataType = 0;
			vector<string> seglist;
			cout << "Please enter the file path for the file you would like to load (use \\\\ to sperate folders): " << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, path);
			if (path.at(0) == '\\')
			{
				path.erase(0, 2);
			}
			ifstream myFile;
			if (myFile.fail() == true)
			{
				cout << "File load failed.";
			}
			else
			{
				myFile.open(path);
				while (getline(myFile, segment, ';'))
				{
					seglist.push_back(segment);
				}
				if (seglist.size() == 0)
				{
					cout << "File load failed!" << endl;
				}
				else
				{
					for (int i = 0; i < seglist.size(); i++)
					{
						if (dataType == 0)
						{

							name = seglist[i];
							dataType = dataType + 1;
							
						}
						else if (dataType == 1)
						{
							description = seglist[i];
							dataType = dataType + 1;
						}
						else if (dataType == 2)
						{
							price = atof(seglist[i].c_str());
							dataType = dataType + 1;
						}
						else if (dataType == 3)
						{
							if (seglist[i].find("\n") != string::npos)
							{
								hitcount = atof(seglist[i].substr(0, seglist[i].find("\n")).c_str());
								treap.root = treap.insert(treap.root, name, description, price, hitcount);
								mainList.push_back(treapNode(name, description, price, hitcount));
							}
							else
							{
								hitcount = atof(seglist[i].c_str());
								treap.root = treap.insert(treap.root, name, description, price, hitcount);
								mainList.push_back(treapNode(name, description, price, hitcount));
							}
							if (seglist[i].find("\n") != string::npos)
							{
								name = seglist[i].substr(seglist[i].find("\n") + 1, seglist[i].size() - 1);
								dataType = 1;
							}
							else
								dataType = 0;
						}
					}
					cout << "File load success!" << endl;
				}
				
			}
			
		}
		else if (option == 2)
		{
			string name = "";
			cout << "Please enter the name of the item you would like find(Case-Sensitive): " << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, name);
			if (name == "")
			{
				cout << "Invalid input!" << endl;
			}
			else
			{
				TreapNode *tempNode = treap.search(treap.root, name);
				if (tempNode == NULL)
				{
					cout << "There is no item with that name." << endl;
				}
				else
				{
					cout << "Name: " << name << endl;
					cout << "Description: " << tempNode->description << endl;
					cout << "Price: " << tempNode->price << endl;
					cout << "Hitcounts: " << tempNode->hitcount << endl;
				}
			}
		}
		else if (option == 3)
		{
			vector<TreapNode> nodeList;
			nodeList = mainList;
			cout << "Names arranged in ascending order!" << endl;
			std::sort(nodeList.begin(), nodeList.end(), compare_by_name);
			/*/while (queue.isEmpty() == false)
			{
				TreapNode treapNode = queue.dequeue();
				secondQueue.enqueue(treapNode);
				nodeList.push_back(treapNode);
				std::sort(nodeList.begin(), nodeList.end(), compare_by_name);
			}
			while (secondQueue.isEmpty() == false)
			{
				TreapNode treapNode = secondQueue.dequeue();
				queue.enqueue(treapNode);
			}/*/
			for (int i = 0; i < mainList.size(); i++)
			{
				cout << "Name: " << nodeList[i].name << ", Description: " << nodeList[i].description << ", Price: " << nodeList[i].price << ", Hitcounts: " << nodeList[i].hitcount << endl;
			}
		}
		else if (option == 4)
		{
			string name = "";
			cout << "Please enter the name of the item you would like find(Case-Sensitive): " << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, name);
			if (name == "")
			{
				cout << "Invalid input!" << endl;
			}
			else
			{
				TreapNode *tempNode = treap.search(treap.root, name);
				if (tempNode == NULL)
				{
					cout << "There is no item with that name." << endl;
				}
				else
				{
					cout << "Name: " << name << endl;
					cout << "Hitcounts: " << tempNode->hitcount << endl;
				}
			}
		}
		else if (option == 5)
		{
			string path;
			ofstream myFile;
			cout << "Please enter the file path for the file you would like to write to (use \\ to sperate folders, start with \\ if in root): " << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, path);
			if (path.at(0) == '\\')
			{
				path.erase(0, 2);
			}
			if (myFile.fail() == true)
			{
				cout << "File load failed.";
			}
			else
			{
				myFile.open(path);
				/*/while (mainList.empty() == false)
				{
					TreapNode treapNode = queue.dequeue();
					secondQueue.enqueue(treapNode);
					myFile << treapNode.name << ";" << treapNode.description << ";" << treapNode.price << "; " << treapNode.hitcount << "\n";
				}
				while (secondQueue.isEmpty() == false)
				{
					TreapNode treapNode = secondQueue.dequeue();
					queue.enqueue(treapNode);
				}/*/
				for (int i = 0; i < mainList.size(); i++)
				{
					myFile << mainList[i].name << ";" << mainList[i].description << ";" << mainList[i].price << "; " << mainList[i].hitcount << "\n";
				}
				cout << "Written Successfully to file!" << endl;
			}
		}
		else if (option == 6)
		{
			string item;
			if (mainList.empty())
			{
				cout << "There is nothing in the tree!" << endl;
			}
			else
			{
				for (int i = 0; i < mainList.size(); i++)
				{
					cout << "Name: " << mainList[i].name << "Description: " << mainList[i].description << "Price: $" << mainList[i].price << "Hit Count: " << mainList[i].hitcount << endl;
				}
				cout << "Please enter the item you want to delete: " << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin, item);
				if (item == "")
				{
					cout << "Invalid input!" << endl;
				}
				else
				{
					TreapNode *tempNode = treap.search(treap.root, item);
					if (tempNode == NULL)
					{
						cout << "There is no item with that name." << endl;
					}
					else
					{
						treap.root = treap.deleteNode(treap.root, item);
						for (int i = 0; i < mainList.size(); i++)
						{
							if (mainList[i].name == item)
							{
								mainList.erase(mainList.begin() + i);
							}
						}
						cout << "Item deleted.";
					}
				}
			}
			


		}
		else if (option == 7)
		{
			string name, description,priceString,hitcountString;
			double price, hitcount;
			cout << "Please enter the name of the item you want to insert: " << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, name);
			TreapNode *tempNode = treap.search(treap.root, name);
			if (tempNode != NULL)
			{
				cout << "There is already an item with that name" << endl;
			}
			else
			{
				cout << "Please enter the description of the item you want to insert: " << endl;
				getline(cin, description);
				cout << "Please enter the price of the item you want to insert: " << endl;
				getline(cin, priceString);
				price = atof(priceString.c_str());
				cout << "Please enter the hitcount of the item you want to insert" << endl;
				getline(cin, hitcountString);
				hitcount = atof(hitcountString.c_str());
				treap.root = treap.insert(treap.root, name, description, price, hitcount);
				cout << "Item " << name << " inserted successfully." << endl;
				mainList.push_back(treapNode(name, description, price, hitcount));
			}
			
		}
		else if (option == 8)
		{
			
			if (mainList.empty())
			{
				cout << "There is nothing in the tree!" << endl;
			}
			else
				treap.inorder(treap.root);

		}
		else if (option == 0)
		{
			continue;
		}
		else
		{
			cout << "Invalid option!!!" << endl;
			
		}
	}
		
	system("PAUSE");
	return 0;
}

void displayMenu()
{
	cout << "_______________________________________" << endl << "	Hit Count Sorting System" << endl << "_______________________________________" << endl;
	cout << "1. Load Data" << endl;
	cout << "2. Search for an item" << endl;
	cout << "3. Display items in ascending order of name" << endl;
	cout << "4. Display the number of hits of an item" << endl;
	cout << "5. Save data to a file" << endl;
	cout << "6. Delete an item." << endl;
	cout << "7. Insert an item." << endl;
	cout << "8. Display the nodes in the tree." << endl;
	cout << "0. Exit" << endl;
	cout << "Please enter your option: " << endl;
}
TreapNode treapNode(string name, string description, double price, double hitcount)
{
	TreapNode temp;
	temp.name = name;
	temp.description = description;
	temp.price = price;
	temp.hitcount = hitcount;
	temp.left = temp.right = NULL;
	return temp;
}

bool compare_by_name(const TreapNode& lhs, const TreapNode& rhs)
{
	return lhs.name < rhs.name;
}