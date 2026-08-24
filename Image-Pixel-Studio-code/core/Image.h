#ifndef IMAGE_H
#define IMAGE_H
#include "Pixel.h"
#include <string>
using namespace std;
//class FilterSession;
class Image{
private:
Pixel **pixels;
int width;
int height;
public:
//parametrized constructor
Image(int w,int h);

// copy constructor
Image(const Image &other);

// destructor
~Image();

// access pixel
Pixel &at(int r,int c);

// saving image
void save(const string &path);

// display ASCII preview
void displayASCII();

// getters
int getWidth()const;
int getHeight()const;

// friend class
friend class FilterSession;};

#endif
