#include <stdio.h>
#include "seqstack.h"
#include <string.h>

int kuohao(char str[])
{
    seqstack s;
    init(&s);
    for (int i = 0; i < strlen(str); i++)
    {
        char c = str[i];
        if (c == '(' || c == '[' || c == '{')
        {
            push(&s, c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (empty(s))
            {
                return 0;
            }
            char v = pop(&s);
            if (v == '(' && c == ')')
            {
                continue;
            }
            else if (v == '[' && c == ']')
            {
                continue;
            }
            else if (v == '{' && c == '}')
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            continue;
        }
        //printf("%c\n",str[i]);
    }
    if (empty(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

main()
{
    char str[100];
    printf("ÇëÊäÈëÀ¨ºÅ£º");
    //scanf("%s",str);
    gets(str);
    int res = kuohao(str);
    if (res)
    {
        printf("ÕýÈ·!");
    }
    else
    {
        printf("´íÎó!");
    }
}
