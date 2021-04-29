/*
 * main.cpp
 *
 * COSC 051 Fall 2018
 * Project #1 (Code)
 *
 * Due on: OCT 3, 2018
 * Author: byy2
 *
 *
 * In accordance with the class policies and Georgetown's
 * Honor Code, I certify that, with the exception of the
 * class resources and those items noted below, I have neither
 * given nor received any assistance on this project.
 *
 * References not otherwise commented within the program source code.
 * Note that you should not mention any help from the TAs, the professor,
 * or any code taken from the class textbooks.
 */


#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>
using namespace std; 

//constants
    const double MARBLE_PRICE = 92.99;
    const double GRANITE_PRICE = 78.99;
    const double QUARTZ_PRICE = 56.99;
    const double EDGE_FINISHING_RATE = 4.99;
    const double WASTAGE_PERCENT = 0.26;
    const double MAX_LENGTH = 25.0;
    const double MIN_LENGTH = 5.0;
    const double MAX_DEPTH = 25.0;
    const double MIN_DEPTH = 5.0;
    const int MIN_EDGES_FINISHED = 0;
    const int MAX_EDGES_FINISHED = 2;

    
int main() //START function main
{   
    //variables
    string stoneName = " ";
    char stoneType = ' ';
    double stonePriceRate = 0.0;
    double length = 0.0;
    double depth = 0.0;
    double height = 0.0;
    int numLengthEdgesFinished = 0;
    int numDepthEdgesFinished = 0;
    double totalFinishingLength = 0.0;
    double counterArea = 0.0;
    double totalMaterialSqFt = 0.0;
    double totalMaterialCost = 0.0;
    double edgeFinishingCost = 0.0;
    double totalCost = 0.0;
    double minHeight = 0.0;
    double maxHeight = 0.0;
    
    //START PROGRAM
    
    //introduce stone type options
    cout << "Hi, I’m Claude! Welcome to my boutique where I design high-end custom counters. \n";
    cout << "There are three options for stone type: "<<endl;
    cout << "Granite - $" << GRANITE_PRICE <<"/sq ft" << endl;
    cout << "Marble  - $" << MARBLE_PRICE << "/sq ft" << endl;
    cout << "Quartz  - $" << QUARTZ_PRICE << "/sq ft" << endl;
    
    //ask user which kind of stone they want
    cout << "Please type which kind of stone you would like ";
    cout << "(m-marble, g-granite, q-quartz): ";
    cin >> stoneType;
    cin.ignore(20,'\n'); //only read in first character and ignore the rest
    cout << endl;
    
    //if stone is Granite
    if(toupper(stoneType) == 'G')
    {
        stoneName = "Granite";
        stonePriceRate = GRANITE_PRICE;
    }
    
    //if stone is Marble
     if(toupper(stoneType) == 'M')
    {
         stoneName = "Marble";
         stonePriceRate = MARBLE_PRICE;
    }
   
    //if stone is Quartz
    if(toupper(stoneType) == 'Q')
    {
        stoneName = "Quartz";
        stonePriceRate = QUARTZ_PRICE;
    }
    
    if ((toupper(stoneType) != 'G') && (toupper(stoneType) != 'M') && (toupper(stoneType) != 'Q'))
    {
        cout << "That is not a possible stone type choice. Exiting program." << endl;
        return 1;
    }
    
    //if stoneType is valid, begin rest of calculations
    
    //choose counter top length and depth:
    cout << "Now choose the counter top length and depth. " << endl;
    cout << "Please keep in mind that the length must be greater than or equal to the depth.";
    cout << endl;
    
    
    //ask for depth
    cout << "What is your desired counter top depth? ";
    cout << "(" << MIN_DEPTH <<"ft - " << MAX_DEPTH << "ft): ";
    cin >> depth;
    cout << endl;
    
    
    //test depth entry validity
    if((depth < MIN_DEPTH) || (depth > MAX_DEPTH))
    {
        cout << "Invalid. Depth entry is out of range. Exiting program." << endl; 
        return 1;
    }
    
    
    //ask for length	
    cout << "What is your desired counter top length? ";
    cout << "(" << depth <<"ft - " << MAX_LENGTH << "ft): ";
    cin >> length;
    cout << endl;
    
    //test length validity
    if((length < depth) || (length > MAX_LENGTH))
    {
        cout << "Invalid. Length entry is out of range. Exiting program." << endl; 
        return 1;  
    }

    
    //range for height
    minHeight = 0.58*depth;
    maxHeight = 0.8*depth;
    
    //ask for height
    cout << "What is your desired counter top height? ";
    cout << "(" << fixed << setprecision(2) << minHeight <<"ft - ";
    cout << fixed << setprecision(2) << maxHeight << "ft): ";
    cin >> height;
    cout << endl;

    //test height entry validity
    if((height < minHeight) || (height > maxHeight))
    {
        cout << "Invalid. Height entry is out of range. Exiting program. " << endl; 
        return 1;
    }
    
    //tell about finishing edges
    cout << "Exposed edges can be finished by smoothing and polishing for $";
    cout << EDGE_FINISHING_RATE << "/ft." << endl; 
    
    //ask for number of finished length edges
    cout << "How many length edges would you like to have finished ";
    cout << "(" << MIN_EDGES_FINISHED << " - " << MAX_EDGES_FINISHED << ")? ";
    cin >> numLengthEdgesFinished;
    cout << endl;
    
    //test for validity of number of finished length edges
    if(numLengthEdgesFinished < MIN_EDGES_FINISHED || numLengthEdgesFinished > MAX_EDGES_FINISHED)
    {
        cout << "The number of length edges you want finished is out of our range. ";
        cout << "Exiting program." << endl; 
        return 1;   
    }
    
    //ask for number of finished depth edges
    cout << "How many depth edges would you like to have finished ";
    cout << "(" << MIN_EDGES_FINISHED << " - " << MAX_EDGES_FINISHED << ")? ";
    cin >> numDepthEdgesFinished;
    cout << endl;

    //test for validity of number of finished depth edges
    if(numDepthEdgesFinished < MIN_EDGES_FINISHED || numDepthEdgesFinished > MAX_EDGES_FINISHED)
    {
        cout << "The number of depth edges you want finished is out of our range. ";
        cout << "Exiting program." << endl; 
        return 1;
    }

    //if all values are valid, these calculations will execute
    counterArea = length * height;
    totalMaterialSqFt = ceil(counterArea * (1 + WASTAGE_PERCENT));
    totalMaterialCost = totalMaterialSqFt * stonePriceRate;
    //round totalMaterialCost to nearest whole number
    totalFinishingLength = numLengthEdgesFinished * length + numDepthEdgesFinished * depth;
    edgeFinishingCost = totalFinishingLength * EDGE_FINISHING_RATE;
    totalCost = totalMaterialCost + edgeFinishingCost;


    //program output
    
    cout << "             Dimensions            " << endl;
    cout << setw(7) << length << " feet - counter top length." << endl;
    cout << setw(7) << depth << " feet - counter top depth." << endl;
    cout << setw(7) << height << " feet - counter top height." << endl;
    cout << setw(7) << totalMaterialSqFt;
    cout << " square feet - " << stoneName << " required to begin fabrication." << endl;
    cout << endl;
   
    
    cout << "              Costs                " << endl;
    cout << setw(10) << totalMaterialCost << " dollars - cost for " << stoneName << endl;
    cout << setw(10) << edgeFinishingCost << " dollars - cost for edge finishing" << endl;
    
    cout << "------------------------------------------------------" << endl;
    cout << setw(10) << totalCost << " dollars - total cost" << endl;
    cout << endl;
    
    cout << "Thank you for using Claude's Custom Counters, Inc. Calculator." << endl;
    
    
    return 0;
} //END function main