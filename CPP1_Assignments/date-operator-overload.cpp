#include<bits/stdc++.h>
using namespace std;

class Time {
	private:
		int h, m, s;
	public:
		friend istream &operator >> ( istream &input, Time &time ) 
		{
        	input >> time.h; 
        	input.ignore();
        	input >> time.m;
        	input.ignore();
        	input >> time.s; 
        	return input;
		}
		friend ostream &operator << ( ostream &output, Time &time ) 
		{
        	output << time.h << ":" << time.m << ":" << time.s; 
        	return output;
		}
		bool operator == ( Time &time) {
			if(h == time.h && m == time.m && s == time.s)
					return true;
			return false;
		}
		Time operator + (Time &time) {
			Time t;
			bool hold;
			t.s = s + time.s;
			if(t.s >= 60) {
				t.s -= 60;
				hold = true;
			}
			t.m = m + time.m;
			if(hold)
				t.m++;
			hold = false;
			if(t.m >= 60) {
				t.m -= 60;
				hold = true;
			}
			t.h = h + time.h;
			if(hold)
				t.h++;
			if(t.h >= 24)
				t.h -= 24;
			return t;
		}
};

int main() {
	Time t1, t2, t3;
	cin >> t1 >> t2;
	t3 = t1 + t2;
	if(t1 == t2)
		cout << "Equal" << endl;
	else
		cout << "Not Equal" << endl;
	cout << t3;
	return 0;
}