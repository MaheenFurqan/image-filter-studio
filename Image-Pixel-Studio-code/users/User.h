#ifndef USER_H
#define USER_H
#include <string>
using namespace std;
class User{
protected:
string CNIC;
string password;
string fullName;
string gender;
string phone;
string city;
bool isBlocked;
public:
User(string cnic,string pass,string name,string gen,string ph,string cty,bool blocked);

// getters
string getCNIC()const;
string getPassword()const;
string getFullName()const;
string getGender()const;
string getPhone()const;
string getCity()const;
bool getIsBlocked()const;
void setBlocked(bool val);

bool login(string enteredPass);
void logout();
virtual void displayMenu()=0;
virtual ~User();};

#endif
