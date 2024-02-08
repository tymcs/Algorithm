#include<stdio.h>
int max(int a,int b);
int main()
{
    int m,n;
    int wt[10];
    int p[10];
    int k[10][10];

    printf("\nEnter the number of item: ");
    scanf("%d",&n);

    printf("\nEnter the weight : ");
    scanf("%d",&m);

    printf("\nEnter the weight of each item : ");
    for(int i = 1 ; i <= n; i++ )
    {
        scanf("%d",&wt[i]);

    }
    printf("\nEnter the corresponding profit for each item: ");
    for(int i = 1 ; i <=n ;i++)
    {
        scanf("%d",&p[i]);
    }

    for(int i = 0 ; i <= n ;i++ )
    {
        for(int j = 0 ; j <= m; j++)
        {
            if(i == 0 || j == 0)
            k[i][j] = 0;

            else if(wt[i] <= j)
            {
                k[i][j] = max(p[i] + k[i - 1][j - wt[i]],k[i - 1][j]);
            }

            else
            {
                k[i][j] = k[i - 1][j]; 
            }
        }
    }

    printf("\nMaximum profit : %d",k[n][m]);

   

    return 0;
}
 int max(int a, int b)
    {
        if(a>b)
        return a;
        else 
        return b;
    }