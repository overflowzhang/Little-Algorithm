#include <stdio.h>  
#include <stdlib.h>  
int f(int n);  
int main()  
{  
    int n,t;  
    scanf("%d",&n);  
    t=f(n);  
    printf("%d",t);  
    return 0;  
}  
int f(int n)  
{  
    long s;  
    if(n==1)  
        s=1;  
    else if(n==2)  
        s=2;  
    else  
        s=f(n-1)+f(n-2);  
    return s;  
}  