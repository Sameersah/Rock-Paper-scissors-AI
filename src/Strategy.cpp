//
// Created by Sameer on 10/03/25.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>

using namespace std;

class Strategy {
public:
    virtual Choice getChoice(const vector<Choice>& history) = 0;
    virtual ~Strategy() {}
};