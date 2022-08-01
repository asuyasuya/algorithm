#include<stdio.h>
#include<stdlib.h>

int trace(int* A, int n){
  for (int i=0; i<n; i++){
    if(i>0){
      printf(" ");
    }
    printf("%d", A[i]);
  }
  printf("\n");
}


int main(){
  int n;
  scanf("%d", &n);
  int *A = (int *)malloc(sizeof(int)*n);
  for (int i=0; i<n; i++){
    scanf("%d", &A[i]);
  }

  for (int i=1; i<n; i++){
    // out
    trace(A, n);
    //sort
    for (int j=0; j<i; j++){
      if (A[i] < A[j]){
        int current = A[i];
        for (int k=i; k>j; k--){
          A[k] = A[k-1];
        }
        A[j] = current;
        break;
      }
    }
  }
  // out
  trace(A,n);

  return 0;
}