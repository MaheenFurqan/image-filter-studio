#include "FlipHorizontal.h"
//constructor
FlipHorizontal::FlipHorizontal():Filter("Flip Horizontal","Geometric"){}

//fnc to apply filter
void FlipHorizontal::apply(Image &img){
int h=img.getHeight();
int w=img.getWidth();
for(int i=0;i<h;i++){
for(int j=0;j<w/2;j++){
//swapping  
Pixel temp=img.at(i,j);
img.at(i,j)=img.at(i,w-j-1);
img.at(i,w-j-1)=temp;}}}
