#include"Admin.h"
#include "../managers/CustomerManager.h"
#include "../managers/CatalogManager.h"
#include "../managers/SessionManager.h"
#include <iostream>
using namespace std;
Admin::Admin():User("0000000000000","Admin@123","Admin","M","","",false){
adminID="admin";}

bool Admin::login(string id,string pass){
if(id==adminID && pass==password){
cout<<"Admin login successful!"<<endl;
return true;}
cout<<"Invalid admin credentials!"<<endl;
return false;}

void Admin::displayMenu(){
cout<<"===== ADMIN PANEL ====="<<endl;
cout<<"1.Manage Customers"<<endl;
cout<<"2.Manage Catalog"<<endl;
cout<<"3.View Sessions"<<endl;
cout<<"4.Logout"<<endl;}

void Admin::manageCustomers(CustomerFileManager &cm){
int choice;
do{
cout<<"===== MANAGE CUSTOMERS ====="<<endl;
cout<<"1. View All Customers"<<endl;
cout<<"2. Block Customer"<<endl;
cout<<"3. Delete Customer"<<endl;
cout<<"4. Back"<<endl;
cout<<"Enter choice: "<<endl;
cin>>choice;
if(choice==1){
int count;
Customer** list=cm.loadAll(count);
for(int i=0;i<count;i++){
cout<<list[i]->getCNIC()<<" | "<<list[i]->getFullName()<<endl;}}
else if(choice==2){
string cnic;
cout<<"Enter CNIC to block: ";
cin>>cnic;
cm.blockCustomer(cnic);
cout<<"Customer blocked."<<endl;}
else if(choice==3){
string cnic;
cout<<"Enter CNIC to delete: ";
cin>>cnic;
cm.deleteCustomer(cnic);
cout<<"Customer deleted."<<endl;}}
while(choice!= 4);}

void Admin::manageCatalog(CatalogFileManager &catalog){
int choice;
do{
cout<<"--- CATALOG MANAGEMENT ---"<<endl;
cout<<"1. View Filters"<<endl;
cout<<"2. Back"<<endl;
cout<<"Enter choice: ";
cin>>choice;
if(choice == 1){
catalog.displayCatalog();}}
while(choice!=2);}

void Admin::viewAllSessions(SessionManager &sm){
cout<<"===== ALL SESSIONS ====="<<endl;
sm.viewSessions();}
