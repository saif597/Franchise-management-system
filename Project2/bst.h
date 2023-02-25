#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#include<iostream>
using namespace std;
struct BinarySearchTree
{
	int number;
	string name, idCard, address, network, status;
	int  recharge;
	BinarySearchTree* left, * right;
};
typedef BinarySearchTree* ptr;
ptr getNewNode(int num, string nam, string id, string add, string net, string stat, int rech)
{
	BinarySearchTree* newNode = new BinarySearchTree();
	newNode->number = num;
	newNode->name = nam;
	newNode->idCard = id;
	newNode->address = add;
	newNode->network = net;
	newNode->status = stat;
	newNode->recharge = rech;
	newNode->left = newNode->right = NULL;
	return newNode;
}
ptr insert(BinarySearchTree* root, int num, string nam, string id, string add, string net, string stat, int rech)
{
	if (root == NULL)
	{
		root = getNewNode(num, nam, id, add, net, stat, rech);
	}
	else if (num <= root->number)
	{
		root->left = insert(root->left, num, nam, id, add, net, stat, rech);
	}
	else
		root->right = insert(root->right, num, nam, id, add, net, stat, rech);
	return root;
}

void search(BinarySearchTree* root, int num)
{
	if (root == NULL)
	{
		cout << "Not found tree is empty" << endl;
	}
	else if (root->number == num)
	{
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\t\t\t\t\t\t\t*************" << endl;
		cout << "\t\t\t\t\t\t\tThe number is found" << endl;
		if (root->network == "zong")
		{
			cout << "\t\t\t\t\t\t\tThe number is : 0311" << root->number << endl;
		}
		if (root->network == "ufone")
		{
			cout << "\t\t\t\t\t\t\tThe number is : 0332" << root->number << endl;
		}
		if (root->network == "telenor")
		{
			cout << "\t\t\t\t\t\t\tThe number is : 0344" << root->number << endl;
		}
		if (root->network == "jazz")
		{
			cout << "\t\t\t\t\t\t\tThe number is : 0300" << root->number << endl;
		}
		cout << "\t\t\t\t\t\t\tThe name of owner is : " << root->name << endl;
		cout << "\t\t\t\t\t\t\tThe id-Card number is  : " << root->idCard << endl;
		cout << "\t\t\t\t\t\t\tThe address of owner is : " << root->address << endl;
		cout << "\t\t\t\t\t\t\tThe network of number is  : " << root->network << endl;
		cout << "\t\t\t\t\t\t\tThe  status of number is : " << root->status << endl;
		cout << "\t\t\t\t\t\t\tThe current balance is :  " << root->recharge << endl;
		cout << "\t\t\t\t\t\t\t************" << endl;
		cout << "Press any key to continue" << endl;
		system("pause>null");
		system("CLS");
	}
	else if (num <= root->number)
	{
		search(root->left, num);
	}
	else if (num >= root->number)

	{
		search(root->right, num);
	}
}
void searchInTree(string fileName, int numberToSearch)
{
	BinarySearchTree* root = NULL;

	int num, rech;
	string id, add, nam, stat, net;
	ifstream toR;
	string text;
	int count = 0;
	int c = 0;
	toR.open(fileName + ".txt");
	while (!toR.eof())
	{
		getline(toR, text);
		if (count == 0)
		{
			if (text == "")
			{
				break;
			}
			else
			{
				num = stoi(text);
				count++;
				continue;
			}
		}
		else if (count == 1)
		{
			nam = text;
			count++;
			continue;
		}
		else if (count == 2)
		{
			id = text;
			count++;
			continue;
		}
		else if (count == 3)
		{
			add = text;
			count++;
			continue;
		}
		else if (count == 4)
		{
			net = text;
			count++;
			continue;
		}
		else if (count == 5)
		{
			stat = text;
			count++;
			continue;
		}
		else if (count == 6)
		{
			rech = stoi(text);
			/*c++;
			if (c >= 1)
			{*/
			root = insert(root, num, nam, id, add, net, stat, rech);
			/*}
			else
			{
				insert(root, num, nam, id, add, net, stat, rech);
			}*/
			count++;
			continue;
		}
		else if (text == "~")
		{
			count = 0;
			continue;
		}
	}
	search(root, numberToSearch);
}