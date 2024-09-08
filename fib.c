#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numInputted, fibN, num;

int printRecursion(int n){
   int fibcur;
   if (n == 1){
      fibcur= 0;
   } else
   if (n == 2){
      fibcur = 1;
   }
   else{
      fibcur = (printRecursion(n-1)+printRecursion(n-2));
   }
   return fibcur;
}

int printIteration(int n){
   if (n<=1){
      return 0;
   } else if(n==2){
      return 1;
   }
   int term1=0, term2=1, curfib;
   for (int i = 3; i <= n; i++){
      curfib = term1 + term2;
      term1 = term2;
      term2 = curfib;
   }
   return curfib;
}

int gatheringNumber(char *fileIn, int inputted){
   int numFromFile;
   FILE *gatheringFiles = fopen(fileIn, "r");
   fscanf(gatheringFiles, "%d", &numFromFile);
   int number = numFromFile + inputted;
   fclose(gatheringFiles);
   return number;

}


int main(int argc, char *argv[]) {
   int numInputted = atoi(argv[1]);
   char ir = argv[2][0];
   char *fileInputted = argv[3];

   num = gatheringNumber(fileInputted, numInputted);
   if(ir =='i'){
      fibN = printIteration(num);
   } 
   else{
      fibN = printRecursion(num);
   }
   printf("%d\n", fibN);
   return 0;
}