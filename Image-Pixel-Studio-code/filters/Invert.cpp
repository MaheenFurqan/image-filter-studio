#include "Invert.h"
//constructor
InvertFilter::InvertFilter():Filter("Invert","Pixel Transform"){}

//virtual fnc definition
void InvertFilter::apply(Image &img){
for(int i=0;i<img.getHeight();i++){
for(int j=0;j<img.getWidth();j++){
Pixel &p=img.at(i,j);
p.setRed(255-p.getRed());
p.setGreen(255-p.getGreen());
p.setBlue(255-p.getBlue());}}}
