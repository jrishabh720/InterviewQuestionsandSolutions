    #include<stdio.h>
    int main()
    {
        int x;
        printf("Enter The Size of Array : ");
        scanf("%d",&x);
        int array[x-1],i ;
        printf("Enter The Value of Array : \n");
          for( i = 0 ; i <= x-1 ; i++)
          {
              printf("Array[%d] = ",i);
              scanf("%d",&array[i]);
          }
        int left[x-1] , right[x-1];
        left[0] = 1 ;
        right[x-1] = 1 ;
          for( i = 1 ; i <= x-1 ; i++)
          {
              left[i] = left[i-1] * array[i-1];
          }
        printf("\nThis is Multiplication of array[i-1] and left[i-1]\n");
          for( i = 0 ; i <= x-1 ; i++)
          {
            printf("Array[%d] = %d , Left[%d] = %d\n",i,array[i],i,left[i]);
          }
          for( i = x-2 ; i >= 0 ; i--)
          {
              right[i] = right[i+1] * array[i+1];
          }
       printf("\nThis is Multiplication of array[i+1] and right[i+1]\n");
          for( i = 0 ; i <= x-1 ; i++)
          {
            printf("Array[%d] = %d , Right[%d] = %d\n",i,array[i],i,right[i]);
          }
        printf("\nThis is Multiplication of Right[i] * Left[i]\n");
          for( i = 0 ; i <= x-1 ; i++)
          {
              printf("Right[%d] * left[%d] = %d * %d = %d\n",i,i,right[i],left[i],right[i]*left[i]);
          }
        return 0 ;
    }
