#include <iostream>
#include "templateprac.h"

using namespace std;

class Node {
	public:
		int data;
		Node *next;

		Node(int a) {
			this->data=data;
			next=NULL;
		}
};
template<typename t>
t add(t x, t y) {
std::cout<<"sum is: "<<(x+y)<<std::endl;
return x+y;
}
template<typename t>
t max(t x, t y) {
	std::cout<<typeid(t).name()<<std::endl;
	return x>y?x:y;
}
/*template<typename t>
t max(t* ptr, int size) {
	t maxi=ptr[0];
	for (int i = 1; i < size; i++) {
	if(maxi<ptr[i]) maxi=ptr[i];
	}
	return maxi;
}*/
template char max(char x, char y);

template<> const char* max<const char*>(const char* x, const char* y) {
	std::cout<<"Maxconst char*()"<<std::endl;
	int a=strcmp(x,y);
	return a > 0 ? x : y;

}

template<int size>

void print() {
char buffer[size];

cout<<size<<endl;

}


/*template<typename t>
t asum(t* ptr, int size) {
	t sum = 0;
	for (int i = 0; i < size; i++) {
		sum += ptr[i];
	}
	std::cout << "Sum: " << sum << std::endl;
	return sum;
}*/

template<typename t, int size>
t asum(t (&ref)[size]) {
	t sum = 0;
	for (int i = 0; i < size; i++) {
		sum += ref[i];
	}
	std::cout << "Sum: " << sum << std::endl;
	return sum;
}

int main() {
int arr[]={1,2,35};
int sum=asum(arr);
const char* a = {"A"};
const char* b={"B"};
auto s=max<const char*>(a,b);
cout<<s<<endl;

print<3>();
return 0;

}