#include"CustomerManager.h"
#include<fstream>
#include<iostream>
using namespace std;
CustomerFileManager::CustomerFileManager(string file){
fileName=file;}

//fnc to load all the filters
Customer** CustomerFileManager::loadAll(int &count){
ifstream fin(fileName.c_str());
count=0;
if(!fin){return nullptr;}
string line;
////counting lines
while (getline(fin, line)){
if(line!=""){count++;}}
fin.clear();
fin.seekg(0);
Customer** list=new Customer*[count];
int i=0;
while (getline(fin, line)){
if(line==""){continue;}
string data[7];
int index=0;
string temp="";
for(int j=0;j<line.length();j++){
if(line[j]=='|'){
data[index++]=temp;
temp="";}
else{
temp+=line[j];}}
data[index]=temp;
list[i++]=new Customer(data[0],data[1],data[2],data[3],data[4],data[5],data[6]=="1",0);}
fin.close();
return list;}

//fnc to save
void CustomerFileManager::saveAll(Customer** list, int count){
ofstream fout(fileName.c_str());
for(int i=0;i<count;i++){
fout << list[i]->getCNIC()<<"|"<<list[i]->getPassword()<<"|"<<list[i]->getFullName()<<"|"<<list[i]->getGender()<<"|"<<list[i]->getPhone()<<"|";
fout<<list[i]->getCity()<<"|"<<(list[i]->getIsBlocked()?"1":"0")<<endl;}
fout.close();}

//fnc for searching
Customer* CustomerFileManager::searchCustomer(string CNIC){
int count;
Customer** list=loadAll(count);
for(int i=0;i<count;i++){
if(list[i]->getCNIC()==CNIC){return list[i];}}
return nullptr;}

//fnc to block
void CustomerFileManager::blockCustomer(string CNIC){
int count;
Customer** list=loadAll(count);
bool found=false;
for(int i=0;i<count;i++){
if(list[i]->getCNIC()==CNIC){
list[i]->setBlocked(true);
found=true;}}
saveAll(list, count);
if(!found){
cout<<"Customer not found!"<<endl;
return;}
cout<<"Customer blocked."<<endl;
cout<<"blocking CNIC = "<<CNIC<<endl;
// Write to file
ofstream fout("data/blocked_cnics.txt", ios::app);
if(!fout.is_open()){
cout<<"Error opening blocked file!"<<endl;
return;}
fout<<CNIC<<endl;
fout.close();}

//fnc to delete
void CustomerFileManager::deleteCustomer(string CNIC){
int count;
Customer** list = loadAll(count);
Customer** newList=new Customer*[count];
int newCount=0;
for(int i=0;i<count;i++){
if(list[i]->getCNIC()!=CNIC){
newList[newCount++]=list[i];}}
saveAll(newList,newCount);
cout<<"Customer deleted."<<endl;}

//fnc to check the dupication of cnic
bool CustomerFileManager::cnicExists(string CNIC){
ifstream fin(fileName.c_str());
string line;
while (getline(fin, line)){
string temp="";
for(int i=0;i<line.length();i++){
if(line[i]=='|'){break;}
temp+=line[i];}
if(temp==CNIC){return true;}}
return false;}

//writing blocked in a file
bool CustomerFileManager::isBlockedCNIC(string CNIC){
ifstream fin("data/blocked_cnics.txt");
string line;
while(getline(fin, line)){
if(line==CNIC){return true;}}
return false;}

//fnc to add a customer
void CustomerFileManager::addCustomer(Customer* c){
ofstream fout(fileName.c_str(),ios::app);
fout<<c->getCNIC()<<"|"<<c->getPassword()<<"|"<<c->getFullName()<<"|"<<c->getGender()<<"|"<<c->getPhone()<<"|"<<c->getCity()<<"|"<<"0"<<endl;
fout.close();}
