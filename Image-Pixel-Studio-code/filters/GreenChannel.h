#ifndef GREENCHANNEL_H
#define GREENCHANNEL_H
#include "Filter.h"
class GreenChannel:public Filter{
public:
GreenChannel();
void apply(Image &img);};

#endif
