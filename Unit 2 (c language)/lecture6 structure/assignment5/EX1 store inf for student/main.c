/*EX1 store information for student
 *
 *   Created on: 30/7/2022
 *      Author: Ayman-Gamal
 */
#include <stdio.h>
#include <stdlib.h>
struct Sstudent {
    char Name[50];
    int Roll;
    float Marks;
};
int main()
{   struct Sstudent s;
    printf("Enter student information : \n");
    printf("Enter name : ");
    gets (s.Name);
    printf("Enter roll number : ");
    scanf("%d",&s.Roll);
    printf("Enter marks : ");
    scanf("%f",&s.Marks);
    printf("Displaying information : \n");
    printf(" name: %s\n roll: %d\n marks: %.2f",s.Name,s.Roll,s.Marks);
    return 0;
}
