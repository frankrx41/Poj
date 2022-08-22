#include <stdio.h>
#include <math.h>

int main()
{
    int a;
    int i;
    int n;
    scanf("%d", &n);

    int l = 1 + (int)log10(a);
    for(;n-- && scanf("%d", &a); )
    {
        for(i=a - 9*l; i<a; i++)
        {
            if( i/1000000 + (i/100000)%10 + (i/10000)%10 + (i/1000)%10 + (i/100)%10 + (i/10)%10 + i%10 + i == a )
            {
                printf("%d\n", i);
                break;
            }
        }
        if( i == a )
        {
            printf("0\n");
        }
    }
}