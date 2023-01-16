#include<bits/stdc++.h>
using namespace std;

class Number_List {
private:
	int *arr;
	int index;
	int size;
public:
	Number_List(int size) {
		this->size = size - 1;
		arr = new int[size];
		index = 0;
	}
	void add(int n) {
		if(index <= size) {
			arr[index++] = n;
			for(int i = index - 1 ; i > 0 ; i--) {
				if(arr[i] < arr[i - 1])
					swap(arr[i], arr[i - 1]);
			}
			cout << n << " added to the array." << endl;
		} else
			cout << "Array is full." << endl;
	}
	void display() {
		cout << "The array elements are: " << endl;
		for(int i = 0 ; i < index ; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	void getMax() {
		if(index == 0)
			cout << "Array is empty." << endl;
		else
			cout << "The maximum elements is: " << arr[index - 1] << endl;
	}
	void getMin() {
		if(index == 0)
			cout << "Array is empty." << endl;
		else
			cout << "The minimum element is: " << arr[0] << endl;
	}
};

int main() {
	int size, n;
	cout << "Enter size for array: ";
	cin >> size;
	Number_List n1(size);
	cout << "Enter elements or x to stop: ";
	while(cin >> n) 
		n1.add(n);
	n1.getMax();
	n1.getMin();
	n1.display();
	return 0;
}