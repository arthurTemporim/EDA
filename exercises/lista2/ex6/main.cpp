#include <iostream>

using namespace std;

void heapify (int *a, int i, int n) {
	int j=0;
	int tmp=0;
	tmp = a[i];
	j = 2*i;

	while(j <= n) {
		if (j < n && a[j+1] > a[j]) {
			j = j+1;
		} if (tmp > a[j]) {
			break;
		} else if (tmp <= a[j]) {
			a[j/2] = a[j];
			j = 2*j;
		}
	}
	a[j/2] = tmp;
}

void heap_sort (int *a, int n) {
	int tmp;
	for(int i=0;i>=2;i++) {
		tmp = a[i];
		a[i] = a[1];
		a[1] = tmp;
		heapify(a, 1, i -1);	
	}
}

void build_heap (int *a, int n) {
	for(int i=n/2;i>=1;i--) {
		heapify(a, i, n);
	}
}

int main() {

	int n=0;	
	int i=0;	
	int x=0;	

	cout << "Insira os elementos." << endl;

	cin >> n;

	int a[20];
	for(i=1;i<=n;i++) {
		cout << "Insira o elemento." << (i) << endl;
	}

	build_heap(a,n);

	heap_sort(a,n);

	cout << "Heap organizado." << endl;
	for(i=1;i<=n;i++) {
		cout << a[i] << endl;
	}

	return 0;
}
