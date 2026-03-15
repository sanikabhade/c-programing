#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Student {
    int id;
    char name[50];
    int age;
    float marks;
};

struct Student students[MAX];
int count = 0;

void addStudent() {
    if(count >= MAX) {
        printf("Student list is full!\n");
        return;
    }

    printf("\nEnter Student ID: ");
    scanf("%d", &students[count].id);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Age: ");
    scanf("%d", &students[count].age);

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    count++;

    printf("Student added successfully!\n");
}

void displayStudents() {
    if(count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n----- Student List -----\n");

    for(int i=0;i<count;i++) {
        printf("\nID: %d", students[i].id);
        printf("\nName: %s", students[i].name);
        printf("\nAge: %d", students[i].age);
        printf("\nMarks: %.2f\n", students[i].marks);
    }
}

void searchStudent() {
    int id;
    int found = 0;

    printf("\nEnter Student ID to search: ");
    scanf("%d",&id);

    for(int i=0;i<count;i++) {
        if(students[i].id == id) {
            printf("\nStudent Found\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Student not found.\n");
}

void deleteStudent() {
    int id, found = 0;

    printf("\nEnter Student ID to delete: ");
    scanf("%d",&id);

    for(int i=0;i<count;i++) {
        if(students[i].id == id) {
            found = 1;

            for(int j=i;j<count-1;j++) {
                students[j] = students[j+1];
            }

            count--;
            printf("Student deleted successfully.\n");
            break;
        }
    }

    if(!found)
        printf("Student not found.\n");
}

void saveToFile() {
    FILE *fp = fopen("students.txt","w");

    if(fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for(int i=0;i<count;i++) {
        fprintf(fp,"%d %s %d %.2f\n",
        students[i].id,
        students[i].name,
        students[i].age,
        students[i].marks);
    }

    fclose(fp);

    printf("Data saved to file successfully.\n");
}

void loadFromFile() {
    FILE *fp = fopen("students.txt","r");

    if(fp == NULL)
        return;

    while(fscanf(fp,"%d %s %d %f",
        &students[count].id,
        students[count].name,
        &students[count].age,
        &students[count].marks) != EOF) {

        count++;
    }

    fclose(fp);
}

int main() {

    int choice;

    loadFromFile();

    while(1) {

        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Save Data\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice) {

            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                saveToFile();
                break;

            case 6:
                saveToFile();
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}