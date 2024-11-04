#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#pragma warning (disable : 4996)

char studentID[13];
char studentName[51];
char adminPassword[51] = "000000"; //Password to enter admin mode
char course[5][8]; //6 courses with maximum 8 characters
char grade[5][3]; //6 grades with maximum 3 characters
int creditHours[5];
float gradePoint[5];
float gPA[2];
float cGPA;
float totalQualityPoint;
int totalCreditHours;

void printLogo() {
	printf("K   K   OOOOOO   L         EEEEEEE    JJJJJJJJ     PPPPPPP   AAAAAAAA   SSSSSS   AAAAAAAA   RRRRRR   \n");
	printf("K  K    O    O   L         E              J        P     P   A      A   S        A      A   R    R   \n");
	printf("K K     O    O   L         E              J        P     P   A      A   S        A      A   R    R   \n");
	printf("KK      O    O   L         EEEEEEE        J        PPPPPPP   A      A   SSSSSS   A      A   RRRRRR   \n");
	printf("K K     O    O   L         E              J        P         AAAAAAAA        S   AAAAAAAA   R  R     \n");
	printf("K  K    O    O   L         E              J        P         A      A        S   A      A   R   R    \n");
	printf("K   K   OOOOOO   LLLLLLL   EEEEEEE   JJJJJJ        P         A      A   SSSSSS   A      A   R    R   \n");
	printf("\n");
}

int menu() {
	int choice;
	printf("Welcome to Kolej Pasar GPA & CGPA calculator! \n");
	printf("1. Kolej Pasar Admin\n");
	printf("2. Kolej Pasar Student\n");
	printf("3. Quit\n");
	printf("\nSelect the desired mode by entering a number (1, 2 or 3 only) > ");
	scanf("%d", &choice);
	return choice;
}

void getStudentDetails() {
	printf("\n");
	rewind(stdin);
	printf("----------------------------\n");
	printf("Please enter student ID : ");
	scanf("%s", &studentID);
	rewind(stdin);
	printf("----------------------------\n");
	printf("Please enter student name : ");
	scanf("%[^\n]", &studentName);
	rewind(stdin);
}

void studentDetails() {
	getStudentDetails();

	for (int i = 0; i < 6; i++) {

		printf("-------------------------------------------\n");
		printf("Enter course code for course %d : ", i + 1);
		scanf("%s", course[i]);
		getchar();
		printf("Grade obtained : ");
		scanf("%s", grade[i]);
		getchar();
		printf("Credit hour for the course : ");
		scanf("%d", &creditHours[i]);
		getchar();

		if (strcmp(grade[i], "A") == 0 || strcmp(grade[i], "a") == 0) {
			gradePoint[i] = 4.00;
		}
		else if (strcmp(grade[i], "A-") == 0 || strcmp(grade[i], "a-") == 0) {
			gradePoint[i] = 3.75;
		}
		else if (strcmp(grade[i], "B+") == 0 || strcmp(grade[i], "b+") == 0) {
			gradePoint[i] = 3.50;
		}
		else if (strcmp(grade[i], "B") == 0 || strcmp(grade[i], "b") == 0) {
			gradePoint[i] = 3.00;
		}
		else if (strcmp(grade[i], "B-") == 0 || strcmp(grade[i], "b-") == 0) {
			gradePoint[i] = 2.75;
		}
		else if (strcmp(grade[i], "C+") == 0 || strcmp(grade[i], "c+") == 0) {
			gradePoint[i] = 2.50;
		}
		else if (strcmp(grade[i], "C") == 0 || strcmp(grade[i], "c") == 0) {
			gradePoint[i] = 2.00;
		}
		else if (strcmp(grade[i], "F") == 0 || strcmp(grade[i], "f") == 0) {
			gradePoint[i] = 0.00;
		}
		else {
			printf("Invalid grade input. Please restart and enter a valid grade.\n");
			return;
		}
	}
	calculation();
}

float calculation() {
	int i;
	float qualityPoint1 = 0, qualityPoint2 = 0, qualityPoint3 = 0;
	int creditHours1 = 0, creditHours2 = 0, creditHours3 = 0;

	for (i = 0; i < 2; i++) {
		qualityPoint1 += gradePoint[i] * creditHours[i];
		creditHours1 += creditHours[i];
	}
	for (i = 2; i < 4; i++) {
		qualityPoint2 += gradePoint[i] * creditHours[i];
		creditHours2 += creditHours[i];
	}
	for (i = 4; i < 6; i++) {
		qualityPoint3 += gradePoint[i] * creditHours[i];
		creditHours3 += creditHours[i];
	}
	gPA[0] = qualityPoint1 / creditHours1;
	gPA[1] = qualityPoint2 / creditHours2;
	gPA[2] = qualityPoint3 / creditHours3;
	float totalQualityPoints = qualityPoint1 + qualityPoint2 + qualityPoint3;
	int totalCreditHours = creditHours1 + creditHours2 + creditHours3;
	cGPA = totalQualityPoints / totalCreditHours;
}

void display() {
	printf("\n--------------------------------------\n");
	printf("Student name : %s\n", studentName);
	printf("Student ID : %s\n", studentID);
	printf("GPA for Semester 1 > %.2f\n", gPA[0]);
	printf("GPA for Semester 2 > %.2f\n", gPA[1]);
	printf("GPA for Semester 3 > %.2f\n", gPA[2]);
	printf("CGPA > %.2f\n", cGPA);
	printf("--------------------------------------\n\n");
}

int main() {
	int choice;
	printLogo();
	while (1) {
		choice = menu();
		if (choice == 1) {
			char staffPassword[51];
			printf("Please enter the password for admin mode : ");
			scanf("%s", staffPassword);
			if (strcmp(staffPassword, adminPassword) == 0) {
				printf("\nYou are now in admin mode.\n");
				studentDetails();
				display();
				printf("You have done key in the student details. Thank you admin xxx.\n\n");
			}
			else {
				printf("ACCESS DENIED.\n");
			}

		}
		else if (choice == 2) {
			printf("\nYou are now in student mode.\n");
			getStudentDetails();
			display();
		}
		else if (choice == 3) {
			printf("\nExiting . . . \n");
			return 0;
			break; //to exit the program appriopriately
		}
		else {
			printf("Invalid number. Please type in number 1 - 3.\n");
		}
	}
}