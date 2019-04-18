/*
 * Author: Roberto Ventura
 * Date: 4/12/19 
 * Purpose: Mastermind Game
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char** argv) {
    srand(static_cast<unsigned int> (time(0)));

    int attempts = 10;
    int row[4];
    int hVals[4];

    //create the random numbers
    hVals[0] = rand()% 8+1;
    hVals[1] = rand()% 8+1;
    hVals[2] = rand()% 8+1;
    hVals[3] = rand()% 8+1;

    //get values to compare to the constant random values
    for (int i = 0; i < attempts; i++) 
    {
        cout<<"Attempts Left: "<<attempts-i<<endl;
        cout<<endl;
        
        for(int j=0;j<4;j++)
        {   
            cout<<"Enter Space "<<j+1<<" (1-8): ";
            cin>>row[j];
            while(row[j]<=0 || row[j]>8)
            {
                cout<<"Enter Space "<<j+1<<" Again! (1-8): ";
                cin>>row[j];
            }
        }
            
        cout<<endl;
        if (row[0] == hVals[0] && row[1] == hVals[1]
                && row[2] == hVals[2] && row[3] == hVals[3]) 
        {
            cout << "You win!" << endl;
            return 0;
        } 
        else 
        {
            if (row[0] == hVals[0]) {
                cout << "One Red"<<endl;
            } 
            else if (row[0] == hVals[1] || row[0] == hVals[2] ||
                    row[0] == hVals[3]) {
                cout << "One White"<<endl;
            }
            
            if (row[1] == hVals[1]) 
            {
                cout << "One Red"<<endl;
            } 
            else if (row[1] == hVals[0] || row[1] == hVals[2] ||
                    row[1] == hVals[3]) 
            {
                cout << "One White"<<endl;
            } 
            
            if (row[2] == hVals[2]) 
            {
                cout << "One Red"<<endl;
            } 

            else if (row[2] == hVals[0] || row[2] == hVals[1] ||
                    row[2] == hVals[3]) 
            {
                cout << "One White"<<endl;
            }
            
            if (row[3] == hVals[3]) 
            {
                cout << "One Red"<<endl;
            } 
            else if (row[3] == hVals[0] || row[3] == hVals[1] ||
                    row[3] == hVals[2]) 
            {
                cout << "One White"<<endl;
            }
            cout<<endl;
        }
    }
    
    cout<<"You Lost, Answer: ";
    for(int i=0;i<4;i++){
        cout<<hVals[i];
    }
    cout<<endl;
    
    return 0;
}

