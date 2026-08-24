#include "Filter.h"
// constructor
Filter::Filter(string name,string catagory){
this->name=name;
this->category=catagory;}

// getters
string Filter::getName()const{
return name;}
string Filter::getCategory()const{
return category;}

// destructor
Filter::~Filter(){}
