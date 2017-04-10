#include <iostream>
#include <time.h>    


using namespace std;

void heapify(int *a, int i, int n) {

	int j, temp;
	temp = a[i];
	j = 2*i;

	while (j <= n) {

		if (j < n && a[j+1] > a[j]) {
			j = j+1;
		} if (temp > a[j]) {
			break;
		} else if (temp <= a[j]) {
			a[j/2] = a[j];
			j = 2*j;
		}
	}

	a[j/2] = temp;
	return;
}

void heapsort(int *a, int n) {

	int i, temp;
	for (i = n; i >= 2; i--) {

		temp = a[i];
		a[i] = a[1];
		a[1] = temp;

		heapify(a, 1, i - 1);
	}
}

void build_heap(int *a, int n) {
	for(int i = n/2; i >= 1; i--) {
		heapify(a, i, n);
	}
}

void initialize_heap(int heap[], int size_of_heap) {
	for (int i = 1; i <= size_of_heap; i++) {
		heap[i] = i*2;
	}
}

void print_heap(int heap[], int size_of_heap) {
	cout << "HEAP" << endl;
	cout << "[";
	for (int i = 1; i <= size_of_heap; i++) {
		cout<< heap[i] << " ";
	}
	cout << "]" << endl;
}

int main() {

	const int size_of_heap = 1000000;
	clock_t begin, end;
	double normal_sort=0, insertion_sort=0;

	int *heap = (int*) malloc((size_of_heap+1) * sizeof(int));
	initialize_heap(heap, size_of_heap);	
	cout << "INITAL ";
	//print_heap(heap, size_of_heap);

	build_heap(heap,size_of_heap);
	//print_heap(heap, size_of_heap);

	begin =  clock();
	heapsort(heap, size_of_heap);
	end = clock();
	normal_sort = (double) (end-begin)/CLOCKS_PER_SEC;
	cout << "SORTED";
	//print_heap(heap, size_of_heap);
	cout << "TIME OF NORMAL SORT " << normal_sort << endl;

	return 0;
}
