#include <stdio.h>
#include<time.h>
void knapSack(int W, int wt[] ,int val[],int n);
int getMax(int x, int y);
int main() {
int n;
int W ;
int i,j;
clock_t start, end;
printf("enter number of Questions in the Exam paper :");
scanf("%d", &n);
printf("---------------------------------------------------");
int values[n];
int weights[n];
printf("\nenter marks (maximum) for all %d questions\n \n",n);
for(i=1;i<=n;i++)
{
printf("enter marks (maximum) for question number %d :",i);
scanf("%d", &weights[i]);
}
printf("---------------------------------------------------");
printf("\nenter marks scored by the student for all %d questions \n",n);
for(i=1;i<=n;i++)
{
printf("enter marks scored by student in question number %d :",i);
scanf("%d", &values[i]);
}
printf("---------------------------------------------------");
//Read Max. Weight Capacity of Knapsack
printf("\nenter the total(maximum) marks of th paper : ");
scanf("%d", &W);
start = clock();
knapSack(W, weights, values, n);
end = clock();
double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);
printf("Time taken = %1f s",(double)(time_taken));
return 0;
}
int getMax(int x, int y) {
if(x > y) {
return x;
} else {
return y;
}
}
void knapSack(int W, int wt[], int val[], int n) {
int i, w;
//value table having n+1 rows and W+1 columns
int V[n+1][W+1];
//fill the row i=0 with value 0
for(w = 0; w <= W; w++) {
V[0][w] = 0;
}
//fille the column w=0 with value 0
for(i = 0; i <= n; i++) {
V[i][0] = 0;
}
//fill the value table
for(i = 1; i <= n; i++) {
for(w = 1; w <= W; w++) {
if(wt[i] <= w) {
V[i][w] = getMax(V[i-1][w], val[i] + V[i-1][w - wt[i]]);
} else {
V[i][w] = V[i-1][w];
}
}
}
//max value that can be put inside the knapsack
printf("Max Value: %d\n", V[n][W]);
}
