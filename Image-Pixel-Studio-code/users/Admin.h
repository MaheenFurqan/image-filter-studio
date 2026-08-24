#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"
class CustomerFileManager;
class CatalogFileManager;
class SessionManager;
class Admin:public User{
private:
string adminID;
public:
Admin();
bool login(string id, string pass);
void manageCustomers(CustomerFileManager &cm);
void manageCatalog(CatalogFileManager &catalog);
void viewAllSessions(SessionManager &sm);
void displayMenu();};



#endif
