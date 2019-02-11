#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int asciiToBinary(int input) {
        int result = 0, i = 1, remainder;

        /* convert decimal to binary format */
        while (input > 0) {
                remainder = input % 2;
                result = result + (i * remainder);
                input = input / 2;
                i = i * 10;
        }
}

int main(){
  
    char str[100];
    int i=0;
    printf("Enter any string: ");
    scanf("%s",str);
    len =strlen(str);
    printf("ASCII values of each characters of given string: ");
    while(str[i])
         printf("%d ",str[i++]);
    
    printf("Binary values of each characters of given string: ");
    while (len!=0) 
        {
                printf("\t %d \t",asciiToBinary(toascii(str)));
        }
   
    return 0;
}
