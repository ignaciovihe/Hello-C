#include <stdio.h>
#include "exercise.h"

int main(void) {
    employee_t employee = create_employee(1, "Alice");
    department_t department = create_department("Engineering");

    assign_employee(&employee, &department);
    assign_manager(&department, &employee);

    printf("Employee: %s\n", employee.name);
    printf("Department: %s\n", employee.department->name);
    printf("Manager: %s\n", department.manager->name);

    return 0;
}