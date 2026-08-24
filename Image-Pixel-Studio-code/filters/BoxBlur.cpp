#include "BoxBlur.h"
BoxBlur::BoxBlur():Filter("Box Blur","Spatial Filter"){}
void BoxBlur::apply(Image &img){
int h=img.getHeight();
int w=img.getWidth();
//copy of image
Image temp(img);
//skipping border
for(int i=1;i<h-1;i++){
for(int j=1;j<w-1;j++){
int sumR=0,sumG=0,sumB=0;
//neighbour
for(int di=0;di<=2;di++){
for(int dj=0;dj<=2;dj++){
Pixel &p=temp.at(i+di-1,j+dj-1);
sumR+=p.getRed();
sumG+=p.getGreen();
sumB+=p.getBlue();}}
img.at(i,j).setRed(sumR/9);
img.at(i,j).setGreen(sumG/9);
img.at(i,j).setBlue(sumB/9);}}}
