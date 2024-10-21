#include <iostream>
using namespace std;
class Shape {
public:
	virtual void area() = 0;

};
class circle :public Shape {
private:
	int radius;
public:
	circle(int r = 0) {
		radius = r;
	}
	void area() {
		float Area;
		Area = 3.14 * radius * radius;
		cout << "Area of circle is: " << Area << endl;
	}
};
class rectangle :public Shape {
private:
	int length;
	int width;
public:
	rectangle(int l=0,int w=0){
		length = l;
		width = w;
	}
	void area() {
		float Area;
		Area = length * width;
		cout << "Area of rectangle is: " << Area << endl;
	}
};
int main() {
	circle c(5);
	rectangle r(3, 2);
	Shape* s;
	s = &c;
	s->area();
	s = &r;
	s->area();
	return 0;
}