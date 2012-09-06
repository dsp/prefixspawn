#ifndef _PREFIXSPAN_H_
#define _PREFIXSPAN_H_

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <strstream>

#include <stdlib.h>
#include <string.h>

using namespace std;

typedef pair<unsigned int, vector<unsigned int> > Transaction; //<id <itemsets> >

struct Pairdata {
  vector<Transaction> database;
  vector<unsigned int> indeces;
  void clear() {
    database.clear();
    indeces.clear();
  }
};

class Prefixspan {
  unsigned int min_sup;
  unsigned int max_pat;
  unsigned int max_sup;
  vector<unsigned int> pattern;

public:
  Prefixspan(unsigned int _min_sup, unsigned int _max_pat, unsigned int _max_sup) : min_sup(_min_sup), max_pat(_max_pat), max_sup(_max_sup){};
  void read(const string &_filename, Pairdata &pairdata);
  void print_pattern(Pairdata &projected);
  void run(const string &_filename);
  void project(Pairdata &projected);
};

#endif // _PREFIXSPAN_H
