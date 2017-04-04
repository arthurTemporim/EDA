#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int * initialize_vector(int * vector, int vector_length); 
void print_vector(int * vector, int vector_length);
int * initialize_primary_index(int * primary_index, int primary_index_lenght, int * vector, int gap);
void print_primary_index(int * primary_index, int primary_index_length);
void print_menu();
string search(int value, int * primary_index, int* vector, int gap);


int main() {

	const int length = 100;
	const int primary_index_lenght = 10;
	const int gap = 10;

	int vector[length];
	int primary_index[primary_index_lenght];

	initialize_vector(vector, length);
	print_vector(vector, length);

	initialize_primary_index(primary_index, primary_index_lenght, vector, gap);
	print_primary_index(primary_index, primary_index_lenght);

	print_menu();
	int value=0;
	cin >> value;

	string result;
	result =  search(value, primary_index, vector, gap);
	cout << result << endl;

	return 0;
}

string search(int value, int *primary_index, int * vector, int gap) {
	string response = "NOT FOUNDED!";
	for(int i=0;i<sizeof(primary_index);i++) {
		if(value < primary_index[i]) {
			for(int j=0;j<gap;j++) {
				if(value == vector[j]) {
					response = "FOUNDED!";
				} else {
					// nothing to do.
				}
			}
		} else {
			// nothing to do.
		}
	}
	return response;
}

int * initialize_vector(int * vector, int vector_length) {
  for(int i=0;i<vector_length;i++) {
  	vector[i] = i;
  }
	return vector;  
}

void print_vector(int * vector, int vector_length) {
	cout << "---------------" << endl;
	cout << "VECTOR" << endl;
	cout << "---------------" << endl;
  cout << '[';
  for(int i=0;i<vector_length;i++) {
  	cout << vector[i] << " ";
  }
  cout << ']';
	cout << endl;
	cout << "---------------" << endl;
}

int * initialize_primary_index(int * primary_index, 
															 int primary_index_lenght, int * vector,
															 int gap) {
	int j=0;
	for(int i=0;i<primary_index_lenght;i++) {
		primary_index[i] = vector[j];
		j +=gap;
	}
}

void print_primary_index(int * primary_index, int primary_index_length) {
	cout << "PRIMARY INDEX" << endl;
	cout << "---------------" << endl;
  for(int i=0;i<primary_index_length;i++) {
  	cout << primary_index[i] << endl;
  }
	cout << "---------------" << endl;
}

void print_menu() {
	cout << "---------------" << endl;
	cout << "PRINT A VALUE TO SEARCH" << endl;
	cout << "---------------" << endl;
}
