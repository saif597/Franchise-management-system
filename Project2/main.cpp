#include<iostream>
#include<fstream>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include"functions.h"
#include"list.h"
#include"bst.h"
using namespace std;
class User
{
	int number, recharge;
	string name, idCard, address, status, network;
public:
	void registerUser(string nam, string id, string  pass, string add);//for pass file
	//login manually in main to extract attributes of registration and pass them directly to setdata so that system does'nt aks for info on every purchase;
	void setData(string num, int rech, string nam, string id, string  add, string stat, string net);//for info file//when user will ask for number we will have all data loaded 
	void setUfone(int num, int rech, string nam, string id, string  add, string stat, string net);
	void setZong(int num, int rech, string nam, string id, string  add, string stat, string net);
	void setTelenor(int num, int rech, string nam, string id, string  add, string stat, string net);
	void setJazz(int num, int rech, string nam, string id, string  add, string stat, string net);

};
void User::setUfone(int num, int rech, string nam, string id, string  add, string stat, string net)
{
	ofstream toWrite;
	toWrite.open("ufone.txt", ios::app);
	toWrite << num << endl;
	toWrite << nam << endl;
	toWrite << id << endl;
	toWrite << add << endl;
	toWrite << net << endl;
	toWrite << stat << endl;
	toWrite << rech << endl;
	toWrite << "~" << endl;
	toWrite.close();
}
void User::setZong(int num, int rech, string nam, string id, string  add, string stat, string net)
{
	ofstream toWrite;
	toWrite.open("zong.txt", ios::app);
	toWrite << num << endl;
	toWrite << nam << endl;
	toWrite << id << endl;
	toWrite << add << endl;
	toWrite << net << endl;
	toWrite << stat << endl;
	toWrite << rech << endl;
	toWrite << "~" << endl;
	toWrite.close();
}
void User::setTelenor(int num, int rech, string nam, string id, string  add, string stat, string net)
{
	ofstream toWrite;
	toWrite.open("telenor.txt", ios::app);
	toWrite << num << endl;
	toWrite << nam << endl;
	toWrite << id << endl;
	toWrite << add << endl;
	toWrite << net << endl;
	toWrite << stat << endl;
	toWrite << rech << endl;
	toWrite << "~" << endl;
	toWrite.close();
}
void User::setJazz(int num, int rech, string nam, string id, string  add, string stat, string net)
{
	ofstream toWrite;
	toWrite.open("jazz.txt", ios::app);
	toWrite << num << endl;
	toWrite << nam << endl;
	toWrite << id << endl;
	toWrite << add << endl;
	toWrite << net << endl;
	toWrite << stat << endl;
	toWrite << rech << endl;
	toWrite << "~" << endl;
	toWrite.close();
}
void User::setData(string num, int rech, string nam, string id, string  add, string stat, string net)
{
	ofstream toWrite;
	toWrite.open("info.txt", ios::app);
	toWrite << num << endl;
	toWrite << nam << endl;
	toWrite << id << endl;
	toWrite << add << endl;
	toWrite << net << endl;
	toWrite << stat << endl;
	toWrite << rech << endl;
	toWrite << "~" << endl;
	toWrite.close();
}
void User::registerUser(string nam, string id, string  pass, string add)
{
	ofstream toWrite;;
	toWrite.open(id + ".txt");
	toWrite << id << endl;
	toWrite << pass << endl;
	toWrite << add << endl;
	toWrite << nam << endl;
	toWrite.close();
}
void main()
{
	system("color B1");
	int numberGenerated;
	string name, password, address, idCard;
	string inId, inPass;
	string fileId, filepass, fileName, fileAdd;
	int ch, ac;
	ch = 2;
	User u1;
	//main screen here 

	system("mode con: cols=120 lines=20");
	system("Color F5");
	string title = { "\n\n\n\n\n\t\t\t\t\tW E L C O M E\n\n\t\t\t\t\t\t\tT O \n\n\t\t\t\t\t\t\t\tF R A N C H I S E " };
	for (int i = 0; i < title.length(); i++)
	{
		cout << title[i];
		Sleep(100);
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t\t *********************************************************************" << endl;
	cout << "\t\t\t\t				DSA PROJECT                 " << endl;
	cout << "\t\t\t\t     Name : Syed Saif ur Rehman    Enrollement : 01-131202-042   " << endl;
	cout << "\t\t\t\t *********************************************************************" << endl;
	system("pause>null");
	//main screen
	do
	{
		system("CLS");
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\n";
		cout << "\t\t\t\t\t\t\t\t ____________________________" << endl;
		cout << "\t\t\t\t\t\t\t\t|			     |" << endl;
		cout << "\t\t\t\t\t\t\t\t|    press 1 for admin       |" << endl;
		cout << "\t\t\t\t\t\t\t\t|____________________________|" << endl;
		cout << "\t\t\t\t\t\t\t\t|    press 2 for user        |" << endl;
		cout << "\t\t\t\t\t\t\t\t|____________________________|" << endl;
		cout << "\t\t\t\t\t\t\t\t|    press 3 to close system |" << endl;
		cout << "\t\t\t\t\t\t\t\t|____________________________|" << endl;
		cout << endl;
		cout << endl;
		cout << "Enter your choice : ";
		cin >> ch;
		if (ch == 1)//admin portion
		{
			string idA, passA;
			cin.ignore();
			cout << "Enter id :";
			getline(cin, idA);
			passA = inputPass();
			cout << endl;
			string adpa;
			ifstream f;
			f.open("adminpass.txt");
			f >> adpa;
			f.close();
			if ((idA == "999") && (passA == adpa))//access to admin
			{
				system("CLS");
				int adc;
				do
				{
					int nts;//number to search
					cout << "\n";
					cout << "\n";
					cout << "\n";
					cout << "\n";
					cout << "\t\t\t\t\t\t\t ______________________________________________" << endl;
					cout << "\t\t\t\t\t\t\t|			                       |" << endl;
					cout << "\t\t\t\t\t\t\t|   Press 1 for searching info by number       |" << endl;
					cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
					cout << "\t\t\t\t\t\t\t|    Press 2 for searching info by name        |" << endl;
					cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
					cout << "\t\t\t\t\t\t\t|    Press 3 for changing status of a number   |" << endl;
					cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
					cout << "\t\t\t\t\t\t\t|    Press 4 for changing network of a number  |" << endl;
					cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
					cout << "\t\t\t\t\t\t\t|    Press 5 to go back                        |" << endl;
					cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
					cout << endl;
					cout << endl;
					cout << "Enter your choice  :";
					cin >> adc;
					if (adc == 1)
					{
						system("CLS");
						int netC;
						cout << "\n";
						cout << "\n";
						cout << "\n";
						cout << "\n";
						cout << "\t\t\t\t\t\t\t ______________________________________________" << endl;
						cout << "\t\t\t\t\t\t\t|			                       |" << endl;
						cout << "\t\t\t\t\t\t\t|                       select a network       |" << endl;
						cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
						cout << "\t\t\t\t\t\t\t|  Press 1 for zong                            |" << endl;
						cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
						cout << "\t\t\t\t\t\t\t|  Press 2 for ufone                           |" << endl;
						cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
						cout << "\t\t\t\t\t\t\t|  Press 3 for telenor                         |" << endl;
						cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
						cout << "\t\t\t\t\t\t\t|  Press 4 for jazz                            |" << endl;
						cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
						cout << "Enter your choice  : ";
						cin >> netC;
						if (netC == 1)
						{
							cout << "Enter the number to search " << endl;
							cout << "0311";
							cin >> nts;
							searchInTree("zong", nts);
						}
						else if (netC == 2)
						{
							cout << "Enter the number to search " << endl;
							cout << "0332";
							cin >> nts;
							searchInTree("ufone", nts);
						}
						else if (netC == 3)
						{
							cout << "Enter the number to search " << endl;
							cout << "0344";
							cin >> nts;
							searchInTree("telenor", nts);
						}
						else if (netC == 4)
						{
							cout << "Enter the number to search " << endl;
							cout << "0300";
							cin >> nts;
							searchInTree("jazz", nts);
						}
					}
					else if (adc == 2)
					{
						int netC;
						cout << "\t\t\t\t\t\t\t ______________________________________________" << endl;
						cout << "\t\t\t\t\t\t\t|			                       |" << endl;
						cout << "\t\t\t\t\t\t\t|                       select a network       |" << endl;
						cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
						cout << "\t\t\t\t\t\t\t|  Press 1 for zong                            |" << endl;
						cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
						cout << "\t\t\t\t\t\t\t|  Press 2 for ufone                           |" << endl;
						cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
						cout << "\t\t\t\t\t\t\t|  Press 3 for telenor                         |" << endl;
						cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
						cout << "\t\t\t\t\t\t\t|  Press 4 for jazz                            |" << endl;
						cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;

						cin >> netC;
						if (netC == 1)
						{
							string nameToLook;
							cout << "Enter the name to search :";
							cin.ignore();
							getline(cin, nameToLook);
							List p;
							insertAndFind("zong", nameToLook);
						}
						if (netC == 2)
						{

							string nameToLook;
							cout << "Enter the name to search :";
							cin.ignore();
							getline(cin, nameToLook);
							List p;
							insertAndFind("ufone", nameToLook);

						}
						if (netC == 3)
						{

							string nameToLook;
							cout << "Enter the name to search :";
							cin.ignore();
							getline(cin, nameToLook);
							List p;
							insertAndFind("telenor", nameToLook);

						}
						if (netC == 4)
						{

							string nameToLook;
							cout << "Enter the name to search :";
							cin.ignore();
							getline(cin, nameToLook);
							List p;
							insertAndFind("jazz", nameToLook);
						}
					}
					else if (adc == 3)
					{
						int inp;
						int numToChange;
						cout << "\t\t\t\t\t\t\t ______________________________________________" << endl;
						cout << "\t\t\t\t\t\t\t|			                       |" << endl;
						cout << "\t\t\t\t\t\t\t|                       select a network       |" << endl;
						cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
						cout << "\t\t\t\t\t\t\t|  Press 1 for zong                            |" << endl;
						cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
						cout << "\t\t\t\t\t\t\t|  Press 2 for ufone                           |" << endl;
						cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
						cout << "\t\t\t\t\t\t\t|  Press 3 for telenor                         |" << endl;
						cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
						cout << "\t\t\t\t\t\t\t|  Press 4 for jazz                            |" << endl;
						cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
						cout << "Enter your choice  : ";
						cin >> inp;
						if (inp == 1)
						{
							cout << "Enter your current number : 0311";
							cin >> numToChange;
							string net1 = "zong";
							if (numberIsInFile(numToChange, net1))
							{
								changeStatus(numToChange, net1);
							}
							else if (!numberIsInFile(numToChange, net1))
							{
								cout << "User not registered on zong" << endl;
							}
						}
						else if (inp == 2)
						{
							cout << "Enter your current number : 0332";
							cin >> numToChange;
							string net2 = "ufone";
							if (numberIsInFile(numToChange, net2))
							{
								changeStatus(numToChange, net2);
							}
							else if (!numberIsInFile(numToChange, net2))
							{
								cout << "User not registered on ufone" << endl;
							}
						}
						else if (inp == 3)
						{
							cout << "Enter your current number : 0344";
							cin >> numToChange;
							string net3 = "telenor";
							if (numberIsInFile(numToChange, net3))
							{
								changeStatus(numToChange, net3);
							}
							else if (!numberIsInFile(numToChange, net3))
							{
								cout << "User not registered on telenor" << endl;
							}
						}
						else if (inp == 4)
						{
							cout << "Enter your current number : 0300";
							cin >> numToChange;
							string net4 = "jazz";
							if (numberIsInFile(numToChange, net4))
							{
								changeStatus(numToChange, net4);
							}
							else if (!numberIsInFile(numToChange, net4))
							{
								cout << "User not registered on jazz" << endl;
							}
						}
						else
						{
							cout << "Wrong input" << endl;
							system("pause>null");
							system("CLS");
						}
					}
					else if (adc == 4)
					{
						int sel;
						cout << "select current network " << endl;
						cout << " press 1 for zong" << endl;
						cout << " press 2 for ufone" << endl;
						cout << " press 3 for telenor" << endl;
						cout << " press 4 for jazz" << endl;
						cin >> sel;
						if (sel == 1)
						{
							int ntc;
							cout << "Enter the number  : 0311";
							cin >> ntc;
							string f1 = "zong";
							int t;
							cout << "select network to change to" << endl;
							cout << " press 1 for ufone" << endl;
							cout << " press 2 for telenor" << endl;
							cout << " press 3 for jazz" << endl;
							cin >> t;
							if (t == 1)
							{
								string f2 = "ufone";
								swapNetwork(ntc, f1, f2);
							}
							else if (t == 2)
							{
								string f2 = "telenor";
								swapNetwork(ntc, f1, f2);
							}
							else if (t == 3)
							{
								string f2 = "jazz";
								swapNetwork(ntc, f1, f2);
							}
							else
							{
								cout << "Buri baat" << endl;
							}
						}
						else if (sel == 2)
						{
							int ntc;
							cout << "Enter the number  : 0332";
							cin >> ntc;
							string f1 = "ufone";
							int t;
							cout << " press 1 for zong" << endl;
							cout << " press 2 for telenor" << endl;
							cout << " press 3 for jazz" << endl;
							cin >> t;
							if (t == 1)
							{
								string f2 = "zong";
								swapNetwork(ntc, f1, f2);
							}
							else if (t == 2)
							{
								string f2 = "telenor";
								swapNetwork(ntc, f1, f2);
							}
							else if (t == 3)
							{
								string f2 = "jazz";
								swapNetwork(ntc, f1, f2);
							}
							else
							{
								cout << "Buri baat" << endl;
							}
						}
						else if (sel == 3)
						{
							int ntc;
							cout << "Enter the number  : 0344";
							cin >> ntc;
							string f1 = "telenor";
							int t;
							cout << " press 1 for zong" << endl;
							cout << " press 2 for ufone" << endl;
							cout << " press 3 for jazz" << endl;
							cin >> t;
							if (t == 1)
							{
								string f2 = "zong";
								swapNetwork(ntc, f1, f2);
							}
							else if (t == 2)
							{
								string f2 = "ufone";
								swapNetwork(ntc, f1, f2);
							}
							else if (t == 3)
							{
								string f2 = "jazz";
								swapNetwork(ntc, f1, f2);
							}
							else
							{
								cout << "Buri baat" << endl;
							}
						}
						else if (sel == 4)
						{
							int ntc;
							cout << "Enter the number  : 0300";
							cin >> ntc;
							string f1 = "jazz";
							int t;
							cout << " press 1 for zong" << endl;
							cout << " press 2 for ufone" << endl;
							cout << " press 3 for telenor" << endl;
							cin >> t;
							if (t == 1)
							{
								string f2 = "zong";
								swapNetwork(ntc, f1, f2);
							}
							else if (t == 2)
							{
								string f2 = "ufone";
								swapNetwork(ntc, f1, f2);
							}
							else if (t == 3)
							{
								string f2 = "telenor";
							}
							else
							{
								cout << "Buri baat" << endl;
							}
						}
						else
						{
							cout << "Buri baat" << endl;
						}
					}
					else if (adc == 5)
					{
						break;
					}
					else
					{
						cout << "Invalid input" << endl;
						cout << "Press any key to redo" << endl;
						system("pause>null");
						system("CLS");
					}
					system("pause>null");
				} while (adc != 5);
			}
			else
			{
				cout << "Wrong credentials " << endl;
			}

		}
		else if (ch == 2)///user code
		{

			do
			{
				system("CLS");
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\n";
				cout << "\t\t\t\t\t\t\t\t ____________________________" << endl;
				cout << "\t\t\t\t\t\t\t\t|			     |" << endl;
				cout << "\t\t\t\t\t\t\t\t|    press 1 for registration|" << endl;
				cout << "\t\t\t\t\t\t\t\t|____________________________|" << endl;
				cout << "\t\t\t\t\t\t\t\t|    press 2 for login       |" << endl;
				cout << "\t\t\t\t\t\t\t\t|____________________________|" << endl;
				cout << "\t\t\t\t\t\t\t\t|    press 3 to go back      |" << endl;
				cout << "\t\t\t\t\t\t\t\t|____________________________|" << endl;
				cout << endl;
				cout << endl;
				cout << "Enter your choice : ";
				cin >> ac;
				if (ac == 1)
				{
					cin.ignore();
					cout << "Enter your Id-card number : ";
					getline(cin, idCard);
					password = inputPass();
					password = encrypt(password);
					cout << endl;
					cout << "Enter your name : ";
					getline(cin, name);
					cout << "Enter your address : ";
					getline(cin, address);
					u1.registerUser(name, idCard, password, address);
					ofstream f;
					f.open(idCard + "booked.txt");
					f << 0 << endl;
					f.close();
					cout << "you are registered !" << endl;
				}
				else if (ac == 2)
				{
					cin.ignore();
					cout << "Enter your Id-Card number  : ";
					getline(cin, inId);
					inPass = inputPass();
					cout << endl;
					ifstream toR;
					toR.open(inId + ".txt");
					getline(toR, fileId);
					getline(toR, filepass);
					getline(toR, fileAdd);
					getline(toR, fileName);
					toR.close();
					filepass = decrypt(filepass);
					if ((inId == fileId) && (inPass == filepass))
					{
						int c;
						do
						{
							system("CLS");
							cout << "\n";
							cout << "\n";
							cout << "\n";
							cout << "\n";
							cout << "\t\t\t\t\t\t\t ______________________________________________________" << endl;
							cout << "\t\t\t\t\t\t\t|			                               |" << endl;
							cout << "\t\t\t\t\t\t\t|    press 1 to purchase a phone number		       |" << endl;
							cout << "\t\t\t\t\t\t\t|______________________________________________________|" << endl;
							cout << "\t\t\t\t\t\t\t|    press 2 to purchase a golden phone number         |" << endl;
							cout << "\t\t\t\t\t\t\t|______________________________________________________|" << endl;
							cout << "\t\t\t\t\t\t\t|    press 3 for recharge                              |" << endl;
							cout << "\t\t\t\t\t\t\t|______________________________________________________|" << endl;
							cout << "\t\t\t\t\t\t\t|    press 4 to see how many numbers you have purchased|" << endl;
							cout << "\t\t\t\t\t\t\t|______________________________________________________|" << endl;
							cout << "\t\t\t\t\t\t\t|    press 5 to go back                                |" << endl;
							cout << "\t\t\t\t\t\t\t|______________________________________________________|" << endl;
							cout << endl;
							cout << endl;
							cout << "Enter your choice : ";
							cin >> c;
							if (c == 1)
							{
								int purchased;
								ifstream fl;
								fl.open(inId + "booked.txt");
								fl >> purchased;
								fl.close();
								if (purchased < 5)
								{
									int xx = lastNumGenearted()+858993461;
									numberGenerated = generateNum(xx);
									string numGenerated = to_string(numberGenerated);
									purchased++;
									ofstream fp;
									fp.open(inId + "booked.txt");
									fp << purchased << endl;
									fp.close();
									int choice;
									string numPurchased;
									string zong = "0311";
									string ufone = "0332";
									string telenor = "0344";
									string jazz = "0300";
									system("CLS");
									cout << "\t\t\t\t\t\t\t ______________________________________________" << endl;
									cout << "\t\t\t\t\t\t\t|			                       |" << endl;
									cout << "\t\t\t\t\t\t\t|                       select a network       |" << endl;
									cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
									cout << "\t\t\t\t\t\t\t|  Press 1 for zong                            |" << endl;
									cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
									cout << "\t\t\t\t\t\t\t|  Press 2 for ufone                           |" << endl;
									cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
									cout << "\t\t\t\t\t\t\t|  Press 3 for telenor                         |" << endl;
									cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
									cout << "\t\t\t\t\t\t\t|  Press 4 for jazz                            |" << endl;
									cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
									cout << "Enter your choice :";
									cin >> choice;
									if (choice == 1)
									{
										numPurchased = zong + numGenerated;
										cout << "Thanks by zong! " << endl;
										cout << "You have purchased " << numPurchased << " with initial balance of 25 RS. " << endl;
										u1.setData(numPurchased, 25, fileName, fileId, fileAdd, "on", "zong");
										u1.setZong(numberGenerated, 25, fileName, fileId, fileAdd, "on", "zong");
										generatedNumbers(numberGenerated);
									}
									else if (choice == 2)
									{
										numPurchased = ufone + numGenerated;
										cout << "Thanks by ufone! " << endl;
										cout << "You have purchased " << numPurchased << " with initial balance of 25 RS. " << endl;
										u1.setData(numPurchased, 25, fileName, fileId, fileAdd, "on", "ufone");
										u1.setUfone(numberGenerated, 25, fileName, fileId, fileAdd, "on", "ufone");
										generatedNumbers(numberGenerated);
									}
									else if (choice == 3)
									{
										numPurchased = telenor + numGenerated;
										cout << "Thanks by telenor! " << endl;
										cout << "You have purchased " << numPurchased << " with initial balance of 25 RS. " << endl;
										u1.setData(numPurchased, 25, fileName, fileId, fileAdd, "on", "telenor");
										u1.setTelenor(numberGenerated, 25, fileName, fileId, fileAdd, "on", "telenor");
										generatedNumbers(numberGenerated);
									}
									else if (choice == 4)
									{
										numPurchased = jazz + numGenerated;
										cout << "Thanks by jazz! " << endl;
										cout << "You have purchased " << numPurchased << " with initial balance of 25 RS. " << endl;
										u1.setData(numPurchased, 25, fileName, fileId, fileAdd, "on", "jazz");
										u1.setJazz(numberGenerated, 25, fileName, fileId, fileAdd, "on", "jazz");
										generatedNumbers(numberGenerated);
									}

									system("pause>null");
								}
								else if (purchased >= 5)
								{
									cout << "You have already purchased 5 numbers !" << endl;
									system("pause>null");
								}
							}
							if (c == 2)
							{
								int purchasd;
								ifstream fl;
								fl.open(inId + "booked.txt");
								fl >> purchasd;
								fl.close();
								if (purchasd < 5)
								{
									purchasd++;
									ofstream fp;
									fp.open(inId + "booked.txt");
									fp << purchasd << endl;
									fp.close();
									int numToPurchase;
									Stack<int>stk;
									stk.InsertToStack();
									int gT;
									system("CLS");
									cout << "\t\t\t\t\t\t\t ______________________________________________" << endl;
									cout << "\t\t\t\t\t\t\t|			                       |" << endl;
									cout << "\t\t\t\t\t\t\t|                       select a network       |" << endl;
									cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
									cout << "\t\t\t\t\t\t\t|  Press 1 for zong                            |" << endl;
									cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
									cout << "\t\t\t\t\t\t\t|  Press 2 for ufone                           |" << endl;
									cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
									cout << "\t\t\t\t\t\t\t|  Press 3 for telenor                         |" << endl;
									cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
									cout << "\t\t\t\t\t\t\t|  Press 4 for jazz                            |" << endl;
									cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
									cout << "Enter your choice :";
									cin >> gT;
									cin.ignore();
									if (gT == 1)
									{
										cout << "Enter the number : ";
										cout << "0311";
										cin >> numToPurchase;
										if (goldenFound(stk, numToPurchase))
										{
											cout << "Already purchased" << endl;
										}
										else if (!goldenFound(stk, numToPurchase))
										{
											string z = "0311";
											string goldenPurchased = z + to_string(numToPurchase);
											cout << "Number is Available!" << endl;
											cout << "Purchase Successfull !" << endl;
											cout << "you have purchased " << goldenPurchased << " with initial balance of 25" << endl;
											generatedNumbers(numToPurchase);
											u1.setData(goldenPurchased, 25, fileName, fileId, fileAdd, "on", "zong");
											u1.setZong(numToPurchase, 25, fileName, fileId, fileAdd, "on", "zong");
										}
									}
									if (gT == 2)
									{
										cout << "Enter the number : ";
										cout << "0332";
										cin >> numToPurchase;
										if (goldenFound(stk, numToPurchase))
										{
											cout << "Already purchased" << endl;
										}
										else if (!goldenFound(stk, numToPurchase))
										{
											string u = "0332";
											string goldenPurchased = u + to_string(numToPurchase);
											cout << "Number is Available!" << endl;
											cout << "Purchase Successfull !" << endl;
											cout << "you have purchased " << goldenPurchased << " with initial balance of 25" << endl;
											generatedNumbers(numToPurchase);
											u1.setData(goldenPurchased, 25, fileName, fileId, fileAdd, "on", "ufone");
											u1.setUfone(numToPurchase, 25, fileName, fileId, fileAdd, "on", "ufone");
										}
									}
									if (gT == 3)
									{
										cout << "Enter the number : ";
										cout << "0344";
										cin >> numToPurchase;
										if (goldenFound(stk, numToPurchase))
										{
											cout << "Already purchased" << endl;
										}
										else if (!goldenFound(stk, numToPurchase))
										{
											string t = "0344";
											string goldenPurchased = t + to_string(numToPurchase);
											cout << "Number is Available!" << endl;
											cout << "Purchase Successfull !" << endl;
											cout << "you have purchased " << goldenPurchased << " with initial balance of 25" << endl;
											generatedNumbers(numToPurchase);
											u1.setData(goldenPurchased, 25, fileName, fileId, fileAdd, "on", "telenor");
											u1.setTelenor(numToPurchase, 25, fileName, fileId, fileAdd, "on", "telenor");
										}
									}
									if (gT == 4)
									{
										cout << "Enter the number : ";
										cout << "0300";
										cin >> numToPurchase;
										if (goldenFound(stk, numToPurchase))
										{
											cout << "Already purchased" << endl;
										}
										else if (!goldenFound(stk, numToPurchase))
										{
											string j = "0300";
											string goldenPurchased = j + to_string(numToPurchase);
											cout << "Number is Available!" << endl;
											cout << "Purchase Successfull !" << endl;
											cout << "you have purchased " << goldenPurchased << " with initial balance of 25" << endl;
											generatedNumbers(numToPurchase);
											u1.setData(goldenPurchased, 25, fileName, fileId, fileAdd, "on", "jazz");
											u1.setJazz(numToPurchase, 25, fileName, fileId, fileAdd, "on", "jazz");
										}
									}
									else
									{
										system("pause>null");
									}
								}
								else if (purchasd >= 5)
								{
									cout << "you have already purchased 5 numbers :(" << endl;
								}
							}
							if (c == 3)
							{
								int inp;
								int numToLoad;

								system("CLS");
								cout << "\t\t\t\t\t\t\t ______________________________________________" << endl;
								cout << "\t\t\t\t\t\t\t|			                       |" << endl;
								cout << "\t\t\t\t\t\t\t|                       select a network       |" << endl;
								cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
								cout << "\t\t\t\t\t\t\t|  Press 1 for zong                            |" << endl;
								cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
								cout << "\t\t\t\t\t\t\t|  Press 2 for ufone                           |" << endl;
								cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
								cout << "\t\t\t\t\t\t\t|  Press 3 for telenor                         |" << endl;
								cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
								cout << "\t\t\t\t\t\t\t|  Press 4 for jazz                            |" << endl;
								cout << "\t\t\t\t\t\t\t|______________________________________________|" << endl;
								cout << "Enter your choice :";
								cin >> inp;
								if (inp == 1)
								{
									cout << "Enter the number : 0311";
									cin >> numToLoad;
									string net1 = "zong";
									if (numberIsInFile(numToLoad, net1))
									{
										rechargeNum(numToLoad, net1);
									}
									else if (!numberIsInFile(numToLoad, net1))
									{
										cout << "NOT registered on zong" << endl;
									}
								}
								else if (inp == 2)
								{
									cout << "Enter the number : 0332";
									cin >> numToLoad;
									string net2 = "ufone";
									if (numberIsInFile(numToLoad, net2))
									{
										rechargeNum(numToLoad, net2);
									}
									else if (!numberIsInFile(numToLoad, net2))
									{
										cout << "NOT registered on ufone" << endl;
									}
								}
								else if (inp == 3)
								{
									cout << "Enter the number : 0344";
									cin >> numToLoad;
									string net3 = "telenor";
									if (numberIsInFile(numToLoad, net3))
									{
										rechargeNum(numToLoad, net3);
									}
									else if (!numberIsInFile(numToLoad, net3))
									{
										cout << "NOT registered on telenor" << endl;
									}
								}
								else if (inp == 4)
								{
									cout << "Enter the number : 0300";
									cin >> numToLoad;
									string net4 = "jazz";
									if (numberIsInFile(numToLoad, net4))
									{
										rechargeNum(numToLoad, net4);
									}
									else if (!numberIsInFile(numToLoad, net4))
									{
										cout << "NOT registered on ufone" << endl;
									}
								}
								else
								{
									cout << "Invalid" << endl;
								}
							}
							if (c == 4)
							{
								cout << "you have purchased " << numbersOwn(fileId) << " numbers " << endl;
							}
							if (c == 5)
							{
								break;
							}
							else
							{
								system("pause>null");
							}
						} while (c != 5);
					}
				}
				else if (ac == 3)
				{
					system("CLS");
					break;
				}
				else
				{
					main();
				}
			} while (ac != 3);

			system("pause");
		}
		else if (ch == 3)
		{
			exit(1);
		}
		else
		{
			cout << "invalid choice! " << endl;
			cout << "press any key to redo" << endl;
		}
		system("pause>null");
		system("CLS");
	} while (ch != 3);

}
