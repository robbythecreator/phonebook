#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;
void bigorsmall(bool& true_false, string old_name, string new_name);
//true_false returns true if the new name is a higher lexicographic order than the old name
void first_or_last(bool& firstlast, string enteredname, string arrayofnames[][501]);
//firstlast returns true if the entered name is a first name, false otherwise.
void outputphonenumber(string entered_name, string name_book[][501]);
//entered_name is the name you enter, name_book is your array, firstlasttest tells the function
//whether to go through the first or last names of the array.
void makearray(istream& instream, string name_book[][501]);
void sortarray(string book_name[][501]);
void fixname(string& fixname);
void findname(string array_of_names[][501], string entered_name);
int main() {
  string namebook[3][501], name_entered; ifstream in_stream;
  in_stream.open("500_clean.csv");
  if(in_stream.fail()){
    cout << "Input file opening failed.\n";
    exit(1); }
  makearray(in_stream, namebook);
  sortarray(namebook);
  
  //  string testname1 = namebook[0][167], testname2=namebook[0][333];
  cout << "Please enter the name of the person whose phone number you would like: " << endl;
  cin >> name_entered;
  findname(namebook,name_entered);
  




  
  //fixname(name_entered);
  

  /*
  bool true_false_test1=true; 
  bool true_false_test2=true; 
  bool firstlast=false;
  first_or_last(firstlast,name_entered, namebook);
  bigorsmall(true_false_test1, testname1, name_ //  outputphonenumber(name_entered, namebook);
  //  outputphonenumber(name_entered, namebook);
  if(firstlast == true){
    cout << "You entered a first name";
    
    bigorsmall(true_false_test1,testname1, name_entered);
    bigorsmall(true_false_test2, testname2, name_entered);
    
    
    if((name_entered.length() < 3) || name_entered.length() > 12) {
      cout << "Sorry but the phonebook does not contain the name you are looking for.\n";
      exit(1);
    }
    if(true_false_test1 == true) {
      //    cout << name_entered << " is a higher order than " << testname1 << endl;
      for(int i = 167; i >= 0; i--) {
	string searchname = namebook[0][i];
	if(name_entered == searchname) {
	  cout << "The phone number for " << namebook[0][i] << " " << namebook[1][i] << " is: " << namebook[2][i] << endl;
	  exit(1);
	}
      }
    }
    else if(true_false_test2 == true) {
      cout << name_entered << " is a higher order than " << testname2 << " but a lower order than " << testname1 << endl;
      for(int i = 167; i >= 333; i--) {
	string searchname = namebook[0][i];
	if(name_entered == searchname) {
	  cout << "The phone number for " << namebook[0][i] << " " << namebook[1][i] << " is: " << namebook[2][i] << endl;
	  exit(1);
	}
      }
    }
    else {
      //cout << name_entered << " is a higher order than " << testname3 << " but a lower order than " << testname2 << endl;
      for(int i = 333; i < 500; i++) {
	string searchname = namebook[0][i];
	if(name_entered == searchname) {
	  cout << "The phone number for " << namebook[0][i] << " " << namebook[1][i] << " is: " << namebook[2][i] << endl;
	  exit(1);
	}
      }
    }
    
  }
  else {
    cout << "you entered a lastname\n";
    bool nametest=false;
    for(int i = 0; i < 500; i++) {
      string searchname = namebook[1][i];
      if(name_entered == searchname) {
	cout << "The phone number for " << namebook[0][i] << " " << namebook[1][i] << " is: " << namebook[2][i] << endl;
	exit(1);
      }
    }
    if(nametest == false) {cout << "Sorry the phonebook does not contain the name you are looking for.\n";}
  }*/
  return 0;				
}




void bigorsmall(bool& true_false, string old_name, string new_name) {
  char a = new_name[0], b = old_name[0]; int length;
  if(new_name.length() > old_name.length()) { length = old_name.length(); } else { length = new_name.length(); }
  for(int i = 0; i < (length + 1); i++) {
    if(a == b) {
      a = new_name[i+1]; b = old_name[i+1];
    }
    else if(a < b) {
      true_false = true;
      break;
    }
    else if(a > b) {
      true_false = false;
      break; 
    }
  }
}
void first_or_last(bool& firstlast, string enteredname, string arrayofnames[][501]) {
  for(int i = 0; i < 501; i++) {
    string firstname = arrayofnames[0][i];
    if(enteredname == firstname) {
      firstlast = true;
      break;
    }
  }
}

