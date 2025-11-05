include <stdio.h>
int main(){
int matrix [2][2];
int i,j;
printf("enter elements for 2*2 matrix:\n");
for(i=0;<2;i++){
for(j=0;<2;j++){
printf(enter elements[%d][%d]:",i+1,j+1);
scanf("%d",& matrix[i][j]);
}
}
prinf("\nThe2*2 matrix is :\n");
for(i=0;i<2;i++){
for(j=0;j<2;j++){
printf("%d\t",matrix[i][j]);
}
printf("\n")
}
return 0;
}
