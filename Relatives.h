#pragma once
#include <string>
#include <set>
using namespace std;
class Relatives {
 public:
  Relatives(string child, string parent);

  ~Relatives();

  string getChild();
  string getParent();
  void addParent(string parent);
  set<string>& getParents();

 private:
  string child_;
  string parent_;
  set<string> parents_;
};