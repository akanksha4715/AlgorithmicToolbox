#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}
int gcd(int a,int b){
	int num1,num2,rem;
 	if(a>b){num1=a;num2=b;}
 	else {num1=b;num2=a;}
 	while(num2!=0){
 	rem=num1%num2;
 	num1=num2;
 	num2=rem;
 	
 	
 	}
 	return num1;


}
int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}
