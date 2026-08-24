#include"Customer.h"
#include<iostream>
using namespace std;
Customer::Customer(string cnic,string pass,string name,string gen,string ph,string cty,bool blocked,int sessions):User(cnic,pass,name,gen,ph,cty,blocked){
sessionCount=sessions;}

int Customer::getSessionCount()const{
return sessionCount;}

void Customer::incrementSession(){
sessionCount++;}

void Customer::displayMenu(){
cout<<"===== CUSTOMER MENU ====="<<endl;
cout<<"1. Browse Filter Catalog"<<endl;
cout<<"2. Load Image"<<endl;
cout<<"3. Build Pipeline"<<endl;
cout<<"4. Apply Filters"<<endl;
cout<<"5. View History"<<endl;
cout<<"6. Logout"<<endl;}

void Customer::registerUser(){}
void Customer::loadImage(){}
void Customer::buildPipeline(){}
void Customer::applyFilters(){}
void Customer::viewHistory(){}
