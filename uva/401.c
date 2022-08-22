#include <stdio.h>
#include <string.h>

char mi[256];

int main()
{
    char s[4096];

    mi['A'] = 'A';
    mi['E'] = '3';
    mi['H'] = 'H';
    mi['I'] = 'I';
    mi['J'] = 'L';
    mi['L'] = 'J';
    mi['M'] = 'M';
    mi['O'] = 'O';
    mi['S'] = '2';
    mi['T'] = 'T';
    mi['U'] = 'U';
    mi['V'] = 'V';
    mi['W'] = 'W';
    mi['X'] = 'X';
    mi['Y'] = 'Y';
    mi['Z'] = '5';
    mi['1'] = '1';
    mi['2'] = 'S';
    mi['3'] = 'E';
    mi['5'] = 'Z';
    mi['8'] = '8';

    for(; ~scanf("%s", s); )
    {
        int l = strlen(s);
        int i;

        int is_re = 1;
        for(i=0; i<l/2; i++)
        {
            if(s[i] != s[l-i-1])
            {
                is_re = 0;
                break;
            }
        }

        int is_mi = 1;
        for(i=0; i<l/2+1; i++)
        {
            if(s[i] != mi[s[l-i-1]])
            {
                is_mi = 0;
                break;
            }
        }

        printf("%s -- ", s);
        if(is_re && is_mi)
        {
            printf("is a mirrored palindrome.\n");
        }
        else if(is_re)
        {
            printf("is a regular palindrome.\n");

        }
        else if(is_mi)
        {
            printf("is a mirrored string.\n");

        }
        else
        {
            printf("is not a palindrome.\n");
        }
        printf("\n");
    }
}
