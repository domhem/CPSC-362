#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct student
{
	string fname;//for student first name
	string lname;//for student last name
	string Registration;//for Registration No number
	string classes;//for class info
}studentData;//Variable of student type


void menu() {
	system("cls");//Clear screen
	//Level-2 display
	cout << "\t\t\tSTUDENTS INFORMATION AND BIO DATA SECTION\n\n\n";
	cout << "Enter your choice: " << endl;
	cout << "1.Create new entry\n";
	cout << "2.Remove a student\n";
	cout << "3.Find and display entry\n";
	cout << "4.Support \n";
	cout << "5.Exit\n";
}

int main() {

	string userName;
	string userPassword;
	int loginAttempt = 0;
	char choice;
	int i = 0;
	int j;
	while (loginAttempt < 5) {
		cout << "Login" << endl;
		cout << "Username: ";
		cin >> userName;
		cout << "Password: ";
		cin >> userPassword;

		//Username: Tien Password:hello
		if (userName == "tien"&& userPassword == "hello") {
			cout << "Welcome " << userName << endl;

			menu();
			cin >> choice;

			switch (choice) {
			case '1':
			{  ofstream f1("student.txt", ios::app);

			for (i = 0; choice != 'n'; i++)
			{

				if ((choice == 'y') || (choice == 'Y') || (choice == '1'))
				{
					cout << "Enter First name: ";
					cin >> studentData.fname;
					cout << "Enter Last name: ";
					cin >> studentData.lname;
					cout << "Enter Registration number: ";
					cin >> studentData.Registration;
					cout << "Enter class: ";
					cin >> studentData.classes;

					f1 << studentData.fname << endl << studentData.lname << endl << studentData.Registration << endl << studentData.classes << endl;
					cout << "Do you want to enter data: ";
					cout << "Press Y for Continue and N to Finish:  ";
					cin >> choice;
				}
			}
			f1.close();
			}
				continue;//control back to inner loop -1
			case '3':

			{  ifstream f2("student.txt");
			string find;

			cout << "Enter First name to be displayed: ";
			cin >> find;
			cout << endl;
			int notFound = 0;
			for (j = 0; (j < i) || (!f2.eof()); j++)
			{
				getline(f2, studentData.fname);

				if (studentData.fname == find)
				{
					notFound = 1;
					cout << "First Name: " << studentData.fname << endl;
					cout << "Last Name: " << studentData.lname << endl;

					getline(f2, studentData.Registration);
					cout << "Registration No number: " << studentData.Registration << endl;
					getline(f2, studentData.classes);
					cout << "Class: " << studentData.classes << endl << endl;
				}
			}
			if (notFound == 0) {

				cout << "No Record Found" << endl;
			}
			f2.close();
			break;

			}
			case '4':
				system("cls");
				cout << "IT Help Desk\n\n"
					<< "Contact Scott\n"
					<< "e-Mail: Scotttran636@gmail.com\n"
					<< "Call: (626)506-9477\n\n";
				break;
			case'5':{
						cout << "The program will be terminated.\n";
			}
				system("pause");
				return 0;
			}
		}
		else
			cout << "Invalid login attempt, please try again\n \n";
		loginAttempt++;
	}

	if (loginAttempt == 5) {
		cout << "The program will be terminated.\n";

	}
	system("pause");
	return 0;
}
