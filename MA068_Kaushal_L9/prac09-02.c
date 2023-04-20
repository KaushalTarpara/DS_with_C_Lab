#include <stdio.h>
int linearSearch(int arr[],int n,int key){

    int i,count=0;
    for(i=0; i<n; i++)
    {   
        if(key==arr[i])
        {
                printf("%d is itration Done in  Linear Search.",i+1);
                return i;
        }
    }
    printf("%d is itration Done in  Linear Search.",i);
    return -1;;
}

void bubbleSort(int arr[],int n){

    for(int i=0; i<n; i++)
        for(int j=0; j<i; j++)
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
   
}

int binarySearch(int arr[],int n,int key){

    int l=0;
    int r=n-1;
    int count=0;    
    
    while (l <= r) {
        //int m = l + (r - l) / 2; 
        int m=(r+l)/2;
        count++;
        if (arr[m] == key)
        {
            printf("%d is itration Done in Binary Search.",count);
            return m; 
        }
        
        if (arr[m] < key)
            l = m + 1;
        else
            r = m - 1;
    } 
    printf("%d is itration Done in Binary Search.",count);
    return -1;
}
int main(){

    int n;
    
    //Create Array
    printf("\nEnter Number of element :");
    scanf("%d",&n);

    int arr[n];
    for(int i=0; i<n; i++){
        printf("\nEnter Value for %d element :",i);
        scanf("%d",&arr[i]);
    }

    int Lkey;
    printf("\nEnter Value for Linear search :");
    scanf("%d",&Lkey);

    int FoundIndexL=linearSearch(arr,n,Lkey);
    if(FoundIndexL==-1)
        printf("\n %d not Found in Array",Lkey);
    else
        printf("\n %d Found %d index in Array",Lkey,FoundIndexL);


    int Bkey;
    
    printf("\n\nEnter Value for Binary search :");
    scanf("%d",&Bkey);

    bubbleSort(arr,n);
    printf("\nArray is sorted\n");
    
    int FoundIndexB=binarySearch(arr,n,Bkey);
    if(FoundIndexB==-1)
        printf("\n %d not Found in Array",Bkey);
    else
        printf("\n %d Found %d index in Array",Bkey,FoundIndexB);

    //Print array
    printf("\n[");
    for(int i=0; i<n; i++){
        printf(" %d ,",arr[i]);        
    }
    printf("\b]");

    return 0;
}