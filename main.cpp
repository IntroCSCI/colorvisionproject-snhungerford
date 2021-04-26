//Author: Shane Hungerford
#include <iostream>
#include<fstream>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdlib>

using namespace std;

double findLuminosity(long&);
long createBianaryNum();
string toBinary(long);
int convertBinaryToDecimal(int);
string convertBianaryToHex(int);
void outputRGB(vector <int> , ofstream&);
void outputHexadecimal(vector <int> , ofstream&);

int main() {
  int colorNum;
  int evenColorNum;
  long bianaryNum1;
  long bianaryNum2;
  double luminosity1;
  double luminosity2;
  vector <int> colorPalette; //colorPalette is in bianary
  srand (time(NULL));
  string choice;
  ofstream writingFile;
  string fileName;

  do{
  cout << "How many colors would you like in yor palette? (+2)" << endl;
  cin >> colorNum;
  } while(colorNum<2);

  if ( colorNum % 2 == 0){
    evenColorNum=colorNum;
  }
  else{
    evenColorNum=colorNum+1;
  }

  for (int i=0; i<(evenColorNum/2); i++){
    do{
      bianaryNum1=createBianaryNum();
      luminosity1=findLuminosity(bianaryNum1);
      bianaryNum2=createBianaryNum();
      luminosity2=findLuminosity(bianaryNum2);
    }while(luminosity1 == 4.5 * luminosity2 + 0.175);

    colorPalette.push_back(bianaryNum1);
    colorPalette.push_back(bianaryNum2);    
  }
  
  
  if(evenColorNum>colorNum){
    colorPalette.pop_back();
  }
  
  cout << "What is the name of the file you would like your palette saved to?\n";
  cin >> fileName;

  writingFile.open(fileName, ios::out | ios::trunc );

  cout << "Would you like your palette in RGB or hexadecimal?" << endl;
  do{
  cout << "Enter hex, Hex, or HEX for a hexadecimal number.\n Enter rgb or RGB.\n";
  cin >> choice;

  if(choice=="RGB" || choice=="rgb"){
      outputRGB(colorPalette,  writingFile);
    }
    
    else if(choice=="Hex" || choice=="hex" || choice=="HEX"){
      outputHexadecimal(colorPalette, writingFile);
    }
    
  } while(choice!="RGB" && choice!="rgb" &&  choice!="Hex" && choice!="HEX" && choice!="hex");

  writingFile.close();
} //end of main

double findLuminosity(long & bianaryNum){ //accepts decimal form of 8bit number
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

long createBianaryNum(){
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

int convertBinaryToDecimal(int bianaryNum){
  int decimalNumber = 0;
  int i = 0;
  int remainder;
    while (bianaryNum!=0)
    {
        remainder = bianaryNum%10;
        bianaryNum /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}

string convertBianaryToHex(int binaryNum){
  int decimalNum;
  string returnString;
  decimalNum=convertBinaryToDecimal(binaryNum); 
  returnString=to_string(decimalNum);
  return returnString;
  
  
}

void outputRGB(vector <int> colorPalette, ofstream & outfile){
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

    cout << "color pallete at:" << i << " " << colorPalette.at(i) << endl;
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
 
  outfile << endl;
  }
}

void outputHexadecimal(vector <int> colorPalette, ofstream& outfile){
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
    outfile << "Hexadecimal Number" << a+1 << ": ";
    for (int j = i - 1; j >= 0; j--){
        outfile << hexaDeciNum[j];
    }
    outfile << endl;
  }

}


string toBinary(long n){
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}
