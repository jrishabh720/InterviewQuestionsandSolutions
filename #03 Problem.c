#include <stdio.h>
#include <stdlib.h>
int separate (int arr[], int size)
{
    int j = 0, i , temp;
    for(i = 0; i < size; i++)
    {
    if (arr[i] <= 0)
    {
        /*Here we using bitwise operator to swap the
        numbers instead of using the temp variable*/
         arr[j] = arr[j]^arr[i];
         arr[i] = arr[j]^arr[i];
         arr[j] = arr[j]^arr[i];
         j++;
    }
    }
    printf("First We Separate the negetive and positive number \n");
    for( i = 0 ; i <size ; i++)
    {
        printf("Array[%d] = %d\n",i,arr[i]);
    }
    return j;
}
int findMissingPositive(int arr[], int size)
{
printf("Remove the negative numbers from array\n");
int i;
for( i = 0 ; i <size ; i++)
{
        printf("Array[%d] = %d\n",i,arr[i]);
}
for(i = 0; i < size; i++)
{
    if(abs(arr[i]) - 1 < size && arr[ abs(arr[i]) - 1] > 0)
    arr[ abs(arr[i]) - 1] = -arr[ abs(arr[i]) - 1];
    /*
    How these work :
    [
    if(abs(arr[i]) - 1 < size && arr[ abs(arr[i]) - 1] > 0)
    arr[ abs(arr[i]) - 1] = -arr[ abs(arr[i]) - 1];]
    before: arr = { 7, 3, 4, 5, 5, 3, 2}
i == 0: arr[0] = 7
        arr[7-1] is 2 > 0 ~> negate
        arr = { 7, 3, 4, 5, 5, 3, -2}
i == 1: arr[1] = 3
        arr[3-1] is 4 > 0 ~> negate
        arr = { 7, 3, -4, 5, 5, 3, -2}
i == 2: arr[2] is -4 ~> abs for indexing
        arr[4-1] is 5 > 0 ~> negate
        arr = { 7, 3, -4,-5, 5, 3, -2}
i == 3: arr[3] is -5 ~> abs for indexing
        arr[5-1] is 5 > 0 ~> negate
        arr = { 7, 3, -4, -5, -5, 3, -2}
i == 4: arr[4] is -5 ~> abs for indexing
        arr[5-1] is -5 < 0 ~> print abs(-5) as duplicate
i == 5: arr[5] is 3
        arr[3-1] is -4 < 0 ~> print abs(3) as duplicate
i == 6: arr[6] is -2 ~> abs for indexing
        arr[2-1] is 3 > 0 ~> negate
        arr = { 7, -3, -4, -5, -5, 3, -2}

        indices of positive entries: 0, 5 ~> 1 and 6 not in original array
        indices of negative entries: 1, 2, 3, 4, 6 ~> 2, 3, 4, 5, 7 in original array*/
}
for(i = 0; i < size; i++)
    if (arr[i] > 0)
    {
    return i+1;
    }
return size+1;
}
int findMissing(int arr[], int size)
{
int j = separate (arr, size);
// Here arr can shift the positive number over the negative numbers
return findMissingPositive(arr+j, size-j);
}
int main()
{
int size ;
printf("Enter the Value of Size of Array : ");
scanf("%d",&size);
int arr[size];
printf("Enter the values :\n");
for( int i = 0 ; i < size ; i++)
{
    printf("Array[%d] = ",i);
    scanf("%d",&arr[i]);
}
int missing = findMissing(arr,size);
printf("The smallest positive missing number is %d ", missing);
return 0;
}
