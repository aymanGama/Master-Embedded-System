/*
  * main.c
 *
 *  Created on: Sep 17, 2022
 *      Author: DR-Mosaad
 */
#include "student.h"
guide_t helper ;
student_t students[50];
int main()
{
	//init queue with guide struct
	if(list_INIT(&helper, students,50)==no_error)
			APRINTF("____________________Intialize List Is Done________________\n");

	APRINTF(" \n ********** Welcome To Student Management System *********** ");
	char temp[10] ;int roll ;

	while(1)
	{
		APRINTF(" \n chose the task that you want perform :");
		APRINTF(" \n 1:Add The Student Details manually");
		APRINTF(" \n 2:Add The Student Details From Text File");
		APRINTF(" \n 3:Find The Student Details By Roll Number");
		APRINTF(" \n 4:Find The Student Details By First Name");
		APRINTF(" \n 5:Find The Student Details By Course ID");
		APRINTF(" \n 6:Find The Total Number of student");
		APRINTF(" \n 7:Delete The Student Details By Roll NUmber");
		APRINTF(" \n 8:Update The Student Details By Roll NUmber");
		APRINTF(" \n 9:Show All Information ");
		APRINTF(" \n 10:Exit");
		APRINTF(" \n ============================================================");
		APRINTF(" \n Enter Your Choice: ");
		gets(temp);
		APRINTF(" \n==============================================================");
		switch (atoi(temp))
		{
		case 1 :
			Add_student_manualy(&helper);
			break;
		case 2:
			Add_student_from_file(&helper);
			break;
		case 3:

			APRINTF("\n Enter roll number of student to find it  : ");
			gets(temp);
			roll =atoi(temp) ;
			if(find_S_by_rollnumber(&helper,roll)==no_error)
				printstudent(helper.tail);
			else
			{
				APRINTF("\n this roll number is not founded ");
				APRINTF("\n =========================================================================================");

			}
			break;
		case 4:
			find_S_by_firstname (&helper );
			break;
		case 5:
			find_Ss_registered_in_course(&helper);
			break;
		case 6:
			number_of_student(&helper);
			break ;
		case 7:
			deletestudent_by_rollnumber(&helper);
			break;
		case 8 :
			UpdatestudentD_by_rollnumber(&helper);
			break;
		case 9 :
			ShowInfo(&helper);
			break;
		case 10:
			exit(1);
			break;

		default :
			break;

		}

	}

	return 0 ;
}
