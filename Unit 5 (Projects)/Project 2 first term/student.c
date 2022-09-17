/*
 * student.c
 *
 *  Created on: Sep 17, 2022
 *      Author: Ayman_Gamal
 */
#include "student.h"
extern guide_t helper ;


list_status list_INIT (guide_t* p_help ,student_t* p_student ,int length)
{
	p_help->head = p_student ;
	p_help->base = p_student ;
	p_help->tail = p_student ;
	p_help->length = length ;
	p_help->count = 0 ;
	return no_error ;
}
list_status Add_student_manualy (guide_t* p_help )
{
	student_t* select_rollnumber = p_help->base;
	char temp[10]; int i;

//check list initialized

	if(!p_help->base ||!p_help->head)
		return null_list ;

//check list full or not


	if(p_help->count==p_help->length)
	{
		APRINTF("\n Error it is full");
		return full_list;
	}
	APRINTF("\n Enter roll number: ");
	gets(temp);
	p_help->head->roll_number= atoi(temp);

//check roll number founded or not

	while(select_rollnumber !=p_help->head)
	{
		if(select_rollnumber->roll_number ==p_help->head->roll_number)
		{
			APRINTF("\n Error This Roll Number Is Founded,it is information for that student");
			printstudent(select_rollnumber);
			return error ;
		}
		select_rollnumber++ ;

	}
// store data of student
	APRINTF("\n Enter first name: ");
	gets(p_help->head->First_name);

	APRINTF("\n Enter second name: ");
	gets(p_help->head->Second_name);

	APRINTF("\n Enter GPA: ");
	gets(temp);
	p_help->head->gpa=atof(temp);
	APRINTF("\n Enter courses number: ");
	for (i=0;i<5;i++)
	{
		APRINTF("\n Enter course ID (%d) : ",i+1);
		gets(temp);
		p_help->head->courses[i] = atoi(temp);
	}
	p_help->head++;
	p_help->count++;
	APRINTF("\n You Can Enter Another (%d) student ",50-p_help->count);
	APRINTF("\n _______________________________________________________");

	return no_error ;
}

list_status Add_student_from_file (guide_t* p_help )
{
//check list initialized

	if(!p_help->base ||!p_help->head)
		return null_list ;

//check list full or not


	if(p_help->count==p_help->length)
	{
		APRINTF("\n Error it is full");
		return full_list;
	}
	int i ;
	FILE *pfile;
	pfile=fopen("ayman.txt","r");
// lobe until reach to last line
	while (!feof(pfile))
		{
			fscanf(pfile,"%d",&p_help->head->roll_number);
//check roll number is founded or not
			if(find_S_by_rollnumber(&helper,p_help->head->roll_number)!=error)
			{
// if roll number is founded will neglect this line and go to next line
				APRINTF("\n Error This Roll Number %d Is Founded ",p_help->head->roll_number);
				fscanf(pfile, "%*[^\n]");
				continue ;
			}
//store data
			fscanf(pfile,"%s",p_help->head->First_name);
			fscanf(pfile,"%s",p_help->head->Second_name);
			fscanf(pfile,"%f",&p_help->head->gpa);
			for (i=0;i<5;i++)
				{
					fscanf(pfile,"%d",&p_help->head->courses[i]);
				}

				p_help->head++;
				p_help->count++;

		}
	fclose(pfile);
	APRINTF("\n You Can Enter Another (%d) student ",50-p_help->count);
	APRINTF("\n _______________________________________________________");
	return no_error ;
}
list_status find_S_by_rollnumber (guide_t* p_help, int selected_roll)
{
//check list initialized

	if(!p_help->base ||!p_help->head)
		return null_list ;

	student_t* find_roll =p_help->base ;

	while(find_roll !=p_help->head)
	{

//check roll number is founded or not
		if(selected_roll==find_roll->roll_number)
		{
			p_help->tail=find_roll;
			return no_error ;
		}
		find_roll++;
	}
	return error ;
}
list_status find_S_by_firstname (guide_t* p_help )
{
//check list initialized
	if(!p_help->base ||!p_help->head)
		return null_list ;

	student_t* first_student =p_help->base ;
	char temp[10];int x=0;
	APRINTF("\n Enter first name of student to find it  : ");
	gets(temp);
	while(first_student !=p_help->head)
	{

//check  name is the same first name or not
		if(strcmp(temp,first_student->First_name)==0)
		{
			x=1;
			printstudent(first_student);
		}first_student++;
	}
	if(x==0)
	{
		APRINTF("\n this name is not founded");
		APRINTF("\n ===============================================================================================");
		return error ;
	}
	else
	{
		return no_error ;
	}

}

