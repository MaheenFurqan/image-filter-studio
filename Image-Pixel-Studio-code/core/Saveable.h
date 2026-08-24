#ifndef SAVEABLE_H
#define SAVEABLE_H
#include <string>
using namespace std;
class Saveable{
public:
//pure virtual fnc
virtual void save(const string &path)=0;

//destructor
virtual ~Saveable(){}};

#endif
