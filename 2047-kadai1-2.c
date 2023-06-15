#include <stdio.h>

int main(){
    int i,j;
    for(i=1;i<=7;i++){
        int x=i;
        for(j=1;j<=i;j++){
            int y=j;
            printf("mod(%d,%d) = %d\n",x,y,x%y);
        }
        printf("---------------------\n");
    }
    return 0;
}
