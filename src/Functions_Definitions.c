/* Include the library and header file to able to call function that we declare. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions_Prototypes.h"

/* Define pointer "Head= NULL" to make this pointer point at first node of the list and for check if list empty or not. */
struct node *head= NULL;

void Add_Student(const struct student *const ptr)
{
	/* Create a new node in memory to store new student info. */
	struct node *new_node = (struct node*) malloc(sizeof(struct node));

	/* Check memory availability. */
	if(new_node == NULL)
	{
		printf("\nSorry,there is no enough space to store new student.\n");
		printf("\n");
		return;
	}

	/* Fill the information of student into new node. */
	new_node->data.id= ptr->id;
	strcpy(new_node->data.name, ptr->name);
	new_node->data.age= ptr->age;
	new_node->data.gpa= ptr->gpa;

	new_node->next= NULL;						/* Make pointer "next = NULL" because we need to add the student at the end of the list. */

	/* Check if list is empty or not,list is empty so we add new student at first of the list. */
	if (head == NULL)
	{
		head= new_node;
		printf("\nStudent With ID= '%d' added successfully.\n ",ptr->id);
		return;
	}

	/* Make a pointer to loop in list for checking repeated ID. */
	struct node *current= NULL;

	/* Make current pointer point at the first of the list. */
	current= head;

	/* Loop to check repeated ID. */
	while(current != NULL)
	{
		if((current->data.id) == (ptr->id))		/* If ID repeated print error message. */
		{
			printf("\nError!!,the ID= '%d' you trying to add it\nis already exist.\n",ptr->id);
			return;
		}

		current= current->next;
	}
	/* End of loop to check repeated ID. */

	/* Make current pointer point at the first of the list. */
	current= head;

	/* Loop to get last node in list. */
	while(current->next != NULL)
	{
		current= current->next;
	}
	/* End loop to get last node in list. */

	current->next= new_node;
	new_node->next= NULL;

	/* Print successful message. */
	printf("\nStudent With ID= '%d' added successfully.\n ",ptr->id);

}

void Display_Students(void)
{
	/* Check if list is empty or not. */
	if (head == NULL)
	{
		printf("\nError!!,The List is empty,try to add student information first.\n");
		return;
	}

	/* Make a pointer to loop in list for print all students info. */
	struct node *current= NULL;

	/* Make current pointer point at the first of the list. */
	current= head;

	/* Variable to print number of student in the list. */
	int i=1;

	/* Loop to print info for all students. */
	while(current != NULL)
	{
		printf("\nInformation Of Student %d:\n",i);
		puts("--------------------------");
		printf("\nName= %s\n",current->data.name);
		printf("ID= %d\n",current->data.id);
		printf("Age= %d\n",current->data.age);
		printf("GPA= %.2f\n",current->data.gpa);

		current= current->next;
		i++;
	}
	/* End of loop to print info for all students. */

	/* Print successful message. */
	printf("\nThats all Students\n");
}

void Search_Student_By_ID(int id)
{
	/* Check if list is empty or not. */
	if (head == NULL)
	{
		printf("\nError!!,The List is empty,try to add student information first.\n");
		return;
	}

	/* Make a pointer to loop in list for find students info by ID. */
	struct node *current= NULL;


	/* Make current pointer point at the first of the list. */
	current= head;

	/* Loop to find ID of students. */
	while(current != NULL)
	{
		if((current->data.id) == (id))			/* Check if ID that we take from user is in the list or not. */
		{
			printf("\nThe Information of student you want is:\n");
			printf("\nName= %s\n",current->data.name);
			printf("ID= %d\n",current->data.id);
			printf("Age= %d\n",current->data.age);
			printf("GPA= %.2f\n",current->data.gpa);
			printf("\n");
			return;
		}

		current= current->next;
	}
	/* End of loop to find ID of students. */

	/* Print failed message. */
	printf("\nSorry, The student was not found.\nPlease check the ID again.\n");
	printf("\n");
}

