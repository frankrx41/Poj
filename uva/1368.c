/*
*
* Fix:
*
* a[1280][4]
* s[1280]
*/

#include <assert.h>
#include <stdio.h>

int gx[128];
int gy[4];

int main()
{
    gx['A'] = 0;
    gx['C'] = 1;
    gx['G'] = 2;
    gx['T'] = 3;

    gy[0] = 'A';
    gy[1] = 'C';
    gy[2] = 'G';
    gy[3] = 'T';

    int T;
    scanf("%d", &T);
    for(;T--;)
    {
        int m,n;
        scanf("%d %d\n", &m, &n);

        int a[1280][4] = {0};

        {
            int i;
            for(i=0; i<m; i++)
            {
                char s[1280];
                gets(s);
                int j;
                for(j=0; j<n; j++)
                {
                    char ch = s[j];
                    assert(ch == 'A' || ch == 'C' || ch == 'T' || ch == 'G');
                    a[j][gx[ch]]++;
                }
            }
        }

        {
            int j;
            int dis = 0;
            for(j=0; j<n; j++)
            {
                int k;
                int mk = 3;
                for(k=2; k>=0; k--)
                {
                    if(a[j][k] >= a[j][mk])
                    {
                        dis += a[j][mk];
                        mk = k;
                    }
                    else
                    {
                        dis += a[j][k];
                    }
                }
                
                printf("%c", gy[mk]);
            }
            printf("\n");
            printf("%d\n", dis);
        }
    }
}
