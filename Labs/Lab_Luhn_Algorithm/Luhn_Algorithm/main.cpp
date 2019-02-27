/*
 * File:   main.cpp
 * Author: Roberto Ventura
 * Purpose: Using Luhn Algorithm
 * Created on February 26, 2019, 10:09 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

//Function Prototypes 
void MakeCard(int []);
void Test(int []);
void Print(int []);

int main(int argc, char** argv) {
    //Declare Variables 
    srand(static_cast<unsigned int>(time(0)));
    
    int card[10];   //Array to hold 

    MakeCard(card);
    Test(card);
    
    return 0;
}

void Test(int card[]){
    //Declare Variables
    int steps[10];       // Array to hold each digit times 1 or 2 if needed, must be int because it will be added later
    int sum=0;      // Sum of all digits in the card (after digits processed)
    int x;     // Check Digit multiplying sum by 9 %10 
    
    //Rightmost digit and every second digit * 2
    for(int i=9;i>=0;i--)
    {
        if(i%2!=0)
        {
            steps[i]=card[i]*2;
        }
        else
        {
            steps[i]=card[i]*1;
        }
    }
    
    //Print *2 Step
    Print(steps);
    cout<<"x\n";
    cout<<endl;
    
    for(int i=0;i<10;i++)
    {
        if(steps[i]>9)
        {
            steps[i]=steps[i]-9;
        }
    }
    
    for(int i=0;i<10;i++)
    {
        sum+=steps[i];
    }
    
    //Print Sum/2 Digit Numbers to 1 Digit Step
    Print(steps);
    cout<<"="<<sum<<endl;
    cout<<endl;
    
    //Find X and use formula (sum*9)%10
    x = (sum *9)%10;
    
    cout<<"("<<sum<<" *9)%10 = "<<x<<endl;
    if(x==0)
    {
        cout<<"VALID"<<endl;
    }
    else
    {
        cout<<"NOT VALID"<<endl;
    }
}


void MakeCard(int card[]){
    for(int i=0;i<10;i++)
    {
        card[i]=rand()%9+1;
    }
    Print(card);
    cout<<"x\n";
    cout<<endl;
}

void Print(int card[])
{
    for(int i=0;i<10;i++)
    {
        cout<<card[i]<<" ";
    }
}