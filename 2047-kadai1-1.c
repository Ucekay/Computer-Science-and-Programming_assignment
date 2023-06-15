#include <stdio.h>

int main(){
    int i,j;
    for(i=5;2*i-1>0;i--){
        for(j=1;2*j-1<=2*i-1;j++){
            int x=2*i-1,y=2*j-1;
            printf("%d + %d = %d\n",x,y,x+y);
        }
        printf("--------------------\n");
    }
    return 0;
}
