#include "GreenChannel.h"
//constructor
GreenChannel::GreenChannel():Filter("Green Channel only","Pixel Transform"){}

//fnc to apply filter
void GreenChannel::apply(Image &img){
for(int i=0;i<img.getHeight();i++){
for(int j=0;j<img.getWidth();j++){
Pixel &p=img.at(i,j);
p.setRed(0);
p.setBlue(0);}}}
