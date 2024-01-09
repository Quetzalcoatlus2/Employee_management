/*
  Realizati un program in C in care sa va folositi de un fisier cu date de intrare pentru proiect ce va contine minim 10 inregistrari.
Rezumatul programului:

1. Fisierul cu date de intrare contine 740 de inregistrari si 17 campuri.
   Tema proiectului este absenteismul la munca, fisierul continand date despre 740 de angajati.

2. Datele din fisier sunt citite intr-o variabila de tip struct numita "absenteism" si sunt afisate in consola fara ca fisierul de intrare sa contina numarul de inregistrari.

3. Utilizatorul poate acum alege o varianta de ordonare crescatoare in care criteriul dupa care se face sortarea va aparea pe prima coloana din 3 optiuni sau poate trece mai departe fara sa aleaga un tip de ordonare:
   a) dupa costul lunar de deplasare la locul de munca a fiecarui angajat
   b) dupa numarul de ani de cand fiecare angajat lucreaza la firma
   c) dupa numarul de ore absentat in anul precedent
   Dupa fiecare ordonare aleasa, utilizatorul poate alege sa mai faca o ordonare.
   Cand utilizatorul a facut toate ordonarile dorite, acesta poate merge mai departe.

4. Se calculeaza, se afiseaza in consola si se scrie in fisierul cu date de iesire cati angajati au absentat in fiecare luna si cati nu au absentat deloc.

5. Se calculeaza, se afiseaza in consola si se scrie in fisierul cu date de iesire cati angajati au absentat in fiecare zi a saptamananii.

6. Se calculeaza, se afiseaza in consola si se scrie in fisierul cu date de iesire, folosindu-te de functii utilizator (impartire, procentaj, maxim, minim, medie armonica) diverse date derivate:
   -distanta medie parcursa de angajati lunar intre rezidenta si locul de munca;
   -varsta medie la care angajatii s-au angajat la firma;
   -valorile maxime si minime ale coeficientului mediu zilnic de munca (valoarea muncii depuse de fiecare angajat);
   -randamentul mediu al angajatilor;
   -procentul de angajati sanctionati disciplinar;
   -procentul de consumatori de alcool;
   -procentul de fumatori;
   -numarul mediu de copii;
   -numarul mediu de animale de companie;
   -greutatea medie;
   -inaltimea medie;
   -numarul mediu absentat de angajati anul trecut;
   -media armonica a coeficientului zilnic de munca pierdut din absente;
   -cate zile a pierdut, in medie, fiecare angajat, considerandu-se un randament de 100%.

7. Se reprezinta in modul grafic numarul de angajati absenti pentru fiecare luna a anului precedent.



   Baza de date de unde au fost luate datele din fisierul de intrare (17 coloane din 21): https://data.world/aaizemberg/absenteeismatwork/workspace/file?filename=Absenteeism_at_work.tsv

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
	absenteism=fopen("intrare.txt", "r");

	if(!absenteism){
		printf("Eroare fisier!!!");
		return 1;
	}



	printf("LUNA ABSENTEI     ZIUA DE INCEPUT A ABSENTEI DIN SAPTAMANA     COST LUNAR TRANSPORT     "
			"DISTANTA REZIDENTA-SERVICIU     VECHIME LOC DE MUNCA ACTUAL     VARSTA     "
			"COEFICIENT MEDIU ZILNIC DE MUNCA     RANDAMENT     SANCTIONAT DISCIPLINAR     "
			"NIVEL EDUCATIE    NUMAR COPII     CONSUMATOR ALCOOL     FUMATOR     "
			"NUMAR ANIMALE     GREUTATE     INALTIME     ORE ABSENTA\n");



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



	printf("\n\nNumarul de inregistrari este %d.", n);


	do{
	printf("\nAlegeti criteriul dupa care vreti sa faceti ordonarea datelor.\n"
			"Daca doriti ordonarea dupa costul lunar de deplasare la locul de munca, apasati '1'.\n"
			"Daca doriti ordonarea dupa numarul de ani de cand angajatii lucreaza la firma, apasati '2'.\n"
			"Daca doriti ordonarea dupa numarul de ore absentate anul trecut, apasati '3'.\n"
			"Dupa ordonare, puteti introduce din nou una dintre cele 3 cifre pentru o nous ordonare.\n"
			"Daca sunteti multumit cu ordonarea/ordonarile facute sau daca nu doriti sa faceti vreo ordonare si doriti sa mergeti mai departe, apasati '0'.\n"
			"Introduceti cifra corespunzatoare alegerii dumneavoastra:");

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


		printf("\n\n\nCOST LUNAR TRANSPORT     LUNA ABSENTEI     ZIUA DE INCEPUT A ABSENTEI DIN SAPTAMANA     "
							"DISTANTA REZIDENTA-SERVICIU     VECHIME LOC DE MUNCA ACTUAL     VARSTA     "
							"COEFICIENT MEDIU ZILNIC DE MUNCA     RANDAMENT     SANCTIONAT DISCIPLINAR     "
							"NIVEL EDUCATIE    NUMAR COPII     CONSUMATOR ALCOOL     FUMATOR     "
							"NUMAR ANIMALE     GREUTATE     INALTIME     ORE ABSENTA\n");



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


			printf("\n\n\nVECHIME LOC DE MUNCA ACTUAL     LUNA ABSENTEI     ZIUA DE INCEPUT A ABSENTEI DIN SAPTAMANA     "
					"COST LUNAR TRANSPORT     DISTANTA REZIDENTA-SERVICIU     VARSTA     "
						"COEFICIENT MEDIU ZILNIC DE MUNCA     RANDAMENT     SANCTIONAT DISCIPLINAR     "
						"NIVEL EDUCATIE    NUMAR COPII     CONSUMATOR ALCOOL     FUMATOR     "
						"NUMAR ANIMALE     GREUTATE     INALTIME     ORE ABSENTA\n");




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


			printf("     \n\n\nORE ABSENTA     LUNA ABSENTEI     ZIUA DE INCEPUT A ABSENTEI DIN SAPTAMANA     COST LUNAR TRANSPORT     "
						"DISTANTA REZIDENTA-SERVICIU     VECHIME LOC DE MUNCA ACTUAL     VARSTA     "
						"COEFICIENT MEDIU ZILNIC DE MUNCA     RANDAMENT     SANCTIONAT DISCIPLINAR     "
						"NIVEL EDUCATIE    NUMAR COPII     CONSUMATOR ALCOOL     FUMATOR     "
						"NUMAR ANIMALE     GREUTATE     INALTIME\n");


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







    printf("\n\nIntroduceti orice cifra pentru a continua cu numarul de angajati ce au absentat intr-una din lunile anului:");
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
    absenteism_concluzii=fopen("iesire.txt", "w");

    if(!absenteism_concluzii){
	    printf("Eroare la crearea fisierului!!!");
	    return 1;
	    }



    for(i=0; i<12; i++){
	    printf("In luna numarul %2d a anului trecut au absentat %d angajati.\n", i+1, luni[i]);
	    fprintf(absenteism_concluzii, "In luna numarul %2d a anului trecut au absentat %d angajati.\n", i+1, luni[i]);}


    printf("Au fost %d angajati care nu au absentat nici macar o ora anul trecut.\n", luni[12]);
    fprintf(absenteism_concluzii, "Au fost %d angajati care nu au absentat nici macar o ora anul trecut.\n", luni[12]);


	printf("\n\nIntroduceti orice cifra pentru a continua cu numarul de angajati a caror absentare a inceput intr-o anumita zi a saptamanii:");
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
	    printf("\nIn ziua %d a saptamanii a inceput absentarea pentru %3d angajati.", i+1, h[i]);
	    fprintf(absenteism_concluzii, "In ziua %d a saptamanii a inceput absentarea pentru %3d angajati.\n", i+1, h[i]);}


    printf("\n\n\nIntroduceti orice cifra pentru a continua cu alte date derivate din datele de intrare:");
    	fflush(stdout);
        scanf("%d", &i);



	printf("\nDistanta medie pe care angajatii o parcurg de acasa la locul de munca lunar este %.2f kilometri.\n", div(b,n));
    fprintf(absenteism_concluzii,"\n\n\nDistanta medie pe care angajatii o parcurg de acasa la locul de munca lunar este %.2f kilometri.\n", div(b,n));

	printf("Varsta medie a angajatilor la care au inceput sa lucreze la firma este %.2f lei.\n", div(d,n));
	fprintf(absenteism_concluzii, "Varsta medie a angajatilor la care au inceput sa lucreze la firma este %.2f lei.\n", div(b,n));

	printf("Coeficientul mediu zilnic de munca (valoarea muncii depuse de fiecare angajat) variaza intre %.6f si %.6f.\n", minim, maxim);
	fprintf(absenteism_concluzii, "Coeficientul mediu zilnic de munca (nivelul de dificultate) variaza intre %.6f si %.6f.\n", minim, maxim);

    printf("Randamentul mediu al angajatilor este %.2f%%.\n", div(c, n));
	fprintf(absenteism_concluzii, "Randamentul mediu al angajatilor este %.2f%%.\n", div(c, n));

	printf("Procentul de angajati sanctionati disciplinar este %.2f%%.\n", proc(e, n));
	fprintf(absenteism_concluzii, "Procentul de angajati sanctionati disciplinar este %.2f%%.\n", proc(e, n));

	printf("Procentul de angajati consumatori de alcool este %.2f%%.\n", proc(g, n));
	fprintf(absenteism_concluzii,"Procentul de angajati consumatori de alcool este %.2f%%.\n", proc(g, n));

	printf("Procentul de angajati fumatori este %.2f%%.\n", proc(k, n));
	fprintf(absenteism_concluzii, "Procentul de angajati fumatori este %.2f%%.\n", proc(k, n));

	printf("Angajatii au in medie %.2f copii.\n", div(f, n));
	fprintf(absenteism_concluzii, "Angajatii au in medie %.2f copii.\n",  div(f, n));

	printf("Angajatii au in medie %.2f animale de companie.\n",  div(l, n));
	fprintf(absenteism_concluzii, "Angajatii au in medie %.2f animale de companie.\n",  div(l, n));

	printf("Angajatii au in medie %.2f kilograme.\n",  div(m, n));
	fprintf(absenteism_concluzii, "Angajatii au in medie %.2f kilograme.\n", div(m, n));

	printf("Inaltimea medie a angajatilor este %.2f centimetri.\n",  div(o, n));
	fprintf(absenteism_concluzii, "Inaltimea medie a angajatilor este %.2f centimetri.\n",  div(o, n));

	printf("Numarul mediu de ore pe care angajatii l-au absentat anul trecut este %.2f ore, maximul fiind %d.\n", div(p, n), max_ore);
	fprintf(absenteism_concluzii, "Numarul mediu de ore pe care angajatii l-au absentat anul trecut este %.2f ore, maximul fiind %d.\n",  div(p, n), max_ore);

	printf("Media armonica a valorii muncii pierdute din cauza absentarii este %.2f.\n", (float)n/armonic_pierderi);
	fprintf(absenteism_concluzii, "Media armonica a valorii muncii pierdute din cauza absentarii este %.2f.\n", (float)n/armonic_pierderi);

	printf("Aceasta valoare reprezinta echivalentul a %.2f zile pierdute de fiecare angajat in medie cu un randament de 100%%.", (float)n/armonic_pierderi/(n/armonic_coef));
	fprintf(absenteism_concluzii, "Aceasta valoare reprezinta echivalentul a %.2f zile pierdute de fiecare angajat in medie cu un randament de 100%%.", (float)n/armonic_pierderi/(n/armonic_coef));



	printf("\n\n\nIntroduceti orice cifra pentru a continua cu reprezentarea grafica a numarului de angajati ce au absentat in fiecare luna a anului:");
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
		strcpy(string, "Fara absente!");
		for(j=0;j<strlen(string);j++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[j]);


		glColor4f(1.0f, 0.7f, -0.4f, 0.15f);
				glRasterPos2f(-0.6, 0.9);
				strcpy(string, "Reprezentare grafica a celor 740 de angajati pe baza lunii anului in care a avut loc absentarea.");
				for(i=0; i<strlen(string); i++)
					glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);



		glFlush();
	}


	glutInit(&argc, argv);
		glutInitWindowSize(500, 500);
		glutInitWindowPosition(1000, 300);
		glutCreateWindow("Lunile anului");
		glutDisplayFunc(display);
		glutMainLoop();


	return 0;
}


