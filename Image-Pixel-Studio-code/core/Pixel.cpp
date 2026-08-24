#include "Pixel.h"
//default constructor
Pixel::Pixel():red(0),green(0),blue(0){}
//parametrized
Pixel::Pixel(int r,int g,int b){
red=clamp(r);
green=clamp(g);
blue=clamp(b);}

//clamp fnc <restricts to a boundary>
int Pixel::clamp(int value){
if(value<0){return 0;}
if(value>255){return 255;}
else{return value;}}

//setter
void Pixel::setRed(int value){red=clamp(value);}
void Pixel::setGreen(int value){green=clamp(value);}
void Pixel::setBlue(int value){blue=clamp(value);}

//getters
int Pixel::getRed()const{return red;}
int Pixel::getGreen()const{return green;}
int Pixel::getBlue()const{return blue;}

//operator + overloading
Pixel Pixel::operator+(const Pixel &p){
return Pixel(red+p.red,green+p.green,blue+p.blue);}

//operator << overloading
ostream &operator<<(ostream &os,const Pixel &p){
os<<"("<<p.getRed()<<","<<p.getGreen()<<","<<p.getBlue()<<")";
return os;}
