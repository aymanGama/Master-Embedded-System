/*
 * student.h
 *
 *  Created on: Sep 17, 2022
 *      Author: Ayman_Gamal
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define Name_length  10
#define Number_of_courses  5
#define Number_of_students  50
#define    	APRINTF(...)			        { fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);  }


typedef struct  {
	char First_name[Name_length];
	char Second_name[Name_length];
	int roll_number ;
	float gpa;
	int courses[Number_of_courses];

}student_t;

typedef struct{

	int count ;
	int length ;
	student_t* head ;
	student_t* base ;
	student_t* tail ;

}guide_t;
typedef enum {
	no_error ,
	full_list ,
	null_list ,
	empty_list,
	error

}list_status;
 //===============APIS functions============
list_status list_INIT (guide_t* p_help ,student_t* p_student ,int length);
list_status Add_student_manualy (guide_t* p_help );
list_status Add_student_from_file (guide_t* p_help );
list_status find_S_by_rollnumber (guide_t* p_help, int selected_roll);
list_status find_S_by_firstname (guide_t* p_help );
list_status number_of_student (guide_t* p_help );
list_status find_Ss_registered_in_course (guide_t* p_help );
list_status deletestudent_by_rollnumber (guide_t* p_help );
list_status UpdatestudentD_by_rollnumber (guide_t* p_help );
list_status ShowInfo (guide_t* p_help);
void printstudent (student_t* PRINT);






#endif /* STUDENT_H_ */
