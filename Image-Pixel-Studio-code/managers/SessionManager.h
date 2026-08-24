#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H
#include <string>
using namespace std;
class SessionManager{
private:
string fileName;
public:
SessionManager(string file);

void addSession(string cnic, string filters, string outputFile);
void viewSessions(string cnic="");
void viewAllSessions();};

#endif
