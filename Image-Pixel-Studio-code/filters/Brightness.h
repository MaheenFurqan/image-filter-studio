#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H
#include "Filter.h"
class BrightnessFilter:public Filter{
private:
int value;
public:
//constructor
BrightnessFilter(int v);

//apply fnc
void apply(Image &img);};

#endif
