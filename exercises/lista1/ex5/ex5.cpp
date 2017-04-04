#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int * initialize_vector(int * vector, int length); 
void print_vector(int * vector, int length);
void print_menu();

int main() {

	const int length = 100;
	int vector[length]; 

	initialize_vector(vector, length);
	print_vector(vector, length);

	print_menu();
	int value=0;
	cin >> value;

	return 0;
}

int * initialize_vector(int * vector, int length) {      
  for(int i=0;i<length;i++) {                            
    vector[i] = i;                                              
  }                                                             
  return vector;                                                
} 

void print_vector(int * vector, int length) {
	cout << "---------------" << endl;
	cout << "VECTOR" << endl;
	cout << "---------------" << endl;
  cout << '[';
  for(int i=0;i<length;i++) {
  	cout << vector[i] << " ";
  }
  cout << ']';
	cout << endl;
	cout << "---------------" << endl;
}

void print_menu() {    
  cout << "---------------" << endl;    
  cout << "PRINT A VALUE TO SEARCH" << endl;    
  cout << "---------------" << endl;    
}
