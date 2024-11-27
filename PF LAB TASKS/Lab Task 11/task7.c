#include <stdio.h>
#include <string.h>

#define MAX_COURSES 5
#define MAX_STRING_LEN 100


typedef struct Course {
    int courseID;
    char courseName[MAX_STRING_LEN];
    char instructor[MAX_STRING_LEN];
    int credits;
} Course;


typedef struct Department {
    char departmentName[MAX_STRING_LEN];
    Course courses[MAX_COURSES];
    int numCourses; 
} Department;

// Function prototypes
void addDepartment(Department *dept);
void addCourse(Department *dept);
void displayCourses(Department *dept);

int main() {
    Department department; 
    department.numCourses = 0; 

    int choice;
    do {
        printf("\nUniversity Course Enrollment System\n");
        printf("1. Add Department\n");
        printf("2. Add Course to Department\n");
        printf("3. Display Courses in Department\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDepartment(&department);
                break;
            case 2:
                addCourse(&department);
                break;
            case 3:
                displayCourses(&department);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}


void addDepartment(Department *dept) {
    printf("Enter department name: ");
    getchar(); 
    fgets(dept->departmentName, MAX_STRING_LEN, stdin);
    dept->departmentName[strcspn(dept->departmentName, "\n")] = 0; 
    printf("Department added successfully: %s\n", dept->departmentName);
}


void addCourse(Department *dept) {
    if (dept->numCourses >= MAX_COURSES) {
        printf("Maximum number of courses reached.\n");
        return;
    }

    Course newCourse;
    printf("Enter course ID: ");
    scanf("%d", &newCourse.courseID);
    printf("Enter course name: ");
    getchar(); 
    fgets(newCourse.courseName, MAX_STRING_LEN, stdin);
    newCourse.courseName[strcspn(newCourse.courseName, "\n")] = 0; 
    printf("Enter instructor name: ");
    fgets(newCourse.instructor, MAX_STRING_LEN, stdin);
    newCourse.instructor[strcspn(newCourse.instructor, "\n")] = 0; 
    printf("Enter credits: ");
    scanf("%d", &newCourse.credits);

    dept->courses[dept->numCourses++] = newCourse;
    printf("Course added successfully.\n");
}

void displayCourses(Department *dept) {
    printf("\nCourses in Department: %s\n", dept->departmentName);
    for (int i = 0; i < dept->numCourses; i++) {
        Course course = dept->courses[i];
        printf("Course ID: %d, Course Name: %s, Instructor: %s, Credits: %d\n",
               course.courseID, course.courseName, course.instructor, course.credits);
    }
}
