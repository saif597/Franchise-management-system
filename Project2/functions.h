#include<iostream>
#include<string>
#include<fstream>
#include<stdio.h>
#include<conio.h>
using namespace std;
template <class Tu>
class Stack
{
	int top;
	Tu* item;
	Tu maxItem;
public:
	Stack();
	Stack(Tu numberOfItems);
	//~Stack();
	bool isFull();
	bool isEmpty();
	void Push(Tu x);
	Tu pop();
	void InsertToStack()
	{
		ifstream toRead;
		toRead.open("generatedNumbersTillNow.txt", ios::app);
		while (!toRead.eof())
		{
			int c;
			toRead >> c;
			Push(c);
		}
		toRead.close();
	}
};
template <class Tu>
Stack<Tu> ::Stack()
{
	top = -1;
	maxItem = 5000;
	item = new Tu[5000];
}
template <class Tu>
Stack<Tu> ::Stack(Tu numberOfItems)
{
	top = -1;
	maxItem = numberOfItems;
	item = new Tu[maxItem];
}
//template <class T>
//Stack<T> :: ~Stack()
//{
//	delete[]item;
//}
template <class Tu>
bool Stack<Tu> ::isFull()
{
	return(top == maxItem - 1);
}
template <class Tu>
bool Stack<Tu> ::isEmpty()
{
	return (top == -1);
}
template <class Tu>
void Stack<Tu> ::Push(Tu x)
{
	if (isFull())
	{
		cout << "Stack Overflow " << endl;
		exit(1);
	}
	else
	{
		item[++top] = x;
	}
}
template <class Tu>
Tu Stack<Tu> ::pop()
{
	if (isEmpty())
	{
		cout << "Stack Underflow " << endl;
		exit(1);
	}
	else
	{
		return item[top--];
	}
}
int generateNum(int x)
{
	int temp = 1000000 + x + 1;
	ofstream file;
	file.open("num.txt");
	int update;
	update = x + 1;
	file << update << endl;
	file.close();
	Stack <int> nums;
	nums.InsertToStack();
	while (!nums.isEmpty())
	{
		int n;
		n = nums.pop();
		if (n == temp)
		{
			return generateNum(x + 1);
		}
		else
		{
			return temp;
		}
	}
}
int lastNumGenearted()
{
	ifstream f;
	f.open("num.txt");
	int lastNum;
	do
	{
		f >> lastNum;
	} while (!f.eof());
	f.close();
	return lastNum;
}
string inputPass()
{
	const int pass = 15;
	char password[pass + 1];
	char ch;
	int position = 0;
	cout << "Enter your password: ";
	while (1)
	{
		ch = _getch();
		if (ch == 13)
		{
			break;
		}
		else if (ch == 8)
		{
			if (position > 0)
			{
				position--;
				password[position] = '\0';
				cout << "\b \b";
			}
		}
		else if (ch == 32 || ch == 9)
		{
			continue;
		}
		else
		{
			if (position < pass)
			{
				password[position] = ch;
				position++;
				cout << "*";
			}
			else
			{
				cout << "Invalid password";
				break;
			}
		}
	}
	password[position] = '\0';
	return password;
}
void generatedNumbers(int s)
{
	ofstream g;
	g.open("generatedNumbersTillNow.txt", ios::app);
	g << s << endl;
	g.close();
}
bool goldenFound(Stack<int> s, int n)
{
	bool b = false;
	while (!s.isEmpty())
	{
		int num = s.pop();
		if (num == n)
		{
			b = true;
			break;
		}
		else
		{
			continue;
		}
	}
	return b;
}
bool numberIsInFile(int n, string file)
{
	int num, rech;
	string id, add, nam, stat, net;
	ifstream toR;
	string text;
	int count = 0;
	bool ans = false;
	toR.open(file + ".txt");
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
				if (num == n)
				{
					ans = true;
				}
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
			count++;
			continue;
		}
		else if (text == "~")
		{
			count = 0;
			continue;
		}
	}
	return ans;
}
void rechargeNum(int n, string fileName)
{
	int amount;
	cout << "Enter the amount of rupees for load : ";
	cin >> amount;
	int num, rech;
	string id, add, nam, stat, net;

	ifstream toRead;
	ofstream toWrite;
	string text;
	int count = 0;
	bool check = false;
	toRead.open(fileName + ".txt");
	toWrite.open("new" + fileName + ".txt");
	while (!toRead.eof())
	{
		getline(toRead, text);
		if (count == 0)
		{
			if (text == "")
			{
				break;
			}
			else
			{
				num = stoi(text);
				if (num == n)
				{
					check = true;
				}
				else if (num != n)
				{
					check = false;
				}
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
			if (check == true)
			{
				rech = rech + amount;
				cout << "number recharged ! current balance is : " << rech << endl;
			}
			toWrite << num << endl;
			toWrite << nam << endl;
			toWrite << id << endl;
			toWrite << add << endl;
			toWrite << net << endl;
			toWrite << stat << endl;
			toWrite << rech << endl;
			toWrite << "~" << endl;
			count++;
			continue;
		}
		else if (text == "~")
		{
			count = 0;
			continue;
		}
	}
	toRead.close();
	toWrite.close();
	/*toRead.open("new" + fileName + ".txt");
	toWrite.open(fileName + ".txt");*/
	toRead.open("new" + fileName + ".txt");
	toWrite.open(fileName + ".txt");
	count = 0;
	while (!toRead.eof())
	{
		getline(toRead, text);
		if (count == 0)
		{
			if (text == "")
			{
				break;
			}
			else
			{
				toWrite << text << endl;
				count++;
				continue;
			}
		}
		else if (count == 1)
		{
			toWrite << text << endl;
			count++;
			continue;
		}
		else if (count == 2)
		{
			toWrite << text << endl;
			count++;
			continue;
		}
		else if (count == 3)
		{
			toWrite << text << endl;
			count++;
			continue;
		}
		else if (count == 4)
		{
			toWrite << text << endl;
			count++;
			continue;
		}
		else if (count == 5)
		{
			toWrite << text << endl;
			count++;
			continue;
		}
		else if (count == 6)
		{
			toWrite << text << endl;
			count++;
			continue;
		}
		else if (text == "~")
		{
			toWrite << text << endl;
			count = 0;
			continue;
		}
	}
	toRead.close();
	toWrite.close();
}
void changeStatus(int num1, string f1)
{
	string before, after;
	int num, rech;
	string id, add, nam, stat, net;

	ifstream toRead;
	ofstream toWrite;
	string text;
	int count = 0;
	int n = num1;
	bool check = false;
	toRead.open(f1 + ".txt");
	toWrite.open("new" + f1 + ".txt");
	while (!toRead.eof())
	{
		getline(toRead, text);
		if (count == 0)
		{
			if (text == "")
			{
				break;
			}
			else
			{
				num = stoi(text);
				if (num == n)
				{
					check = true;
				}
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
			if (check == true)
			{
				if (stat == "on")

				{
					before = stat;
					stat = "off";
					after = "off";
				}
				else if (stat == "off")

				{
					before = stat;
					stat = "on";
					after = "on";
				}
				check = false;
			}
			count++;
			continue;
		}
		else if (count == 6)
		{
			rech = stoi(text);
			toWrite << num << endl;
			toWrite << nam << endl;
			toWrite << id << endl;
			toWrite << add << endl;
			toWrite << net << endl;
			toWrite << stat << endl;
			toWrite << rech << endl;
			toWrite << "~" << endl;
			count++;
			continue;
		}
		else if (text == "~")
		{
			count = 0;
			continue;
		}
	}
	toRead.close();
	toWrite.close();
	/*toRead.open("new" + f1 + ".txt");
	toWrite.open(f1 + ".txt");*/
	toRead.open("new" + f1 + ".txt");
	toWrite.open(f1 + ".txt");
	count = 0;
	while (!toRead.eof())
	{
		getline(toRead, text);
		if (count == 0)
		{
			if (text == "")
			{
				break;
			}
			else
			{
				toWrite << text << endl;
				count++;
				continue;
			}
		}
		else if (count == 1)
		{
			toWrite << text << endl;
			count++;
			continue;
		}
		else if (count == 2)
		{
			toWrite << text << endl;
			count++;
			continue;
		}
		else if (count == 3)
		{
			toWrite << text << endl;
			count++;
			continue;
		}
		else if (count == 4)
		{
			toWrite << text << endl;
			count++;
			continue;
		}
		else if (count == 5)
		{
			toWrite << text << endl;
			count++;
			continue;
		}
		else if (count == 6)
		{
			toWrite << text << endl;
			count++;
			continue;
		}
		else if (text == "~")
		{
			toWrite << text << endl;
			count = 0;
			continue;
		}
	}
	toRead.close();
	toWrite.close();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t\t ________________________________________________" << endl;
	cout << "\t\t\t\t\t\t\t| The status of number is changed  from " << before << " to " << after << "|" << endl;
	cout << "\t\t\t\t\t\t\t|________________________________________________|" << endl;
	cout << endl;
	cout << "Press any key to continue" << endl;
	system("pause>null");
	system("CLS");
}
void swapNetwork(int n, string f1, string f2)
{
	string noZ = "0311", noU = "0332", noT = "0344", noJ = "0300";
	string ntch;
	int num, rech;
	string net2;
	string net1;
	string text;
	string id, add, nam, stat, net;
	int count = 0;
	bool check = false;
	ifstream toRead;
	ofstream toWrite;
	ofstream toWrite2;
	toRead.open(f1 + ".txt");
	toWrite2.open("new" + f1 + ".txt");
	toWrite.open(f2 + ".txt", ios::app);
	while (!toRead.eof())
	{
		getline(toRead, text);
		if (count == 0)
		{
			if (text == "")
			{
				break;
			}
			else
			{
				num = stoi(text);
				if (num == n)
				{
					check = true;
				}
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
			count++;
			if (check == true)
			{
				toWrite << num << endl;
				toWrite << nam << endl;
				toWrite << id << endl;
				toWrite << add << endl;
				toWrite << f2 << endl;
				toWrite << stat << endl;
				toWrite << rech << endl;
				toWrite << "~" << endl;
			}
			else if (check != true)
			{
				toWrite2 << num << endl;
				toWrite2 << nam << endl;
				toWrite2 << id << endl;
				toWrite2 << add << endl;
				toWrite2 << net << endl;
				toWrite2 << stat << endl;
				toWrite2 << rech << endl;
				toWrite2 << "~" << endl;

			}
			check = false;
			continue;
		}
		else if (text == "~")
		{
			count = 0;
			continue;
		}
	}
	toRead.close();
	toWrite.close();
	toWrite2.close();
	toRead.open("new" + f1 + ".txt");
	toWrite.open(f1 + ".txt");
	count = 0;
	while (!toRead.eof())
	{
		getline(toRead, text);
		if (count == 0)
		{
			if (text == "")
			{
				break;
			}
			else
			{
				toWrite << text << endl;
				count++;
				continue;
			}
		}
		else if (count == 1)
		{
			toWrite << text << endl;
			count++;
			continue;
		}
		else if (count == 2)
		{
			toWrite << text << endl;
			count++;
			continue;
		}
		else if (count == 3)
		{
			toWrite << text << endl;
			count++;
			continue;
		}
		else if (count == 4)
		{
			toWrite << text << endl;
			count++;
			continue;
		}
		else if (count == 5)
		{
			toWrite << text << endl;
			count++;
			continue;
		}
		else if (count == 6)
		{
			toWrite << text << endl;
			count++;
			continue;
		}
		else if (text == "~")
		{
			toWrite << text << endl;
			count = 0;
			continue;
		}
	}
	toRead.close();
	toWrite.close();
	string fnB;
	if (f1 == "zong")
	{
		fnB = noZ + to_string(n);
	}
	else if (f1 == "ufone")
	{
		fnB = noU + to_string(n);
	}
	else if (f1 == "telenor")
	{
		fnB = noT + to_string(n);
	}
	else if (f1 == "jazz")
	{
		fnB = noJ + to_string(n);
	}
	string fnA;
	if (f2 == "zong")
	{
		fnA = noZ + to_string(n);
	}
	else if (f2 == "ufone")
	{
		fnA = noU + to_string(n);
	}
	else if (f2 == "telenor")
	{
		fnA = noT + to_string(n);
	}
	else if (f2 == "jazz")
	{
		fnA = noJ + to_string(n);
	}
	cout << endl;
	cout << "\t\t\t\t\t\t\tThe network of number " << fnB << " is changed from " << f1 << " to " << f2 << endl;
	cout << "\t\t\t\t\t\t\tNetwork after change is :" << f2 << endl;
	cout << "\t\t\t\t\t\t\tNumber after network change is : " << fnA << endl;
	cout << endl;
	cout << "Press any key to continue" << endl;
	system("pause>null");
	system("CLS");
}
int numbersOwn(string id)
{
	ifstream toR;
	toR.open(id + "booked.txt");
	int purchased;
	toR >> purchased;
	toR.close();
	return purchased;
}
string encrypt(string text)
{
	char temp;
	int i, key = 7;
	for (i = 0; text[i] != '\0'; ++i) {
		temp = text[i];
		if (temp >= 'a' && temp <= 'z') {
			temp = temp + key;

			if (temp > 'z') {
				temp = temp - 'z' + 'a' - 1;
			}

			text[i] = temp;
		}
		else if (temp >= 'A' && temp <= 'Z') {
			temp = temp + key;

			if (temp > 'Z') {
				temp = temp - 'Z' + 'A' - 1;
			}

			text[i] = temp;
		}
	}

	return text;
}
string decrypt(string text)
{
	char temp;
	int i, key = 7;
	for (i = 0; text[i] != '\0'; ++i) {
		temp = text[i];
		if (temp >= 'a' && temp <= 'z') {
			temp = temp - key;

			if (temp < 'a') {
				temp = temp + 'z' - 'a' + 1;
			}

			text[i] = temp;
		}
		else if (temp >= 'A' && temp <= 'Z') {
			temp = temp - key;

			if (temp < 'A') {
				temp = temp + 'Z' - 'A' + 1;
			}
			text[i] = temp;
		}
	}

	return text;

}