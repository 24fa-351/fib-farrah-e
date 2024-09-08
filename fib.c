#include <stdio.h>

int numInputted, fibN, num;

int printRecursion(int n){
   int fibcur;
   if (n == 0){
      fibcur= 0;
   } else
   if (n == 1){
      fibcur = 1;
   }
   else{
      fibcur = (printRecursion(n-1)+printRecursion(n-2));
   }
   return fibcur;
}

int printIteration(int n){
   if (n<=0){
      return 0;
   } else if(n==1){
      return 1;
   }
   int term1=0, term2=1, curfib;
   for (int i = 2; i <= n; i++){
      curfib = term1 + term2;
      term1 = term2;
      term2 = curfib;
   }
   return curfib;
}

void recursionOrIteration(char* t){
   if(*t =='i'){
      fibN = printIteration(num);
   } 
   else{
      fibN = printRecursion(num);
   }
   printf("The Fibonnacci number is: %d", fibN, "\n");

}

int gatheringNumber(int inputted){
   const char fileInputted;
   printf("Please input the file name: ");
   scanf("%s", fileInputted);
   int numFromFile;
   FILE *gatheringFiles = fopen(&fileInputted, "r");
   fscanf(gatheringFiles, "%d", &numFromFile);
   int number = numFromFile + inputted;
   fclose(gatheringFiles);
   return number;

}


int main() {
   char* ir;

   printf("Hello!\n");
   printf("Please input an integer: ");
   scanf("%d", &numInputted);
   printf("Please input 'r' for recursion or 'i' for iteration: ");
   scanf(" %c", &ir);
   num = gatheringNumber(numInputted);
   recursionOrIteration(ir); 

   return 0;
}