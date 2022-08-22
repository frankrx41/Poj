#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);

    for(;n--;)
    {
        char s[4096];
        scanf("%s", s);
        int len = strlen(s);
        int i;
        
        for(i=1; i<len; i++)
        {
            if(len%i == 0)
            {
                if( strncmp(s, s+i, i) == 0 )
                {
                    int j;
                    for(j=2;i*j+i<=len;j++)
                    {
                        if(strncmp(s, s+i*j, i) != 0)
                        {
                            break;
                        }
                    }

                    if(i*j+i > len)
                    {
                        printf("%d\n", i);
                        goto e;
                    }
                }
            }
        }
        printf("%d\n", len);
e:
        if( n != 0 )printf("\n");
    }
}
