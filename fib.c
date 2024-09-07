#include <stdio.h>

int numInputted, ir, fibN, num;
char* fileInputted;
int printRecursion(int n){
   if (n == 0){
      fibN= 0;
   }
   if (n == 1){
      fibN = 1;
   }
   else{
      fibN = (printRecursion(n-1)+printRecursion(n-2));
   }
   printf("The Fibonnacci number is: %d", fibN);
}

void printIteration(int n){
   int term1=1, term2=0;
   for (int i = 1; i <=n; i++){
      if (i==1) {
         fibN = 0;
      }
      if (i==2) {
         fibN = 1;
      }
      if(i > 2){
         fibN = term1 + term2;
         term2=term1;
         term1=fibN;
      }
   }
   printf("The Fibonnacci number is: %d", fibN);

}

void recursionOrIteration(char t){
   if(t=='i'){
      printIteration(num);
   } 
   else{
      printRecursion(num);
   }
}

void gatheringNumber(int inputted, const char * c){
   int numFromFile;
   FILE *gatheringFiles = fopen(c, "r");
   if(gatheringFiles == NULL){
      printf("Error: Unable to open file. \n")
   }else{
   fscanf(gatheringFiles, "%d", &numFromFile);
   num = numFromFile + inputted;
   fclose(gatheringFiles);
   }
}

int main() {
   printf("Hello!\n");
   printf("Please input an integer: ");
   scanf("%d", &numInputted);
   printf("Please input 'r' for recursion) or 'i' for iteration: ");
   ir = getchar();
   printf("Please input the file name: ");
   scanf("%s", fileInputted);
   gatheringNumber(numInputted, fileInputted);
   recursionOrIteration(ir); 
   return 0;
}