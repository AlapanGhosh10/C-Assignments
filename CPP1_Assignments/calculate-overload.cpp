#include<bits/stdc++.h>
using namespace std;

void calculate(int m) {
	bool prime = true;
	for(int i = 2 ; i * i <= m ; i++) 
			if(m % i == 0) {
				cout << m << " is not a Prime Number." << endl;
				return;
			}
	cout << m << " is a Prime Number." << endl;
}

void calculate(int m, char ch) {
	if(ch == 'r') {
		int rem, rev = 0;
		while(m > 0) {
			rem = m % 10;
			m /= 10;
			rev = rev * 10 + rem;
		}
		cout << "The reverse is: " << rev << endl;
	} else {
		calculate(m);
	}
}

int main() {
	int m;
	char ch;
	do {
		cout << "Enter number with more than 1 digit: ";
		cin >> m;
	} while(m < 10);
	do {
		cout << "Enter choice r or p: ";
		cin >> ch;
	} while(ch != 'p' && ch != 'r');
	calculate(m, ch);
	return 0;
}