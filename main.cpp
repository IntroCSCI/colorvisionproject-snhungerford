//Author: Shane Hungerford
#include <iostream>
#include <fstream>
#include <string>
#include "Palette.h"

using namespace std;

int main() {
  Palette palette;
  srand (time(NULL));
  int paletteNum;
  ofstream writingFile;
  string fileName;
  string choice;

  do{
  cout << "How many colors would you like in yor palette? (+2)" << endl;
  cin >> paletteNum;
  } while(paletteNum<2);

  palette.inputColorNum(paletteNum);
  palette.colorCalculation();

  cout << "What is the name of the file you would like your palette saved to?" << endl;
  cin >> fileName;

  writingFile.open(fileName, ios::out | ios::trunc );
  
  cout << "Would you like your palette in RGB or hexadecimal?" << endl << endl;
  do{
  cout << "Enter hex, Hex, or HEX for a hexadecimal number.\nEnter rgb or RGB.\n";
  cin >> choice;
  if(choice=="RGB" || choice=="rgb" ||  choice=="Hex" || choice=="HEX" || choice=="hex"){
    palette.inputChoice(choice, writingFile);
  }

  }while(choice!="RGB" && choice!="rgb" &&  choice!="Hex" && choice!="HEX" && choice!="hex");

  cout << "Completed generation of " << fileName << " color palette in " << choice << " format.\n";

  writingFile.close();
}
