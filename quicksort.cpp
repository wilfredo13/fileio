#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int Partition (int A[], int Lb, int Ub){
    // select a pivot from A[Lb] ... A[Ub]
    int pivot = A[Ub];
    //reorder A[Lb]…A[Ub] such that:
    //   - all values to the left of the pivot are <= pivot
    //   - all values to the right of the pivot are > pivot
    while (Lb < Ub){
        while (A[Lb] < pivot) Lb++;
        while (A[Ub] > pivot) Ub--;
        //if (A[Lb] == A[Ub]) Lb++;
        if (Lb < Ub) swap (A[Lb], A[Ub]);
        }

    // return pivot position
    return Ub;
}

void QuickSort(int A[], int Lb, int Ub){
    if (Lb < Ub){
        int M = Partition (A, Lb, Ub);
        QuickSort (A, Lb, M - 1);
        QuickSort (A, M + 1, Ub);
        }
}

int main()
{
    string line;
    int temp, n = 0;
    int c = 0;
    int numbers [10000];
    //int * numbers;
    //numbers = new int [n];
    // n = 0;

    ifstream myfile("data10k.txt");
    while (myfile.good()){
        getline (myfile, line);
        stringstream(line) >> temp;
        numbers[n] = temp;
        n++;
        }

    QuickSort (numbers, 0, 9999);

    for (int n = 0; n < 10000; n++){
        cout << numbers[n] << "\n";
        }

    return 0;
}
