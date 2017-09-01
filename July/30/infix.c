#include <stdio.h>
#include <string.h>

int stack[30];
int top = -1;

void push(int x){
    stack[++top] = x;
}

void pop(){
    if(top >= 0)
        top--;
}

int isEmpty(){
    return (top == -1);
}

char peek(){
    if(!isEmpty())
    return stack[top];
    return '$';
}

int isAlpha(char x){
    if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z')) return 1;
    return 0;
}



int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}

void cal(char *str, char *res){
    int len = strlen(str), in = -1;
    for(int i = 0; i < len; i++){
        if(isAlpha(str[i])) res[++in] = str[i];
        else if(str[i] == '(')
            push(str[i]);
        else if(str[i] == ')'){
            while(!isEmpty() && peek() != '('){
                res[++in] = peek();
                pop();
            }
            pop();
        }
        else{
            while(!isEmpty() && Prec(str[i]) <= Prec(peek()) ){
                res[++in] = peek();
                pop();
            }
            push(str[i]);
        }
    }
    while(!isEmpty()){
        res[++in] = peek();
        pop();
    }
    res[++in] = '\0';
}
 

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
	    char str[30], res[30];
	    scanf("%s", str);
	    cal(str, res);
	    printf("%s\n", res);
	    strcpy(res, "");
	}
	return 0;
}