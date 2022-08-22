
#include <stdio.h>

int main()
{
    int n;
    scanf("%d\n", &n);

    for(;n--;)
    {
        int c = 0;
        int s = 0;
        for(;;)
        {
            char ch = getchar();
            if( ch != '\n' )
            {
                if( ch == 'O' )
                {
                    c++;
                    s += c;
                }
                else
                {
                    c=0;
                }
            }
            else
            {
                printf("%d\n", s);
                break;
            }
        }
    }
}
