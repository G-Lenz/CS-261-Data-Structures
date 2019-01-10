/* CS261- Assignment 1 - Q.1*/
/* Name: George Lenz
 * Date: 4/17.2018
 * Solution description: assigns each student a unique ID and grade
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
	struct student *studentArray = malloc(sizeof(struct student) * 10);
     /*return the pointer*/
	return studentArray;
}

void generate(struct student* students){
     /*Generate random and unique ID and random scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
	for (int i = 0; i < 10; i++)
	{
		int randNumber = (rand() % 10) + 1;
		for (int j = 0; j < 10; j++)
		{
			if (students[j].id == randNumber)
			{
				randNumber = (rand() % 10) + 1;
				j = -1;
			}
		}
		students[i].id = randNumber;
		students[i].score = rand() % 101;
	}
     
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	printf("==STUDENTS==\n");
	printf("ID     SCORE\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%-2d      %d\n", students[i].id, students[i].score);
	}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
	int sum =0;
	double average=0.0;
	int min = students[0].score;
	int max = students[0].score;
	for (int i = 1; i < 10; i++)
	{
		if (students[i].score > max)
		{
			max = students[i].score;
		}
		if (students[i].score < min)
		{
			min = students[i].score;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		sum = sum + students[i].score;
	}
	average = sum / 10.0;

	printf("\n==Scores==\n");
	printf("Minimum: %d\nMaximum: %d\n", min, max);
	printf("Average: %.2lf\n", average);
     
}

void deallocate(struct student* stud){
	free(stud);
     
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
	stud = allocate();
    /*call generate*/
	generate(stud);
    /*call output*/
	output(stud);
    /*call summary*/
	summary(stud);
    /*call deallocate*/
	deallocate(stud);
    return 0;
}
