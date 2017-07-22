#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[4][3] = {{1, 1, 1}, {0, 1, 1}, {1, 1, 0}, {1, 1, 1}};
    int col1=0,row1=0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            if(arr[i][j] == 0){
                if(i == 0)
                    row1 = 1;
                if(j == 0)
                    col1 = 1;
                arr[i][0] = -1;
                arr[0][j] = -1;
                break;
            }
        }
    }
    for(int i = 1; i < 4; i++){
        for(int j = 1; j < 3; j++){
            if(arr[i][0] == -1 || arr[0][j] == -1 )
                arr[i][j] = 0;
        }
    }
    if(row1 == 1){
        for(int i=0;i<3;i++)
            arr[0][i] = 0;
    }
    if(col1 == 1){
        for(int i=0;i<4;i++)
            arr[i][0] = 0;
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            if(arr[i][j] == -1)
                arr[i][j] = 0;
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
