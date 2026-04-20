/*
  Build a C program that uses an input data file for the project containing at least 10 records.
Program summary:

1. The input data file contains 740 records and 17 fields.
   The project topic is workplace absenteeism, and the file contains data about 740 employees.

2. The data from the file is read into a struct variable named "absenteeism_record" and displayed in the console,
   even though the input file does not specify the number of records.

3. The user can choose an ascending sorting option where the selected sort criterion appears in the first column,
   from 3 options, or continue without selecting a sorting type:
   a) by each employee's monthly commuting cost
   b) by the number of years each employee has worked at the company
   c) by the number of hours absent in the previous year
   After each selected sort, the user can choose to sort again.
   When the user has finished all desired sorting operations, they can continue.

4. The program calculates, displays in the console, and writes to the output file how many employees
   were absent in each month and how many were not absent at all.

5. The program calculates, displays in the console, and writes to the output file how many employees
   were absent on each day of the week.

6. The program calculates, displays in the console, and writes to the output file, using user-defined
   functions (division, percentage, maximum, minimum, harmonic mean), several derived values:
   - average monthly distance traveled by employees between residence and workplace;
   - average age at which employees started working at the company;
   - maximum and minimum values of the average daily work coefficient (work value of each employee);
   - average employee performance;
   - percentage of employees with disciplinary sanctions;
   - percentage of alcohol consumers;
   - percentage of smokers;
   - average number of children;
   - average number of pets;
   - average weight;
   - average height;
   - average number of hours employees were absent last year;
   - harmonic mean of the daily lost work coefficient from absences;
   - average number of days lost by each employee, assuming 100% performance.

7. A graphical representation is generated for the number of absent employees in each month of the previous year.

   Data source for the input file (17 columns out of 21):
   https://data.world/aaizemberg/absenteeismatwork/workspace/file?filename=Absenteeism_at_work.tsv

*/


#include<stdio.h>
#include<string.h>
#include<GL/glut.h>
#include<windows.h>


