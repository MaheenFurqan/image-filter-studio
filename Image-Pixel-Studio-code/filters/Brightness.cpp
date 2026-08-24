#include "Brightness.h"
// constructor
BrightnessFilter::BrightnessFilter(int v):Filter("Brightness","Pixel Transform"){
value=v;}

//apply fnc
void BrightnessFilter::apply(Image &img){
for(int i=0;i<img.getHeight();i++){
for(int j=0;j<img.getWidth();j++){
Pixel &p =img.at(i,j);
//value added
p.setRed(Pixel::clamp(p.getRed()+value));
p.setGreen(Pixel::clamp(p.getGreen()+value));
p.setBlue(Pixel::clamp(p.getBlue()+value));}}}
