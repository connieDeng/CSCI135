/*
Author: Connie Deng
Course: CSCI-136
Instructor: Minh Nguyen
Assignment: Lab12 C, e.g., Lab1C

Task C. Class Network: Following others
*/

#include <cmath>
#include <string> 
#include <iostream>
using namespace std;

struct Post{
  string username;
  string message;
};

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
	
	bool following[MAX_USERS][MAX_USERS];
	static const int MAX_POSTS = 100;
	int numPosts;                    // number of posts
	Post posts[MAX_POSTS];           // array of all posts

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
		  for(int r = 0; r < MAX_USERS; r++)
		  {
			  for(int c = 0; c < MAX_USERS; c++)
			  {
				  following[r][c] = false;
			  }
		  }
		numPosts = 0;
	  }
	  
	  // Attempts to sign up a new user with specified username and displayname
	  // return true if the operation was successful, otherwise return false
	  bool addUser(string usrn, string dspn)
	  {
		  int i = 0;
		  if(findID(usrn) == -1 && usrn != "" && numUsers < MAX_USERS) //if user doesnt exist, not an empty string and there is space
		  {
			for(i; i < usrn.length(); i++)
			{
				if(!isalnum(usrn[i])) //check if there are symbols
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
	  
	bool follow(string usrn1, string usrn2)
	{
		if(findID(usrn1) != -1 && findID(usrn2) != -1) //if both users exist
		{
			//cout << findID(usrn1) << " " << findID(usrn2) << "\n";
			following[findID(usrn1)][findID(usrn2)] = true;
			return true;
		}
		return false;
	}
	
    void printDot()
	{
		cout << "digraph {" << "\n";
		
		for(int i = 0; i < numUsers; i++)
		{
			cout << "\"@" << profiles[i].getUsername() << "\"" << "\n";
		}

		//cout << "\n";
		
		for(int row = 0; row < numUsers; row++)
		{
			for(int col = 0; col < numUsers; col++)
			{
				if(following[row][col] == true)
				{
					cout << "\"@" << profiles[row].getUsername() << "\" -> \"@" << profiles[col].getUsername() << "\"" << "\n";
				}
			}
		}
		
		cout << "}";
	}	
	
	// Add a new post
	bool writePost(string usrn, string msg);
	// Print user's "timeline"
	bool printTimeline(string usrn);
};

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}