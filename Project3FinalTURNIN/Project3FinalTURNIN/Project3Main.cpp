// AUTHOR - Jaden B Knuston.
// DATE -	4/11/23     4AM
//          4/12/23     8pm
//          4/13/23     6am
//          4/14/23     7pm
//          4/15/23     3am
//          4/16/23     9pm

/* DESCRIPTION:
Program analyzes daily text records from input file CS210_Project_Three_Input_File.txt:
Records consist of a list of purchased items in order from the stores open to the stores close.
A data file frequency.dat is created in the beginning of the program without user intervention and is for backup purposes.
The frequency.dat file should include every item (represented by a word) paired with the number of times that item appears in the input file.

A menu inputs a choice 1-4 from the user:
    Option 1 allows the user to find the sale frequency of a single item.
    Option 2 outputs all items and frequencies.
    Option 3 outputs all items and frequencies in histogram form.
    Option 4 terminates the program.
/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/
/*Variable Library*/
int choice; //Stores user menu choice: 1, 2, 3, or 4.
string item; //Stores user item choice for menu option 1.

void readFile(string fileName);//Reads from files
void writeFile(string fileName);//Writes to files
int findItem(string item);//Finds item if option 1 is chosen


//Display Functions
void printFrequency();//Outputs the name and frequency sold of all items in number form
void printHistogram();//Outputs the name and frequency sold of all items in historgram form

void outputMenu();//Outputs menu to the user
void outputGreetins();//Greetings and farewell messages to user

void optionTitle1();//Outputs option 1 title if 1 is chosen
void optionTitle2();//Outputs option 2 title if 2 is chosen
void optionTitle3();//Outputs option 3 title if 3 is chosen
void optionTitle4();//Outputs option 4 title if 4 is chosen
void optionTitleEnd();//Outputs a line to signify the end of the process.
/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/





/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/
/*START CLASS*/
class Grocer {

private:
    map<string, int> items;

public:

    /*------------------------------------------------------------------------------*/
    /* readFile() - Reads from the input file */
    void readFile(string fileName) {
        ifstream inputFile;
        inputFile.open(fileName);//Opens file

        //Checks to see if file is open
        if (inputFile.is_open()) {//If file is available

            //Reads items from the file
            string item;
            while (inputFile >> item) {
                items[item]++;
            }
            inputFile.close();//Closes file
        }//END If

        else {//If file is unavailable
            cout << "ERROR --> UNABLE TO OPEN FILE!!!" << endl;//Outputs error message
            choice = 4;//Shuts down program if files are not found
        }//END Else
    }//END Function
/*------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------*/
/* writeFile - Writes to the output file */
    void writeFile(string fileName) {
        ofstream outputFile;
        outputFile.open(fileName);//Opens file

        //Checks to see if file is open
        if (outputFile.is_open()) {//If file is available

            //Writes items name and frequency to file
            for (auto const& item : items) {
                outputFile << item.first << " " << item.second << endl;
            }//END For

            outputFile.close();//Closes file
        }//END If

        else {//If file is unavailable
            cout << "ERROR --> UNABLE TO WRITE TO FILE!!!" << endl;//Outputs error message
            choice = 4;//Shuts down program if files are not found
        }//END Else
    }//END Function
/*------------------------------------------------------------------------------*/










/*------------------------------------------------------------------------------*/
/* printFrequency - Outputs the name and frequency sold of an item */
    void printFrequency() {
        for (auto const& item : items) {

            //Calculates an amount of pre-spaces so that numbers and stars lineup
            int spaceNum = 0;//spaces initially set to zero
            spaceNum = 15 - item.first.length();//Subtracts items length from 15 to caluclate spaces
            for (int i = 0; i < spaceNum; ++i) {//Loop for output of multiple spaces
                cout << " ";//Outputs pre-spaces
            }//END For

            cout << item.first << " - " << item.second << endl;//Prints item, space, and items frequency

        }//END For
    }//END Function
/*------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------*/
/* printHistogram - Outputs the name and frequency of an item in histogram form */
    void printHistogram() {
        for (auto const& item : items) {

            //Calculates an amount of pre-spaces so that numbers and stars lineup
            int spaceNum = 0;//spaces initially set to zero
            spaceNum = 15 - item.first.length();//Subtracts items length from 15 to caluclate spaces
            for (int i = 0; i < spaceNum; ++i) {//Loop for output of multiple spaces
                cout << " ";//Outputs pre-spaces
            }//END For

            cout << item.first << " - ";//Prints item and a space

            //Loop for printing multiple stars for histogram
            for (int i = 0; i < item.second; i++) {
                cout << "*";//Outputs stars
            }/*END For*/

            cout << endl;//Empty Line
        }/*END For*/
    }//END Function
/*------------------------------------------------------------------------------*/










/*------------------------------------------------------------------------------*/
 /* findItem() - Locates an item in the input file and counts it */
    int findItem(string item) {
        if (items.count(item) > 0) {
            return items[item];
        }//END If

        else {
            return 0;
        }//END Else
    }//END Function
/*------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------*/
/* outputMenu() - Outputs menu to user */
    void outputMenu() {
        //OUTPUTS menu to user
        cout << "---------------------------------------------" << endl;
        cout << "1 - Find Single Item Frequency" << endl;
        cout << "2 - Print Frequency of All Items" << endl;
        cout << "3 - Print Histogram of All Items" << endl;
        cout << "4 - Terminate Program" << endl;
        cout << "Enter Your Choice: ";
    }//END Function
/*------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------*/
/* outputGreetings() - Greets and says goodbye to user */
    void outputGreetings() {
        if (choice == 4) {//if user pick 4, outputs end of program message
            cout << "Program Shutting down:" << endl;//Ouputs termination message
            system("pause");//Pauses so user can read message, then needs final key press to end.
        }//END If

        else {//Prints welcome message at the beginning
            cout << "Welcome User! Please Enter 1, 2, 3, or 4." << endl;
        }//END Else
    }//END Function
/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/
};//END CLASS
/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/





















