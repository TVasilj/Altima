#include <string.h>
#include "Relatives.h"

using namespace std;
Relatives::Relatives(string child, string parent) : child_(child), parent_(parent) {
}

Relatives::~Relatives() {

}

string Relatives::getChild() {
  return child_;
}

string Relatives::getParent() {
  return parent_;
}

void Relatives::addParent(string parent) {
  parents_.insert(parent);
}

set<string>& Relatives::getParents() {
  return parents_;
}