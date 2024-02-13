#include <iostream>
using namespace std;

void printpattern(int n, int* arr = nullptr, int length = 0)
{
    if (arr == nullptr)
    {
        arr = new int[n]; 
    }
    if (n == 0)
    {
        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        if (length > 0) {
            delete[] arr; 
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        arr[length] = i;
        printpattern(n - i, arr, length + 1);
    }
    if (length > 0) {
        delete[] arr;  
    }
}
int main()
{
    int n = 4;
    printpattern(n);
    return 0;
}