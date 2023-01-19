#include <iostream>
#include "Course.h"

#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student 
/*Blueprint of a Student*/
{
	private:
		int snumber;		//Student number and 
	public:
		Student ();			//Default constructor
		~Student ();			//Default destructor
		void setSnumber(int aSnumber);   //Sets student number
		int getSnumber();   //Returns student number
		void insertCourse(string aCname, string aCcode, string aCinst);//Inserts a course of a student
		void deleteCourse(string aCcode); //Deletes a course from the array of courses via course code
		bool searchCourse(string aCcode); //Searches for a course in the student array
		int nocss;			//Number of Courses respectively
		string sname;		//Surname
		Course *Array;		//Array of courses
		Student *left;		//Pointer to the left child
		Student *right;		//Pointer to the right child
		int height;			//Height of the node
};

ostream& operator << (ostream& print, Student& s1);
#endif