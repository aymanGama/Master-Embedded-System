/*Ex4 store information of students using structure
 *
 *   Created on: 30/7/2022
 *      Author: Ayman-Gamal
 */
#include <stdio.h>
#include <stdlib.h>
struct Sstudent
{
    char Name[50];
    int Roll;
    float Marks;
};

int main()
{
    char x;
    struct Sstudent student[10];
    int i,k;
    printf ("Enter information of students : \n");
    for (i=0;i<10;i++)
    {
        student[i].Roll=i+1;
        printf("for roll number %d \n",student[i].Roll);
        printf("Enter name : ");
        scanf("%s",&student[i].Name);
        printf("Enter marks : ");
        scanf("%f",&student[i].Marks);
        printf ("if you want to continue store enter y if you end enter any character :  ");fflush(stdout);fflush(stdin);
        scanf ("%c",&x);
        if ((x=='y')&&(i!=10))
            continue;
        else
            break;

    }
    printf("Displaying information of students : \n");
    for (k=0;k<=i;k++)
    {
        student[k].Roll=k+1;
        printf("for roll number %d \n",student[k].Roll);
        printf("name : %s \n",student[k].Name);
        printf("marks : %.2f \n",student[k].Marks);
    }
    return 0;
}
