#include "Contrast.h"
// constructor
ContrastFilter::ContrastFilter():Filter("Contrast","Pixel Transform"){}

//fnc to apply filter
void ContrastFilter::apply(Image &img){
int minVal=255;
int maxVal=0;
for(int i=0;i<img.getHeight();i++){
for(int j=0;j<img.getWidth();j++){
Pixel &p=img.at(i,j);
int r=p.getRed();
int g=p.getGreen();
int b=p.getBlue();

if(r<minVal){minVal=r;}
if(g<minVal){minVal=g;}
if(b<minVal){minVal=b;}
if(r>maxVal){maxVal=r;}
if(g>maxVal){maxVal=g;}
if(b>maxVal){maxVal=b;}}}
for(int i=0;i<img.getHeight();i++){
for(int j=0;j<img.getWidth();j++){
Pixel &p=img.at(i,j);
int r=(p.getRed()-minVal)*255/(maxVal-minVal);
int g=(p.getGreen()-minVal)*255/(maxVal-minVal);
int b=(p.getBlue()-minVal)*255/(maxVal-minVal);

p.setRed(Pixel::clamp(r));
p.setGreen(Pixel::clamp(g));
p.setBlue(Pixel::clamp(b));}}}
