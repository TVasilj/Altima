#pragma once
#include <vector>
#include <set>
#include <stdlib.h>
#include "Relatives.h"

using namespace std;

class Altima {
public:
  Altima();
  ~Altima();


  bool run(vector<Relatives>& relatives);
  set<string> getParentOnly(vector<Relatives>& vect);
  void print(set<string>& parent, vector<Relatives>& relatives);
  void checkChild(string parent, vector<Relatives>& vecto);
  void contains(set<string> parents, string child);
  void printParent(set<string>& parent, vector<Relatives>& relatives);
  void printChild(string parent, vector<Relatives>& vect, string shift);
};
