#include <stdio.h>
#include <string.h>

int is_i_small_than_j(int i, int j, char* s, int l)
{
    int x;
    for(x = 0; x<l; x++)
    {
        char ci, cj;
        ci = s[x+i];
        cj = s[x+j];
        if(ci < cj)
        {
            return 1;
        }
        if( ci > cj )
        {
            return 0;
        }
    }
    return 0;
}

int main()
{
    char a[4096] = "";

    int n;
    scanf("%d", &n);

    for(;n-- && scanf("%s", a);)
    {
        char s[4096] = "";
        strcat(s, a);
        strcat(s, a);

        int l = strlen(a);
        int i = 0, j;

        for(j=i+1; j<l; j++)
        {
            if( !is_i_small_than_j(i, j, s, l) )
            {
                i = j;
            }
        }

        int x;
        for(x = 0; x<l; x++)
        {
            char c = s[i+x];
            printf("%c", c);
        }
        printf("\n");
    }
}
