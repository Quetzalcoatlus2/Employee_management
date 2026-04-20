/*
  Build a C program that uses an input data file for the project containing at least 10 records.
Program summary:

1. The input data file contains 740 records and 17 fields.
   The project topic is workplace absenteeism, and the file contains data about 740 employees.

2. The data from the file is read into a struct variable named "absenteism" and displayed in the console,
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
	int luni[13]={0};
	int h[8]={0};
	int max_ore=0;
	float maxim=0;
	float minim;
	float armonic_pierderi=0;
	float armonic_coef=0;





	float div(int x, int y){
			float z;
			z=(float)x/y;
			return z;
		}


	float proc(int x, int y){
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


	float armonica(float x, float y, int z){
		float w;
		if(z!=0)
		    w=100*8/(x*y*z);
		else
			w=0;
		return w;
		}




	struct absenteism {
	    int luna_absenta;
		int zi_saptamana_absenta;
		int cost_transport_lunar;
		int distanta_rezidenta_serviciu;
		int vechime;
		int varsta;
		int randament;
		int sanctionat_disciplinar;
		int educatie;
		int copii;
		int consumator_alcool;
		int fumator;
		int animale;
		int greutate;
		int inaltime;
		int ore_absenta;
		float coef_munca_zilnic;

	}a[800], u;





	FILE *absenteism;
	absenteism=fopen("input.txt", "r");

	if(!absenteism){
		printf("File error!!!");
		return 1;
	}



	printf("ABSENCE MONTH     ABSENCE START DAY OF WEEK     MONTHLY TRANSPORT COST     "
			"RESIDENCE-WORK DISTANCE     YEARS AT CURRENT JOB     AGE     "
			"AVERAGE DAILY WORK COEFFICIENT     PERFORMANCE     DISCIPLINARY SANCTIONED     "
			"EDUCATION LEVEL    NUMBER OF CHILDREN     ALCOHOL CONSUMER     SMOKER     "
			"NUMBER OF PETS     WEIGHT     HEIGHT     ABSENCE HOURS\n");



	while(!feof(absenteism)){

		fscanf(absenteism, "%d%d%d%d%d%d%f%d%d%d%d%d%d%d%d%d%d", &a[n].luna_absenta,
				&a[n].zi_saptamana_absenta, &a[n].cost_transport_lunar, &a[n].distanta_rezidenta_serviciu,
				&a[n].vechime, &a[n].varsta, &a[n].coef_munca_zilnic, &a[n].randament,
				&a[n].sanctionat_disciplinar, &a[n].educatie, &a[n].copii, &a[n].consumator_alcool,
				&a[n].fumator, &a[n].animale, &a[n].greutate, &a[n].inaltime, &a[n].ore_absenta);




		printf("      %2d                              %d                                 %d              "
				"          %2d                                %2d                   %d                   "
				"%f                 %3d                   %d                       %d               %d "
				"                 %d                %d              %d             %3d           %d    "
				"       %3d\n",
				a[n].luna_absenta, a[n].zi_saptamana_absenta,a[n].cost_transport_lunar,
				a[n].distanta_rezidenta_serviciu, a[n].vechime, a[n].varsta,a[n].coef_munca_zilnic,
				a[n].randament, a[n].sanctionat_disciplinar, a[n].educatie, a[n].copii,
				a[n].consumator_alcool, a[n].fumator, a[n].animale, a[n].greutate, a[n].inaltime,
				a[n].ore_absenta);
		n++;
	}


    fclose(absenteism);



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
			if(a[i].cost_transport_lunar>a[i+1].cost_transport_lunar){
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
					a[i].cost_transport_lunar,a[i].luna_absenta, a[i].zi_saptamana_absenta,
					a[i].distanta_rezidenta_serviciu, a[i].vechime, a[i].varsta,a[i].coef_munca_zilnic,
					a[i].randament, a[i].sanctionat_disciplinar, a[i].educatie, a[i].copii,
					a[i].consumator_alcool, a[i].fumator, a[i].animale, a[i].greutate, a[i].inaltime,
					a[i].ore_absenta);

	}


	else
		if(b==2){


			do{
			flag=0;
			for(i=0; i<n-1 ;i++)
				if(a[i].vechime>a[i+1].vechime){
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
						a[i].vechime,a[i].luna_absenta, a[i].zi_saptamana_absenta,a[i].cost_transport_lunar,
						a[i].distanta_rezidenta_serviciu, a[i].varsta,a[i].coef_munca_zilnic,
						a[i].randament, a[i].sanctionat_disciplinar, a[i].educatie, a[i].copii,
						a[i].consumator_alcool, a[i].fumator, a[i].animale, a[i].greutate, a[i].inaltime,
						a[i].ore_absenta);
		}


		else
		if(b==3){

			do{
					flag=0;
					for(i=0; i<n-1 ;i++)
						if(a[i].ore_absenta>a[i+1].ore_absenta){
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
								 a[i].ore_absenta, a[i].luna_absenta, a[i].zi_saptamana_absenta,a[i].cost_transport_lunar,
							     a[i].distanta_rezidenta_serviciu, a[i].vechime, a[i].varsta,a[i].coef_munca_zilnic,
						         a[i].randament, a[i].sanctionat_disciplinar, a[i].educatie, a[i].copii,
							     a[i].consumator_alcool, a[i].fumator, a[i].animale, a[i].greutate, a[i].inaltime);






		}}while(b==1 || b==2 || b==3);







    printf("\n\nEnter any number to continue with the number of employees absent in each month of the year:");
    fflush(stdout);
    scanf("%ld", &b);
    printf("\n");



    for(i=0; i<n; i++){
	    switch(a[i].luna_absenta){
	    case 1:
			 luni[0]++;
			 break;
	    case 2:
			 luni[1]++;
			 break;
	    case 3:
			 luni[2]++;
			 break;
	    case 4:
			 luni[3]++;
			 break;
	    case 5:
			 luni[4]++;
			 break;
	    case 6:
			 luni[5]++;
			 break;
	    case 7:
			 luni[6]++;
			 break;
	    case 8:
			 luni[7]++;
			 break;
	    case 9:
			 luni[8]++;
			 break;
	    case 10:
			 luni[9]++;
			 break;
	    case 11:
			 luni[10]++;
			 break;
	    case 12:
			 luni[11]++;
			 break;
	    case 0:
	    	 luni[12]++;
	    	 break;
 }}



    FILE *absenteism_concluzii;
    absenteism_concluzii=fopen("output.txt", "w");

    if(!absenteism_concluzii){
	    printf("Error creating file!!!");
	    return 1;
	    }



    for(i=0; i<12; i++){
	    printf("In month number %2d of last year, %d employees were absent.\n", i+1, luni[i]);
	    fprintf(absenteism_concluzii, "In month number %2d of last year, %d employees were absent.\n", i+1, luni[i]);}


    printf("There were %d employees who were not absent for even one hour last year.\n", luni[12]);
    fprintf(absenteism_concluzii, "There were %d employees who were not absent for even one hour last year.\n", luni[12]);


	printf("\n\nEnter any number to continue with the number of employees whose absence started on a given weekday:");
	fflush(stdout);
    scanf("%ld", &b);


	minim=a[0].coef_munca_zilnic+1;



    for(i=0; i<n; i++){

	    h[a[i].zi_saptamana_absenta-2]++;
		b+=a[i].distanta_rezidenta_serviciu;
	    c+=a[i].randament;
	    d+=a[i].varsta-a[i].vechime;
	    e+=a[i].sanctionat_disciplinar;
	    f+=a[i].copii;
	    g+=a[i].consumator_alcool;
	    k+=a[i].fumator;
	    l+=a[i].animale;
	    m+=a[i].greutate;
	    o+=a[i].inaltime;
	    p+=a[i].ore_absenta;


    maxim=max(maxim, a[i].coef_munca_zilnic);
    minim=min(minim, a[i].coef_munca_zilnic);
    max_ore=max(max_ore, a[i].ore_absenta);
    armonic_pierderi+=armonica(a[i].randament, a[i].coef_munca_zilnic, a[i].ore_absenta);
    armonic_coef+=armonica(100, a[i].coef_munca_zilnic, 8);}



    fprintf(absenteism_concluzii, "\n\n\n");


    for(i=0; i<5; i++){
	    printf("\nOn day %d of the week, absence started for %3d employees.", i+1, h[i]);
	    fprintf(absenteism_concluzii, "On day %d of the week, absence started for %3d employees.\n", i+1, h[i]);}


    printf("\n\n\nEnter any number to continue with other values derived from the input data:");
    	fflush(stdout);
        scanf("%d", &i);



	printf("\nThe average monthly distance employees travel from home to work is %.2f kilometers.\n", div(b,n));
    fprintf(absenteism_concluzii,"\n\n\nThe average monthly distance employees travel from home to work is %.2f kilometers.\n", div(b,n));

	printf("The average age at which employees started working at the company is %.2f years.\n", div(d,n));
	fprintf(absenteism_concluzii, "The average age at which employees started working at the company is %.2f years.\n", div(d,n));

	printf("The average daily work coefficient (work value contributed by each employee) ranges between %.6f and %.6f.\n", minim, maxim);
	fprintf(absenteism_concluzii, "The average daily work coefficient (difficulty level) ranges between %.6f and %.6f.\n", minim, maxim);

    printf("The average employee performance is %.2f%%.\n", div(c, n));
	fprintf(absenteism_concluzii, "The average employee performance is %.2f%%.\n", div(c, n));

	printf("The percentage of employees with disciplinary sanctions is %.2f%%.\n", proc(e, n));
	fprintf(absenteism_concluzii, "The percentage of employees with disciplinary sanctions is %.2f%%.\n", proc(e, n));

	printf("The percentage of employees who consume alcohol is %.2f%%.\n", proc(g, n));
	fprintf(absenteism_concluzii,"The percentage of employees who consume alcohol is %.2f%%.\n", proc(g, n));

	printf("The percentage of employees who smoke is %.2f%%.\n", proc(k, n));
	fprintf(absenteism_concluzii, "The percentage of employees who smoke is %.2f%%.\n", proc(k, n));

	printf("Employees have an average of %.2f children.\n", div(f, n));
	fprintf(absenteism_concluzii, "Employees have an average of %.2f children.\n",  div(f, n));

	printf("Employees have an average of %.2f pets.\n",  div(l, n));
	fprintf(absenteism_concluzii, "Employees have an average of %.2f pets.\n",  div(l, n));

	printf("Employees have an average weight of %.2f kilograms.\n",  div(m, n));
	fprintf(absenteism_concluzii, "Employees have an average weight of %.2f kilograms.\n", div(m, n));

	printf("The average employee height is %.2f centimeters.\n",  div(o, n));
	fprintf(absenteism_concluzii, "The average employee height is %.2f centimeters.\n",  div(o, n));

	printf("The average number of hours employees were absent last year is %.2f hours, with a maximum of %d.\n", div(p, n), max_ore);
	fprintf(absenteism_concluzii, "The average number of hours employees were absent last year is %.2f hours, with a maximum of %d.\n",  div(p, n), max_ore);

	printf("The harmonic mean of work value lost due to absenteeism is %.2f.\n", (float)n/armonic_pierderi);
	fprintf(absenteism_concluzii, "The harmonic mean of work value lost due to absenteeism is %.2f.\n", (float)n/armonic_pierderi);

	printf("This value represents the equivalent of %.2f days lost on average per employee at 100%% performance.", (float)n/armonic_pierderi/(n/armonic_coef));
	fprintf(absenteism_concluzii, "This value represents the equivalent of %.2f days lost on average per employee at 100%% performance.", (float)n/armonic_pierderi/(n/armonic_coef));



	printf("\n\n\nEnter any number to continue with the graphical representation of the number of employees absent in each month of the year:");
	    	fflush(stdout);
	        scanf("%d", &i);


	fclose(absenteism_concluzii);




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
			glVertex2f(-0.82+i*0.14, -0.9+luni[i]/60.);
			glVertex2f(-0.95+i*0.14, -0.9+luni[i]/60.);
			glEnd();

			glRasterPos2f(-0.90+i*0.14, -0.85+luni[i]/60.);
			sprintf(string, "%d" ,luni[i]);
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
		glVertex2f(0.86, -0.9+luni[12]/60.);
		glVertex2f(0.73, -0.9+luni[12]/60.);
		glEnd();

		glRasterPos2f(0.78, -0.85+luni[12]/60.);
		sprintf(string, "%d" ,luni[12]);
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

