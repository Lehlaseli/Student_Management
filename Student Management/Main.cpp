/***********************************************
 *Group Members:Lereko Ramataboe     202003168 *
 *             :Lehlaseli Moketsane  202002644 *
 ***********************************************/
#include <iostream>
#include "Course.h"
#include "Students.cpp"
#include "input_validation.h"

using namespace std;

int main()
/*console for testing*/
{
	//User input variables
	int asnumber, asize;
	string asname, acname, accode, acinst, intr = "Enter an INTEGER!";
	
	//Menu variables
	int choice1, choice2;
	string choice0,choice;int trys = 3;
	bool  exit = false;
	//Tree of Students OBJECT
	Students tree1;
	//MENU
	cout << "*****************************************\n";
	cout << "*NATIONAL UNIVERSITY OF LESOTHO REGISTRY*\n";
	cout << "*****************************************\n";
	while(exit == false){
		cout << "=================\n";
		cout << "=   MAIN MENU   =\n";
		cout << "=================\n";
		cout << "1.Insert Student:\n";
		cout << "2.Delete Student(Student number):\n";
		cout << "3.Display Student(Student number):\n";
		cout << "4.Update Student Courses(Student number):\n";
		cout << "5.Display all Students:\n";
		cout << "6.Delete all Students:\n";
		cout << "7.Search a Student:\n";
		cout << "8.Exit:\n";
		if(getInput(choice,">choice: ", intr,trys,exit))
			choice2 = stoi(choice);
		else
			choice2 = 8;
		
		switch(choice2){
			case 1:{
				bool exit2 = false;
				cout << "********REGISTRY PORTAL*******\n";
				cout << "\tStudent Name: ";
				getline(cin, asname);
				
				getInput(asnumber,"\tStudent Number: ",intr,trys,exit2);
				do{
					getInput(asize,"\tNumber of Courses: ",intr,trys,exit2);
					if(asize > 8){cout << "Number of courses cannot exceed 8.\n";}
				}
				while(asize >8 && exit2 == false);
		
				Course *acourses = new Course[asize];
				for(int i = 0; i < asize; i++){
					cout << "\t  Course Name: ";
					getline(cin,acourses[i].cname); 
					cout << "\t  Course Instructor: ";
					getline(cin,acourses[i].cinst); 
					cout << "\t  Course Code: ";
					getline (cin,acourses[i].ccode); 
				}
				//Updates the AVL tree after insertion
				tree1.set_root(tree1.InsertStudent(tree1.get_root(),asnumber,asname,asize,acourses));
				break;
				}
			case 2:
				getInput(asnumber,"Student number: ",intr,trys,exit);
				//Updates the AVL tree after Deletion
				tree1.set_root(tree1.DeleteStudent(tree1.get_root(),asnumber));
				break;
			case 3:
				getInput(asnumber,"Student number: ",intr,trys,exit);
				tree1.DisplayStudent(tree1.get_root(),asnumber);
				break;
			case 4:{
				bool exit2 = false;
				getInput(asnumber,"Student number: ",intr,trys,exit);
				if (tree1.Search(tree1.get_root(),asnumber))
				{
					do{ cout << "****************\n";
						cout << "*   SUB-MENU   *\n";
						cout << "****************\n";
						cout << "  1.Insert course:\n";
						cout << "  2.Delete course:\n";
						cout << "  3.Search course:\n";
						cout << "  4.Back to Main-Menu:\n";
						getInput(choice1,"  >choice ",intr,trys,exit2);

						if (choice1 == 2){
							cout << "    Course Code: ";
							cin >> accode;
							tree1.key->deleteCourse(accode);
						}
						else if(choice1 == 1){
							cout << "    Course Name: ";
							getline(cin,acname); 
							cout << "    Course Code: ";
							getline(cin,accode);
							cout << "    Course Instructor: ";
							getline(cin,acinst); 
							tree1.key->insertCourse(acname,accode, acinst);
						}
						else if(choice1 == 3)
						{cout << "    Course Code: ";
						cin >> accode;tree1.key->searchCourse(accode);}
						else{exit2 = true;}
					} while (exit2 == false);
				}
				else{cout << "--Incorrect student number--\n";}
				break;}
			case 5:
				cout << "**************************\n";
				cout << "*All Students in Database*\n";
				cout << "**************************\n";
				tree1.DisplayAll(tree1.get_root());
				break;
			case 6:{
				cout << "    Are you sure you want to Wipe Database? yes/no.\n";
				cout << "    Answer: ";
				cin >> choice0;
				if(choice0 == "Yes" || choice0 == "yes" || choice0 == "YES"){
					tree1.destroyTree(tree1.get_root());
					tree1.set_root(NULL);}
				else{cout << "--Greate choice--\n";}
				break;}
			case 7:
				getInput(asnumber,"Student number: ",intr,trys,exit);
				if(tree1.Search(tree1.get_root(),asnumber))
				{cout << "--Student Number Present in Database--\n";}
				else{cout << "--Student Number Absent from Database--\n";}	
				break;
			case 8:
				exit = true;
				break;				
			default:{
				cout << "--Enter a number between (1-8)--\n";
				break;
			}
		}
	}
	cout << "Christ Jesus is Lord";
	return 0;
}