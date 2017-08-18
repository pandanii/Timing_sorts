// Danielle Lewis
// sortFinal.cpp
// 12-04-15
// Sorting efficiency program

# include <iostream>
#include <stdlib.h>     // srand, rand
#include <time.h>       // time
#include <ctime>        //clock
#include <cstdlib>      //sleep
#include <math.h>       // sqrt
using namespace std;

void quickSort(int arr[], int left, int right);
void mergeSort(int a[], int [], int low, int high);
void merge(int arr[], int b[], int low, int pivot, int high);
void quickInsert(int arr[], int left, int right);
void insertionSort (int arr[], int length);
void quickMerge(int arr[], int low, double param, int high);

int main (int argc, char *argv[])
{
    // check command line argument
    if(argc != 3)
        cout<<"Error with arguments"<<endl;
    // dynamically builds the array
    int arraySize;
    arraySize = atoi(argv[2]);
    int counter = 0;
    int myArray[arraySize];
    int newArray[arraySize];
    int mergeArray[arraySize];
    double sqrtmerge;
	sqrtmerge = sqrt (arraySize) +1;

    //initializing clocks
    clock_t qs;
    clock_t ms;
    clock_t qi;
    clock_t qm;

    // initialize random seed
    srand(time(NULL));
    // populating the random array
    while(counter < arraySize)
        {
        myArray[counter]= rand()%100+1;
        counter++;
        }
        int b = 0;
    while( b < arraySize)
    {
        newArray[b] = myArray[b];
	b++;

    }
// starting time of clock quick sort
qs = clock();
quickSort(myArray, 0, arraySize);
//sleep(5176);
//end of clock
qs = clock() - qs;
cout<< "QS: "<<qs/(float)CLOCKS_PER_SEC <<" sec" << endl;

ms = clock();
mergeSort(myArray, mergeArray, 0, arraySize);
ms = clock() - ms;
cout<< "MS: "<<ms/(float)CLOCKS_PER_SEC <<" sec" << endl;

qi = clock();
quickInsert(myArray, 0, arraySize);
qi = clock() - qi;
cout<< "QI: "<<qi/(float)CLOCKS_PER_SEC <<" sec" << endl;

qm = clock();
quickMerge(myArray, 0, sqrtmerge, arraySize);
qm = clock() - qm;
cout<< "QM: "<<qm/(float)CLOCKS_PER_SEC <<" sec" << endl;

}// end of main
//=========================================================
void quickSort(int arr[], int left, int right)
{
int i = left, j = right;
int tmp;
int pivot; // = arr[(left + right) / 2];
if (arr[i] < arr[j])
    pivot = arr[i];
else
    pivot = arr[j];

// partition
    while (i <= j)
        {
        while (arr[i] < pivot)
            i++;
            while (arr[j] > pivot)
                j--;
                if (i <= j)
                    {
                    tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                    i++;
                    j--;
                    }
        }
// recursion
if (left < j)
    quickSort(arr, left, j);
if (i < right)
        quickSort(arr, i, right);
}
//=========================================================
void mergeSort(int arr[], int b[], int low, int high)
{
    int pivot;
    if(low < high)
    {
        pivot = (low+high)/2;
        mergeSort(arr,b,low,pivot);
        mergeSort(arr,b,pivot+1,high);
        merge(arr,b,low,pivot,high);
    }
}
//=========================================================
void merge(int arr[], int b[], int low, int pivot, int high)
{
    int h,i,j,k;
    h = low;
    i = low;
    j = pivot+1;

    while((h <= pivot)&&(j <= high))
        {
        if(arr[h] <= arr[j])
            {
            b[i] = arr[h];
            h++;
            }
        else
            {
            b[i] = arr[j];
            j++;
            }
        i++;
        }
    if(h > pivot)
        {
        for(k = j; k <= high; k++)
            {
            b[i] = arr[k];
            i++;
            }
        }
    else
        {
        for(k = h; k <= pivot; k++)
            {
            b[i] = arr[k];
            i++;
            }
        }
    for(k = low; k <= high; k++)
        arr[k] = b[k];
}
//=========================================================
void quickInsert(int arr[], int left, int right)
{
int i = left, j = right;
int tmp;
int pivot;
int min = 10;
//int pivot; // = arr[(left + right) / 2];
if (arr[i] < arr[j])
    pivot = arr[i];
else
    pivot = arr[j];

if (left < min && right > min)
    {
    insertionSort(arr,left);
    insertionSort(arr, right);
    }

else
{

// partition
    while (i <= j)
        {
        while (arr[i] < pivot)
            i++;
            while (arr[j] > pivot)
                j--;
                if (i <= j)
                    {
                    tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                    i++;
                    j--;
                    }
        }
// recursion
if (left < j)
    quickSort(arr, left, j);
if (i < right)
        quickSort(arr, i, right);
} // end of else
} // end of qi
//=========================================================

void insertionSort (int arr[], int length)
{
int j, temp;
for (int i = 0; i < length; i++)
    {
    j = i;

    while (j > 0 && arr[j] < arr[j-1])
        {
        temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
        j--;
        }
    }
}
//=========================================================
void quickMerge(int arr[], int low, double param, int high)
{
int i = low, j = high;
int tmp;
double pivot = param;
if (arr[i] < arr[j])
    pivot = arr[i];
else
    pivot = arr[j];
// partition
    while (i <= j)
        {
        while (arr[i] < pivot)
            i++;
            while (arr[j] > pivot)
                j--;
                if (i <= j)
                    {
                    tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                    i++;
                    j--;
                    }
        }
// recursion
if (low < j)
    quickMerge(arr, low, pivot, j);
if (i < high)
    quickMerge(arr, i, pivot, high);
}







