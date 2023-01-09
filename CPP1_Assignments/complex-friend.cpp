#include<bits/stdc++.h>
using namespace std;

class Complex {
private:
	int real, imag;
public:
	Complex() {
		real = 0;
		imag = 0;
	}
	Complex(int r) {
		real = r;
		imag = 0;
	} 
	Complex(int r, int i) {
		real = r;
		imag = i;
	}
	void show() {
		cout << "Real: " << real << ", Imaginary: " << imag << endl;
	}
	friend class Operation;
};

class Operation {
public:
	Complex sum(Complex &n1, Complex &n2) {
		Complex s;
		s.real = n1.real + n2.real;
		s.imag = n1.imag + n2.imag;
		return s;
	}
};

int main() {
	Complex n1(10);
	Complex n2(20, 30);
	Operation o1;
	Complex n3 = o1.sum(n1, n2);
	n1.show();
	n2.show();
	n3.show();
}