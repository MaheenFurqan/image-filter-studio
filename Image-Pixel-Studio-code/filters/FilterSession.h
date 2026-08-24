#ifndef FILTERSESSION_H
#define FILTERSESSION_H
#include <string>
#include "Filter.h"
using namespace std;
class FilterSession{
private:
Filter **filters;
int filtercount;
Image *image;
string UserCNIC;

public:
FilterSession(string cnic,Image *img);
FilterSession &addFilter(Filter *f);
void applyAll();
void clear();
void saveResults(string path);
Image* getImage();
~FilterSession();};

#endif
