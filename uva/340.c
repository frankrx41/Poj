#include <stdio.h>

int main()
{
    int count = 1;

    for(count = 1;; count++)
    {
        int n;
        scanf("%d", &n);
        if(n == 0)
        {
            return 0;
        }
        int i;
        int a[10000];
        int e[10] = {0};
        for(i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
            e[a[i]] += 1;
        }
        printf("Game %d:\n", count);

        int b[10000];
        for(;;)
        {
            int g[10];
            for(i=0; i<=9; i++)
            {
                g[i] = e[i];
            }
            int x = 0, y = 0;
            for(i=0; i<n; i++)
            {
                scanf("%d", &b[i]);
                if( b[i] == 0 )
                {
                    if( i == n-1 )
                    {
                        goto e;
                    }
                    else
                    {
                        continue;
                    }
                }
                if(b[i] == a[i])
                {
                    x++;
                    g[b[i]]--;
                    if( g[b[i]] < 0 )
                    {
                        g[b[i]]++;
                        y--;
                    }
                }
                else
                {
                    if(g[b[i]])
                    {
                        y++;
                        g[b[i]]--;
                    }
                }
            }
            printf("    (%d,%d)\n", x, y);
        }
e:
        ;
    }
}
