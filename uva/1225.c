/*
* m--
*/

#include <stdio.h>

int main()
{
    int n;
    int m;
    scanf("%d", &m);

    for(;m-- && ~scanf("%d", &n);)
    {
        int c[10] = {0};
        int i;
        for(i=1; i<=n; i++)
        {
            int k=i;
            while(k)
            {
                int k10 = k % 10;
                k /= 10;
                int j;
                for(j=0; j<10; j++)
                {
                    if(k10 == j)
                    {
                        c[j]++;
                        break;
                    }
                }
            }
        }

        int j;
        for(j=0; j<9; j++)
        {
            printf("%d ", c[j]);
        }
        printf("%d\n", c[9]);
    }
}
