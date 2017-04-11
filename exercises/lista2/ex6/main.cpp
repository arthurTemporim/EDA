#include <iostream>
#include <time.h>    

using namespace std;

void heapify(int *heap, int i, int size_of_heap);
void heapsort(int *heap, int size_of_heap); 
void build_heap(int *heap, int size_of_heap);
void initialize_heap(int heap[], int size_of_heap);
void print_heap(int heap[], int size_of_heap);


void heapsort_insertion(int *heap, int size_of_heap) {
	int *insertion_heap = (int*) malloc((size_of_heap+1) * sizeof(int));

	for(int i=size_of_heap;i>=2;i--) {
	}		
}

int main() {

	const int size_of_heap = 100000;
	clock_t begin, end;
	double normal_sort=0, insertion_sort=0;

	int *heap = (int*) malloc((size_of_heap+1) * sizeof(int));
	initialize_heap(heap, size_of_heap);	
	cout << "INITAL ";
	//print_heap(heap, size_of_heap);

	build_heap(heap,size_of_heap);
	//print_heap(heap, size_of_heap);

	heapsort_insertion(heap, size_of_heap);
	begin =  clock();
	heapsort(heap, size_of_heap);
	end = clock();
	normal_sort = (double) (end-begin)/CLOCKS_PER_SEC;
	cout << "SORTED";
	//print_heap(heap, size_of_heap);
	cout << "TIME OF NORMAL SORT " << normal_sort << endl;

	return 0;
}


void heapify(int *heap, int i, int size_of_heap) {
	int j, temp;
	temp = heap[i];
	j = 2*i;

	while (j <= size_of_heap) {

		if (j < size_of_heap && heap[j+1] > heap[j]) {
			j = j+1;
		} if (temp > heap[j]) {
			break;
		} else if (temp <= heap[j]) {
			heap[j/2] = heap[j];
			j = 2*j;
		}
	}

	heap[j/2] = temp;
}

void heapsort(int *heap, int size_of_heap) {
	int tmp;
	for (int i = size_of_heap; i >= 2; i--) {

		tmp = heap[i];
		heap[i] = heap[1];
		heap[1] = tmp;

		heapify(heap, 1, i - 1);
	}
}

void build_heap(int *heap, int size_of_heap) {
	for(int i = size_of_heap/2; i >= 1; i--) {
		heapify(heap, i, size_of_heap);
	}
}

void initialize_heap(int heap[], int size_of_heap) {
	for (int i = 0; i <= size_of_heap; i++) {
		heap[i] = i;
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
