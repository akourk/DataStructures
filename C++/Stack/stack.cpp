
#include <iostream>
#include "Stack.h"
#include <assert.h>
using namespace std;

int main() {
	Stack<int> numbers;
	int x, n;
	cout<<"Enter a number:";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"x:";
		cin>>x;
		numbers.push(x);
	}
	cout<<numbers.stop();
	return 0;
}
