#include <stdio.h>
#include <string.h>

#define MAX_DEPARTMENTS 5
#define MAX_COURSES 10
#define MAX_STUDENTS 50


typedef struct {
    int id;
    char name[50];
} Student;


typedef struct {
    int id;
    char name[50];
    char instructor[50];
    int credits;
    int studentCount;
    Student students[MAX_STUDENTS];
} Course;


typedef struct {
    int id;
    char name[50];
    int courseCount;
    Course courses[MAX_COURSES];
} Department;


typedef struct {
    int departmentCount;
    Department departments[MAX_DEPARTMENTS];
} University;

// Function prototypes
void addDepartment(University *university);
void addCourse(University *university);
void enrollStudent(University *university);
void displayUniversityData(University university);

int main() {
    University university;
    university.departmentCount = 0;

    int choice;
    while (1) {
        printf("\nUniversity Management System\n");
        printf("1. Add Department\n");
        printf("2. Add Course to Department\n");
        printf("3. Enroll Student in Course\n");
        printf("4. Display University Data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addDepartment(&university);
                break;
            case 2:
                addCourse(&university);
                break;
            case 3:
                enrollStudent(&university);
                break;
            case 4:
                displayUniversityData(university);
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


void addDepartment(University *university) {
    if (university->departmentCount >= MAX_DEPARTMENTS) {
        printf("Maximum number of departments reached.\n");
        return;
    }

    Department *dept = &university->departments[university->departmentCount];
    dept->id = university->departmentCount + 1;
    printf("Enter Department Name: ");
    getchar(); 
    fgets(dept->name, sizeof(dept->name), stdin);
    dept->name[strcspn(dept->name, "\n")] = '\0'; 
    dept->courseCount = 0;

    university->departmentCount++;
    printf("Department added successfully.\n");
}


void addCourse(University *university) {
    if (university->departmentCount == 0) {
        printf("No departments available. Add a department first.\n");
        return;
    }

    int deptID;
    printf("Enter Department ID to add a course: ");
    scanf("%d", &deptID);

    if (deptID < 1 || deptID > university->departmentCount) {
        printf("Invalid Department ID.\n");
        return;
    }

    Department *dept = &university->departments[deptID - 1];
    if (dept->courseCount >= MAX_COURSES) {
        printf("Maximum number of courses for this department reached.\n");
        return;
    }

    Course *course = &dept->courses[dept->courseCount];
    course->id = dept->courseCount + 1;
    printf("Enter Course Name: ");
    getchar(); // Clear newline
    fgets(course->name, sizeof(course->name), stdin);
    course->name[strcspn(course->name, "\n")] = '\0'; 
    printf("Enter Instructor Name: ");
    fgets(course->instructor, sizeof(course->instructor), stdin);
    course->instructor[strcspn(course->instructor, "\n")] = '\0'; 
    printf("Enter Course Credits: ");
    scanf("%d", &course->credits);
    course->studentCount = 0;

    dept->courseCount++;
    printf("Course added successfully to %s department.\n", dept->name);
}

int isValidDepartmentID(University *university, int deptID) {
    for (int i = 0; i < university->departmentCount; i++) {
        if (university->departments[i].id == deptID) {
            return 1; // Found valid department ID
        }
    }
    return 0; // Invalid ID
}

void enrollStudent(University *university) {
    if (university->departmentCount == 0) {
        printf("No departments available. Add a department first.\n");
        return;
    }

    int deptID, courseID;
    printf("Enter Department ID: ");
    scanf("%d", &deptID);

    if (!isValidDepartmentID(university, deptID)) {
    printf("Invalid Department ID.\n");
    return;
}
        Department *dept = &university->departments[deptID - 1];
        if (dept->courseCount == 0) {
            printf("No courses available in this department.\n");
            return;
    }

    printf("Enter Course ID: ");
    scanf("%d", &courseID);

    if (courseID < 1 || courseID > dept->courseCount) {
        printf("Invalid Course ID.\n");
        return;
    }

    Course *course = &dept->courses[courseID - 1];
    if (course->studentCount >= MAX_STUDENTS) {
        printf("Maximum number of students for this course reached.\n");
        return;
    }

    Student *student = &course->students[course->studentCount];
    student->id = course->studentCount + 1;
    printf("Enter Student Name: ");
    getchar(); 
    fgets(student->name, sizeof(student->name), stdin);
    student->name[strcspn(student->name, "\n")] = '\0'; 

    course->studentCount++;
    printf("Student enrolled successfully in %s course.\n", course->name);
}


void displayUniversityData(University university) {
    if (university.departmentCount == 0) {
        printf("No departments available.\n");
        return;
    }

    printf("\nUniversity Data:\n");
    for (int i = 0; i < university.departmentCount; i++) {
        Department dept = university.departments[i];
        printf("Department %d: %s\n", dept.id, dept.name);

        if (dept.courseCount == 0) {
            printf("  No courses available.\n");
            continue;
        }

        for (int j = 0; j < dept.courseCount; j++) {
            Course course = dept.courses[j];
            printf("  Course %d: %s\n", course.id, course.name);
            printf("    Instructor: %s\n", course.instructor);
            printf("    Credits: %d\n", course.credits);
            printf("    Enrolled Students: %d\n", course.studentCount);

            for (int k = 0; k < course.studentCount; k++) {
                Student student = course.students[k];
                printf("      Student %d: %s\n", student.id, student.name);
            }
        }
    }
}
