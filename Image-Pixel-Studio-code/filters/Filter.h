#ifndef FILTER_H
#define FILTER_H
#include <string>
#include "../core/Image.h"
using namespace std;
class Filter{
protected:
string name;
string category;
public:
//constructor
Filter(string name,string catagory);

//getters
string getName()const;
string getCategory()const;

//pure virtual fnc
virtual void apply(Image &img)=0;

//destructor
virtual ~Filter();};

#endif
