#ifndef REDCHANNEL_H
#define REDCHANNEL_H
#include "Filter.h"
class RedChannel:public Filter{
public:
RedChannel();
void apply(Image &img);};

#endif
