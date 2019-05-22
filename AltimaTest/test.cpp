#include <gtest/gtest.h>

#include "pch.h"

#include "../Altima.cpp"
#include "../Relatives.cpp"

class AltimaTest : public testing::Test {
 public: 
 AltimaTest() {
    altima = new Altima();
  }
 
  ~AltimaTest() {
    delete altima;
  }

   Altima* altima;
};

TEST_F(AltimaTest, CheckChildParent) {
  Relatives rel("Marko", "Nikola");
  EXPECT_EQ(rel.getChild(), "Marko");
  EXPECT_EQ(rel.getParent(), "Nikola");
}

TEST_F(AltimaTest, CorrectOutput) {
  vector<Relatives> relatives_;
  Relatives rel1("Marko", "Ivan");
  Relatives rel2("Petar", "Marko");
  Relatives rel3("Luka", "Ivan");
  relatives_.push_back(rel1);
  relatives_.push_back(rel2);
  relatives_.push_back(rel3);
  
  /* This part proves, that Altima::run() won't call abort(), and we can conclude there are no cyclic relationships */
  EXPECT_TRUE(altima->run(relatives_));

  set<string> parents;
  parents.insert("Ivan");
  parents.insert("Marko");

  /* This part proves that "parent" of Petar are Marko and Ivan*/
  EXPECT_EQ(relatives_[1].getParents(), parents);
}
TEST_F(AltimaTest, CyclicRelatives) {
  vector<Relatives> relatives_;
  Relatives rel1("Marko", "Ivan");
  Relatives rel2("Petar", "Marko");
  Relatives rel3("Ivan", "Petar"); 
  relatives_.push_back(rel1);
  relatives_.push_back(rel2);
  relatives_.push_back(rel3);
  
  /* This part proves, that Altima::run() will call abort(), and we can conclude there are cyclic relationships */
  EXPECT_DEATH(altima->run(relatives_), ".*");
}

