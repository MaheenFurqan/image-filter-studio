#ifndef INVERT_H
#define INVERT_H
#include "Filter.h"
class InvertFilter:public Filter{
public:
//constructor
InvertFilter();
void apply(Image &img);};

#endif
