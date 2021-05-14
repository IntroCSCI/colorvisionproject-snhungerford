#include "Palette.h"
#include <iostream>
#include<fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;


void Palette::inputColorNum(int & Num ){
  inputNum = Num;
  if ( inputNum % 2 == 0){
    colorNum=Num;
  }
  else{
    colorNum=Num+1;
  }

}

void Palette::colorCalculation(){
  int evenColorNum = colorNum;
  colorProblemSolving(evenColorNum, inputNum);
}

void Palette::colorProblemSolving(int & evenColorNum, int  &inputNum){
  long binaryNum1;
  long binaryNum2;
  double luminosity1;
  double luminosity2;
  vector <int> colors;
  
  for (int i=0; i<(evenColorNum/2); i++){
    do{
      binaryNum1=createBianaryNum();
      luminosity1=findLuminosity(binaryNum1);
      binaryNum2=createBianaryNum();
      luminosity2=findLuminosity(binaryNum2);
    }while(luminosity1 == 4.5 * luminosity2 + 0.175);

    colors.push_back(binaryNum1);
    colors.push_back(binaryNum2);
  }
  if(evenColorNum>inputNum){
    colors.pop_back();
  }
outputToColorPalette(colors);  
}

double Palette::findLuminosity(long & bianaryNum){ //accepts decimal form of 8bit number
  long RlRGB;
  long GlRGB;
  long BlRGB;
  double RsRGB;
  double GsRGB;
  double BsRGB;
  string Rstring;
  string Gstring;
  string Bstring;
  double red;
  double green;
  double blue;
  string bianaryString;
  double luminosity;
  char * pEnd;

  bianaryString=toBinary(bianaryNum);

  for (int r=0; r<8; r++){ //seperates out first 8 bits
    Rstring.push_back(bianaryString[r]);
  }
  RlRGB=strtol(Rstring.c_str(), &pEnd, 2);

  for (int g=8; g<16; g++){// seperates out second 8 bits
    Gstring.push_back(bianaryString[g]);
  }
  GlRGB=strtol(Gstring.c_str(), &pEnd, 2);
 

  for (int b=16; b<24; b++){ // seperates out third 8 bits
    Bstring.push_back(bianaryString[b]);
  }
  BlRGB=strtol(Bstring.c_str(), &pEnd, 2);
  
  RsRGB= RlRGB/255.0;
  GsRGB = GsRGB/255.0;
  BsRGB = BsRGB/255.0;

  if (RsRGB<=0.03928){
    red=RsRGB/12.92;
  }
  else{
    red = pow(((RsRGB + 0.055) / 1.055), 2.4);
  }
  
  if (GsRGB<=0.03928){
    green = GsRGB/12.92;
  }
  else{
    green = pow(((GsRGB + 0.055) / 1.055), 2.4);
  }
  
  if (BsRGB<=0.03928){
    blue = BsRGB / 12.92;
  }
  else{
    blue = pow(((BsRGB + 0.055) / 1.055), 2.4);
  }
  
  luminosity = (0.2126*red) + (0.7152*blue) + (0.0722*blue);
  return luminosity; 
}

string Palette::toBinary(long n){
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

void Palette::inputChoice(string & choice, ofstream & writingFile){
  if(choice=="RGB" || choice=="rgb"){
      outputRGB(colorPalette,  writingFile);
    }
    
    else if(choice=="Hex" || choice=="hex" || choice=="HEX"){
      outputHexadecimal(colorPalette, writingFile);
    }
}

void Palette::outputRGB(vector <int> colorPalette, ofstream & outfile){


  long bianaryNum;
  string bianaryString;
  string Rstring;
  string Gstring;
  string Bstring;
  long RlRGB;
  long GlRGB;
  long BlRGB;
  char * pEnd;

  for(int i=0; i<colorPalette.size(); i++){
    bianaryString="";
    Rstring="";
    Gstring="";
    Bstring="";
    RlRGB=0;
    GlRGB=0;
    BlRGB=0;

    bianaryNum=colorPalette.at(i);
    bianaryString=toBinary(bianaryNum);

  for (int r=0; r<8; r++){ //seperates out first 8 bits
    Rstring.push_back(bianaryString[r]);
  }
  RlRGB=strtol(Rstring.c_str(), &pEnd, 2);
  outfile << "R: " <<  RlRGB << " ";

  for (int g=8; g<16; g++){// seperates out second 8 bits
    Gstring.push_back(bianaryString[g]);
  }
  GlRGB=strtol(Gstring.c_str(), &pEnd, 2);
  outfile << "G: " << GlRGB << " ";
 

  for (int b=16; b<24; b++){ // seperates out third 8 bits
    Bstring.push_back(bianaryString[b]);
  }
  BlRGB=strtol(Bstring.c_str(), &pEnd, 2);
  outfile << "B: " << BlRGB << " ";
 
    if(i!=colorPalette.size()-1){
    outfile << endl;
    }
  }
}

void Palette::outputHexadecimal(vector <int> colorPalette, ofstream& outfile){
  for (int a=0; a<colorPalette.size(); a++){
    
    // char array to store hexadecimal number
    char hexaDeciNum[100];
 
    // counter for hexadecimal number array
    int i = 0;
    while (colorPalette.at(a) != 0) {
        // temporary variable to store remainder
        int temp = 0;
 
        // storing remainder in temp variable.
        temp = colorPalette.at(a) % 16;
 
        // check if temp < 10
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
 
        colorPalette.at(a) = colorPalette.at(a) / 16;
    }
    outfile << "Hexadecimal Palette" << a+1 << ": ";
    for (int j = i - 1; j >= 0; j--){
        outfile << hexaDeciNum[j];
    }
    
    if(a!=colorPalette.size()-1){
    outfile << endl;
    }
  }

}

long Palette::createBianaryNum(){
  string bianaryString;
  int singleBianary;
  char bianaryChar;
  long bianaryNum;
  char * pEnd;

  
    for(int a=0; a<24; a++){
      singleBianary=rand()%2;
      bianaryChar=singleBianary + '0';
      
      bianaryString.push_back(bianaryChar);
      bianaryChar=' ';
      
    }
  
  bianaryNum=strtol(bianaryString.c_str(), &pEnd, 2);
  return bianaryNum; //returns a three 8-bit bianary number  in decimal form
}

void Palette::outputToColorPalette(vector <int> & colors){
  colorPalette=colors;
}
