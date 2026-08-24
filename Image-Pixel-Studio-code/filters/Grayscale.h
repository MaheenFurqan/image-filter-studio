#ifndef GRAYSCALE_H
#define GRAYSCALE_H
#include "Filter.h"
class GrayscaleFilter:public Filter{
public:
//constructor
GrayscaleFilter(); 
void apply(Image &img);};

#endif
