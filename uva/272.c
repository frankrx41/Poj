#include <stdio.h>

int main()
{
    char ch;
    int s = 1;
    for(;ch = getchar();)
    {
        if( ch == EOF )
            return 0;
        if( ch == '"' )
        {
            printf("%s", s++%2 ? "``" : "''");
        }
        else
        {
            putchar(ch);
        }
    }
}
