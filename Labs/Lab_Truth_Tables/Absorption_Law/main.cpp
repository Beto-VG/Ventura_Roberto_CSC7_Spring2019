/* 
 * File:   main.cpp
 * Author: Roberto Ventura
 * Created on February 26, 2016
 * Purpose:  Absorption Laws
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
    cout<<"X  Y  X&&Y  X||Y  X||(X&&Y)  X&&(X||Y)  X  "<<endl;
    
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
    cout<<(x?'T':'F')<<"  ";
    cout<<(y?'T':'F')<<"    ";
    cout<<((x&&y)?'T':'F')<<"     ";
    cout<<((x||y)?'T':'F')<<"      ";
    cout<<(x||(x&&y)?'T':'F')<<"           ";
    cout<<(x&&(x||y)?'T':'F')<<"      ";
    cout<<(x?'T':'F');
    cout<<endl;
}