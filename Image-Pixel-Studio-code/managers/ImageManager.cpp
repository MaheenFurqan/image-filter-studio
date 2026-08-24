#define STB_IMAGE_IMPLEMENTATION
#include"../stb/stb_image.h"
#include"ImageManager.h"
#include<iostream>
using namespace std;
Image* ImageFileManager::load(string path){
int w,h,ch;

unsigned char* data = stbi_load(path.c_str(), &w, &h, &ch, 3);

if (!data){
cout<<"Error loading image."<<endl;
return nullptr;}
Image* img=new Image(w, h);
int index=0;
for(int i=0;i<h;i++){
for(int j=0;j<w;j++){
img->at(i,j).setRed(data[index++]);
img->at(i,j).setGreen(data[index++]);
img->at(i,j).setBlue(data[index++]);}}
stbi_image_free(data);
return img;}

void ImageFileManager::save(string path, Image* img){
img->save(path);}
