#include <iostream>
#include <cstdio>

using namespace std;

typedef struct list {
	int key;
	int registry;
} list;

list * initialize_list(list * li, int lenght);

int main() {

	const int length = 100;
	list li[length];
	initialize_list(li, length);

	return 0;
}

list * initialize_list(list * li, int length) {
	int k = 100;
	for(int i=0;i<length;i++) {
		li[i].key = i;
		li[i].registry = k+2;
	}	
	return li;
}
