#include"User.h"
#include<iostream>
using namespace std;
User::User(string cnic,string pass,string name,string gen,string ph,string cty,bool blocked){
CNIC=cnic;
password=pass;
fullName=name;
gender=gen;
phone=ph;
city=cty;
isBlocked=blocked;}

string User::getCNIC()const{return CNIC;}
string User::getPassword()const{return password;}
string User::getFullName()const{return fullName;}
string User::getGender()const{return gender;}
string User::getPhone()const{return phone;}
string User::getCity()const{return city;}
bool User::getIsBlocked()const{return isBlocked;}
void User::setBlocked(bool val){isBlocked=val;}
bool User::login(string enteredPass){
if(isBlocked){
cout<<"Account is BLOCKED!"<<endl;
return false;}
if(enteredPass==password){
cout<<"Login successful!"<<endl;
return true;}
cout<<"Invalid password!"<<endl;
return false;}

void User::logout(){
cout<<"Logged out successfully."<<endl;}

User::~User(){}
