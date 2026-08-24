#ifndef IMAGEMANAGER_H
#define IMAGEMANAGER_H
#include"../core/Image.h"
#include<string>
using namespace std;
class ImageFileManager{
public:
Image* load(string path);
void save(string path,Image* img);};

#endif
