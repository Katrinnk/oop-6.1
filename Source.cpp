#include <iostream>
#include "Array.h"
#include <time.h>

Array DynamicArray(int arr[], const int size);
using namespace std;
int main()
{
    srand((unsigned)time(NULL));
    const int size = 35;
    int arr[size];

    for (int i = 0; i < size; i++)
        arr[i] = -50 + rand() % int(50 - (-50) + 1);  //формування масиву числами в діапазоні від -50 до +50
    Array taskArray = DynamicArray(arr, size);
    cout << "masyv:"<<endl;
    cout << DynamicArray(arr,size);
    cout << "masyv z sumoiu ta serednim znachenniam v kintsi:"<<endl;
    taskArray.SumaVKinets();
    taskArray.SeredZnachVKinets();
    cout << taskArray;
    cout << "Zamina:0==SeredneZnachennia:" << endl;
    taskArray.Change();
    cout << taskArray;

    return 0;
}
Array DynamicArray(int arr[], const int size)
{
    Array dynamicArray = Array(size);

    for (int i = 0; i < size; i++)
        dynamicArray[i] = arr[i];

    return dynamicArray;
}