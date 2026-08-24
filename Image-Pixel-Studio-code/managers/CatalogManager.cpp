#include"CatalogManager.h"
#include"../filters/Grayscale.h"
#include"../filters/Invert.h"
#include"../filters/Brightness.h"
#include"../filters/Contrast.h"
#include"../filters/RedChannel.h"
#include"../filters/GreenChannel.h"
#include"../filters/BlueChannel.h"
#include"../filters/BoxBlur.h"
#include"../filters/FlipHorizontal.h"
#include"../filters/FlipVertical.h"
#include<fstream>
#include<iostream>
using namespace std;
CatalogFileManager::CatalogFileManager(string file){
fileName=file;}

void CatalogFileManager::displayCatalog(){
ifstream fin(fileName.c_str());
string line;
cout<<"--- FILTER CATALOG ---"<<endl;
while(getline(fin, line)){
cout<<line<<endl;}
fin.close();}

void CatalogFileManager::toggleFilter(string id){
cout<<"Toggle logic here.";}

//fnc to get filters enabled
Filter** CatalogFileManager::getEnabledFilters(int &count){
count = 10;
Filter** list=new Filter*[count];
list[0]=new GrayscaleFilter();
list[1]=new InvertFilter();
int brightnessValue;
cout<<"Enter brightness: ";
cin>>brightnessValue;
list[2]=new BrightnessFilter(brightnessValue);
list[3]=new ContrastFilter();
list[4]=new RedChannel();
list[5]=new GreenChannel();
list[6]=new BlueChannel();
list[7]=new BoxBlur();
list[8]=new FlipHorizontal();
list[9]=new FlipVertical();
return list;}
