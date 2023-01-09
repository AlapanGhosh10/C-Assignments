#include<bits/stdc++.h>
using namespace std;

class Shape {
protected:
	double pi = 3.141592653589793238;
};

class Circle : public Shape {
private:
	int radius;
public:
	Circle() {
		cout << "Enter radius of circle: ";
		cin >> radius;
	}
	void getArea() {
		cout << "Area is: " << pi * radius * radius << " units." << endl;
	}
};

int main() {
	Circle c1;
	c1.getArea();
	return 0;
}