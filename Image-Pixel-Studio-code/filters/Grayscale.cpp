#include "Grayscale.h"
//constructor
GrayscaleFilter::GrayscaleFilter():Filter("Grayscale","Pixel Transform"){}

//virtual fnc definition
void GrayscaleFilter::apply(Image &img){
for(int i=0;i<img.getHeight();i++){
for(int j=0;j<img.getWidth();j++){
Pixel &p=img.at(i,j);
int gray=(p.getRed()+p.getGreen()+p.getBlue())/3;
p.setRed(gray);
p.setGreen(gray);
p.setBlue(gray);}}}
