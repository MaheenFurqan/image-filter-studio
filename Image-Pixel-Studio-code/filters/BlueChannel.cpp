#include "BlueChannel.h"
//constructor
BlueChannel::BlueChannel():Filter("Blue Channel only","Pixel Transform"){}

//fnc to apply filter
void BlueChannel::apply(Image &img){
for(int i=0;i<img.getHeight();i++){
for(int j=0;j<img.getWidth();j++){
Pixel &p=img.at(i,j);
p.setRed(0);
p.setGreen(0);}}}
