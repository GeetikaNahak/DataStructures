/*Implementing Sparse Matrix representation*/

#include<stdio.h>
int main(){
    int r,c;
    printf("\nEnter row and column:\n");
    scanf("%d%d",&r,&c);
    int sparseMatrix[r][c];
    int i,j;int ct=0;
    printf("\n Enter Matrix\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&sparseMatrix[i][j]);
        }
    }
    
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(sparseMatrix[i][j]==0)ct++;
        }
    }
    printf("\n%d\n",ct);
    printf("Evaluate...\n");
    int SPR[ct][3];
    if(ct>=(r*c)/2){int k=1;
        SPR[0][0]=r;
        SPR[0][1]=c;
        SPR[0][2]=r*c-ct;
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(sparseMatrix[i][j]!=0){
                    SPR[k][0]=i;
                    SPR[k][1]=j;
                    SPR[k][2]=sparseMatrix[i][j];
                    k++;
                }
            }
        }
        printf("\n row col val\n");
        for(i=0;i<k;i++){
            for(j=0;j<3;j++){
                printf("  %d ",SPR[i][j]);
            }printf("\n");
        }
    }
    printf("\nEnd\n");
    
}

/*
output:
Enter row and column:
3 3
Enter Matrix
0 1 0
2 0 0 
3 0 4
5
Evaluate...

 row col val
  3   3   4 
  0   1   1 
  1   0   2 
  2   0   3 
  2   2   4 

End
*/