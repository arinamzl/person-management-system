#include <iostream>
using namespace std;

class person
{
private:
	string fName, lName, ID;
public:
	person* link;
	person() {
		link = NULL;
	}
	friend class Teacher;
	friend class Student;
	friend class employee;
	void show() {
		cout << "\nfirst name: " << fName << " _ last name: " << lName << " _ ID: " << ID << endl;
	}
	string getID() {
		return ID;
	}
	string type;
};
class Teacher :public person
{
private:
	int payT;
	string IDteacher;
public:
	void insertTeacher();
	friend class person;
	void show() {
		person::show();
		cout << "Teacher ID: " << IDteacher;
		cout << " _ Pay: " << payT<<endl;
	}
};
void Teacher::insertTeacher() {
	cout << "enter your first name, last name, id, payment, and teachers id:  ";
	cin >> fName >> lName >> ID >> payT >> IDteacher;
	type = "teacher";
}
class Student :public person
{
private:
	string StudentNumber;
	int payS;
public:
	void insertStudent();
	void show() {
		person::show();
		cout << "student Number: " << StudentNumber;
		cout << " _ Pay: " << payS << endl;
	}
};
void Student::insertStudent(){
	cout << "enter your first name, last name, id, payment, and student number:  ";
	cin >> fName >> lName >> ID >> payS >> StudentNumber ;
	type = "student";
}
class employee :public person
{
private:
	string employeeNumber;
	int payE;
public:
	void insertEmployee();
	void show() {
		person::show();
		cout << "Employee number: " << employeeNumber;
		cout << " _ Pay: " << payE << endl;
	}
};
void employee::insertEmployee() {
	cout << "enter your first name, last name, id, payment, and student number:  ";
	cin >> fName >> lName >> ID >> payE >> employeeNumber;

}

person* start = NULL;
void insertNode(person* p) {
	p->link = start;
	start = p;
}
void displayAll() {
	person* temp = start;

	if (temp == NULL) {
		cout << "\list is empty ";
			return;
	}
	while (temp != NULL) {
		if (temp->type == "teacher") {
			((Teacher*)temp)->show();
		}
		else if (temp->type == "student") {
			((Student*)temp)->show();
		}
		else {
			((employee*)temp)->show();
		}
		temp = temp->link;
	}
}


void deleteNode() {
	string id;
	cout << "Enter ID to delete : ";
	cin >> id;
	person* temp = start;
	person* prev = NULL;
	while (temp != NULL) {
		if (temp->getID() == id) {
			if (prev == NULL) {
				start = temp->link;
			}
			else {
				prev->link = temp->link;
			}
			delete temp;
			cout << "\nDeleted ";
			return;
		}
		prev = temp;
		temp = temp->link;

	}
	cout << "\nNot found ";

}

int menu();
int main()
{
	int m;
	Teacher* obNew1=new Teacher;
	Student* obNew2 = new Student;
	employee* obNew3 = new employee;
	while (true)
	{
		//system("cls");
		m=menu();
		switch (m)
		{
		case 1:
			obNew1 = new Teacher;
			obNew1->insertTeacher();
			insertNode(obNew1);
			break;

		case 2:
			obNew2 = new Student;
			obNew2->insertStudent();
			insertNode(obNew2);
			break;
		case 3:
			obNew3 = new employee;
			obNew3->insertEmployee();
			insertNode(obNew3);
			break;
		case 4:
			displayAll();
			system("pause");
			break;
		case 5:
			deleteNode();
			system("pause");
			break;
		case 6:
			return 0;
		default:
			cout << "\n\nyour choice is invalid";

		}
	}
}
int menu() {
	int choice;
	cout << "\n\t\t1)Enter a new node for teacher";
	cout << "\n\t\t2)Enter a new node for student";
	cout << "\n\t\t3)Enter a new node for employee";
	cout << "\n\t\t4)display all of the list";
	cout << "\n\t\t5)delete a node of the list";
	cout << "\n\t\t6)Exit";
	cout << "\n\t\tEnter your choice: ";
	cin >> choice;
	return choice;
}