#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H
#include"../users/Customer.h"
#include<string>
using namespace std;
class CustomerFileManager{
private:
string fileName;
public:
CustomerFileManager(string file);
Customer** loadAll(int &count);
void saveAll(Customer** list,int count);
Customer* searchCustomer(string CNIC);
void blockCustomer(string CNIC);
void deleteCustomer(string CNIC);
bool cnicExists(string CNIC);
bool isBlockedCNIC(string CNIC);
void addCustomer(Customer* c);};

#endif
