// Student1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;


struct name {
	string givenName;
	string FamilyName;

};
struct dob {
	int day;
	int month;
	int year;
};
class student {
public:
	name name_;
	dob dob_;
	int age;


	string matricule;
	string classroom;
	static void displayStudentsByClassroom(vector<student>& students, string classroom) {
		vector<student> studentsInClassroom;

		// Iterate through the vector of students and add any students with the specified classroom to a new vector
		for (const auto& student : students) {
			if (student.classroom == classroom) {
				studentsInClassroom.push_back(student);
			}
		}

		// Sort the new vector of students in alphabetical order based on their last name
		sort(studentsInClassroom.begin(), studentsInClassroom.end(), [](const student& s1, const student& s2) {
			return s1.name_.FamilyName < s2.name_.FamilyName;
			});

		// Display the students in alphabetical order
		for (const auto& student : studentsInClassroom) {
			
			cout << "name: " + student.name_.FamilyName + " " + student.name_.givenName + "\n";
			cout << "DOB: " << student.dob_.day << "/" << student.dob_.month << "/" << student.dob_.year;
			cout << "\nMatricule: " + student.matricule + "\n";
			cout << "\nAge: " << student.age;
			cout << "\n";
		
		}
	}
	student() {

	}

	student(name studentName, dob studentDOB, string studentMatricule, int studentAge, string studentclassroom) {
		name_ = studentName;
		dob_ = studentDOB;
		matricule = studentMatricule;
		age = studentAge;
		classroom = studentclassroom;
	}
	void display(student student) {
		cout << "\nname: " + student.name_.FamilyName + " " + student.name_.givenName + "\n";
		cout << "DOB: "<<student.dob_.day<<"/"<<student.dob_.month<<"/"<<student.dob_.year;
		cout << "\nMatricule: " + student.matricule ;
		cout << "\nAge: " <<student.age;
		cout << "\n";
	}
	void addstudent() {

	}


private:



};
static void deleteStudentFromVector(vector<student>& students, string matriculeToDelete) {
	for (auto iter = students.begin(); iter != students.end(); iter++) {
		if (iter->matricule == matriculeToDelete) {
			students.erase(iter);
			break;
		}
	}
}
class classroom {
public:
	vector<student> students;
	string Name;
	classroom(string className) {
		Name = className;
	}

	void addStudent(student student) {
		students.push_back(student);
	}
	void removeStudent(student student) {
		for (int i = 0; i < students.size(); i++) {
			if (students[i].matricule == student.matricule) {
				students.erase(students.begin() + i);
				break;
			}
		}
	}

};
vector <student> studentlist;
vector <classroom> classrooms;
vector<student> studentinclass;



void displayStudentlist(vector <student> studentlist) {
	int i;
	for (i = 0; i < studentlist.size(); i++) {
		cout << "Name: " << studentlist[i].name_.FamilyName << studentlist[i].name_.givenName;
		cout << "\ndob: " << studentlist[i].dob_.day << "/" << studentlist[i].dob_.month << "/" << studentlist[i].dob_.year;
		cout << "\nMatricule: " << studentlist[i].matricule;
		cout << "\nAge :" << studentlist[i].age;
		cout << "\nClassroom: " << studentlist[i].classroom;
		cout << "\n";
		cout << "===========================";
			cout << "\n";

	}

}

void addstudent(student st) {
	cout << "Enter the Family name of the student: ";
	cin >> st.name_.FamilyName;
	cout << "Enter the given name of the student: ";
	cin >> st.name_.givenName;
	cout << "Enter the dob: day: ";
	cin >> st.dob_.day;
	cout << "Enter the dob: month: ";
	cin >> st.dob_.month;
	cout << "Enter the dob: year: ";
	cin >> st.dob_.year;
	cout << "Enter the Class: ";
	cin >> st.classroom;
	st.matricule =st.classroom.substr(0,1)+ st.classroom.substr(5, 1)+"00"+to_string(studentlist.size());
	cout << "\nMatricule generated: " << st.matricule;
	cout << "\nAge generated : "<<2023- st.dob_.year;
	st.age = 2023 - st.dob_.year;
	
	studentlist.push_back(st);









}	

int main()
{
	
			
			

		
	
	student student;



	cout << "\n=====Welcome to our school management system  \n";
	cout << "1. Manage Students \n2. ManageClassrooms \n3. exit\n";
	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		cout << "1. Add a student\n2. Delete a Student  \n4. Display all Students\n";
		cin >> choice;
		if (choice == 1) {
			addstudent(student);
			main();
			system("cls");


		}
		else if (choice == 2) {
			cout << "Enter the Matricule: ";
			string mat;
			cin >> mat;
			deleteStudentFromVector(studentlist, mat);
			system("cls");

		}
		else if (choice == 4) {
			displayStudentlist(studentlist);
			main();
			system("cls");


		}

		break;
	case 2:
		
		cout << "1.Create Classrooms \n 2. Display classrooms";
		cin >> choice;
		if (choice == 1) {
			string classroom1;
			cout << "Whats the name of the classroom?\n";
			cin >> classroom1;
			classroom cp(classroom1);
			classrooms.push_back(cp);
			main();
		}
		else if (choice == 2) {
			int j;
			cout << "what class do you want to see: ";
				string see;
			cin >> see;
			for (j = 0; j < studentlist.size(); j++) {
				if (studentlist[j].classroom == see) {
					studentlist[j].display(studentlist[j]);
					studentlist[j].displayStudentsByClassroom(studentlist, see);
					system("pause");
					main();
				}
			}

		}
		break;

	}

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
