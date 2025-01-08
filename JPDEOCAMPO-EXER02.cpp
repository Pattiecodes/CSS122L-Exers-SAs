/*
* Programmer: DE OCAMPO, James Patrick B.
* Date Created: 01/08/2025
* Terminal No: 00
* Program: BSIT-O
* Course / Section: CSS122L / FOPI01
*/

/* Program Starts here*/
#include <iostream>
#include <iomanip>
using namespace std;

//global declarations
int i;
const int arraySize = 10;
typedef double *pointers; //typedef used for miles per gallon pointer variables

//function prototypes
//for grade elimination
void getInput(double *input); //prompt the user to input 10 grades
double getLow(double *low);   //compute and returns the value of the lowest grade
double getSum(double *sum);   //compute for the sum of 10 grades
//choices and try again
char getChoice(char *ch); //display the menu of choices and input the choice of the user

//miles per gallon
void MilesPerGallon(double *ptr1, double *ptr2, int sz); //final output of the computer miles
//and gallons
void MperG(); //prompts the user to specify the size of the array for miles and gallons

int main()
{
    char choice;
    char *chr = &choice;
    char opt;
    char tryAgain;

    do
    {
        opt = getChoice(chr);
        switch (*chr)
        {
        case '1':
        {
            do
            {
                double grade[arraySize];
                double *ptr = grade;
                double gsum, glow, ave;

                system("cls");
                getInput(ptr);
                glow = getLow(ptr);
                gsum = getSum(ptr) - glow;
                ave = gsum / (arraySize - 1);

                cout << "\nYou entered\n";
                for (i = 0; i < arraySize; i++)
                {
                    cout << "Grade[" << i + 1 << "]: " << grade[i] << endl;
                }
                cout << "Sum = " << gsum << endl;
                cout << "Lowest = " << glow << endl;
                cout << "Average = " << fixed << setprecision(2) << ave << endl;

                cout << "Do you want to try again? [y/n]: ";
                cin >> tryAgain;
            } while (tryAgain == 'y' || tryAgain == 'Y');
        }
        break;

        case '2':
        {
            do
            {
                MperG();
                cout << "Do you want to try again? [y/n]: ";
                cin >> tryAgain;
            } while (tryAgain == 'y' || tryAgain == 'Y');
        }
        break;

        case '3':
            cout << "goodbye for now....\n";
            system("pause");
            exit(1);
            break;

        default:
            cout << "Invalid choice, please try again.\n";
            break;
        }
    } while (*chr != '3');

    cout << endl;
    system("pause");
    return 0;
}

//////////////////////////////////////////////
char getChoice(char *ch)
{
    cout << "\nChoose an option:\n";
    cout << "1. Grade Elimination\n";
    cout << "2. Miles per Gallon\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> *ch;
    return *ch;
}

//////////////////////////////////////////////
void getInput(double *input)
{
    cout << "Grade Elimination:\n";
    cout << "===================\n";
    for (i = 0; i < arraySize; i++)
    {
        cout << "Enter grade [" << i + 1 << "]: ";
        cin >> *(input + i);
    }
}

//////////////////////////////////////////////
double getSum(double *sum)
{
    double total = 0;
    for (i = 0; i < arraySize; i++)
    {
        total += *(sum + i);
    }
    return total;
}

//////////////////////////////////////////////
double getLow(double *low)
{
    double baba = *low;
    for (i = 1; i < arraySize; i++)
    {
        if (*(low + i) < baba)
        {
            baba = *(low + i);
        }
    }
    return baba;
}

//////////////////////////////////////////////
void MperG()
{
    int msize;
    do
    {
        cout << "Enter the size of the array (5-15): ";
        cin >> msize;
        if (msize < 5 || msize > 15)
        {
            cout << "Invalid size! Size must be between 5 and 15.\n";
        }
    } while (msize < 5 || msize > 15);

    pointers milPtr = new double[msize];
    pointers galPtr = new double[msize];

    for (int ctr = 0; ctr < msize; ctr++)
    {
        do
        {
            cout << "Enter miles[" << ctr << "]: ";
            cin >> *(milPtr + ctr);
            if (*(milPtr + ctr) < 100 || *(milPtr + ctr) > 250)
            {
                cout << *(milPtr + ctr) << " is invalid!.. 100-250 only\n";
                cout << "reenter a new value\n";
            }
        } while (*(milPtr + ctr) < 100 || *(milPtr + ctr) > 250);

        do
        {
            cout << "Enter gallons[" << ctr << "]: ";
            cin >> *(galPtr + ctr);
            if (*(galPtr + ctr) < 5 || *(galPtr + ctr) > 25)
            {
                cout << *(galPtr + ctr) << " is invalid!.. 5-25 only\n";
                cout << "reenter a new value\n";
            }
        } while (*(galPtr + ctr) < 5 || *(galPtr + ctr) > 25);
    }

    MilesPerGallon(milPtr, galPtr, msize);

    delete[] milPtr;
    delete[] galPtr;
}

//////////////////////////////////////////////
void MilesPerGallon(double *ptr1, double *ptr2, int sz)
{
    double *mpg = new double[sz];
    for (int index = 0; index < sz; index++)
    {
        mpg[index] = ptr1[index] / ptr2[index];
    }

    cout << "\nmiles    /    gallon    =    MPG\n";
    for (int index = 0; index < sz; index++)
    {
        cout << fixed << setprecision(2) << setw(7) << ptr1[index] 
             << " / " << setw(7) << ptr2[index] << " = " << setw(7) << mpg[index] << endl;
    }

    delete[] mpg;
}
