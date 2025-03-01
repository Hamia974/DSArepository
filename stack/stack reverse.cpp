void reversed(Stack<string> &s, Stack<string> &reverse){
	Stack<string> s1(3);
	Stack<string> s2(3);
	while (!s.isempty()){
		s1.push(s.pop());
	}
	while (!s1.isempty()){
		s2.push(s1.pop());
	}
	while (!s2.isempty()){
		reverse.push(s2.pop());
	}

}
int main(){
	Stack<string> s(3);
	s.push("BOOK A");
	s.push("Book B");
	s.push("Book C");
	s.display();
	Stack<string> reverse(3);
	reversed(s, reverse);
	reverse.display();
}
