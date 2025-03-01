//
//#include "minheap.h"
//#include "maxheap.h"
//int main(){
//	maxheap m;
//	m.insert(5);
//	m.insert(9);
//	m.insert(1);
//	m.insert(12);
//	m.insert(3);
//	m.insert(0);
//	m.insert(-8);
//	m.insert(90);
//	m.print();
//	m.heapsort();
//}
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;
int main(){
	unordered_map<string, int> m;
	string str;
	while (1){
		cin >> str;
		if (str == "stop"){
			break;
		}
		m[str]++;
		
	}
	for (auto x : m){
		cout << x.first << endl;
		cout << x.second << endl;
	}
}