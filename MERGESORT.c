#include<stdio.h>
#include<time.h>
int a[20], n;
void merge(int[],int,int);
void sort(int[],int,int,int);
void main(){
    int i;
    clock_t start, end;
    double time_taken;

    printf("Enter the no. of elements in array: ");
    scanf("%d",&n);

    printf("\nEnter the array elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    start = clock();
    merge(a,0,n-1);
    end = clock();

    time_taken = (double)(end-start)/CLOCKS_PER_SEC;

    printf("The sorted array is:\n");
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    printf("\nTime taken for execution= %f\n", time_taken);
}

void merge(int a[], int low, int high){

    if(low<high){
        int mid = low + (high-low)/2;
        merge(a,low,mid);
        merge(a,mid+1,high);
        sort(a,low,mid,high);
    }

}


void sort(int a[], int low, int mid, int high){
    int i = low, j=mid+1, k=low;
    int temp[n];

    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
        }
    }

    while(i<=mid){
        temp[k++] = a[i++];
    }

    while(j<=high){
        temp[k++] = a[j++];
    }

    for(i=low;i<=high;i++){
        a[i] = temp[i];
    }
}
