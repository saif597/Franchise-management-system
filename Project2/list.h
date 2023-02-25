#include<iostream>
using namespace std;
class  List
{
	struct node
	{
		int number;
		string name, idCard, address, network, status;
		int recharge;
		struct node* next;
		struct node* pre;
	};
	typedef struct node* nodeptr;
	nodeptr listptr;
public:
	List();
	void insert(int num, string nam, string id, string add, string net, string stat, int rech);
	void displayNumByName(string nam);
};

List::List()
{
	listptr = 0;
}

void List::insert(int num, string nam, string id, string add, string net, string stat, int rech)
{
	nodeptr p = new node;
	p->number = num;
	p->name = nam;
	p->idCard = id;
	p->address = add;
	p->network = net;
	p->status = stat;
	p->recharge = rech;
	p->next = listptr;
	p->pre = NULL;
	listptr = p;
}
void List::displayNumByName(string nam)
{
	int countDisplay = 0;
	nodeptr p = new node;
	p = listptr;
	while (p != NULL)
	{
		if (p->name == nam)
		{
			countDisplay++;
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\n";
			cout << "\t\t\t\t\t\t\t*************" << endl;
			cout << " " << endl;
			if (p->network == "zong")
			{
				cout << "\t\t\t\t\t\t\tThe number is : 0311" << p->number << endl;
			}
			if (p->network == "ufone")
			{
				cout << "\t\t\t\t\t\t\tThe number is : 0332" << p->number << endl;
			}
			if (p->network == "telenor")
			{
				cout << "\t\t\t\t\t\t\tThe number is : 0344" << p->number << endl;
			}
			if (p->network == "jazz")
			{
				cout << "\t\t\t\t\t\t\tThe number is : 0300" << p->number << endl;
			}
			cout << "\t\t\t\t\t\t\tName of user : " << p->name << endl;
			cout << "\t\t\t\t\t\t\tid-Card number of user : " << p->idCard << endl;
			cout << "\t\t\t\t\t\t\tAddress of user : " << p->address << endl;
			cout << "\t\t\t\t\t\t\tNetwork of number : " << p->network << endl;
			cout << "\t\t\t\t\t\t\tStatus of number : " << p->status << endl;
			cout << "\t\t\t\t\t\t\tcurrent balance : " << p->recharge << endl;
			cout << " " << endl;
			cout << "\t\t\t\t\t\t\t*************" << endl;
		}
		p = p->next;
	}
	if (countDisplay == 0)
	{
		cout << "Name not registered " << endl;
	}
	cout << "Press any key to continue" << endl;
	system("pause>null");
	system("CLS");
}
List insertFromFile(string fileName)
{
	List toReturn;
	int num, rech;
	string id, add, nam, stat, net;
	ifstream toR;
	string text;
	int count = 0;
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
			toReturn.insert(num, nam, id, add, net, stat, rech);
			count++;
			continue;
		}
		else if (text == "~")
		{
			count = 0;
			continue;
		}
	}
	return toReturn;
}
void insertAndFind(string fName, string nam)
{
	List l;
	l = insertFromFile(fName);
	l.displayNumByName(nam);
}