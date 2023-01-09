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
	Complex sum(Complex n) {
		Complex s;
		s.real = real + n.real;
		s.imag = imag + n.imag;
		return s;
	}
	void show() {
		cout << "Real: " << real << ", Imaginary: " << imag << endl;
	}
};

int main() {
	Complex n1(10);
	Complex n2(20, 30);
	Complex n3 = n1.sum(n2);
	n1.show();
	n2.show();
	n3.show();
}