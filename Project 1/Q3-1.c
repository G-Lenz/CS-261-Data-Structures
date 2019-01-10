/* CS261- Assignment 1 - Q.3*/
/* Name: George Lenz
 * Date: 4/17/2018
 * Solution description: generates a list of ID's and grades then sorts by grade
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/   
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (students[i].score > students[j].score)
			{
				struct student temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
}

int main(){
    /*Declare an integer n and assign it a value.*/
	int n = 10;
    /*Allocate memory for n students using malloc.*/
	struct student *stud = malloc(sizeof(struct student) * n);
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
		for (int i = 0; i < n; i++)
		{
			int randNumber = (rand() % n) + 1;
			for (int j = 0; j < n; j++)
			{
				if (stud[j].id == randNumber)
				{
					randNumber = (rand() % n) + 1;
					j = -1;
				}
			}
			stud[i].id = randNumber;
			stud[i].score = rand() % 101;
		}
    /*Print the contents of the array of n students.*/
	printf("==STUDENTS==\n");
	printf("ID     SCORE\n");
	for (int i = 0; i < n; i++)
	{
		printf("%-2d      %d\n", stud[i].id, stud[i].score);
	}
    /*Pass this array along with n to the sort() function*/
	sort(stud, n);
    
    /*Print the contents of the array of n students.*/
	printf("==STUDENTS==\n");
	printf("ID     SCORE\n");
	for (int i = 0; i < n; i++)
	{
		printf("%-2d      %d\n", stud[i].id, stud[i].score);
	}
    
    return 0;
}
