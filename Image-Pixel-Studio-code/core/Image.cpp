#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../stb/stb_image_write.h"
#include "Image.h"
#include <vector>

//constructor
Image::Image(int w,int h){
width=w;
height=h;
//memory allocation
pixels=new Pixel*[height];
for(int i=0;i<height;i++){
pixels[i]=new Pixel[width];}}

//copy constructor
Image::Image(const Image &other){
width=other.width;
height=other.height;
pixels=new Pixel*[height];
for(int i=0;i<height;i++){
pixels[i]=new Pixel[width];
for(int j=0;j<width;j++){
pixels[i][j]=other.pixels[i][j];}}}

//destructor
Image::~Image(){
for(int i=0;i<height;i++){
delete[]pixels[i];}
delete[]pixels;}

//at  fnc(access a specific pixel)
Pixel &Image::at(int r,int c){
if(r<0||r>=height||c<0||c>=width){
cout<<"Index out of bounds!"<<endl;
exit (-1);}
return pixels[r][c];}

//getters
int Image::getWidth()const{
return width;}
int Image::getHeight()const{
return height;}

//display ASCII
void Image::displayASCII(){
for(int i=0;i<height;i++){
for(int j=0;j<width;j++){
Pixel p=pixels[i][j];
int brightness=(p.getRed()+p.getGreen()+p.getBlue())/3;
char ch;
if(brightness<32)ch=' ';
else if(brightness<64)ch='.';
else if(brightness<96)ch=':';
else if(brightness<128)ch='-';
else if(brightness<149)ch='=';
else if(brightness<170)ch='+';
else if(brightness<192)ch='*';
else if(brightness<224){ch='#';}
else if(brightness<=255){ch='@';}
cout<<ch;}
cout<<endl;}}

//saving
void Image::save(const string &path){
int w=width;
int h=height;
unsigned char *data=new unsigned char[w*h*3];
int index=0;
for(int i=0;i<h;i++){
for(int j=0;j<w;j++){
Pixel &p=pixels[i][j];
data[index++]=(unsigned char)p.getRed();
data[index++]=(unsigned char)p.getGreen();
data[index++]=(unsigned char)p.getBlue();}}

stbi_write_png(path.c_str(),w,h,3,data,w*3);
delete[] data;}
