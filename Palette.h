#ifndef PALETTE_H
#define PALETTE_H

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Palette {
  private:
    int colorNum;
    int inputNum;
    void colorProblemSolving(int &, int &);
    long createBianaryNum();
    double findLuminosity(long&);
    vector <int> colorPalette; //colorPalette
    void outputRGB(vector <int> , ofstream&);
    void outputHexadecimal(vector <int> , ofstream&);
  
  public:
    void inputColorNum(int&);
    void inputChoice(string &, ofstream&);
    string toBinary(long);
    void colorCalculation();
    void output();
    void outputToColorPalette(vector <int> &);

};

#endif
