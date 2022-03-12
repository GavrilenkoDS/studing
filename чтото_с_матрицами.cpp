#include <stdio.h>
#include <process.h>
const int N = 5;
 	float a [5][5] = {
    6 ,2 ,3, -1, 2,
	1, 2, 3 ,1 ,-3,
	2, 2 ,-1 ,-3 ,-2 ,
	5, 4, 3 ,2 ,-2,
	4 ,-3 ,3 ,-2 ,6 ,
  };
   float b[5] = {4,14,12,21,-28};
    float x[5]={0};
void printmatrix(){
   //print matrix "a"
   int i=0,j=0;
   printf("\n");
   for(i=0; i<N; i++){
       for(j=0; j<N; j++){
      printf(" %+f*X%d", a[i][j], j);
       }
       printf(" =%f\n", b[i]);
   }
}
 
void printresult(){
   int i=0;
   printf("\n");
  printf("Result\n");
   for(i=0; i<N; i++){
       printf("X%d = %f\n", i, x[i]);
   }
}
 
void diagonal(){
   int i, j, k;
   
   float temp=0;
   for(i=0; i<N; i++){
       if(a[i][i]==0){
       for(j=0; j<N; j++){
           if(j==i) continue;
           if(a[j][i] !=0 && a[i][j]!=0){
           for(k=0; k<N; k++){
               temp = a[j][k];
               a[j][k] = a[i][k];
               a[i][k] = temp;
           }
           temp = b[j];
           b[j] = b[i];
           b[i] = temp;
           break;
           }
       }
       }
   }
}
 
void cls(){
   for(int i=0; i<25; i++) printf("\n");
}
 
int main(){
printmatrix();
  diagonal();
   printmatrix();
   //process rows
   for(int k=0; k<N; k++){
       for(int i=k+1; i<N; i++){
       if(a[k][k]==0){
           printf("\nSolution is not exist.\n");
           return 0;
       }
       float M = a[i][k] / a[k][k];
       for(int j=k; j<N; j++){
           a[i][j] -= M * a[k][j];
       }
       b[i] -= M*b[k];
       }
   }
   printmatrix();
   for(int i=N-1; i>=0; i--){
       float s = 0;
       for(int j = i; j<N; j++){
       s = s+a[i][j]*x[j];
       }
       x[i] = (b[i] - s) / a[i][i];
   }
   printresult();
   
}
