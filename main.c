/*==============================================================*/
                /*Título: Projeto de Avaliação da disciplina LOG1*/
                /*Autor: Pedro Yoshiaki Freitas Nohara*/
                /*Data de início: 15/05/2024*/
                /*Data de término:*/ 
/*==============================================================*/

/*Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/*Definição de constantes*/

/*Definição dos tipos de dados Structure*/

/*Variáveis Globais*/
int dia, mes, ano;
int diaspormes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; /*Array com 12 elementos de 0 a 11*/
int diasporano = 0;

/*Protótipos de funções*/
int Bissexto(int ano);
int validardata(int dia, int mes, int ano);
void diasano (void);


/*Construção das funções*/
/*Função para verificar se o ano é bissexto*/
  int Bissexto(int ano){
  if (ano % 4 == 0){ /*Se o ano é divisível por 4, ele é um candidato a ser bissexto*/
        if (ano % 100 == 0){ /*Se for divísivel por 100, não é, exceto se for 400*/
            if (ano % 400 == 0) return 1; /*Testa pra ver se é 400, se sim bissexto*/
            else return 0;
        } else return 1;
    } else return 0; /*1 se for bissexto e 0 se não*/
}

/*Função para validar data*/
   int validardata(int dia, int mes, int ano){
       if (Bissexto(ano)){ /*Se Bissexto for 1 ajusta os dias de fevereiro*/
           diaspormes[1] = 29; /*Segundo elemento 'fevereiro' vira 29*/
       }
       if (mes < 1 || mes > 12) return 0;
       if (dia < 1 || dia > diaspormes [mes - 1]) return 0;
       return 1;
       
   }
   
/*Função para incrementar dias no ano*/
void diasano (void){
	int i;
		for (i = 0; i<12; i++)
			diasporano = diasporano + diaspormes[i];
}

/*Função para incrementar data*/
void incrementardata(int *dia, int *mes, int *ano) {
    (*dia)++;  // Incrementa o dia
    
    /* Verifica se o dia excedeu o número de dias no mês atual */
    if (*dia > diaspormes[*mes - 1]) {
        *dia = 1;  // Reseta o dia para 1
        (*mes)++;  // Incrementa o mês
        
        /* Verifica se o mês excedeu 12 (dezembro) */
        if (*mes > 12) {
            *mes = 1;  // Reseta o mês para janeiro
            (*ano)++;  // Incrementa o ano
        }
    }
}


/*Função para processardatasdetreino*/
void processarTreinos(int diasporano) {
    int contadorAtletismo = 0, contadorNatacao = 0, contadorRugby = 0, contadorJudo = 0;
  
    FILE *datasTreinos = fopen("DATASTREINOS.TXT", "w");
    FILE *datasComuns = fopen("DATASCOMUNS.TXT", "w");
    
  	int cont;
    for (cont = 0; cont < diasporano; cont++) {
        contadorAtletismo = (contadorAtletismo + 1) % 2;
        contadorNatacao = (contadorNatacao + 1) % 3;
        contadorRugby = (contadorRugby + 1) % 5;
        contadorJudo = (contadorJudo + 1) % 9;

        // Verificar e armazenar
        if (contadorAtletismo == 0) fprintf(datasTreinos, "Atletismo: %02d/%02d/%04d\n", dia, mes, ano);
        if (contadorNatacao == 0) fprintf(datasTreinos, "Natacao: %02d/%02d/%04d\n", dia, mes, ano);
        if (contadorRugby == 0) fprintf(datasTreinos, "Rugby: %02d/%02d/%04d\n", dia, mes, ano);
        if (contadorJudo == 0) fprintf(datasTreinos, "Judo: %02d/%02d/%04d\n", dia, mes, ano);

        if (contadorAtletismo == 0 && contadorNatacao == 0 && contadorRugby == 0 && contadorJudo == 0) {
            fprintf(datasComuns, "Data comum: %02d/%02d/%04d\n", dia, mes, ano);
        }

        incrementardata(&dia, &mes, &ano);
    }

    fclose(datasTreinos);
    fclose(datasComuns);
}

   
/*Corpo do programa*/
int main()
{
    /*Pegar data OK*/
 	printf("Insira o dia: ");
    scanf("%d", &dia);
    printf("Insira o mes: ");
    scanf("%d", &mes);
    printf("Insira o ano: ");
    scanf("%d", &ano);
	
    /*Puxar função validardata que puxa função Bissexto*/
    if (!validardata(dia, mes, ano)){
        printf ("\nData inv%clida", 160);
        getch();
        return 1;
    } else printf ("\nData digitada: %.2i/%.2i/%i", dia, mes, ano);
    
    if (Bissexto(ano) == 1) { /*A Função validar data adiciona um dia a fevereiro se for bissexto*/
    	printf ("\n\nEsse ano %c bissexto", 130);
		printf ("\n\nFevereiro nesse ano tem %i dias", diaspormes[1]); /*Teste de código*/
		diaspormes [1] = 29;
		
		diasano();
		
		printf ("\n\nEsse ano tem %i dias", diasporano);
		getch();
		
		processarTreinos(diasporano);
    	
	}
    else {
    	printf ("\n\nEsse ano não %c Bissexto", 130);
    	printf ("\n\nFevereiro nesse ano tem %i dias", diaspormes[1]); /*Teste de código*/
    	diaspormes [1] = 28;
    	diasano();
		
		printf ("\n\nEsse ano tem %i dias", diasporano);
		getch();
		
		processarTreinos(diasporano);
	}
	
	system ("Notepad DATASCOMUNS.TXT");
	system ("Notepad DATASTREINOS.TXT");
	
    getch();
    
    
    
    return 0;
}
