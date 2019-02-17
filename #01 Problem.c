/* Given a list of numbers and a number k , return weather any two numbers from the list add up to k.
For example, given [10,15,3,7] and k of 17 , return 10 + 7 is 17
Bonus: Can You Do in one pass ? */
#include<stdio.h>
int rec(int i , int j ,int k , int n,int array[])
{
    int sum;
    for( i = 0 ; i<j ;)
    {
        sum = array[i] + array[j];
        if( sum > k)
        {
            j--;
        }else if( sum < k)
        {
            i++;
        }else if( sum == k )
        {
            printf("Value equal to sum of array[%d]  = %d and array[%d] = %d",i,array[i],j,array[j]);
            printf("\n%d+%d=%d",array[i],array[j],k);
            return 1;//True
        }
    }
    return 0;//False
}
int main()
{
    int n ;
    printf("Enter The Value of Number of Arrays = ");
    scanf("%d",&n);
    int array[n],i,j,k,x;
    printf("Enter the Number Which you Want to search in addition of Two Number = ");
    scanf("%d",&x);
    printf("Enter The Value of Array \n");
    for( i = 0 ; i <=n-1;i++)
    {
        printf("Array[%d] = ",i);
        scanf("%d",&array[i]);
    }
    // Here Put Sorting of Array
    for( i = 0 ; i <=n-1;i++)
    {
        for( j = 0 ; j <=n-i-1;j++)
        {
        if( array[j]>array[j+1])
        {
           array[j] = array[j]^array[j+1];
           array[j+1] = array[j]^array[j+1];
           array[j] = array[j]^array[j+1];
        }
        }
    }
    k = x ;
    j = n-1;
    rec(i,j,k,n,array);
    return 0 ;
}
