#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main () {
    // declare variables
    string line;
    int numbers[11];
    int temp = 0, n = 0;
    int largestNum = 0, smallNum = 0, pivot = 0;

    fstream myfile("data.txt");

    while (myfile.good())   {
        getline (myfile, line);
        stringstream(line) >> temp;
        numbers[n] = temp;
        n++;}
    myfile.close();

    for (n = 0; n < 11; n++)
    {cout << numbers[n] << endl;}

    for (n = 0; n < 11; n++)
        if (numbers[n] >= pivot) pivot = numbers[n];
        else smallNum = numbers[n];
    cout << endl << smallNum << endl;
       // else smallNum = numbers[n];
       // cout << endl << smallNum << "..." << endl;

    return (0);
}