list_status find_Ss_registered_in_course (guide_t* p_help )
{
//check list initialized
	if(!p_help->base ||!p_help->head)
		return null_list ;

	student_t* find_courseID =p_help->base ;
	char temp[10];int x=0; int course_ID ;
	APRINTF("\n Enter course ID to find students registered in it , course ID : ");
	gets(temp);
	course_ID= atoi(temp); int count=0;
	while(find_courseID != p_help->head)
	{
		int i ;
		for ( i=0 ; i<5 ; i++ )
		{
//check course ID is founded and print data of student who register in this course
			if(find_courseID->courses[i]==course_ID)
			{
				x=1;
				count++;
				printstudent(find_courseID);
			}
		}find_courseID++;

	}
	if(x==0)
	{
		APRINTF("\n may be you enter wrong ID because all student did not register in this course");
		APRINTF("\n ===============================================================================================");
		return error ;
	}
	else
	{
// number of students registered in this course
		APRINTF("\n Number of students registered in this course = %d",count);
		APRINTF("\n ===============================================================================================");
		return no_error ;
	}

}
list_status number_of_student (guide_t* p_help )
{
//check list initialized
	if(!p_help->base ||!p_help->head)
		return null_list ;
// print number of student
	APRINTF("\n Number Of Students is : %d",p_help->count);
	APRINTF("\n ===============================================================================================");
	return no_error;
}
list_status deletestudent_by_rollnumber (guide_t* p_help )
{
//check list initialized
	if(!p_help->base ||!p_help->head)
		return null_list ;
// check list empty or not
	if (p_help->count==0)
	{
		APRINTF("\n You Can Not Delete Any Student list Is Empty");
		APRINTF("\n ===================================================");
		return empty_list ;
	}
	student_t* find_roll =p_help->base ;
	student_t* next_student =(student_t*)(find_roll+1) ;
	int selected_roll ; char temp[10];int x=0;
	APRINTF("\n Enter roll number of student to be deleted  : ");
	gets(temp);
	selected_roll =atoi(temp) ;
	while(find_roll !=p_help->head)
	{
		int i ;
		if(selected_roll==find_roll->roll_number||x==1)
		{
			x=1;
			strcpy(find_roll->First_name,next_student->First_name);
			strcpy(find_roll->Second_name,next_student->Second_name);
			find_roll->gpa=next_student->gpa;
			find_roll->roll_number=next_student->roll_number;
			for ( i=0 ; i<5 ; i++ )
			{
				find_roll->courses[i]=next_student->courses[i];
			}
		}
		find_roll++;
		next_student++;
	}
	if(x==0)
	{
		APRINTF("\n this roll number is not founded");
		return error ;
	}
	else
	{
		APRINTF("\n ======================DELETE STUDENT============DONE=====================");
		p_help->head--;
		p_help->count--;
		return no_error;
	}

}
list_status UpdatestudentD_by_rollnumber (guide_t* p_help )
{
//check list initialized
	if(!p_help->base ||!p_help->head)
		return null_list ;

	int new_roll ;
	student_t* find_roll =p_help->base ;
	int selected_roll ; char temp[10];
	APRINTF("\n Enter roll number of student to update information  : ");
	gets(temp);
	selected_roll =atoi(temp) ; int x=0;
	while(find_roll !=p_help->head)
	{
		int i ;    char var[10];
		if(selected_roll==find_roll->roll_number)
		{
			x=1 ;
			APRINTF(" \n chose the task that you want to update it :");
			APRINTF("\n 1:first name");
			APRINTF("\n 2:second name ");
			APRINTF("\n 3:roll number ");
			APRINTF("\n 4:GPA ");
			APRINTF("\n 5:courses ");
			APRINTF(" \n Enter Your Choice: ");
			gets(temp);
			switch (atoi(temp))
			{
			case 1:
				APRINTF("\n Enter new first name: ");
				gets(find_roll->First_name);
				break;
			case 2:
				APRINTF("\n Enter new second name: ");
				gets(find_roll->Second_name);
				break ;
			case 3:

				APRINTF("\n Enter new roll number: ");
				gets(temp);
				new_roll= atoi(temp);
// check if new roll number is founded or not
				if(find_S_by_rollnumber(&helper,new_roll)!=error)
				{
					APRINTF("\n Error This Roll Number %d Is Founded ",new_roll);
					APRINTF("\n ===================================================== ");

					break;
				}
				find_roll->roll_number=new_roll;

				break;
			case 4:
				APRINTF("\n Enter new GPA: ");
				gets(var);
				find_roll->gpa = atoi(var);
				break ;
			case 5:
				APRINTF("\n Enter new courses: ");
				for (i=0;i<5;i++)
				{
					APRINTF("\n Enter course %d : ",i+1);
					gets(var);
					find_roll->courses[i] = atoi(var);
				}
				break ;
			default :
				break;

			}

		}

		find_roll++;

	}
// check if entered roll number of student to be update is found or not
	if(x==0)
	{
		APRINTF("\n This Roll Number Is Not Founded");
		APRINTF("\n ===================================");

		return error ;
	}
	else
	{

		return no_error;
	}

}
list_status ShowInfo (guide_t* p_help)
{
	int counter=0;
	APRINTF(" \n All Student With Their Information :  ");
	student_t* find_student =p_help->base ;
	while(find_student !=p_help->head)
	{
		APRINTF("\n ====================Student(%d) Information ==================",counter+1);
		printstudent(find_student);
		find_student++;
		counter++;
	}
	return no_error;
}
void printstudent (student_t* PRINT)
{
	int i ;
	APRINTF("\n student information__________");
	APRINTF("\n roll number : %d",PRINT->roll_number);
	APRINTF("\n first name: %s",PRINT->First_name);
	APRINTF("\n second  name: %s",PRINT->Second_name);
	APRINTF("\n GPA: %.2f",PRINT->gpa);
	APRINTF("\n courses:");
	for ( i=0 ; i<5 ; i++ )
	{
		APRINTF("%d \t",PRINT->courses[i]);
	}
	APRINTF("\n --------------------------------");
}
