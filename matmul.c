#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r1,c1,r2,c2;
    printf("Enter row and col of mat 1:\n");
    scanf("%d %d",&r1,&c1);
    printf("Enter row and col of mat 2:\n");
    scanf("%d %d",&r2,&c2);

    int** mat1 = (int**)malloc(r1*sizeof(int*));
    for(int i=0;i<r1;i++){
        mat1[i]=(int*)malloc(c1*sizeof(int));
    }
    
    int** mat2 = (int**)malloc(r2*sizeof(int*));
    for(int i=0;i<r1;i++){
        mat2[i]=(int*)malloc(c2*sizeof(int));
    }
    
    int** res = (int**)malloc(r1*sizeof(int*));
    for(int i=0;i<r1;i++){
        res[i]=(int*)malloc(c2*sizeof(int));
    }
    printf("Enter elements of mat1:\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            scanf("%d",&mat1[i][j]);
        }
    }
    printf("Enter elements of mat2:\n");
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            scanf("%d",&mat2[i][j]);
        }
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            res[i][j]=0;
            for(int k=0;k<c1;k++){
                res[i][j]+=mat1[i][k]*mat2[k][j];
            }
        }
    }
    printf("Result of matrix is:\n");
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
            printf("%d\t",res[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<r1;i++){
        free(mat1[i]);
    }
    free(mat1);
    for(int i=0;i<r2;i++){
        free(mat2[i]);
    }
    free(mat2);
    for(int i=0;i<r1;i++){
        free(res[i]);
    }
    free(res);
    return 0;
}