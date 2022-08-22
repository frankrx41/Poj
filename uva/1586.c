#include <ctype.h>
#include <stdio.h>

int main()
{
    int n;
    scanf("%d\n", &n);

    float W[256];
    W['C'] = 12.01;
    W['H'] = 1.008;
    W['O'] = 16.00;
    W['N'] = 14.01;

    for(;n--;)
    {
        float pw = 0;
        int hope_digit = 0;
        float w = 0;
        for(;;)
        {
            char ch = getchar();
            if( ch == '\n' )
            {
                if( hope_digit )
                {
                    w += pw;
                }
                printf("%.3f\n", w);
                break;
            }

            if( isalpha(ch) )
            {
                if( hope_digit )
                {
                    w += pw;
                }
                hope_digit = 1;
                pw = W[ch];
            }
            if( isdigit(ch) && hope_digit )
            {
                hope_digit = 0;
                char s[256];
                s[0] = ch;
                char cs;
                int i = 1;
                for(;;)
                {
                    cs = getchar();
                    if( !isdigit(cs) )
                    {
                        ungetc(cs, stdin);
                        break;
                    }
                    else
                    {
                        s[i++] = cs;
                    }
                }
                s[i] = 0;
                int num;
                sscanf(s, "%d", &num);
                w += pw*num;
            }
        }
    }
}
