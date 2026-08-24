#ifndef CATALOGMANAGER_H
#define CATALOGMANAGER_H
#include"../filters/Filter.h"
#include<string>
using namespace std;
class CatalogFileManager{
private:
string fileName;
public:
CatalogFileManager(string file);
void displayCatalog();
void toggleFilter(string id);
Filter** getEnabledFilters(int &count);};

#endif
