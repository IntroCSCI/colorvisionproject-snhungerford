//Author: Shane Hungerford
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() {

int paletteNum;
int red;
int blue;
int green;
string fileName;

ofstream outfile;

  cout << "How many colors would you like in your palette?\n";
  cin >> paletteNum;
  cout << "What is the name of the file you would like your palette saved to?\n";
  cin >> fileName;

  outfile.open(fileName, ios::out | ios::trunc );

for(int i = 1; i<(paletteNum+1); i++){
  outfile << "Color #" << i << ": ";
  
 outfile << "R";
  for(int b = 0; b < 3; b++){
    outfile << rand()%9;
  }
  outfile << " ";

  outfile << "G";
  for(int b = 0; b < 3; b++){
    outfile << rand()%9;
  }
  outfile << " ";

  outfile << "B";
  for(int b = 0; b < 3; b++){
    outfile << rand()%9;
  }
  outfile << " ";
  outfile << endl;

}
outfile << endl;
outfile.close();

return 0;
}
