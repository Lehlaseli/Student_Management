#include <iostream>
#include "Students.h"

/***********
 * Methods *
 ***********
*/

int height(Student *N) 
/*Gives the distance of a Student from the Root*/
{
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b)
/*Finds the maximum of two integers
  returns a if it is greater than b,
  else returns b*/
{
  return (a > b) ? a : b;
}

Student *newStudent(int aSnumber, string aSname, int aNocss, Course *aCourses)
/*Student creation Algorithm Takes name,number of courses,Array of courses for each student*/ 
{
  Student *newstd = new Student();
  newstd->setSnumber(aSnumber);
  newstd->sname =aSname;
  newstd->nocss =aNocss;
  newstd->Array =aCourses;
  newstd->height = 1;
  return (newstd);
}

// Rotate right
Student *rightRotate(Student *y) 
{
  Student *x = y->left;			//x holds the left subtree of y
  Student *T2 = x->right;		//T2 holds the right subtree of 
  
  x->right = y;					//right subtree of x becomes parent of y
  y->left = T2;					//oldsubtree of x is the left subtree of patrent
  y->height = max(height(y->left),height(y->right)) +1;
  x->height = max(height(x->left),height(x->right)) +1;
  return x;
}

Student *leftRotate(Student *x)
{
    Student *y = x->right;
    Student *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    // Update heights
    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;
    // Return new root
    return y;
}

// Get the balance factor of each Student
int getBalanceFactor(Student *N) {
  if (N == NULL)
    return 0;
  /*Balance factor = Left hieght - right height*/  
  return height(N->left)-height(N->right);
}

bool Students :: IsEmpty()
/*Checks if Tree is Empty*/
{
	if(root == NULL){return true;}
	return false;	
}

Student *Students :: get_root()
/*Returns the root*/
{
	return root;	
}

void Students :: set_root(Student *updated)
/*Updates the tree after an operation*/
{
	root = updated;
}

Student *Students :: InsertStudent(Student *cpos, int aSnumber, string aSname, int aNocss, Course *aCourses) {
  /*Finds a suitable place to insert the node, by using student number as the key to create a binary seardch
    and updates the balance factor of each node, and balances it if necessary*/
  if(cpos == NULL){
    return (newStudent(aSnumber,aSname,aNocss,aCourses));
	}
  if (aSnumber < cpos->getSnumber())
    cpos->left = InsertStudent(cpos->left, aSnumber,aSname,aNocss,aCourses);
  else if (aSnumber > cpos->getSnumber())
    cpos->right = InsertStudent(cpos->right, aSnumber,aSname,aNocss,aCourses);
  else
    return cpos;
  /* Update the balance factor of each Student and
     balance the tree.*/
  
  cpos->height = 1 + max(height(cpos->left),height(cpos->right));
  int balanceFactor = getBalanceFactor(cpos);
  if (balanceFactor > 1) {
    if (aSnumber < cpos->left->getSnumber()) {
      return rightRotate(cpos);
    } else if (aSnumber > cpos->left->getSnumber()) {
      cpos->left = leftRotate(cpos->left);
      return rightRotate(cpos);
    }
  }
  if (balanceFactor < -1) {
    if (aSnumber > cpos->right->getSnumber()) {
      return leftRotate(cpos);
    }
	else if (aSnumber < cpos->right->getSnumber()) {
      cpos->right = rightRotate(cpos->right);
      return leftRotate(cpos);
    }
  }
  return cpos;
}

void Students ::  DisplayAll(Student *cpos){
	/*Prints all Students of the tree by In-order traversal
	  Time complexity nlog(n)*/
	if(IsEmpty()){cout << "--There are currently no Entries in Database--\n";}
	if(cpos == NULL){
		return;
	}
	DisplayAll(cpos->left);
		cout << *cpos<<endl;
		cout << endl;
	DisplayAll(cpos->right);
}

void Students ::  DisplayStudent(Student *cpos, int aSnumber)
/*Prints a Particular Student by searching the tree*/
{
	cout << "*********************\n";
	cout << "*  STUDENT DETAILS  *\n";
	cout << "*********************\n";
	if(Search(cpos,aSnumber) == true){
		cout << *key << endl;
	}
	else{
		cout << "--Student Number Absent from Database--\n";
	}
}

bool Students :: Search(Student* cpos, int aSnumber)
{
    // If cpos is NULL
    if (cpos == NULL){return false;}
    // If found, return true,base case to break the recurcion
    else if (cpos->getSnumber() == aSnumber){
    	key = cpos;
        return true;
	}
    /* Recur to the left subtree if the current 
	Student's value is greater than aSnumber*/
    else if (cpos->getSnumber() > aSnumber){
        bool val = Search(cpos->left, aSnumber);
        return val;
    }
    /* Otherwise, recur to the
       right subtree*/
    else {bool val = Search(cpos->right, aSnumber);
        return val;
	}
}
 

// Student with minimum value
Student *StudentWithMimumValue(Student *student)
/*Finds the bottom left Student of the tree*/
{
  Student *current = student;
  while (current->left != NULL)
    current = current->left;
  return current;
}
// Delete a Student
Student *Students :: DeleteStudent(Student *cpos, int aSnumber)
/* Traverses The tree By comparing the given Student number With aech Student on the tree
And deletes him then computes the balance factor, and bances the tree if neccessary.*/
{
  if (cpos == NULL)return cpos;
  if (aSnumber < cpos->getSnumber())
    cpos->left = DeleteStudent(cpos->left, aSnumber);
  else if (aSnumber > cpos->getSnumber())
    cpos->right = DeleteStudent(cpos->right, aSnumber);
  else {
    if ((cpos->left == NULL) ||(cpos->right == NULL)){
      Student *temp = cpos->left ? cpos->left : cpos->right;
      if (temp == NULL) {temp = cpos;cpos = NULL;} 
	  else
        *cpos = *temp;
      free(temp);
    } else {
      Student *temp = StudentWithMimumValue(cpos->right);
      cpos->setSnumber(temp->getSnumber());
      cpos->right = DeleteStudent(cpos->right,temp->getSnumber());
    }
  }

  if (cpos == NULL)
    return cpos;
  // Update the balance factor of each Student and
  // balance the tree
  cpos->height = 1 + max(height(cpos->left),height(cpos->right));
  int balanceFactor = getBalanceFactor(cpos);
  if (balanceFactor > 1) {
    if (getBalanceFactor(cpos->left) >= 0) {
      return rightRotate(cpos);
    } else {
      cpos->left = leftRotate(cpos->left);
      return rightRotate(cpos);
    }
  }
  if (balanceFactor < -1) {
    if (getBalanceFactor(cpos->right) <= 0) {
      return leftRotate(cpos);
    } else {
      cpos->right = rightRotate(cpos->right);
      return leftRotate(cpos);
    }
  }
  return cpos;
}

void Students :: destroyTree(Student *cpos)
{
	if(cpos == NULL){return;}
	//Post-Order traversal
	destroyTree(cpos->left);
	destroyTree(cpos->right);
	//Deletion
	{delete cpos;}
}
