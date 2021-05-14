Palette Pusher

## Description

This program asks the user for the amount of color codes they would like in a file of their naming. It will then create color codes in either RGB or Hexadecimal format depending on the users preference.

### v0.2 Updates

This program now makes sure that the colors displayed all have a contrast ratio of 4.5. This means that the colors outputted will likley retain their contast when viewed by someone who is color blind. 

### v1.0 Updates

Now added a class for ease of modification and also a quicker user interface. 

## Developer

Shane Hungerford

## Example

To run the program, give the following commands:

```
g++ --std=c++11 *.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
How many colors would you like in yor palette? (+2)
6
What is the name of the file you would like your palette saved to?
exampleFile
Would you like your palette in RGB or hexadecimal?

Enter hex, Hex, or HEX for a hexadecimal number.
Enter rgb or RGB.
Hex
Completed generation of exampleFile color palette in Hex format.

```

## C++ Guide

### Variables and Data Types
ofstream writingFile; //A variable that tells the system that the program will be writing to a file, as well as naming it 'writingFile'.
vector <int> colorPalette; //This is the vector of decimal values that represent color values, they are only outputted to this array if they meet certian contrast levels. 
string choice; // Stores the users choice of either hex or rgb
long & bianaryNum // This is passed throught to the findLuminosity function. 

### Console Input and Output

 do{
  cout << "How many colors would you like in yor palette? (+2)" << endl;
  cin >> colorNum;
  } while(colorNum<2);
  
 For example, this code above asks the user for the amount of color paletts they would like, and only accepts that number if it is equal or greater that two. 

### Decisions

do{
  cout << "Enter hex, Hex, or HEX for a hexadecimal number.\n Enter rgb or RGB.\n";
  cin >> choice;

  if(choice=="RGB" || choice=="rgb"){   //This line states that if the users choice is RGB or rgb then it will output rgb colors. 
      outputRGB(colorPalette,  writingFile);
    }
    
    else if(choice=="Hex" || choice=="hex" || choice=="HEX"){   //This line states that if the users choice is hex, HEX, or Hex, then it will output hexadecimal numbers. 
      outputHexadecimal(colorPalette, writingFile);
    }
    
  } while(choice!="RGB" && choice!="rgb" &&  choice!="Hex" && choice!="HEX" && choice!="hex"); //This while statement says that if the choice is not any of the ones the program is looking for then it will rerun the code. 
  
  The code above will not allow the user to enter in anything except for one of the five codes that will pass the while statement. 

### Iteration

for(int i=0; i<colorPalette.size(); i++){ //iterates as long as it is smaller than the size of the vector
    bianaryString=""; //Sets all the values to nothing or zero.
    Rstring="";
    Gstring="";
    Bstring="";
    RlRGB=0;
    GlRGB=0;
    BlRGB=0;

    cout << "color pallete at:" << i << " " << colorPalette.at(i) << endl;
    bianaryNum=colorPalette.at(i);
    bianaryString=toBinary(bianaryNum);     //Converts the decimal number (bianaryNum) to a string so the program can use the push_back function. 

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

Here is an example of my code which first iterates through the array and converts the vector elements to strings. It then iterates through those strings and pulls out three sets of 8bits of information. These are what will be used to output true color codes. 

### File Input and Output
In this program there is no reading in from files, but the program does write to one. It opens and closes the writing file within main. The only output to file happens when either function outputRGB or outputHex is called. 
This is an example from outputRGB:

for (int r=0; r<8; r++){ //seperates out first 8 bits
    Rstring.push_back(bianaryString[r]); //Pushes those 8 bits to the string
  }
  RlRGB=strtol(Rstring.c_str(), &pEnd, 2); //Here the string gets converted using strtol which returns a long integer. 
  outfile << "R: " <<  RlRGB << " ";

### Arrays/Vectors
In my function there is only one vector I use and that is to store the color codes in decimal format. There is only one array I use and that is to store the hexadecimal value i produce from my hexadecimal output function. 
Here is an example of iterating through a vector:

for (int a=0; a<colorPalette.size(); a++){...}

### Functions


double findLuminosity(long&);   //Finds the luminosity of a color
long createBianaryNum(); //Creates a random, decimal form that will be used to find color codes. 
string toBinary(long); //Converts a long integer to a string
int convertBinaryToDecimal(int); //Converts a binary number to decimal, this is uesed in createBinaryNumber
string convertBianaryToHex(int); //Converts a binary input to a hexadecimal one
void outputRGB(vector <int> , ofstream&); //Outputs the color code in RGB format
void outputHexadecimal(vector <int> , ofstream&); //Outputs the color code in Hexadecimal format


### Classes

This program now utilizes a Palette class, which contains new functions such as outputToColorPalette(vector <int> &); which sends the palette to a private vector which is used by other meber functions. 