int main(int argc, char** argv) {
	int n=0;
	int i;
	int flag;
	long int b=0;
	int c=0;
	int d=0;
	int e=0;
	int f=0;
	int g=0;
	int k=0;
	int l=0;
	int m=0;
	int o=0;
	int p=0;
	int monthly_absence_counts[13]={0};
	int weekday_absence_counts[8]={0};
	int max_absence_hours=0;
	float max_daily_work_coefficient=0;
	float min_daily_work_coefficient;
	float harmonic_loss_sum=0;
	float harmonic_coefficient_sum=0;





	float div(int x, int y){
			float z;
			z=(float)x/y;
			return z;
		}


	float percentage(int x, int y){
			float z;
			z=(float)x*100/y;
			return z;
		}


	float max(float x, float y){
		if(x>y)
			return x;
		else
			return y;
	}


	float min(float x, float y){
			if(x>y)
				return y;
			else
				return x;
		}


	float harmonic_component(float x, float y, int z){
		float w;
		if(z!=0)
		    w=100*8/(x*y*z);
		else
			w=0;
		return w;
		}




	struct absenteeism_record {
	    int absence_month;
		int absence_weekday;
		int monthly_transport_cost;
		int residence_work_distance;
		int years_at_company;
		int age;
		int performance;
		int disciplinary_sanctioned;
		int education;
		int children;
		int alcohol_consumer;
		int smoker;
		int pets;
		int weight;
		int height;
		int absence_hours;
		float daily_work_coefficient;

	}a[800], u;





	FILE *absenteeism_file;
	absenteeism_file=fopen("input.txt", "r");

	if(!absenteeism_file){
		printf("File error!!!");
		return 1;
	}



	printf("ABSENCE MONTH     ABSENCE START DAY OF WEEK     MONTHLY TRANSPORT COST     "
			"RESIDENCE-WORK DISTANCE     YEARS AT CURRENT JOB     AGE     "
			"AVERAGE DAILY WORK COEFFICIENT     PERFORMANCE     DISCIPLINARY SANCTIONED     "
			"EDUCATION LEVEL    NUMBER OF CHILDREN     ALCOHOL CONSUMER     SMOKER     "
			"NUMBER OF PETS     WEIGHT     HEIGHT     ABSENCE HOURS\n");



	while(!feof(absenteeism_file)){

		fscanf(absenteeism_file, "%d%d%d%d%d%d%f%d%d%d%d%d%d%d%d%d%d", &a[n].absence_month,
				&a[n].absence_weekday, &a[n].monthly_transport_cost, &a[n].residence_work_distance,
				&a[n].years_at_company, &a[n].age, &a[n].daily_work_coefficient, &a[n].performance,
				&a[n].disciplinary_sanctioned, &a[n].education, &a[n].children, &a[n].alcohol_consumer,
				&a[n].smoker, &a[n].pets, &a[n].weight, &a[n].height, &a[n].absence_hours);




		printf("      %2d                              %d                                 %d              "
				"          %2d                                %2d                   %d                   "
				"%f                 %3d                   %d                       %d               %d "
				"                 %d                %d              %d             %3d           %d    "
				"       %3d\n",
				a[n].absence_month, a[n].absence_weekday,a[n].monthly_transport_cost,
				a[n].residence_work_distance, a[n].years_at_company, a[n].age,a[n].daily_work_coefficient,
				a[n].performance, a[n].disciplinary_sanctioned, a[n].education, a[n].children,
				a[n].alcohol_consumer, a[n].smoker, a[n].pets, a[n].weight, a[n].height,
				a[n].absence_hours);
		n++;
	}


    fclose(absenteeism_file);



	printf("\n\nThe number of records is %d.", n);


	do{
	printf("\nChoose the criterion you want to use for sorting the data.\n"
			"If you want sorting by monthly commuting cost, press '1'.\n"
			"If you want sorting by years employees have worked at the company, press '2'.\n"
			"If you want sorting by hours absent last year, press '3'.\n"
			"After sorting, you can enter one of the 3 numbers again for another sort.\n"
			"If you are satisfied with the sorting operations, or do not want to sort and want to continue, press '0'.\n"
			"Enter the number corresponding to your choice:");

	fflush(stdout);
	scanf("%ld", &b);



    if(b==0)
    	{break;}




	if(b==1){

		do{
		flag=0;
		for(i=0; i<n-1 ;i++)
			if(a[i].monthly_transport_cost>a[i+1].monthly_transport_cost){
				u=a[i];
				a[i]=a[i+1];
				a[i+1]=u;
				flag=1;}

	}while(flag==1);


		printf("\n\n\nMONTHLY TRANSPORT COST     ABSENCE MONTH     ABSENCE START DAY OF WEEK     "
							"RESIDENCE-WORK DISTANCE     YEARS AT CURRENT JOB     AGE     "
							"AVERAGE DAILY WORK COEFFICIENT     PERFORMANCE     DISCIPLINARY SANCTIONED     "
							"EDUCATION LEVEL    NUMBER OF CHILDREN     ALCOHOL CONSUMER     SMOKER     "
							"NUMBER OF PETS     WEIGHT     HEIGHT     ABSENCE HOURS\n");



		for(i=0; i<n-1; i++)
			printf("         %d                  %2d                              %d                          "
					"           %2d                               %2d                   %d                   "
					"%f                 %3d                   %d                       %d               %d "
					"                 %d                %d              %d             %3d           %d    "
					"       %3d\n",
					a[i].monthly_transport_cost,a[i].absence_month, a[i].absence_weekday,
					a[i].residence_work_distance, a[i].years_at_company, a[i].age,a[i].daily_work_coefficient,
					a[i].performance, a[i].disciplinary_sanctioned, a[i].education, a[i].children,
					a[i].alcohol_consumer, a[i].smoker, a[i].pets, a[i].weight, a[i].height,
					a[i].absence_hours);

	}


	else
		if(b==2){


			do{
			flag=0;
			for(i=0; i<n-1 ;i++)
				if(a[i].years_at_company>a[i+1].years_at_company){
					u=a[i];
					a[i]=a[i+1];
					a[i+1]=u;
					flag=1;}

		}while(flag==1);


			printf("\n\n\nYEARS AT CURRENT JOB     ABSENCE MONTH     ABSENCE START DAY OF WEEK     "
					"MONTHLY TRANSPORT COST     RESIDENCE-WORK DISTANCE     AGE     "
						"AVERAGE DAILY WORK COEFFICIENT     PERFORMANCE     DISCIPLINARY SANCTIONED     "
						"EDUCATION LEVEL    NUMBER OF CHILDREN     ALCOHOL CONSUMER     SMOKER     "
						"NUMBER OF PETS     WEIGHT     HEIGHT     ABSENCE HOURS\n");




			for(i=0; i<n-1; i++)

				printf("           %2d                        %2d                              %d                   "
						"              %d                           %2d                   %d                  "
						"%f                   %3d                   %d                       "
						"%d              %d                  %d                %d              "
						"%d             %3d           %d          %3d\n",
						a[i].years_at_company,a[i].absence_month, a[i].absence_weekday,a[i].monthly_transport_cost,
						a[i].residence_work_distance, a[i].age,a[i].daily_work_coefficient,
						a[i].performance, a[i].disciplinary_sanctioned, a[i].education, a[i].children,
						a[i].alcohol_consumer, a[i].smoker, a[i].pets, a[i].weight, a[i].height,
						a[i].absence_hours);
		}


		else
		if(b==3){

			do{
					flag=0;
					for(i=0; i<n-1 ;i++)
						if(a[i].absence_hours>a[i+1].absence_hours){
							u=a[i];
							a[i]=a[i+1];
							a[i+1]=u;
							flag=1;}

				}while(flag==1);


			printf("     \n\n\nABSENCE HOURS     ABSENCE MONTH     ABSENCE START DAY OF WEEK     MONTHLY TRANSPORT COST     "
						"RESIDENCE-WORK DISTANCE     YEARS AT CURRENT JOB     AGE     "
						"AVERAGE DAILY WORK COEFFICIENT     PERFORMANCE     DISCIPLINARY SANCTIONED     "
						"EDUCATION LEVEL    NUMBER OF CHILDREN     ALCOHOL CONSUMER     SMOKER     "
						"NUMBER OF PETS     WEIGHT     HEIGHT\n");


			         for(i=0; i<n-1; i++)
					     printf("    %3d              %2d                              %d                                  %d    "
						         "                    %2d                               %2d                    %d                 "
							     " %f                   %3d                    %d                     %d               %d "
							     "                 %d                %d              %d             %3d           %d  \n",
								 a[i].absence_hours, a[i].absence_month, a[i].absence_weekday,a[i].monthly_transport_cost,
							     a[i].residence_work_distance, a[i].years_at_company, a[i].age,a[i].daily_work_coefficient,
						         a[i].performance, a[i].disciplinary_sanctioned, a[i].education, a[i].children,
							     a[i].alcohol_consumer, a[i].smoker, a[i].pets, a[i].weight, a[i].height);






		}}while(b==1 || b==2 || b==3);







    printf("\n\nEnter any number to continue with the number of employees absent in each month of the year:");
    fflush(stdout);
    scanf("%ld", &b);
    printf("\n");



    for(i=0; i<n; i++){
	    switch(a[i].absence_month){
	    case 1:
			 monthly_absence_counts[0]++;
			 break;
	    case 2:
			 monthly_absence_counts[1]++;
			 break;
	    case 3:
			 monthly_absence_counts[2]++;
			 break;
	    case 4:
			 monthly_absence_counts[3]++;
			 break;
	    case 5:
			 monthly_absence_counts[4]++;
			 break;
	    case 6:
			 monthly_absence_counts[5]++;
			 break;
	    case 7:
			 monthly_absence_counts[6]++;
			 break;
	    case 8:
			 monthly_absence_counts[7]++;
			 break;
	    case 9:
			 monthly_absence_counts[8]++;
			 break;
	    case 10:
			 monthly_absence_counts[9]++;
			 break;
	    case 11:
			 monthly_absence_counts[10]++;
			 break;
	    case 12:
			 monthly_absence_counts[11]++;
			 break;
	    case 0:
	    	 monthly_absence_counts[12]++;
	    	 break;
 }}



    FILE *conclusions_file;
    conclusions_file=fopen("output.txt", "w");

    if(!conclusions_file){
	    printf("Error creating file!!!");
	    return 1;
	    }



    for(i=0; i<12; i++){
	    printf("In month number %2d of last year, %d employees were absent.\n", i+1, monthly_absence_counts[i]);
	    fprintf(conclusions_file, "In month number %2d of last year, %d employees were absent.\n", i+1, monthly_absence_counts[i]);}


    printf("There were %d employees who were not absent for even one hour last year.\n", monthly_absence_counts[12]);
    fprintf(conclusions_file, "There were %d employees who were not absent for even one hour last year.\n", monthly_absence_counts[12]);


	printf("\n\nEnter any number to continue with the number of employees whose absence started on a given weekday:");
	fflush(stdout);
    scanf("%ld", &b);


	min_daily_work_coefficient=a[0].daily_work_coefficient+1;



    for(i=0; i<n; i++){

	    weekday_absence_counts[a[i].absence_weekday-2]++;
		b+=a[i].residence_work_distance;
	    c+=a[i].performance;
	    d+=a[i].age-a[i].years_at_company;
	    e+=a[i].disciplinary_sanctioned;
	    f+=a[i].children;
	    g+=a[i].alcohol_consumer;
	    k+=a[i].smoker;
	    l+=a[i].pets;
	    m+=a[i].weight;
	    o+=a[i].height;
	    p+=a[i].absence_hours;


    max_daily_work_coefficient=max(max_daily_work_coefficient, a[i].daily_work_coefficient);
    min_daily_work_coefficient=min(min_daily_work_coefficient, a[i].daily_work_coefficient);
    max_absence_hours=max(max_absence_hours, a[i].absence_hours);
    harmonic_loss_sum+=harmonic_component(a[i].performance, a[i].daily_work_coefficient, a[i].absence_hours);
    harmonic_coefficient_sum+=harmonic_component(100, a[i].daily_work_coefficient, 8);}



    fprintf(conclusions_file, "\n\n\n");


    for(i=0; i<5; i++){
	    printf("\nOn day %d of the week, absence started for %3d employees.", i+1, weekday_absence_counts[i]);
	    fprintf(conclusions_file, "On day %d of the week, absence started for %3d employees.\n", i+1, weekday_absence_counts[i]);}


    printf("\n\n\nEnter any number to continue with other values derived from the input data:");
    	fflush(stdout);
        scanf("%d", &i);



	printf("\nThe average monthly distance employees travel from home to work is %.2f kilometers.\n", div(b,n));
    fprintf(conclusions_file,"\n\n\nThe average monthly distance employees travel from home to work is %.2f kilometers.\n", div(b,n));

	printf("The average age at which employees started working at the company is %.2f years.\n", div(d,n));
	fprintf(conclusions_file, "The average age at which employees started working at the company is %.2f years.\n", div(d,n));

	printf("The average daily work coefficient (work value contributed by each employee) ranges between %.6f and %.6f.\n", min_daily_work_coefficient, max_daily_work_coefficient);
	fprintf(conclusions_file, "The average daily work coefficient (difficulty level) ranges between %.6f and %.6f.\n", min_daily_work_coefficient, max_daily_work_coefficient);

    printf("The average employee performance is %.2f%%.\n", div(c, n));
	fprintf(conclusions_file, "The average employee performance is %.2f%%.\n", div(c, n));

	printf("The percentage of employees with disciplinary sanctions is %.2f%%.\n", percentage(e, n));
	fprintf(conclusions_file, "The percentage of employees with disciplinary sanctions is %.2f%%.\n", percentage(e, n));

	printf("The percentage of employees who consume alcohol is %.2f%%.\n", percentage(g, n));
	fprintf(conclusions_file,"The percentage of employees who consume alcohol is %.2f%%.\n", percentage(g, n));

	printf("The percentage of employees who smoke is %.2f%%.\n", percentage(k, n));
	fprintf(conclusions_file, "The percentage of employees who smoke is %.2f%%.\n", percentage(k, n));

	printf("Employees have an average of %.2f children.\n", div(f, n));
	fprintf(conclusions_file, "Employees have an average of %.2f children.\n",  div(f, n));

	printf("Employees have an average of %.2f pets.\n",  div(l, n));
	fprintf(conclusions_file, "Employees have an average of %.2f pets.\n",  div(l, n));

	printf("Employees have an average weight of %.2f kilograms.\n",  div(m, n));
	fprintf(conclusions_file, "Employees have an average weight of %.2f kilograms.\n", div(m, n));

	printf("The average employee height is %.2f centimeters.\n",  div(o, n));
	fprintf(conclusions_file, "The average employee height is %.2f centimeters.\n",  div(o, n));

	printf("The average number of hours employees were absent last year is %.2f hours, with a maximum of %d.\n", div(p, n), max_absence_hours);
	fprintf(conclusions_file, "The average number of hours employees were absent last year is %.2f hours, with a maximum of %d.\n",  div(p, n), max_absence_hours);

	printf("The harmonic mean of work value lost due to absenteeism is %.2f.\n", (float)n/harmonic_loss_sum);
	fprintf(conclusions_file, "The harmonic mean of work value lost due to absenteeism is %.2f.\n", (float)n/harmonic_loss_sum);

	printf("This value represents the equivalent of %.2f days lost on average per employee at 100%% performance.", (float)n/harmonic_loss_sum/(n/harmonic_coefficient_sum));
	fprintf(conclusions_file, "This value represents the equivalent of %.2f days lost on average per employee at 100%% performance.", (float)n/harmonic_loss_sum/(n/harmonic_coefficient_sum));



	printf("\n\n\nEnter any number to continue with the graphical representation of the number of employees absent in each month of the year:");
	    	fflush(stdout);
	        scanf("%d", &i);


	fclose(conclusions_file);




	void display() {
		int i,j;
		char string[150];

		glClearColor(0.0f, 0.3f, 0.6f, 0.85f);
		glClear(GL_COLOR_BUFFER_BIT);
		for(i=0; i<12; i++){
			glBegin(GL_QUADS);
			glColor4f(0.6f, i/10.f, -i/5.f, i/5.f);
			glVertex2f(-0.95+i*0.14, -0.9);
			glVertex2f(-0.82+i*0.14, -0.9);
			glVertex2f(-0.82+i*0.14, -0.9+monthly_absence_counts[i]/60.);
			glVertex2f(-0.95+i*0.14, -0.9+monthly_absence_counts[i]/60.);
			glEnd();

			glRasterPos2f(-0.90+i*0.14, -0.85+monthly_absence_counts[i]/60.);
			sprintf(string, "%d" ,monthly_absence_counts[i]);
			for(j=0; j<strlen(string); j++)
				glutBitmapCharacter(8, string[j]);

			glRasterPos2f(-0.90+i*0.14, -0.96);
			sprintf(string, "%d", i+1);
			for(j=0;j<strlen(string);j++)
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[j]);

		}

		glBegin(GL_QUADS);
		glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
		glVertex2f(0.73, -0.9);
		glVertex2f(0.86, -0.9);
		glVertex2f(0.86, -0.9+monthly_absence_counts[12]/60.);
		glVertex2f(0.73, -0.9+monthly_absence_counts[12]/60.);
		glEnd();

		glRasterPos2f(0.78, -0.85+monthly_absence_counts[12]/60.);
		sprintf(string, "%d" ,monthly_absence_counts[12]);
		for(j=0; j<strlen(string); j++)
			glutBitmapCharacter(8, string[j]);

		glRasterPos2f(0.72, -0.96);
		strcpy(string, "No absences!");
		for(j=0;j<strlen(string);j++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[j]);


		glColor4f(1.0f, 0.7f, -0.4f, 0.15f);
				glRasterPos2f(-0.6, 0.9);
				strcpy(string, "Graphical representation of 740 employees based on the month in which absence occurred.");
				for(i=0; i<strlen(string); i++)
					glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);



		glFlush();
	}


	glutInit(&argc, argv);
		glutInitWindowSize(500, 500);
		glutInitWindowPosition(1000, 300);
		glutCreateWindow("Months of the year");
		glutDisplayFunc(display);
		glutMainLoop();


	return 0;
}
