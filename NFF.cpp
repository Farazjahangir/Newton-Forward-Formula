#include <iostream>
#include <cmath>
using namespace std;

int **createArray(int n)
{
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    return arr;
}

void **takeInputFromUser(int **sdt, int n)
{
    for (int column = 0; column < 2; column++)
    {
        if (column == 0)
        {
            cout << "Enter values for x each value on a new line:\n";
        }
        else
        {
            cout << "\nEnter values for f(x) each value on new line:\n";
        }

        for (int row = 0; row < n; row++)
        {
            cin >> sdt[row][column];
        }
    }
}

void printArray(int **sdt, int n)
{
    for (int column = 0; column <= n; column++)
    {
        cout << "\n\nColumn No " << column;
        for (int row = 0; row < n; row++)
        {
            cout << "\n";
            cout << sdt[row][column];
        }
    }
}

void constructTable(int **sdt, int n)
{
    for (int column = 2; column <= n; column++)
    {
        for (int row = 0; row < n - column + 1; row++)
        {
            sdt[row][column] = sdt[row + 1][column - 1] - sdt[row][column - 1];
        }
    }
}

int calculateFactorial(int number)
{
    if (number == 0 || number == 1)
    {
        return 1;
    }
    else
    {
        return number * calculateFactorial(number - 1);
    }
}

void NFF(int **sdt, int n)
{
    double valueToInterpolate;
    cout << "\nWrite a number to interploate: ";
    cin >> valueToInterpolate;
    double result = sdt[0][1];
    double h = sdt[1][0] - sdt[0][0];
    double yTerm;
    double xTerm = 0;

    for (int column = 2; column <= n; column++)
    {

        double factValue = calculateFactorial(column - 1);
        double multiply = factValue * pow(h, column - 1);
        yTerm = sdt[0][column] / multiply;

        for (int row = 0; row < column - 1; row++)
        {
            if (xTerm == 0)
            {
                xTerm = valueToInterpolate - sdt[row][0];
            }
            else
            {
                xTerm *= valueToInterpolate - sdt[row][0];
            }
        }

        result += yTerm * xTerm;
        xTerm = 0;
    }

    cout << "\n\nAnswer Is: ";
    cout << result;
}

int main()
{
    int n;
    cout << "Enter Total no of data points: ";
    cin >> n;

    int **sdt = createArray(n);
    takeInputFromUser(sdt, n);
    constructTable(sdt, n);
    NFF(sdt, n);
    // printArray(sdt, n);
    return 0;
}