void makearray(istream& instream, string name_book[][501]) {
  for(int i = 0; i < 501; i++) {
    int count = 0; string first_name = "";
    string last_name = ""; string phone_number = "";
    
    string line1; char nextchar;
    getline(instream, line1);
    
    do {
      nextchar = line1[count];
      first_name += nextchar;     
      count++;
    } while(nextchar != ',');
    first_name.erase(first_name.end()-1);
    name_book[0][i] = first_name;
    do {
      nextchar = line1[count];
      last_name += nextchar;      
      count++;
    } while(nextchar != ',');
    last_name.erase(last_name.end()-1);
    name_book[1][i] = last_name;
    do {
      nextchar = line1[count];
      phone_number += nextchar;
      count++;
    } while(nextchar != '\0');
    phone_number.erase(phone_number.end()-1);
    name_book[2][i] = phone_number;
  }
}
void sortarray(string book_name[][501]) {
  for(int i = 1; i < 501; i++) {

    bool truefalse = true;
    int count1 = 1;    int count2 = 0;    

    while(count1 != 0) {
      if((i-1-count2) >= 0) {
      bool true_false;
	string newname = book_name[0][i-count2];	string oldname = book_name[0][i-1-count2];
	string newlastname = book_name[1][i-count2];	string oldlastname = book_name[1][i-1-count2];
	string newphonenumber = book_name[2][i-count2];	string oldphonenumber = book_name[2][i-1-count2];

	bigorsmall(truefalse, oldname, newname);

	if(truefalse == true) {
	  book_name[0][i-1-count2] = newname;
	  book_name[1][i-1-count2] = newlastname;
	  book_name[2][i-1-count2] = newphonenumber;
	  book_name[0][i-count2] = oldname;
	  book_name[1][i-count2] = oldlastname;
	  book_name[2][i-count2] = oldphonenumber;
	  count2++;
	}
	else { count1 = 0; }
      }
      else { count1 = 0; }
    }
  }
}
void fixname(string& fixname) {
  int length = fixname.length();
  char c = fixname[0];
  fixname[0] = toupper(c);
  for(int i = 1; i < length; i++) {
    char x = fixname[i];
    x = tolower(x);
    fixname[i] = x;
  }
}



void findname(string array_of_names[][501], string entered_name) {
  //cout << array_of_names[0][0] << endl;
  
  string build_name = "";string build_other_name = "";
  int lengthofname = entered_name.length();
  
  int i; int ii;
  //i is the index of the array, ii is the index of the string
      
  for(ii = 0; ii < lengthofname; ii++) { //puts characters onto string until the string equals a name in either index
    
    build_name += entered_name[ii];
    
    //fixname(build_other_name);
        
    //cout << build_name << endl;
        
    for(i = 0; i < 501; i++) {
      fixname(build_name);
      if(build_name == array_of_names[0][i]) {
	//cout << "you entered a first name\n";
	        
	if(entered_name[ii+1] != '\0') {        
	  
	  for(int iii= ii+1; iii < lengthofname; iii++) {
	    //puts characters onto a second string until the string equals another name        
	    //cout << entered_name[iii] << endl;            
	    
	    if(entered_name[iii] != ' ') {
	      build_other_name += entered_name[iii];
	      fixname(build_other_name);
	      //cout << build_other_name << endl;                
	      
	      if(build_other_name == array_of_names[1][i]) {
		//cout << "you entered a last name\n";
		cout << "you entered " << array_of_names[0][i] << " " << array_of_names[1][i] << endl;
		cout << "the phone number you want is: " << array_of_names[2][i] << endl;
		exit(1);
	      }
	    }
	    else if(entered_name[iii+1] == ' ') {
	      break;
	    }
	  }
	}
	else { cout << "you only entered a first name\n"; 
	  cout << "you entered " << array_of_names[0][i] << " " << array_of_names[1][i] << endl;
	  cout << "the phone number you want is: " << array_of_names[2][i] << endl;
	}        
      }
              
      else if(build_name == array_of_names[1][i]) {
	//cout << "you entered a last name\n";
	
	if(entered_name[ii+1] != '\0') {        
	          
	  for(int iii= ii+1; iii < lengthofname; iii++) {
	    //puts characters onto a second string until the string equals another name        
	    //cout << entered_name[iii] << endl;            
	            
	    if(entered_name[iii] != ' ') {
	      build_other_name += entered_name[iii];
	      fixname(build_other_name);
	      //cout << build_other_name << endl;                
	      
	      if(build_other_name == array_of_names[0][i]) {
		//cout << "you entered a first name\n";
		cout << "you entered " << array_of_names[0][i] << " " << array_of_names[1][i] << endl;
		cout << "the phone number you is: " << array_of_names[2][i] << endl;
		exit(1);
	      }
	    }
	            
	    else if(entered_name[iii+1] == ' ') {
	      break;
	    }
	  }
	}
	
	else { cout << "you only entered a last name\n"; 
	  cout << "you entered " << array_of_names[0][i] << " " << array_of_names[1][i] << endl;
	  cout << "the phone number you is: " << array_of_names[2][i] << endl;
	}    
      }     
    }    
  } 
}
