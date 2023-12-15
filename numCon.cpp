//Program that converts decimal numbers to binary, hexadecimal, and BCD.
//Program does not use library functions for conversions
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

//Function to Convert Decimal Number to Binary Number
string decimalToBinaryNumber(int x){
    //Variable Declaration and Initialization to Empty String
    string binaryRep = "";
    //While Loop Cycles as Long as x is True
    while(x){
        //Convert Decimal Number to Binary By Dividing by 2.
        //Binary Only Has Options of 1 and 0 Use of a Ternary Operator
        //For Options
        binaryRep = ((x % 2) ? "1" : "0") + binaryRep;
        //Divide Number By 2 
        x = x / 2;
        //After 4th Digit Space is Required in Output Look via Assignment
        if (binaryRep.length() == 4)
            binaryRep = " " + binaryRep; 
    }
    //While Loop to Cycle As Long as Under 9 Digits Via Output on Assignment
    while (binaryRep.length() != 9){
        binaryRep = "0" + binaryRep; 
        //If Statement Repeat Required or First Few Numbers Do Not Get Space in Between 
        if (binaryRep.length() == 4)
            binaryRep = " " + binaryRep;
    }
    return binaryRep;
}

//Function to Convert Decimal NUmber to Hexadecimal Number
string decimalToHexNumber(int x){
    //Variable Declaration and Initialization to Empty String
    string heximalRep = "";
    //While Loop Cycles as Long as x is True
    while(x){
        //Convert Decimal Number to Hexidecimal By Dividing by 16 and 
        //Storing Remainder
        int remainder = x % 16; 
        //Variable to Hold Current Answer
        string temporaryHolder;
        //If Less Than 10 Store Integer as Character
        if (remainder < 10)
            //Store Integer as Character 
            temporaryHolder = to_string(remainder);
        //Else Convert Integer Into Alphabetic Equivalent in Hexidecimal Terms
        else{
            //Switch Statement Cleaner to Read Than Multiple if Statements For Remainder Options
            switch (remainder){
                //If Integer is 10 the Equivalent is A
            case 10:
                temporaryHolder = "A";
                break;
                //If Integer is 11 the Equivalent is B
            case 11:
                temporaryHolder = "B";
                break;
                //If Integer is 12 the Equivalent is C
            case 12:
                temporaryHolder = "C";
                break;
                //If Integer is 13 the Equivalent is D
            case 13:
                temporaryHolder = "D";
                break;
                //If Integer is 14 the Equivalent is E
            case 14:
                temporaryHolder = "E";
                break;
                //If Integer is 15 the Equivalent is F
            case 15:
                temporaryHolder = "F";
                break;
            }
        }
        //Store Current Remainder into Array
        heximalRep = temporaryHolder + heximalRep;
        //Continue to Divide by 16 until x Cannot Divide Anymore
        x = x / 16;
    }
    //While Hexadecimal Number is Less than 16 Display with 0 in Front
    while (heximalRep.length() != 2) {
        heximalRep = "0" + heximalRep;
    }
    return heximalRep;
}

//Function to Convert Decimal Number to Binary Coded Number
string decimalToBCDNumber(int x){
    //Variable Declaration and Initialization to Empty String
    string BCDRep = "";
    //While Loop Cycles as Long as x is True
    while(x){
        //Storing Remainder
        int remainder = x % 10; 
        //Variable to Hold Current Answer
        string temporaryHolder;
        //Switch Statement Cleaner to Read Than Multiple if Statements For Remainder Options
        //All Cases Binary Coded Number Options
        switch (remainder){
        case 0:
            temporaryHolder = "0000";
            break;
        case 1:
            temporaryHolder = "0001";
            break;
        case 2:
            temporaryHolder = "0010";
            break;
        case 3:
            temporaryHolder = "0011";
            break;
        case 4:
            temporaryHolder = "0100";
            break;
        case 5:
            temporaryHolder = "0101";
            break;
        case 6:
            temporaryHolder = "0110";
            break;
        case 7:
            temporaryHolder = "0111";
            break;
        case 8:
            temporaryHolder = "1000";
            break;
        case 9:
            temporaryHolder = "1001";
            break;
        }
        //Store Into Array With Space After Each Set of 4
        BCDRep = temporaryHolder + " " + BCDRep;
        //Continue to Divide by 10 Until Unable
        x = x / 10;
    }
    //While Loop Required For Proper Display to Decimal Number 63
    while (BCDRep.length() != 15) {
        BCDRep = "0000 " + BCDRep;
    }
    return BCDRep;
}

int main(){
    //Variable For Output File
    ofstream outputFile;
    //Explicit Output File Open
    outputFile.open("output.txt");

    //Display Type to Screen With Proper Spacing Per Assignment
    cout << "DECIMAL \tBINARY \t\t\tHEXADECIMAL \tBCD" << endl;

    //Write Type to File With Proper Spacing Per Assignment
    outputFile << "DECIMAL \tBINARY \t\t\tHEXADECIMAL \tBCD" << endl;

    //Loop, Call Functions, and Both Display to Screen and Write to Output 
    //File Conversions Until Maximum Number is Reached
    for (int i = 0; i < 256; i++) {
        cout << i << "\t\t" << decimalToBinaryNumber(i) << "\t\t" << decimalToHexNumber(i) << "\t\t" << decimalToBCDNumber(i) << endl;
        outputFile << i << "\t\t" << decimalToBinaryNumber(i) << "\t\t" << decimalToHexNumber(i) << "\t\t" << decimalToBCDNumber(i) << endl;
    }


    return 0;
}