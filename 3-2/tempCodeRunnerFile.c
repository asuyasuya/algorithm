#include<stdio.h>
#include<stdlib.h>
int main(){
  int n;
  scanf("%d", &n);
  int *A = (int *)malloc(sizeof(int)*n);
  for (int i=0; i<n; i++){
    scanf("%d", &A[i]);
  }
  printf("\n");

  for (int i=1; i<n; i++){
    // out
    for (int j=0; j<n; j++){
      printf("%d ", A[j]);
    }
    printf("\n");

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
  for (int j=0; j<n; j++){
    printf("%d ", A[j]);
  }
  printf("\n");

  return 0;
}