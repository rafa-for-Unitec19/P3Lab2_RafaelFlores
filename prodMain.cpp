#include <iostream>
			

int fastEuclides(int a, int b){
	int r = a % b;
	return r ? fastEuclides(b, r) : b;
}

int main(){
	
	return 0;	
}
