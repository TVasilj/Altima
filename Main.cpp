#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>

#include "Altima.h"
#include "Relatives.h"
using namespace std;

vector<Relatives> readData();

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