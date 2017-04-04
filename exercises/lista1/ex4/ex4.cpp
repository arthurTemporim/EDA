#include <iostream>
#include <cstdio>

using namespace std;

void print_vector(int * vector, int vector_length);
int * initialize_vector(int * vector, int vector_length); 

int main() {

	const int length = 100;
	int vector[length];

	initialize_vector(vector, length);
	print_vector(vector, length);

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
