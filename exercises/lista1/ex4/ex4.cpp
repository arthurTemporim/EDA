#include <iostream>

using namespace std;

int * initialize_vector(int * vector, int vector_length);
void print_vector(int * vector, int vector_length); 

int main() {
	
	const int vector_length = 100;
	int vector[vector_length];

	initialize_vector(vector, vector_length);
	print_vector(vector, vector_length);


	return 0;
}

int * initialize_vector(int * vector, int vector_length) {
	for(int i=0;i<vector_length;i++) {
		vector[i] = i;
	}
	return vector;	
}

void print_vector(int * vector, int vector_length) {
	cout << '[';
	for(int i=0;i<vector_length;i++) {
		cout << vector[i] << " ";
	}
	cout << ']';
	cout << endl;
}
