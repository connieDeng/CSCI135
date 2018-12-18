/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab12 B, e.g., Lab1C

Task B. Class Network: Adding users
*/

#include <cmath>
#include <string> 
#include <iostream>
using namespace std;

class Profile 
{
	private:
		string username;
		string displayname;
	public:
		// Profile constructor for a user (initializing 
		// private variables username=usrn, displayname=dspn)
		Profile(string usrn, string dspn)
		{
			username = usrn;
			displayname = dspn;
		}
		
		// Default Profile constructor (username="", displayname="")
		Profile()
		{
			username="";
			displayname="";
		}
		
		// Return username
		string getUsername()
		{
			return username;
		}
		
		// Return name in the format: "displayname (@username)"
		string getFullName()
		{
			return displayname + "(@" + username + ")";
		}
		// Change display name
		void setDisplayName(string dspn)
		{
			displayname = dspn;
		}
};

class Network 
{
	private:
	  static const int MAX_USERS = 20; // max number of user profiles
	  int numUsers;                    // number of registered users
	  Profile profiles[MAX_USERS];     // user profiles array:
									   // mapping integer ID -> Profile

	  // Returns user ID (index in the 'profiles' array) by their username
	  // (or -1 if username is not found)
	  int findID (string usrn)
	  {
		  for(int i = 0; i < numUsers; i++)
		  {
			if(profiles[i].getUsername() == usrn)
			{
				return i;
			}
		  }
		  return -1;
	  }
	  
	public:
	  // Constructor, makes an empty network (numUsers = 0)
	  Network()
	  {
		  numUsers = 0;
	  }
	  
	  // Attempts to sign up a new user with specified username and displayname
	  // return true if the operation was successful, otherwise return false
	  bool addUser(string usrn, string dspn)
	  {
		  int i = 0;
		  if(findID(usrn) == -1 && usrn != "" && numUsers < MAX_USERS)
		  {
			for(i; i < usrn.length(); i++)
			{
				if(!isalnum(usrn[i]))
				{
					return false;
				}
			
			}
			
			profiles[numUsers] = Profile(usrn, dspn);
			numUsers++;
			return true;
			
		  }
		  return false;
	  }
};

int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i), 
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}