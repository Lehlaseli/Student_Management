#include <iostream>
#include<limits>

#ifndef INPUT_VALIDATION
#define INPUT_VALIDATION
using namespace std;


bool check_number(string str) {
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
      return true;
}

bool check_number(int str) {
  return true;
}

template<typename T>
bool getInput(T &input,string message,string error, int aTrys, bool terminate)
{
    cout << message;
    cin >> input;
    while(cin.fail() ||	!check_number(input)){           
        if(aTrys == 0){ cout <<"Contact +26657780400 for assistance.\n";
            cin.clear();cin.ignore(numeric_limits<streamsize>::max(),'\n');
            terminate = true;
            return false;
		}

		cout << "Invalid input\n";
        cin.clear();cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "("<<aTrys<<") trys remaining.\n";
        
        cout << error<<endl;
        cout << message;
		cin >> input;
		aTrys--;
	}cin.clear();cin.ignore();
	return true;
}
#endif