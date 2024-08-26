#ifndef SRC_FUNCTIONS_PROTOTYPES_H_
#define SRC_FUNCTIONS_PROTOTYPES_H_

/* Define a structure "Student" to store data of students. */
struct student
{
	int id;				/* Student ID */
	char name[50];		/* Student Name */
	int age;			/* Student Age */
	float gpa;			/* Student GPA */
};

/* Define a structure to represent a node in a linked list */
struct node
{
	struct student data;
	struct node *next;
};


/* All function prototype that we define it */
void Add_Student(const struct student *const ptr);

void Display_Students(void);

void Search_Student_By_ID(int id);

void Update_Student(int id);

float Calculate_Average_GPA(void);

void Search_Highest_GPA(void);

void Delete_Student(int id);

#endif /* SRC_FUNCTIONS_PROTOTYPES_H_ */
