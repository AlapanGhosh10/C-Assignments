#include<bits/stdc++.h>
using namespace std;

class Triangle {
private:
	double a, b, c, area, peri;
public:
	Triangle() {
		cout << "Enter three sides of the triangle: ";
		cin >> a >> b >> c;
	}
	void calculateArea();
	void calculatePerimeter();
	void printData() {
		cout << "The three sides are: " << a << ", " << b << ", " << c << "." << endl;
		cout << "The perimeter is: " << peri << " units." << endl;
		cout << "The area is: " << area << " units." << endl;
	}
};

void Triangle :: calculateArea() {
	int s = (a + b + c) / 2;
	area = sqrt(s * (s - a) * (s - b) * (s - c));
}

void Triangle :: calculatePerimeter() {
	peri = a + b + c;
}

int main() {
	Triangle t1;
	t1.calculatePerimeter();
	t1.calculateArea();
	t1.printData();
}