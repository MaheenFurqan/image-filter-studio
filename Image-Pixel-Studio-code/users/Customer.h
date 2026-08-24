#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "User.h"
class Customer:public User{
private:
int sessionCount;
public:
Customer(string cnic,string pass,string name,string gen,string ph,string cty,bool blocked,int sessions);
int getSessionCount() const;
void incrementSession();
void registerUser();
void loadImage();
void buildPipeline();
void applyFilters();
void viewHistory();
void displayMenu();};

#endif
