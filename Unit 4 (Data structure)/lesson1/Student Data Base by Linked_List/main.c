
/*
   * main.c
 *
 *  Created on: Sep 3, 2022
 *      Author: Ayman_Gamal
 */

#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

#define    APRINTF(...)			    { fflush(stdout); \
											 fflush(stdin); \
											 printf(__VA_ARGS__); \
											 fflush(stdout); \
											 fflush(stdin);    }


struct Sdata {
	char name[30] ;
	int ID ;
	float height ;
};
struct Sstudent {
	struct Sdata Dstudent ;
	struct Sstudent* PNext_student ;
};
//APIS
void Add_student ();
int Delet_student ();
void Delet_all_student ();
void View_list ();
int get_node_student ();
int Number_of_Nodes (struct Sstudent* GPFirst_student);
int get_node_from_the_END();
int find_middle_of_list();






struct Sstudent* GPFirst_student=NULL ;


void main ()
{
	while(1)
	{

		char temp[30];        //ask user to enter number of option
		APRINTF ("\n \t Choose one of the following options ");
		APRINTF ("\n 1: Add student  ");
		APRINTF ("\n 2: Delete student  ");
		APRINTF ("\n 3: View students ");
		APRINTF ("\n 4: Delete All  ");
		APRINTF ("\n 5: get node information");
		APRINTF ("\n 6: Number of nodes ");
		APRINTF ("\n 7: get node information form end of list ");
		APRINTF ("\n 8: get middle nodes of list ");
		APRINTF ("\n Enter option Number : ");
		gets(temp);
		APRINTF("\n =========================================================");


		switch ( atoi (temp))
		{
		case 1:
		{
			Add_student();
			break ;

		}
		case 2:
		{
			Delet_student();
			break ;

		}
		case 3:
		{
			View_list();
			break ;

		}
		case 4:
		{
			Delet_all_student();
			break ;

		}
		case 5:
		{
			get_node_student();
			break ;
		}
		case 6:
		{
			APRINTF ("\n Number of Nodes= %d ",Number_of_Nodes(GPFirst_student))
			break;
		}
		case 7:
		{
			get_node_from_the_END();
			break;
		}
		case 8:
		{
			find_middle_of_list();
			break;
		}
		default :
			break ;
		}


	}

}




void Add_student ()
{
	char temp[30];
	struct Sstudent* PNew_student ;
	struct Sstudent* PLast_student=GPFirst_student ;
	// check list empty or not
	if(GPFirst_student)
	{
		while (PLast_student->PNext_student)   //check until reach last student
			PLast_student=PLast_student->PNext_student;

		PNew_student = (struct Sstudent*) malloc (sizeof (struct Sstudent));  // allocate new student
		PLast_student->PNext_student = PNew_student ;    // pointer of last student point to new student

	}
	else
	{             //if empty
		PNew_student = (struct Sstudent*) malloc (sizeof (struct Sstudent)); // allocate new student
		GPFirst_student= PNew_student; //head point to new student

	} //enter data
	APRINTF ("\n Enter ID: ")
	gets(temp);
	PNew_student->Dstudent.ID=atoi(temp) ;

	APRINTF ("\n Enter name: ")
	gets(PNew_student->Dstudent.name);

	APRINTF ("\n Enter height: ")
	gets(temp);
	PNew_student->Dstudent.height=atof(temp);

	PNew_student->PNext_student =NULL;
}


int Delet_student ()
{
	char temp[30] ;

	if(GPFirst_student)
	{
		unsigned int select_ID ;
		APRINTF("\n Enter select ID student to be deleted : ")
		gets(temp);
		select_ID = atoi(temp) ;
		struct Sstudent* Pselect_student = GPFirst_student ;
		struct Sstudent* Pprevious_student = NULL ;
		while (Pselect_student) //check until end list
		{

			if (Pselect_student->Dstudent.ID == select_ID) //check by id
			{
				if (GPFirst_student == Pselect_student ) // if first student
				{
					GPFirst_student = Pselect_student->PNext_student ; // head point to second student
				}
				else
				{       //another student point to next student because current student will deleted
					Pprevious_student->PNext_student = Pselect_student->PNext_student ;
				}
				APRINTF ("\n we deleted all information for student  =%s  ",Pselect_student->Dstudent.name)
				APRINTF ("\n ====================================")

				free(Pselect_student);
				return 1 ;
			}

			Pprevious_student = Pselect_student ; //point to next student
			Pselect_student= Pselect_student->PNext_student ;

		}
		APRINTF("\n this ID is not found please enter correct ID ")
		return 0 ;

	}
	else
	{
		APRINTF ("\n it is empty we found nothing to delete ")
										return 0 ;
	}

}
void View_list ()
{
	struct Sstudent* Pcurrent_student =GPFirst_student ;
	int count =0 ;
	if (GPFirst_student)
	{
		while (Pcurrent_student)
		{
			APRINTF("\n \t Record number : %d",count+1)
			APRINTF("\n ID : %d",Pcurrent_student->Dstudent.ID)
			APRINTF("\n Name : %s",Pcurrent_student->Dstudent.name)
			APRINTF("\n Height : %f",Pcurrent_student->Dstudent.height)
            Pcurrent_student= Pcurrent_student->PNext_student ;
			count++ ;
		}}
	else
	{
		APRINTF("\n===== Empty list========")
	}

}

