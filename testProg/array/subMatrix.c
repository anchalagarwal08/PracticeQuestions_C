/*
Maximum size square sub-matrix with all 1s
Given a binary matrix, find out the maximum size square sub-matrix with all 1s.
*/

#include <stdio.h>
#include <string.h>
#define R 6
#define C 5
void findSubMatrix(int M[R][C]);
int main()
{
 int M[R][C] = {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
 findSubMatrix(M);
 return 0;
}
void findSubMatrix(int M[R][C]){
 int S[R][C];
 int max_val, max_i,max_j;
 int i, j;
 for(i =0;i<R;i++)
  S[0][i]=M[0][i];
 
 for(j=0;j<C;j++)
  S[j][0] = M[j][0];
 
 for(i=1;i<R;i++)
 {
   for(j=1;j<C;j++){
   if(M[i][j]==1)
    	S[i][j] = min(S[i][j-1],S[i-1][j],S[i-1][j-1])+1;
   else
      S[i][j] =0; 
   }
 }
 
 max_val = S[0][0];
 max_i =0;
 max_j=0;
  for(i=0;i<R;i++)
  {
   for(j=0;j<C;j++){
	if(S[i][j]>max_val){
	  max_val = S[i][j];
	  max_i = i;
          max_j = j;
        }
   }
 }
 for(i=max_i;i>max_i-max_val;i--)
  {
   for(j=max_j;j>max_j-max_val;j--){
     printf("%d ", M[i][j]);    
    }
     printf("\n");
   }
}

int min(int a, int b, int c){
  int m = a;
  if (m > b) 
    m = b;
  if (m > c) 
    m = c;
  return m;

}