void Update_Student(int id)
{
	/* Check if list is empty or not. */
	if (head == NULL)
	{
		printf("\nError!!,The List is empty,try to add student information first.\n");
		return;
	}

	/* Make a pointer to loop in list for find students info by ID. */
	struct node *current= NULL;


	/* Make current pointer point at the first of the list. */
	current= head;

	/* Loop to find ID of students. */
	while(current != NULL)
	{
		if((current->data.id) == (id))			/* Check if ID that we take from user is in the list or not. */
		{
			/* Print first the info before update it. */
			printf("\nThe Information of student\nBEFORE Update:\n");
			puts("--------------");
			printf("Name= %s\n",current->data.name);
			printf("ID= %d\n",current->data.id);
			printf("Age= %d\n",current->data.age);
			printf("GPA= %.2f\n",current->data.gpa);
			printf("\n");

			/* Take the new update from user. */
			printf("\nEnter new Name:");
			scanf("%s",current->data.name);
			printf("Enter new Age:");
			scanf("%d",&current->data.age);
			printf("Enter new GPA:");
			scanf("%f",&current->data.gpa);
			printf("\n");

			/* Print the info after update it. */
			printf("\nThe Information of student\nAFTER Update:\n");
			puts("---------------");
			printf("Name= %s\n",current->data.name);
			printf("ID= %d\n",id);
			printf("Age= %d\n",current->data.age);
			printf("GPA= %.2f\n",current->data.gpa);
			printf("\n");
			/* Print successful  message. */
			printf("\nStudent With ID= '%d' updated successfully.\n ",id);
			printf("\n");
			return;
		}

		current= current->next;
	}
	/* End of loop to find ID of students. */

	/* Print failed message. */
	printf("\nSorry, The student was not found.\nPlease check the ID again.\n");
}

float Calculate_Average_GPA(void)
{
	/* Define and declare "ave_gpa" to store result of AVG of GPA,"sum_gpa" to store total sum of GPA and "Number_Of_Student' to count student. */
	float avg_gpa, sum_gpa= 0;
	int Number_Of_Student= 0;

	/* Check if list is empty or not. */
	if (head == NULL)
	{
		avg_gpa= 0;
		return avg_gpa;
	}

	/* Make a pointer to loop in list. */
	struct node *current= NULL;


	/* Make current pointer point at the first of the list. */
	current= head;

	/* Loop to count total sum of GPA and number of student. */
	while(current != NULL)
	{
		sum_gpa += current->data.gpa;

		current= current->next;
		Number_Of_Student++;
	}
	/* End loop to count total sum of GPA and number of student. */

	/* Calculate AVG of GPA. */
	avg_gpa= sum_gpa / Number_Of_Student;

	return avg_gpa;
}

void Search_Highest_GPA(void)
{
	/* Check if list is empty or not. */
	if (head == NULL)
	{
		printf("\nError!!,The List is empty,try to add student information first.\n");
		return;
	}

	/* Assume that the first node has highest GPA and compare with other node.*/
	struct student highest_gpa= head->data;

	/* Make a pointer to loop in list. */
	struct node *current= NULL;

	/* Make current pointer point at the second node of the list. */
	current= head->next;

	/* Loop to find highest GPA. */
	while(current != NULL)
	{
		if ( (highest_gpa.gpa) < (current->data.gpa) )		/* Compare between highest GPA and other GPA in the list. */
		{
			highest_gpa = current->data;
		}

		current= current->next;
	}
	/* End loop to find highest GPA. */

	printf("\nInformation Of Highest GPA of Student:\n");
	printf("Name= %s\n",highest_gpa.name);
	printf("ID= %d\n",highest_gpa.id);
	printf("Age= %d\n",highest_gpa.age);
	printf("GPA= %.2f\n",highest_gpa.gpa);
	printf("\n");
	return;
}

void Delete_Student(int id)
{
	/* Check if list is empty or not. */
	if (head == NULL)
	{
		printf("\nError!!,The List is empty,try to add student information first.\n");
		return;
	}

	/* Make a pointers to loop in list. */
	struct node *current= NULL;
	struct node *prev= NULL;
	struct node *deleted_node= NULL;

	/* Check if the first node have the ID that we need to delete it. */
	if(head->data.id == id)
	{
		deleted_node= head;
		head= head->next;
		free(deleted_node);
		printf("\nThe student's ID= '%d' deleted successfully.\n",id);
		return;
	}

	/* Make current pointer point at the second node of the list. */
	current= head->next;

	/* Make prev and deleted_node pointers point at the first node of the list. */
	prev= head;
	deleted_node= head;

	/* Loop to find students by his ID. */
	while(current != NULL)
	{
		if((current->data.id) == (id))			/* Check if ID that we take from user is in the list or not. */
		{
			deleted_node= current;
			prev->next= current->next;
			free(deleted_node);
			printf("\nThe student's ID= '%d' deleted successfully.\n",id);
			printf("\n");
			return;
		}

		prev= current;
		current= current->next;
	}
	/* End loop to find students by his ID. */

	/* Print failed message. */
	printf("\nSorry, The student was not found.\nPlease check the ID again.\n");

}
