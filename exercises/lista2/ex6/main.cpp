#include <iostream>

using namespace std;

const int size_vector = 11;

void create_vector(int vector[]) {
	for(int i=0;i<size_vector;i++) {
		vector[i] = i;
	}
}

void print_Vector(int vector[]) {
	for(int i=0;i<size_vector;i++) {
		cout << vector[i] << endl;
	}
}

int main() {
	int *vector = (int *) malloc(size_vector * sizeof(int));
	
	create_vector(vector);
	print_Vector(vector);

	return 0;
}
