#ifndef CONTRAST_H
#define CONTRAST_H
#include "Filter.h"
class ContrastFilter:public Filter{
public:
ContrastFilter();
void apply(Image &img);};

#endif
