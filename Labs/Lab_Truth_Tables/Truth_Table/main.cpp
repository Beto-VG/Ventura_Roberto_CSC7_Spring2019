/* 
 * File:   main.cpp
 * Author: Roberto Ventura
 * Created on February 24, 2016
 * Purpose:  Truth Table
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
void truthRow(bool,bool);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    bool valOne,valTwo;
    
    //Display the Heading
    cout<<"X Y !X !Y X&&Y X||Y X^Y X^Y^X X^Y^Y !(X&&Y) !X||!Y "<<
          " !(X||Y) !X&&!Y"<<endl;
    
    //First Row
    valOne=true;
    valTwo=true;
    truthRow(valOne,valTwo);
    
    //Second Row
    valOne=true;
    valTwo=false;
    truthRow(valOne,valTwo);

    
    //Third Row
    valOne=false;
    valTwo=true;
    truthRow(valOne,valTwo);

    
    //Fourth Row
    valOne=false;
    valTwo=false;
    truthRow(valOne,valTwo);
    
    
    //Exit
    return 0;
}

void truthRow(bool x,bool y)
{
    cout<<(x?'T':'F')<<" "
        <<(y?'T':'F')<<"  "
        <<(!x?'T':'F')<<"  "
        <<(!y?'T':'F')<<"   "
        <<(x&&y?'T':'F')<<"    "
        <<(x||y?'T':'F')<<"   "
        <<(x^y?'T':'F')<<"    "
        <<(x^y^x?'T':'F')<<"     "
        <<(x^y^y?'T':'F')<<"      "
        <<(!(x&&y)?'T':'F')<<"       "
        <<(!x||!y?'T':'F')<<"       "
        <<(!(x||y)?'T':'F')<<"       "
        <<(!x&&!y?'T':'F')<<endl;            
}
