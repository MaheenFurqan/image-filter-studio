#include "FilterSession.h"
#include <iostream>
using namespace std;
// constructor
FilterSession::FilterSession(string cnic,Image* img){
UserCNIC=cnic;
image=img;
filters=nullptr;
filtercount=0;}

//fnc to add filter
FilterSession &FilterSession::addFilter(Filter *f){
Filter **temp=new Filter*[filtercount+1];
for(int i=0;i<filtercount;i++){
temp[i]=filters[i];}
temp[filtercount]=f;
delete[] filters;
filters=temp;
filtercount++;
return *this;}    // this helps in method chaining

//fnc to apply all filters
void FilterSession::applyAll(){
for(int i=0;i<filtercount;i++){
filters[i]->apply(*image);}}

//fnc to have image
Image *FilterSession::getImage(){
return image;}

//fnc to clear/clean
void FilterSession::clear(){
for(int i=0;i<filtercount;i++){
delete filters[i];}
delete[] filters;
filters=nullptr;
filtercount=0;}

//fnc for saving
void FilterSession::saveResults(string path){
if(image){
image->save(path);
cout<<"Image saved successfully: "<<path<<endl;}}

// destructor
FilterSession::~FilterSession(){
clear();}
