///////////////////////////////////////////////////////////////
// Program name : Creation of multiple child process         //
// File name    : NP1.c                                      //
// Author	: Kannan K D P , SCT15CS033                  //
// Date		: 12/01/2018				     //
///////////////////////////////////////////////////////////////

#include <stdio.h>
#include <sys/types.h>

int main(){
	int A[3][3],B[3][3],C[3][3]; // Declaration of matrices
	int i,j,k; // Declaration of looping variables
	int n,n1; // Declaration of pid variables

	printf("Enter the values for matrix A\n"); // Matrix A
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("Enter the value for A[%d][%d] :",i,j);
			scanf("%d",&A[i][j]);
			printf("\n");
		}
	}
	

	printf("The matrix A is :\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d\t",A[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("Enter the values for matrix B\n"); // Matrix B
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("Enter the value for B[%d][%d] :",i,j);
			scanf("%d",&B[i][j]);
			printf("\n");
		}
	}

	printf("The matrix B is :\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d\t",B[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			C[i][j]=0;
		}
	}

	n=fork();
	
	if(n==0){ // Child process 1
		printf("The child1 process is executing now....\n");
		printf("Matrix multiplication of two matrices A and B\n");
		for(i=0;i<3;i++){		//Multiplication of matrices A and B
			for(j=0;j<3;j++){
				for(k=0;k<3;k++){
					C[i][j]=C[i][j]+(A[i][k]*B[k][j]);
				}
			}
		}

		printf("The resultant matrix C is :\n"); // Resultant matrix C
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				printf("%d\t",C[i][j]);
			}
			printf("\n");
		}
		sleep(1000);
	}	

	else if(n>0){
		n1=fork(); 
		if(n1==0){ // Child process 2
			printf("The child2 process is executing now....\n");
			printf("Matrix addition of two matrices A and B\n");
			for(i=0;i<3;i++){ 			//Addition of matrices A and B
				for(j=0;j<3;j++){
					C[i][j]=A[i][j]+B[i][j];
				}
			}

			printf("The resultant matrix C is :\n"); // Resultant matrix C
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					printf("%d\t",C[i][j]);
				}
				printf("\n");
			}
		}	
	}

	else{
		printf("Unfortunately, some error has occured....\n");
	}
	
	return 0;
}