void Delet_all_student ()
{
	struct Sstudent* Pdelet_student =NULL ;
	struct Sstudent* Pcurrent_student =GPFirst_student ;

	while (Pcurrent_student)
	{
		Pdelet_student= Pcurrent_student ;
		Pcurrent_student= Pcurrent_student->PNext_student;
		free(Pdelet_student);

	}
	GPFirst_student = NULL;
	APRINTF("\n All Students Are Deleted ")
	APRINTF("\n ==================================")

}
int get_node_student ()
{
	unsigned int count =0 ;
	if(GPFirst_student)
	{
		struct Sstudent* Pcurrent_student =GPFirst_student ;
		unsigned int Node;
		APRINTF("\n Enter index you need it :")
		scanf("%d",&Node);
		while (Pcurrent_student)
		{
			if (Node == count)
			{
				APRINTF("\n ID : %d",Pcurrent_student->Dstudent.ID)
				APRINTF("\n Name : %s",Pcurrent_student->Dstudent.name)
				APRINTF("\n Height : %f",Pcurrent_student->Dstudent.height)
				return 1; ;
			}

			count++;
			Pcurrent_student=Pcurrent_student->PNext_student ;
		}
		APRINTF("\n index : %d   is not founded",Node)
		return 0 ;
	}
	else
	{
		APRINTF("\n it is empty list no index in it ")
		return 0 ;
	}
}
int Number_of_Nodes (struct Sstudent* Pcurrent_student)
{

	if (Pcurrent_student)
	{
		return 1+Number_of_Nodes(Pcurrent_student->PNext_student) ;
	}
	else
	{
		return 0 ;
	}
}
int get_node_from_the_END()
{
	if (GPFirst_student==NULL)
	{
		APRINTF("\n it is empty list ==== ")
		return 0;
	}

	else
	{
		unsigned int n , count=0 ;
		struct Sstudent* Pmain=GPFirst_student;
		struct Sstudent* Pref=GPFirst_student;
		APRINTF("\n Enter node number you need it from the end of list: ")
		scanf("%d",&n);
		if(n==0)
		{
			APRINTF("\n Error you enter 0 and we start count form 1 ")
			return 0;
		}
		else
		{
			while(n>count)
			{
				if(Pref==NULL)
				{
					APRINTF("\n Error you enter number bigger than number of list nodes")
	            	APRINTF("\n  you enter: %d , the number of list nodes=%d",n,Number_of_Nodes(GPFirst_student))
					return 0;
				}
				Pref=Pref->PNext_student;
				count++;
			}
			while(Pref)
			{
				Pref=Pref->PNext_student;
				Pmain=Pmain->PNext_student;
			}

			APRINTF("\n \t Node number (%d) from end of list is:",n)
			APRINTF("\n ID : %d",Pmain->Dstudent.ID)
			APRINTF("\n Name : %s",Pmain->Dstudent.name)
			APRINTF("\n Height : %f",Pmain->Dstudent.height)
			return 1;

		}
	}
}
int find_middle_of_list()
{
	if (GPFirst_student==NULL)
		{
			APRINTF("\n it is empty list ==== ")
			return 0;
		}

		else
		{
			unsigned int count =1 ;
			struct Sstudent* fast_2=GPFirst_student;
			struct Sstudent* slow_1=GPFirst_student;
			while(fast_2->PNext_student)
			{
				fast_2=fast_2->PNext_student;
				if(fast_2->PNext_student)
				{
					fast_2=fast_2->PNext_student;
					slow_1=slow_1->PNext_student;
					count++;
				}
				else
				{
					slow_1=slow_1->PNext_student;
					count++;
					break;
				}
			}
            APRINTF("\n list nodes=%d , so the middle node is node:%d ",Number_of_Nodes(GPFirst_student),count)
			APRINTF("\n ID : %d",slow_1->Dstudent.ID)
			APRINTF("\n Name : %s",slow_1->Dstudent.name)
			APRINTF("\n Height : %f",slow_1->Dstudent.height)
			return 1;

		}

}


