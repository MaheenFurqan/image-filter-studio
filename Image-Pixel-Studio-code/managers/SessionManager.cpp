#include"SessionManager.h"
#include<fstream>
#include<iostream>
using namespace std;
SessionManager::SessionManager(string file){
fileName=file;}

void SessionManager::addSession(string cnic, string filters, string outputFile){
ofstream fout(fileName.c_str(), ios::app);
fout<<cnic<<"|"<<filters<<"|"<<outputFile<<endl;
fout.close();}

void SessionManager::viewSessions(string cnic){
ifstream fin(fileName.c_str());
string line;
while(getline(fin, line)){
if(line.find(cnic)!=string::npos)
cout<<line<<endl;}
fin.close();}

void SessionManager::viewAllSessions(){
ifstream fin(fileName.c_str());
string line;
while(getline(fin, line)){
cout<<line<<endl;}
fin.close();}
