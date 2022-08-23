/*
 * 1/2 => 2*(.5)=1
 * 1/6 = 0.166667
 *
 *      0.1 6
 *     ________
 *  6 / 1 0
 *        6
 *     -----
 *        4 0
 *        3 6
 *       -----
 *          4
 *
 *
 *      0.1 4 2 8 5 7 
 *     __________________
 *  7 / 1 0
 *        7
 *     -----
 *        3 0
 *        2 8
 *       -----
 *          2 0
 *          1 4
 *          ----
 *            6 0
 *            5 6
 *            ----
 *              4 0
 *              3 5
 *              ----
 *                5 0
 *                4 9
 *                ----
 *                  1 0
 *
 *      0.1 1
 *     ________
 * 43 / 5 0
 *      4 3
 *     -----
 *        7 0
 *        4 3
 *       -----
 *        2 7 0
 *
 *
 *
 *        return 0;
 */

#include <stdio.h>
#include <string.h>

int main()
{
    int a,b;
    for(;scanf("%d %d", &a, &b) == 2;)
    {
        /*printf("%f\n", 1.*a/b);*/
        printf("%d/%d = ", a, b);
        int lplen = 1;
        char s[4096];
        s[0] = 0;
        int loop_start = 0;
        int d=1;
        {
            int mod[3000] = {0};
            for(;;)
            {
                int c;
                if( a < b )
                {
                    if(d==1)
                    {
                        if( s[0] == 0 )strcat(s, "0");
                        strcat(s, ".");
                        mod[a] = d;
                    }
                    a *= 10;
                    d++;
                }
                c = a/b;
                a -= c*b;
                a %= b;
                if(d<52)
                {
                    if(d > 1 && c == 0 && a == 0);
                    else sprintf(s, "%s%d", s, c);
                }
                if(d==52)
                {
                    sprintf(s, "%s%s", s, "...");
                }
                if( a == 0 )
                {
                    if(d==1)
                    {
                        strcat(s, ".");
                    }
                    break;
                }
                if(mod[a])
                {
                    loop_start = mod[a];
                    lplen = d - loop_start;
                    break;
                }
                mod[a] = d;
            }
        }
        int i;
        for(i=0; s[i] != '.' && s[i]; i++)
        {
            printf("%c", s[i]);
        }
        int j;

        for(j=0;s[i]; i++,j++)
        {
            if(loop_start && j==loop_start)printf("(");
            printf("%c", s[i]);
        }
        if(loop_start)printf(")");
        else printf("(0)");
        printf("\n");
        printf("   %d = number of digits in repeating cycle\n\n", lplen);
    }
    return 0;
}
