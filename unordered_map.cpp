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
