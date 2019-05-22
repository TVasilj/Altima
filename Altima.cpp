#include <iostream>
#include "Altima.h"

Altima::Altima() {

}

Altima::~Altima() {

}

bool Altima::run(vector<Relatives>& relatives) {
  set<string> parent_;

  try {
    parent_ = getParentOnly(relatives);
    print(parent_, relatives);
  }
  catch (const char* msg) {
    cout << msg << endl;
    abort();
  }
  return true;
}

set<string> Altima::getParentOnly(vector<Relatives>& vect) {
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
    throw "cyclic relationships!";
  }
  return parent;
}

void Altima::print(set<string>& parent, vector<Relatives>& relatives) {
  for (std::set<string>::iterator it = parent.begin(); it != parent.end(); ++it) {
    checkChild(*it, relatives);
  }
  printParent(parent, relatives);
}

void Altima::checkChild(string parent, vector<Relatives>& vecto) {
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

void Altima::contains(set<string> parents, string child) {
  for (set<string>::const_iterator p = parents.begin(); p != parents.end(); ++p) {
    if (*p == child) {
      throw "cylcic!";
    }
  }
}

void Altima::printParent(set<string>& parent, vector<Relatives>& relatives) {
  for (std::set<string>::iterator it = parent.begin(); it != parent.end(); ++it) {
    cout << *it << endl;
    printChild(*it, relatives, "");
  }
}

void Altima::printChild(string parent, vector<Relatives>& vecto, string shift) {
  shift = shift + "     ";
  for (std::vector<Relatives>::iterator it = vecto.begin(); it != vecto.end(); ++it) {
    if (parent == it->getParent()) {
      cout << shift << it->getChild() << endl;
      printChild(it->getChild(), vecto, shift);
    }
  }
}