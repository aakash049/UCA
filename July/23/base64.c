#include <stdio.h>

int main(){
    int index = 0;
    char encoderArray[64];
    for(char x = 'A'; x <= 'Z'; x++,index++)
        encoderArray[index] = x;
    for(char x = 'a'; x <= 'z'; x++,index++)
        encoderArray[index] = x; 
    for(char x = '0'; x <= '9'; x++,index++)
        encoderArray[index] = x;
    encoderArray[index] = '/';
    // PENDING    
}
