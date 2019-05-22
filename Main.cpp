#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>

#include "Altima.h"
#include "Relatives.h"
using namespace std;

vector<Relatives> readData();
/*
set<string> getParentOnly(vector<Relatives>& vect);

void run(vector<Relatives>& relatives);
void print(set<string>& parent, vector<Relatives>& relatives);
void checkChild(string parent, vector<Relatives>& vecto);
void contains(set<string> parents, string child);
void printParent(set<string>& parent, vector<Relatives>& relatives);
void printChild(string parent, vector<Relatives>& vect, string shift);
*/
int main()
{
  Altima a;
  vector<Relatives> relatives_(readData());
  a.run(relatives_);

  system("pause");
  return 0;
}

vector<Relatives> readData() {
  string         line = "";
  string         word = "";
  fstream        myData;
  myData.open("relatives.txt");
  vector<Relatives> relativesVector;

  while (getline(myData, line)) {
    string word = "";
    string relatives[2];
    for (char x : line)
    {
      if (x == ' ')
      {
        relatives[0] = word;
        word = "";
      }
      else
      {
        word = word + x;
        relatives[1] = word;
      }
    }
    Relatives rel(relatives[0], relatives[1]);
    relativesVector.push_back(rel);
  }
  myData.close();
  return relativesVector;
}
/*
void run(vector<Relatives>& relatives) {
  set<string> parent_;

  try {
    parent_ = getParentOnly(relatives);
    print(parent_, relatives);
  }
  catch (const char* msg) {
    cout << msg << endl;
    abort();
  }
}

set<string> getParentOnly(vector<Relatives>& vect) {
  set<string> parent;

  for (std::vector<Relatives>::iterator it1 = vect.begin(); it1 != vect.end(); ++it1) {
    int i = 0;
    for (std::vector<Relatives>::iterator it2 = vect.begin(); it2 != vect.end(); ++it2) {
      if (it1->getParent() == it2->getChild()) {
        i++;
      }
    }
    if (i == 0) parent.insert(it1->getParent());
  }
  if (parent.size() == 0) {
    throw "cyclic!";
  }
  return parent;
}

void print(set<string>& parent, vector<Relatives>& relatives) {
  for (std::set<string>::iterator it = parent.begin(); it != parent.end(); ++it) {
    checkChild(*it, relatives);
  }
  printParent(parent, relatives);
}

void checkChild(string parent, vector<Relatives>& vecto) {
  for (std::vector<Relatives>::iterator it = vecto.begin(); it != vecto.end(); ++it) {
    if (parent == it->getParent()) {
      it->addParent(parent);
      for (std::vector<Relatives>::iterator it1 = vecto.begin(); it1 != vecto.end(); ++it1) {
        if (it->getChild() == it1->getParent()) {
          for (set<string>::const_iterator p = it->getParents().begin(); p != it->getParents().end(); ++p) {
            it1->addParent(*p);
          }
        }
      }

      contains(it->getParents(), it->getChild());
      checkChild(it->getChild(), vecto);
    }
  }
}

void contains(set<string> parents, string child) {
  for (set<string>::const_iterator p = parents.begin(); p != parents.end(); ++p) {
    if (*p == child) {
      throw "cylcic!";
    }
  }
}

void printParent(set<string>& parent, vector<Relatives>& relatives) {
  for (std::set<string>::iterator it = parent.begin(); it != parent.end(); ++it) {
    cout << *it << endl;
    printChild(*it, relatives, "");
  }
}

void printChild(string parent, vector<Relatives>& vecto, string shift) {
  shift = shift + "     ";
  for (std::vector<Relatives>::iterator it = vecto.begin(); it != vecto.end(); ++it) {
    if (parent == it->getParent()) {
      cout << shift << it->getChild() << endl;
      printChild(it->getChild(), vecto, shift);
    }
  }
}
*/