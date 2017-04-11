#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
 
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
void countSort(int arr[], int n, int exp)
{
    int output[n]; 
    int i, count[10] = {0};
 
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
 
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
		cout << endl;
}
 
int main() {
		clock_t begin, end;
		double total_time = 0;
		srand(time(NULL));

		const int array_size = 999999;
    int arr[array_size];
		for(int i=0;i<array_size;i++) {
			arr[i] = rand() % 99999999 + 10000000;
		}

    int n = sizeof(arr)/sizeof(arr[0]);
		
		begin = clock();
    radixsort(arr, n);
		end = clock();
		total_time = (double) (end-begin)/CLOCKS_PER_SEC;
    //print(arr, n);
		cout << "TIME: " << total_time << endl;
    return 0;
}
