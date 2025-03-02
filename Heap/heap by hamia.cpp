
#include "minheap.h"
#include "maxheap.h"
int main(){
	maxheap m;
	m.insert(5);
	m.insert(9);
	m.insert(1);
	m.insert(12);
	m.insert(3);
	m.insert(0);
	m.insert(-8);
	m.insert(90);
	m.print();
	m.heapsort();
}
