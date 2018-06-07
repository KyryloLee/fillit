#include <stdio.h>
#include "libft.h"

void    swap(char **x1, char **x2)
{
    char *x;

    x = *x1;
    *x1 = *x2;
    *x2 = x;
}

void per(char **arr, int st, int ls)
{
    int i;
    int k;

    i = 0;
    k = 0;
    if(st == ls)
    {
        while(k < ls)
            printf("%s ",arr[k++]);
        printf("\n");
    }
    else
    {
        i = st;
        while(i < ls)
        {
            swap(arr + st, arr + i);
            per(arr, st + 1, ls);
            swap(arr + st, arr + i);
            i++;
        }
    }
}

int main()
{
    //int arr[]={1,2,3,4,5};
    int st=0;
    int ls=3;
    char **input;

    input = (char**)malloc(sizeof(char*) * 3);
    input[0] = ft_strdup("a");
    input[1] = ft_strdup("b");
    input[2] = ft_strdup("c");
    per(input,st,ls);
}
