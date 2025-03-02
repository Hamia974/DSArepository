#include <iostream>
#include <string>
using namespace std;
class Student{
private:
	string* name;
	int score;
	int time;
	int max_size;
	int csize;
	string* newqueue;
public:
	Student(int s = 0){
		name = new string[s];
		score = 0;
		newqueue = new string[s];
		time = 0;
		csize = 0;
		max_size = s;
	}

	bool isfull(){
		return csize == max_size;
	}
	bool isempty(){
		return csize == 0;
	}
	void enqueue(){
		string n;
		cout << "enter student name: ";
		cin >> n;
		name[csize] = n;
		csize++;
	}
	string dequeue_name(){
		if (isempty()) {
			cout << "queue is empty. " << endl;
		}
		else{
			string temp = name[0];
			csize--;
			for (int i = 0; i < csize; i++){
				name[i] = name[i + 1];
				score = rand() % 100;
				time = rand() % 100;
			}
			return temp;
		}
	}
	void enqueue_newqeueue(){

		for (int i = 0; i < max_size; i++){
			newqueue[i] = dequeue_name();
		}
	}
	void display_newqueue(){
		cout << "student names ,score and time are: " << endl;
		for (int i = 0; i < max_size; i++){
			score = rand() % 100;
			time = rand() % 100;
			cout << newqueue[i] << " " << score << " " << time << " ";
			cout << endl;
		}
	}

};
int main(){
	Student s(3);
	int choice;
	do {
		cout << "  Quiz Competition Menu:" << endl;
		cout << "1. Add a student to the waiting queue" << endl;
		cout << "2. Start the quiz and generate scores" << endl;
		cout << "3. Display the scores, names, and time taken by the students" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			if (s.isfull()){
				cout << "queue is full." << endl;
			}
			else{
				for (int i = 0; i < 3; i++){
					s.enqueue();
				}
			}
			break;
		case 2:
			if (s.isempty()) {
				cout << "Waiting queue is empty. No students to process." << endl;
			}
			else{
				s.enqueue_newqeueue();
				cout << "quiz has been started." << endl;
			}
			break;
		case 3:
			cout << "Completed Students:" << endl;
			s.display_newqueue();
			break;
		case 0:
			cout << "Exiting program." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 0);
	return 0;
}
