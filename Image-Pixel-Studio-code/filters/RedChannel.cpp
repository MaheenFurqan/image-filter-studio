#include "RedChannel.h"
//constructor
RedChannel::RedChannel():Filter("Red Channel only","Pixel Transform"){}

//fnc to apply filter
void RedChannel::apply(Image &img){
for(int i=0;i<img.getHeight();i++){
for(int j=0;j<img.getWidth();j++){
Pixel &p=img.at(i,j);
p.setGreen(0);
p.setBlue(0);}}}
