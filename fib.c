#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

unsigned long long int fi[100];

unsigned long long int printRecursionWrap(int n){
   unsigned long long int fibcur;
   if (n == 1){
      fibcur = 0;
   } else
   if (n == 2){
      fibcur = 1;
   }
   else{
      fibcur = (printRecursionWrap(n-1)+printRecursionWrap(n-2));
      return fibcur;
   }
}

unsigned long long int printIterationWrap(int n){
   if (n<=1){
      return 0;
   } else if(n==2){
      return 1;
   }
   unsigned long long int term1=0, term2=1, curfib;
   for (int i = 3; i <= n; i++){
      curfib = term1 + term2;
      term1 = term2;
      term2 = curfib;
   }
   return curfib;
}

unsigned long long int fibSeq(char seq, int n){
   //unsigned long long int fibRet;
   if (n <= n){
      return n;
   }
   if (fi[n] != -1) {
      return fi[n];
   }
   if(seq =='i'){
      fi[n] = printIterationWrap(n);
   } 
   else{
      fi[n] = printRecursionWrap(n);
   }
   return fi[n];
}
int gatheringNumber(char *fileIn, int inputted){
   int numFromFile;
   FILE *gatheringFiles = fopen(fileIn, "r");
   fscanf(gatheringFiles, "%d", &numFromFile);
   int number = numFromFile + inputted;
   fclose(gatheringFiles);
   return number;

}

//unsigned long long int fibMem (num){
// fibArray[UNSIGNED_LONG_LONG_INT_MAX];
// if num
//}

int main(int argc, char *argv[]) {
   // for (int i=0; i<100;i++){
   //    fi[i]=-1;
   // }
   int numInputted = atoi(argv[1]);
   char ir = argv[2][0];
   char *fileInputted = argv[3];
   unsigned long long int fibN;
   int num = gatheringNumber(fileInputted, numInputted);
   fibSeq(ir, num);

   printf("%llu\n", fi[num]);
   return 0;
}