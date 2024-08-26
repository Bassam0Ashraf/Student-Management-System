/*
 * Main.c
 *
 *  Created on: Aug 14, 2024
 *      Author: Bassam Ashraf
 */

/* Include the library and header file to able to call function that we declare. */
#include <stdio.h>
#include "Functions_Prototypes.h"

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	/* Loop to displays the menu options to the user. */
	for(;;)
	{
		puts("-----------------------------------------------------");

		// Menu Options for user.
		printf("1. Add Student.\n");
		printf("2. Display Students.\n");
		printf("3. Search Student by ID.\n");
		printf("4. Update Student Information.\n");
		printf("5. Delete Student.\n");
		printf("6. Calculate Average GPA.\n");
		printf("7. Search For Student With Highest GPA.\n");
		printf("8. Exit.\n");

		/* Take the number that chosen by user. */
		int number;
		printf("\nchoose number: ");
		scanf("%d",&number);

		puts("-----------------------------------------------------");

		/* We use switch function to accesses the cases from 1 to 8. */
		switch(number)
		{
		int id; 										/* Declaration of 'id' variable that we will use in case 3,4 and 5. */
		case 1:
			struct student s; 							/* Declaration for 's' as member in struct student. */
			printf("Enter student information:\n");
			printf("Name of Student:");
			scanf("%s",s.name);							/* Get name from user and store it in "s.name". */
			printf("ID of Student:");
			scanf("%d",&s.id);							/* Get ID from user and store it in "s.id". */
			printf("Age of Student:");
			scanf("%d",&s.age);							/* Get age from user and store it in "s.age". */
			printf("GPA of Student:");
			scanf("%f",&s.gpa);							/* Get GPA from user and store it in "s.GPA". */
			Add_Student(&s);;							/* Call function "Add_Student" to store the information in our list. */
			printf("\n");
			break;

		case 2:
			Display_Students();							/* Call function "Display_Students" to display all information for all student in the list. */
			break;

		case 3:
			printf("Enter the ID of Student you want the information it:");
			scanf("%d",&id);							/* Get ID from user and store it in "id" to search the student by his ID. */
			Search_Student_By_ID(id);					/* Call function "Search_Student_By_ID" to get the information for student that user want it. */
			break;

		case 4:
			printf("Enter the ID of Student you want to update it:");
			scanf("%d",&id);							/* Get ID from user and store it in "id" to search the student by his ID. */
			Update_Student(id);							/* Call function "Update_Student" to update student information. */
			break;

		case 5:
			printf("Enter the ID of Student you want to delete it:");
			scanf("%d",&id);							/* Get ID from user and store it in "id" to search the student by his ID. */
			Delete_Student(id);							/* Call function "Delete_Student" to delete student from the list. */
			break;

		case 6:
			printf("Average Of GPA= %.2f\n",Calculate_Average_GPA());		/* Call function "Calculate_Average_GPA" to calculate AVG of GPA. */
			break;

		case 7:
			Search_Highest_GPA();						/* Call function "Search_Highest_GPA" to search for the highest GPA in the list. */
			break;

		case 8:
			printf("\nThank You :)\n");
			return 0;									/* Exit from "for" loop and terminates the program. */
		}

	}
}
