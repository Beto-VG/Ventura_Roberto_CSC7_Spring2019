/*
 * Author: Roberto Ventura
 * Date: 4/17/19
 * Purpose: Create simulation of all possible outcomes in Mastermind
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Function Prototypes
void prntArr(char[], int);
void incGuess(char []);
int numRight(char [], char [], int);
int nWrSpot(char [], char [], int);

int main(int argc, char** argv) {
    //Set Random Number Seed
    srand(static_cast<unsigned int> (time(0)));

    //Declare Variables
    const int x = 10000;
    const int SIZE = 4;
    char ans[SIZE];
    char guess[SIZE];
    char copyAns[SIZE];
    char copyGss[SIZE];
    int nRight;
    int wrongSp;
    int sum;
    ofstream file;
    char choice;
    
    cout<<"Do you want to enter the code?(Y for Yes) ";
    cin>>choice;
    
    if(choice=='Y' || choice=='y')
    {
        for(int i=0;i<4;i++)
        {
            cout<<"Enter Code Spot "<<i+1<<" (0-9): ";
            cin>>ans[i];
            
            while(ans[i]<48 || ans[i]>57)
            {
                cout<<"Enter Code Spot "<<i+1<<" Again(0-9): ";
                cin>>ans[i];
            }
        }
    }
    else
    {
        //Set Answer To Random Numbers, 0000-9999
        for (int i = 0; i < 4; i++) {
            ans[i] = rand() % 10 + 48;
        }
    }
            
    //Start Guess at 0000
    guess[0] = 48;
    guess[1] = 48;
    guess[2] = 48;
    guess[3] = 48;

    file.open("results.txt", ios::out | ios::trunc);

    //Output Results and Increment Guess by 1, x Amount of Times, Also to File
    cout << "Code Guess Right Wrong Spot Sum\n";
    file << "Code Guess Right Wrong Spot Sum\n"; 
    for (int i = 0; i < x; i++) {
        //Make A Copy of Answer Array to Edit as Right Spot,Wrong Spots Found
        for(int j=0;j<SIZE;j++)
        {
            copyAns[j]=ans[j];
            copyGss[j]=guess[j];
        }

        //Set Number Right, Wrong Spot, and sum
        nRight = numRight(copyAns, copyGss, SIZE);
        wrongSp = nWrSpot(copyAns, copyGss, SIZE);
        sum = nRight + wrongSp;

        //Print to Console
        prntArr(ans, SIZE);
        cout << " ";
        prntArr(guess, SIZE);
        cout << "    " <<nRight<<"        "<<wrongSp<<"      "<<sum<<endl;

        //Write to File, Console Cuts Results
        file << ans;
        file << " ";
        file << guess[0]<<guess[1]<<guess[2]<<guess[3];
        file << "    " <<nRight<<"        "<<wrongSp<<"      "<<sum<<endl;
        
        //Increment By 1
        incGuess(guess);
    }

    file.close();
    return 0;
}

//Takes an Array and Size 
//Prints Array's Contents

void prntArr(char a[], int b) 
{
    for (int i = 0; i < b; i++) 
    {
        cout << a[i];
    }
}

//Takes Array of Char and Increments by 1

void incGuess(char a[]) 
{
    //Increment by 1
    a[3] += 1;

    //If Last Character is Past 9 Reset to 0 and Add One to Char Before
    if (a[3] == 58) 
    {
        a[3] = 48;
        a[2] += 1;
    }

    //If Third Character is Past 9 Reset to 0 and Add One to Char Before
    if (a[2] == 58) 
    {
        a[2] = 48;
        a[1] += 1;
    }

    //If Second Character is Past 9 Reset to 0 and Add One to Char Before
    if (a[1] == 58) 
    {
        a[1] = 48;
        a[0] += 1;
    }
}

//Takes In Two Arrays and Size
//Compares if Contents Match
//Alters Array Contents if a Match is Found to not Count Matched Spot 
//in Other Function, so I Pass in a Copy of Answer and Guess Array 
//Returns how Many Characters Were in the Right Spot  
int numRight(char a[], char b[], int c) 
{
    int n = 0;

    for (int i = 0; i < c; i++) 
    {
        if (b[i] == a[i]) 
        {
            a[i] = 'X'; // Remove From Answer Copy so it's Only Picked Once
            b[i] = 'Y'; // Remove From Guess Copy so it's Only Picked Once
            n++;        // Increment Number Right
        }
    }

    return n;
}

//Takes In Two Arrays and Size
//Compares if Contents Match in Different Spots
//Copied Answer Array is Meant to be Passed in to Avoid Duplicates
//Returns how Many Characters are in the Wrong Spot  
int nWrSpot(char a[], char b[], int c) 
{
    int n = 0;

    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            if (b[i] == a[j]) 
            {
                n++;        // Increment Number in Wrong Spot
                a[j] = 'X'; // Remove From Answer Copy so it's Only Picked Once
                b[i] = 'Y'; // Remove From Guess Copy so it's Only Picked Once
            }
        }
    }
    return n;
}