/********************************************************
 Author: Ashmit Shankar Mukherjee
 Date Created: October 10, 2023
 Description:
 This program calculates the linear interpolation function of the freezing temperature of seawater by
 using data points uploaded by the user. It first computes the model parameters and then inputs them
 into the interpolation function model equation. The program also gives the user an option to calculate
 the freezing temperature of the seawater based on an input of salinity. In addition to these options
 the program also gives the user an option to exit the program anytime they want.
 ***********************************************************/

#include <iostream> //Library required for console input/output
#include <fstream> //Library required for file streams

using namespace std;

int main ()
{
    //declaring variables
    double x(0),y(0),sumX(0),sumY(0),sumXY(0),sumX2(0),m,b,s,t;
    int n(0), choice;
    string filename;
    
    
    while(true) //Looping the program
    {
        do { //printing menu and looping in case of invalid input
            cout<<"1. Calculate Linear Interpolation Function\n"
                <<"2. Find freezing point\n"
                <<"3. Exit\n"
                <<"Enter choice: ";
           
            
            cin>>choice;
            if (choice != 1 && choice != 2 && choice != 3) //validates choice
                cout << "Invalid choice! Please try again\n";
        }
        while(choice!=1&&choice!=2&&choice!=3);
        switch(choice) //switch statement for the 3 choices
        {
            case 1: //case 1- calculating just the linear interpolation function
            {
                cout<<"Enter file name- "; //asks user for file name input
                cin>>filename; //reads file name into variables
                ifstream infile(filename,ios::in); //creating input filestream for the file
                if(infile.fail()) //error message is shown in-case filestream opening is failed
                {
                    cout<<"Error opening file. ";
                    exit(-1);}
                while(!infile.eof()) //loop for reading the values of the data file to x and y then finding out the required measures like xy,x^2
                {
                    infile >> x >> y; //reading values from the file and assigning them to x and y
                    if(infile.eof())break; //breaks loop when reaching end of file
                    sumX += x; //to find summation of x
                    sumY += y; //to find summation of y
                    sumXY += x*y; //to find summation of xy
                    sumX2 += x*x; //to find summation of x^2
                    n++; //increment n
                    
                }
                
                m = (sumX * sumY - n*sumXY)/(sumX*sumX - n*sumX2); //finds the value of m from the given formula
                b = (sumX * sumXY - sumX2 * sumY)/(sumX * sumX - n * sumX2); //finds the value of b from the given formula
                cout<<"The linear interpolation function is:\n" <<"Temperature=" <<m <<" * Salinity + " <<b <<endl; //prints the linear interpolation function with the calculated model parameters
                infile.close(); //closes the file
            }
                break;
                
            case 2: //Case 2- calculating linear interpolation function from the provided data points and then calculating freezing point for any salinity input
            {cout<<"Enter file name: "; //asks user for file name input
                cin>>filename; //reads file name into variables
                ifstream infile(filename,ios::in); //creating input filestream for the file
                if(infile.fail()) //error message is shown in-case filestream opening is failed
                {
                    cout<<"Error opening file ";
                    exit(-1);}
                do {cout<<"Enter salinity in parts per thousand: ";//asks user to input value of salinity for which freezing point should be calculated
                    cin>>s;//reads the value to a variable
                    if(s<0)//program asks user to input a valid number in case the value is negative, since salinity cannot be less than 0,
                        cout<<"Enter a valid input\n"; }
                while(s<0);
                while(!infile.eof()) //loop for reading the values of the data file to x and y then finding out the required measures like summation of xy,x^2
                {
                    infile >> x >> y; //reading values from the file and assigning them to x and y
                    if(infile.eof())break; //breaks loop when reaching end of file
                    sumX += x; //to find summation of x
                    sumY += y; //to find summation of y
                    sumXY += x*y; //to find summation of xy
                    sumX2 += x*x; //to find summation of x^2
                    n++; //increment n
                    
                }
                
                m = (sumX * sumY - n*sumXY)/(sumX*sumX - n*sumX2); //finds the value of m from the given formula
                b = (sumX * sumXY - sumX2 * sumY)/(sumX * sumX - n * sumX2); //finds the value of b from the given formula
                t=m*s+b; //inputs the calculated model parameters and the input salinity to the interpolation function to find out freezing point
                cout<<"The freezing point is: "<<t<<"°F"<<endl;//displays the freezing point calculated previously
                infile.close();//closes the file
            }
                break;
            case 3: exit(0); //case 3- exits the program if 3 is entered
                break;
                
        }
        
        
    }
    
    return 0;
}

/************************************END****************************************/
