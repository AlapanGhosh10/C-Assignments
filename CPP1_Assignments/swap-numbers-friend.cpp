#include<bits/stdc++.h>
using namespace std;

class Num {
private:
	int val;
public:
	Num() {
		cout << "Enter a number: ";
		cin >> val;
	}
	void displayNum() {
		cout << "The number is: " << val << endl;
	}
	friend class Swap;
};

class Swap {
public:
	void swapNums(Num &n1, Num &n2) {
		n1.val = n1.val + n2.val;
		n2.val = n1.val - n2.val;
		n1.val = n1.val - n2.val;
	}
};

int main() {
	Num n1, n2;
	Swap sw;
	sw.swapNums(n1, n2);
	n1.displayNum();
	n2.displayNum();
}