#include "FlipVertical.h"
//constructor
FlipVertical::FlipVertical():Filter("Flip Vertical","Geometric"){}

//fnc to apply filter
void FlipVertical::apply(Image &img){
int h=img.getHeight();
int w=img.getWidth();
for(int i=0;i<h/2;i++){
for(int j=0;j<w;j++){
//swap
Pixel temp=img.at(i,j);
img.at(i,j)=img.at(h-i-1,j);
img.at(h-i-1,j)=temp;}}}
