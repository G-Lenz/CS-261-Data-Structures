/* CS261- Assignment 1 - Q.4*/
/* Name: George Lenz
 * Date: 4/17/2018
 * Solution description: Changes a string to camel case
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){

	
	return ch -'a'+'A';
}


void camelCase(char* word){
     /*Convert to camelCase*/
	for (int i = 0; word[i] != '\0'; i++)
	{
		if (word[i] == '_' && word[i+1]!='\0')
		{
			if ((int)word[i + 1] > 96 && (int)word[i + 1] < 123)
			{
				word[i + 1] = toUpperCase(word[i + 1]);
			}
			for (int j = i; word[j] != '\0'; j++)
			{
				word[j] = word[j + 1];
			}
		}
	}
}

int main(){
	char *word = malloc(sizeof(char) * 100);
    /*Read the string from the keyboard */
	printf("Enter a string you would like to convert to camelCase\n");
	scanf("%s", word);
	scanf(word);
    /*Call camelCase*/
    camelCase(word);
	
    /*Print the new the string */
	printf("%s\n", word);
	
    return 0;
}