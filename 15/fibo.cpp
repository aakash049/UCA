#include <iostream>
#include <cmath>
using namespace std;

int main(void){
  for(int i=0;i<10;i++){
    float x =  ((1.0*pow((1+sqrt(5))/2.0,i) - 1.0*pow((1-sqrt(5))/2.0,i)))/sqrt(5);
    cout << x << endl;
  }
}