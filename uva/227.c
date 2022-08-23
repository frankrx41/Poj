#include <stdio.h>

int main()
{
    int n = 1;
    for(;;)
    {
        for(;;)
        {
            char ch;
            ch = getchar(); /* \n */
            if(ch != '\n')
            {
                ungetc(ch, stdin);
                break;
            }
        }
        char ch = getchar();
        if( ch == 'Z' )break;
        else ungetc(ch, stdin);
        if(n>1) printf("\n");

        char a[5][5];
        int i;
        int pi, pj;
        for(i=0; i<5; i++)
        {
            int j;
            for(j=0; j<5; j++)
            {
                a[i][j] = getchar();
                if( a[i][j] == ' ' || a[i][j] == '\n')
                {
                    pi = i;
                    pj = j;
                    if( a[i][j] == '\n' ) ungetc('\n', stdin);
                }
                /*printf("[%c]", a[i][j]);*/
            }
            for(;;)
            {
                ch = getchar(); /* \n */
                if(ch == '\n')break;
            }
        }
        printf("Puzzle #%d:\n", n++);


        /*for(i=0; i<5; i++)
        {
        printf("%c %c %c %c %c\n", a[i][0], a[i][1], a[i][2], a[i][3], a[i][4]);
        }*/

        /*
        * i0,j0    i0,j1
        * i1,j0    i1,j1
        */

        int has_no = 0;
        for(;;)
        {
            char ch = getchar();
            if( ch == '0')
            {
                break;
            }
            else
            {
                if( has_no )continue;
                switch(ch)
                {
                case 'A':
                {
                    if( pi == 0 )has_no = 1;
                    a[pi][pj] = a[pi-1][pj];
                    a[--pi][pj] = ' ';
                    break;
                }
                case 'B':
                {
                    if( pi == 4 )has_no = 1;
                    else a[pi][pj] = a[pi+1][pj];
                    a[++pi][pj] = ' ';
                    break;
                }
                case 'L':
                {
                    if( pj == 0 )has_no = 1;
                    else a[pi][pj] = a[pi][pj-1];
                    a[pi][--pj] = ' ';
                    break;
                }
                case 'R':
                    if( pj == 4 )has_no = 1;
                    else a[pi][pj] = a[pi][pj+1];
                    a[pi][++pj] = ' ';
                    break;
                case '\n':
                case ' ':
                    continue;
                default:
                    has_no = 1;
                }
            }

            /*printf("---\n");
            int i;
            for(i=0; i<5; i++)
            {
            printf("%c %c %c %c %c\n", a[i][0], a[i][1], a[i][2], a[i][3], a[i][4]);
            }*/
        }

        if( has_no )
        {
            printf("This puzzle has no final configuration.\n");
        }
        else
        {
            int i;
            for(i=0; i<5; i++)
            {
                printf("%c %c %c %c %c\n", a[i][0], a[i][1], a[i][2], a[i][3], a[i][4]);
            }
        }
    }
    return 0;
}
