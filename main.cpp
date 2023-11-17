#include <iostream>
#include <ctime>

using namespace std;

//function to genrate random numbers
void generateRandomArray(int *a , int sizeofArray)
{
    srand(time(NULL));
    for(int i = 0 ; i < sizeofArray ; i++)
    {
        a[i] = rand() % 101;
    }
}

//function to print array
void printArray(int * a , int sizeOfArray)
{
    for (int i = 0 ; i < sizeOfArray ; i++)
    {
        cout << a[i] << "\t";
    }
    cout << "\n";
}

//partitioning function (part of quick sort algorithm)
int partitioning (int * a , int firstIndex , int lastIndex)
{
    int rightCounter = firstIndex + 1;
    int leftCounter = lastIndex;
    int pivot = a[firstIndex];
    int temp;
    while (rightCounter <= leftCounter)
    {
        while(rightCounter <= lastIndex && a[rightCounter] <= pivot)
        {
            rightCounter++;
        }
        while (leftCounter > firstIndex && a[leftCounter] >= pivot)
        {
            leftCounter--;
        }
        if(rightCounter < leftCounter)
        {
            temp = a[rightCounter];
            a[rightCounter] = a[leftCounter];
            a[leftCounter] = temp;
        }
    }
    temp = a[firstIndex];
    a[firstIndex] = a[leftCounter];
    a[leftCounter] = temp;
    return leftCounter;
}

//quick sort algorithm function using partitioning as a function
void quickSort(int * a , int firstIndex , int lastIndex)
{
    if (firstIndex >= lastIndex)
        return;
    int partitioningReturn = partitioning(a , firstIndex , lastIndex);
    quickSort (a , firstIndex , partitioningReturn - 1);
    quickSort (a , partitioningReturn + 1 , lastIndex);
}

//quick sort algorithm function without using partitioning as a function
void partitioningQuickSort(int * a , int firstIndex , int lastIndex)
{
    if (firstIndex >= lastIndex)
        return;
    int leftCounter = firstIndex + 1;
    int rightCounter = lastIndex;
    int pivot = a[firstIndex];
    int temp;
    while (leftCounter <= rightCounter)
    {
        while(leftCounter <= lastIndex && a[leftCounter] <= pivot)
        {
            leftCounter++;
        }
        while (rightCounter > firstIndex && a[rightCounter] >= pivot)
        {
            rightCounter--;
        }
        if(leftCounter < rightCounter)
        {
            temp = a[leftCounter];
            a[leftCounter] = a[rightCounter];
            a[rightCounter] = temp;
        }
    }
    temp = a[firstIndex];
    a[firstIndex] = a[rightCounter];
    a[rightCounter] = temp;
    partitioningQuickSort (a , firstIndex , rightCounter - 1);
    partitioningQuickSort (a , rightCounter + 1 , lastIndex);
}

//merge arrays function (part of merge sort algorithm)
void mergeTwoArrays(int *a , int firstIndexOfFirstArray , int lastIndexOfFirstArray , int firstIndexOfSecondArray , int lastIndexOfSecondArray)
{
    int *tempArray;
    tempArray = new int[((lastIndexOfSecondArray - firstIndexOfFirstArray) + 1)];
    int firstArrayCounter = firstIndexOfFirstArray;
    int secondArrayCounter = firstIndexOfSecondArray;
    int tempArrayCounter = 0;
    while(firstArrayCounter <= lastIndexOfFirstArray && secondArrayCounter <= lastIndexOfSecondArray)
    {
        if (a[firstArrayCounter] < a[secondArrayCounter])
        {
            tempArray[tempArrayCounter] = a[firstArrayCounter];
            tempArrayCounter++;
            firstArrayCounter++;
        }
        else
        {
            tempArray[tempArrayCounter] = a[secondArrayCounter];
            tempArrayCounter++;
            secondArrayCounter++;
        }
    }
    while (firstArrayCounter <= lastIndexOfFirstArray)
    {
        tempArray[tempArrayCounter] = a[firstArrayCounter];
        firstArrayCounter++;
        tempArrayCounter++;
    }
    while (secondArrayCounter <= lastIndexOfSecondArray)
    {
        tempArray[tempArrayCounter] = a[secondArrayCounter];
        secondArrayCounter++;
        tempArrayCounter++;
    }
    for (int i = 0 ; i < ((lastIndexOfSecondArray - firstIndexOfFirstArray) + 1) ; i++)
    {
        a[i + firstIndexOfFirstArray] = tempArray[i];
    }
    delete[] tempArray;
}

//merge sort algorithm function
void mergeSort(int * a , int firstIndex , int lastIndex)
{
    if (firstIndex >= lastIndex)
        return;
    int midIndex = ((firstIndex + lastIndex) / 2);
    mergeSort(a , firstIndex , midIndex);
    mergeSort(a , midIndex + 1 , lastIndex);
    mergeTwoArrays(a , firstIndex , midIndex , midIndex + 1 , lastIndex);
}

//simple selection sort algorithm
void simpleSelectionSortAlgorithm(int *a , int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

//selection sort algorithm function
void selectionSortAlgorithm(int *a , int n)
{
    int temp , minValueIndex;
    for(int i = 0 ; i < n - 1 ; i++)
    {
        minValueIndex = i;
        for(int j = i + 1 ; j < n ; j++)
        {
            if(a[minValueIndex] > a[j])
            {
                minValueIndex = j;
            }
        }
        if(minValueIndex != i)
        {
            temp = a[i];
            a[i] = a[minValueIndex];
            a[minValueIndex] = temp;
        }
    }
}

//simple bubble sort algorithm function
void simpleBubbleSortAlgorithm(int *a , int n)
{
    int temp;
    for (int i = 0 ; i < n - 1 ; i++)
    {
        for(int j = 0 ; j < n - i - 1 ; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

//bubble sort algorithm function
void bubbleSortAlgorithm(int *a , int n)
{
    int temp;
    bool isSwapped;
    for (int i = 0 ; i < n - 1 ; i++)
    {
        isSwapped = false;
        for(int j = 0 ; j < n - i - 1 ; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSwapped = true;
            }
        }
        if(isSwapped == false)
        {
            break;
        }
    }
}

//insertion sort algorithm function
void insertionSortAlgorithm(int *a , int n)
{
    int temp , j;
    for (int i = 1 ; i < n ; i++)
    {
        temp = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

//main function to call the functions
int main()
{
    int arr[5];
    generateRandomArray(arr , 5);
    printArray(arr , 5);
    quickSort(arr , 0 , 4);
    printArray(arr , 5);
    return 0;
}
