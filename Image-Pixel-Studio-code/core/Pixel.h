#ifndef PIXEL_H
#define PIXEL_H
#include<iostream>
using namespace std;
class Pixel{
private:
int red,green,blue;
public:
Pixel();
Pixel(int r,int g,int b);
int getRed()const;
int getGreen()const;
int getBlue()const;
void setRed(int r);
void setGreen(int g);
void setBlue(int b);
static int clamp(int val);
Pixel operator+(const Pixel &p);
friend ostream &operator<<(ostream &out,const Pixel &p);};

#endif
