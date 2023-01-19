#include "Student.cpp"
#include "Course.h"

#ifndef STUDENTS_H
#define STUDENTS_H

class Students
/*Defines a Tree of students including all the
  Including all the methods. Insert, Delete,
  Display etc,,.*/
{
	private:
		Student *root = NULL;
	public:	
		Student *key = NULL;
		//Methods
		bool IsEmpty();
		bool Search(Student* cpos, int aSnumber);
		void set_root(Student *updated);
		void DisplayStudent(Student *cpos, int aSname);
		void DisplayAll(Student *cpos);
		void destroyTree(Student *cpos);
		Student *deleteRoot();
		Student *get_root();
		Student *InsertStudent(Student *cpos, int aSnumber, string aSname, int aNocss, Course *aCourses);
		Student *DeleteStudent(Student *root, int aSnumber);
};
#endif