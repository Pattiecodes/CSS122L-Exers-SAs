/*
* Programmer: DE OCAMPO, James Patrick B.
* Date Created: 01/08/2025
* Terminal No: 00
* Program: BSIT-O
* Course / Section: CSS122L / FOPI01
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
char getMenu();
void getTry();
void getBinDisplay(int *ptr, int *xsize);
int getLoc(int *ptr, int size, int *xtarget);
int getSize();
void getInput(double *ptr, int xsize);
double getElim(double *ptr, int xsize);

int main()
{
    char choice;
    do
    {
        try
        {
            choice = getMenu();
            switch (choice)
            {
            case '1':
            {
                int xsize = 10;
                int arr[10] = {1, 3, 7, 9, 11, 21, 33, 45, 56, 89};

                getBinDisplay(arr, &xsize);

                int xtarget;
                cout << "Enter the target element to search: ";
                cin >> xtarget;

                int result = getLoc(arr, xsize, &xtarget);
                if (result != -1)
                    cout << xtarget << " is at position [" << result << "]" << endl;
                else
                    cout << xtarget << " is not in the list." << endl;
            }
            break;

            case '2':
            {
                int size = getSize();

                double *grades = new double[size];
                getInput(grades, size);

                double eliminated = getElim(grades, size);

                cout << "The average is: " << fixed << setprecision(2) << eliminated << endl;

                delete[] grades;
            }
            break;

            case '3':
                cout << "goodbye for now....\n";
                break;

            default:
                throw "Invalid choice! Please enter a valid option.";
            }
        }
        catch (const char *msg)
        {
            cout << msg << endl;
        }

        getTry();
    } while (choice != '3');

    return 0;
}

// Function Definitions
char getMenu()
{
    char choice;
    cout << "\nChoose an option:\n";
    cout << "1. Binary Searching\n";
    cout << "2. Grade Elimination\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice < '1' || choice > '3')
        throw "Invalid choice! Please enter a valid option.";
    return choice;
}

void getTry()
{
    char tryAgain;
    do
    {
        cout << "Do you want to try again? [y/n]: ";
        cin >> tryAgain;
        if (tryAgain == 'n' || tryAgain == 'N')
            exit(0);
        else if (tryAgain != 'y' && tryAgain != 'Y')
            cout << "Invalid input! Please enter 'y' or 'n'.\n";
    } while (tryAgain != 'y' && tryAgain != 'Y');
}

void getBinDisplay(int *ptr, int *xsize)
{
    cout << "Array elements: ";
    for (int i = 0; i < *xsize; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;
}

int getLoc(int *ptr, int size, int *xtarget)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (ptr[mid] == *xtarget)
            return mid;
        if (ptr[mid] < *xtarget)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int getSize()
{
    int size;
    do
    {
        cout << "Enter the number of grades: ";
        cin >> size;
        if (size <= 0)
            cout << "Invalid size! Size must be greater than 0.\n";
    } while (size <= 0);
    return size;
}

void getInput(double *ptr, int xsize)
{
    for (int i = 0; i < xsize; i++)
    {
        cout << "Enter grade [" << i << "]: ";
        cin >> ptr[i];
    }
}

double getElim(double *ptr, int xsize)
{
    double total = 0, lowest = ptr[0];
    for (int i = 1; i < xsize; i++)
    {
        if (ptr[i] < lowest)
            lowest = ptr[i];
        total += ptr[i];
    }
    total -= lowest;
    cout << fixed << setprecision(2) << lowest << " is eliminated" << endl;
    return total / (xsize - 1);
}
