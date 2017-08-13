#include <stdio.h>
#include <conio.h>

#define IN   1  /* inside a word */
#define OUT  0  /* outside a word */

void PrintASCII(){
	char c;
	for(c = -128; c < 127; c++){
		printf("%c  ", c);
		if(c % 16 == 0) printf("\n");
	}
}
/*=====================================================================================*/
/* count lines, words, and characters in input */
void CountLineWordChar()
{
	int c, nl, nw, nc, state;
	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
	   ++nc;
	   if (c == '\n')
	       ++nl;
	   if (c==' ' || c=='\n' || c=='\t')
	       state = OUT;
	   else if (state == OUT) {
	       state = IN;
	       ++nw;
	   }
	}
	printf("%d %d %d\n", nl, nw, nc);
}
/*=====================================================================================*/
/* Dem so tu trong chuoi */
int CountWord(char *str) 
{ 
	int dem=0; 
	
	for (int i=0; i<strlen(str); i++) 
		if(str[i]==' '&& isalpha(str[i+1]))
			dem +=1;
	dem +=1;
	
	return dem; 
} 
/*=====================================================================================*/

/*=====================================================================================*/
