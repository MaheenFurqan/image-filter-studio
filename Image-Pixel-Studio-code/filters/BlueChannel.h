#ifndef BLUECHANNEL_H
#define BLUECHANNEL_H
#include "Filter.h"
class BlueChannel:public Filter{
public:
BlueChannel();
void apply(Image &img);};

#endif
