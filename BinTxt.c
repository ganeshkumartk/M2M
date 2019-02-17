/* C source code for Text to binary conversion 
    part of M2M Assignment */

// Ganesh Kumar T K (MSM17B034) //

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void textToBinary(char *text, int textLength, char *binary, int binaryLength);
void decimalToBinary(int decimal, char *octet);
void acii(char *string, int n);

int main(void)
{
	char text[101];
    char *binary;
	int textLength, binaryLength;

    printf("Enter text: ");
    scanf("%100[^\n]s", text);
	textLength = strlen(text);
    printf("Your ASCII format is: ");
    acii(text, textLength);
    binaryLength = textLength * 9;      // 8 binary digits + 1 space separator
    binary = malloc(binaryLength + 1);  // + 1 null terminator
    if(binary == NULL)
        exit(1);
    
    textToBinary(text, textLength, binary, binaryLength);
    printf("Your binary format is:\n%s\n", binary);
    
    free(binary);
	
	return 0;
}

void textToBinary(char *text, int textLength, char *binary, int binaryLength)
{
    char *octet = malloc(9);
    if(octet == NULL)
        exit(1);
    while(*text)
    {
        decimalToBinary(*text, octet);
        while(*octet)
            *binary++ = *octet++;
        *binary++ = ' ';
        ++text;
        octet -= 8;
    }
    *binary = '\0';
    binary -= binaryLength;
    free(octet);
}

void decimalToBinary(int decimal, char *octet)
{
	octet += 8;
	*octet = '\0';
	if(decimal == 0)
	{
		octet -= 8;
		octet = "00000000";
	}
	else
	{
		while(decimal > 0)
		{
			--octet;
			*octet = decimal % 2 + '0';
			decimal = decimal / 2;
		}
	}
    while(strlen(octet) < 8)
    {
        --octet;
        *octet = '0';
    }
}


void acii(char *string, int n)
{
      int i=0;

while (i < n)

        {

            printf(" %c = %d\n", string[i], string[i] );

            ++i ;

        }

}
