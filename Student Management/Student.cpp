#include <iostream>
#include "Student.h"

Student :: Student ()
/*Default constructor, sets both left and right child pointers to NULL*/
{
	snumber = 0;
	left = NULL;
	right = NULL;
}

Student :: ~Student ()
/*Default destructor, sets both left and right child pointers to NULL*/
{
	cout << "--Student destroyed--\n";
}

void Student :: setSnumber(int aSnumber)
/*Sets the inputted student number as the Student's student number, since student number is private*/
{
	this->snumber = aSnumber;
}

bool Student :: searchCourse(string aCcode)
/*Searches a course in a student's array of Courses, returns true if course present, else returns false*/
{
	for(int i = 0; i < this->nocss; i++){
		if (aCcode == this->Array[i].ccode)
		{cout << "Found!\n";return true;}
	}
	cout << "Absent!\n";return false;
}

void Student :: insertCourse(string aCname, string aCcode, string aCinst)
/*Inserts a Course for a particullar student by incresing the size of the array
  and inserting it at the end of the array.*/
{
	Course c1, *old_array = this->Array;
	int newsize = this->nocss + 1;
	Course *new_array = new Course[newsize];

	for(int i = 0; i < this->nocss; i++){
		new_array[i] = old_array[i];
	}

	c1.ccode = aCcode;
	c1.cinst = aCinst;
	c1.cname = aCname;

	new_array[nocss] = c1;
	this->Array = new_array;
	this->nocss = newsize;
	delete [] old_array;
}

void Student :: deleteCourse(string aCcode)
/*Deletes a chosen course of a particular student. The algorithm searches for the course in
  the array and replaces it with the next course*/
{
	if(searchCourse(aCcode)){
		for (int i = 0; i < nocss; i++)
		{
			if (aCcode == Array[i].ccode)
			{
				for(int x = i; x < nocss-1; x++){Array[x] = Array[x+1];}
				nocss--;cout <<"--Deletion successful--\n";
				break;
			}
		}
	}
	else{cout << "--Deletion unsuccessfull--\n";}
}

int Student :: getSnumber()
/*Returns the student number for the particullar student*/
{
	return this->snumber;
}

ostream& operator << (ostream& print, Student& s1)
/*Teaches the system to print a student with all his details by overloading the << operator*/
{
	print <<"Student Name: "<< s1.sname <<endl;
	print <<"Student Number: "<< s1.getSnumber() <<endl;
	print << "  --List of Courses--\n";
		for(int i = 0; i < s1.nocss; i++){
			print << "   Course code: "<<s1.Array[i].ccode<<endl;
			print << "   Course name: "<<s1.Array[i].cname<<endl;
			print << "   Course instructor: "<<s1.Array[i].cinst<<endl;
		}
	return print;
}