/* OTHER FUNCTIONS */
/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/
//Outputs option 1 title if 1 is chosen
void optionTitle1() {
    cout << "Option 1 chosen - Single Item Frequency." << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Enter item: ";
    cin >> item;//Input item
    cout << "Frequency: ";
}//END Function


/*------------------------------------------------------------------------------*/
//Outputs option 2 title if 2 is chosen
void optionTitle2() {
    cout << "Option 2 chosen - Print All Item Frequency" << endl;
    cout << "---------------------------------------------" << endl;
}//END Function


/*------------------------------------------------------------------------------*/
//Outputs option 3 title if 3 is chosen
void optionTitle3() {
    cout << "Option 3 chosen - Print All Item Histogram:" << endl;
    cout << "---------------------------------------------" << endl;
}//END Function


/*------------------------------------------------------------------------------*/
//Outputs option 4 title if 4 is chosen
void optionTitle4() {
    cout << "Option 4 chosen - Terminate Program:" << endl;
    cout << "---------------------------------------------" << endl;
}//END Function


/*------------------------------------------------------------------------------*/
//Outputs a line to signify the end of the process.
void optionTitleEnd() {
    cout << "END---------------------------------------------END" << endl;
    cout << endl << endl;//Empty Line
}//END Function


/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/


























/*START MAIN*/ /*START MAIN*/ /*START MAIN*/
/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/
int main() {
    Grocer grocer; //Grocer Class
    grocer.readFile("CS210_Project_Three_Input_File.txt"); //Input File
    grocer.writeFile("frequency.dat"); //Output File

    /*---------------------------------------------------*/
    grocer.outputGreetings();//Greeting Message

    do {//START Do-While

        /*---------------------------------------------------*/
        //Shuts down program if files are not found
        if (choice == 4) {
            break;
        }
        /*---------------------------------------------------*/
        grocer.outputMenu();//Outputs menu to user
        cin >> choice;//Inputs menu choice from user
        cout << endl;//Empty Line

        /*---------------------------------------------------*/
        switch (choice) {//Start Swtich for user menu
            /*---------------------------------------------------*/
            /* OPTION 1: Find user item frequency */
        case 1: //If user input is 1
            optionTitle1();//Start display function
            cout << grocer.findItem(item) << endl;//Finds single item frequency
            optionTitleEnd();//End display function
            break;//Exit Loop

            /*---------------------------------------------------*/
            /* OPTION 2: Prints frequency of all the items */
        case 2: //If user input is 2
            optionTitle2();//Start display function
            grocer.printFrequency();//Outputs the name and frequency sold of all items in number form
            optionTitleEnd();//End display function
            break;//Exit Loop

            /*---------------------------------------------------*/
            /* OPTION 3: Prints a histogram of all the items */
        case 3: //If user input is 3
            optionTitle3();//Start display function
            grocer.printHistogram();//Outputs the name and frequency sold of all items in historgram form
            optionTitleEnd();//End display function
            break;//Exit Loop

            /*---------------------------------------------------*/
            /* OPTION 4: Terminates the program */
        case 4: //If user input is 4
            optionTitle4();//Start display function
            grocer.outputGreetings();//Greetings and farewell messages to user
            optionTitleEnd();//End display function
            break;//Exit Loop

            /*---------------------------------------------------*/
            /* OPTION Default: Incorrect Input results in re-input from user until 1, 2, 3, or 4 is typed.*/
        default: //If user input is incorrect
            cout << "!!!Invalid Input!!! Please Enter 1, 2, 3, or 4." << endl;
            break;//Exit Loop

            /*---------------------------------------------------*/
        }//END Switch
    } while (choice != 4); //END Do-While if input is 4
    /*---------------------------------------------------*/
    return 0;
} /*END While*/
/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/
/*END MAIN*/ /*END MAIN*/ /*END MAIN*/