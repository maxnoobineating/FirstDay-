#include<iostream>
using namespace std;
double price[] = { 55.39, 109.23, 48.29, 81.59, 81.58, 105.53, 94.45, 12.24 };
const int capital = 100;
extern const char* text();
double best_benifit(int c = 0) {
	int size = sizeof(price) / sizeof(double);
	while (c<size) {
		int i = c;
		while (i<size) {
			if (price[i] >= price[i + 1]) {
				if (i != c)
					return ((price[i] - price[c]) / price[c]) * capital + best_benifit(i + 1);
				break;
			}
			i++;
		}
		c = i + 1;
	}
	return 1;
}
int main() {
	cout << capital + best_benifit()
		<< endl;
	cout<<sizeof(long long)<<endl;
	int g = 15;
	const (int*) a = &g;
	*a = 16;
	return 0;
}