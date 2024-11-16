/*==================================================================*/
                /*Título: Projeto de Avaliação da disciplina LOG1*/
                /*Autor: Pedro Yoshiaki Freitas Nohara*/
                /*Data de início: 15/05/2024*/
                /*Data de término:23/08/2024*/ 
/*==================================================================*/

/*Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/*Variáveis Globais*/
int dia, mes, ano;
int diaspormes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; /*Variável alterada caso o ano seja bissexto*/
int diasporano = 0;
int diaF, mesF, anoF;

/*Protótipos de funções*/
int Bissexto(int ano); /*Recebe o ano da variável global e devolve 1 se bissexto e 0 se não*/
int validardata(int dia, int mes, int ano); /*recebe a data, primeiro verifica se o ano bissexto, se for, altera a variável global diaspormes [1] para 29, depois o mês, depois o dia 
											e se esse dia está conforme a variável diaspormes, caso sim retorna 1 verdadeiro, se não retorna 0 falso*/
void calcularDataFutura(void); /*Recebe as datas capturadas e soma mais 365 dias ou 366 se bissexto, salvando os resultados em diaF, mesF e anoF*/
const char* dia_da_semana(int dia, int mes, int ano); /*Fornece o dia da semana a partir de dia, mes e ano*/
void incrementardata(int *dia, int *mes, int *ano, int v); /*Adicionar datas a partir de um intervalo específico v*/
void processarTreinos(void); /*Gerar datastreinos.txt*/

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
   	 	diaspormes [1] = 28;
   	 	
       if (Bissexto(ano)){ /*Se Bissexto for 1 ajusta os dias de fevereiro*/
           diaspormes[1] = 29; /*Segundo elemento 'fevereiro' vira 29*/
       }
       if (mes < 1 || mes > 12) return 0;
       if (dia < 1 || dia > diaspormes [mes - 1]) return 0;
       return 1;
   }
   
/*Função para calcular a data final*/
   void calcularDataFutura(void) 
   {
    diaF = dia; /*Variáveis glboais*/
    mesF = mes;
    anoF = ano;
    diaspormes [1] = 28;
 	int i; /*Variável local*/
 	
    for (i = 0; i < diasporano; i++) {
        diaF++;
		diaspormes [1] = 28;
        /*Verifica se o ano é bissexto e ajusta fevereiro*/
        if (Bissexto(anoF)) {
            diaspormes[1] = 29;
        } else {
            diaspormes[1] = 28;
        }

        /*Ajusta o dia e avança o mês se necessário*/
        if (diaF > diaspormes[mesF - 1]) {
            diaF = 1;
            mesF++;
        }

        /*Ajusta o mês e avança o ano se necessário*/
        if (mesF > 12) {
            mesF = 1;
            anoF++;
        }
    }
}

/*Função para incrementar data*/
void incrementardata(int *dia, int *mes, int *ano, int v) {
    int diaspormes_local[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Cópia local
    *dia += v;  // Incrementa o dia

    // Atualiza fevereiro para 29 dias se o ano for bissexto
    if (Bissexto(*ano)) {
        diaspormes_local[1] = 29;
    }

    // Ajusta o dia, mês e ano
    while (*dia > diaspormes_local[*mes - 1]) {
        *dia -= diaspormes_local[*mes - 1];  // Subtrai os dias do mês atual
        (*mes)++;  // Incrementa o mês

        if (*mes > 12) {
            *mes = 1;  // Reseta o mês para janeiro
            (*ano)++;  // Incrementa o ano

            // Atualiza fevereiro para o novo ano
            if (Bissexto(*ano)) {
                diaspormes_local[1] = 29;
            } else {
                diaspormes_local[1] = 28;
            }
        }
    }
}

/*Função para processardatasdetreino*/
	void processarTreinos(void) {
	
		int diaA = dia, mesA = mes, anoA = ano; /*Dias de treino Atletismo*/
		int diaN = dia, mesN = mes, anoN = ano; /*Dias de treino Natação*/
		int diaR = dia, mesR = mes, anoR = ano; /*Dias de treino Rugby*/
		int diaJ = dia, mesJ = mes, anoJ = ano; /*Dias de treino Judô*/
  
    	FILE *datasTreinos = fopen("DATASTREINOS.TXT", "w");
    		if (datasTreinos == NULL) 
			{
        		printf("Erro ao abrir o arquivo DATASTREINOS.TXT\n");
        		getch();
        		exit (0);
			}
    
    /*topo do txt*/
        fprintf(datasTreinos,"---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        fprintf(datasTreinos,"                                       As modalidades treinam de %02d/%02d/%04d - (%s) a %02d/%02d/%04d - (%s)                                           \n", dia, mes, ano, dia_da_semana(dia, mes, ano), diaF, mesF, anoF, dia_da_semana(diaF, mesF, anoF));
        fprintf(datasTreinos,"---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		fprintf(datasTreinos, "             Atletismo                                  Natação                                 Rugby                               Judô                \n");
        fprintf(datasTreinos, "          (a cada 2 dias)                           (a cada 3 dias)                        (a cada 5 dias)                    (a cada 9 dias)           \n");
        fprintf(datasTreinos,"---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        
      
  // Loop para processar os treinos
    while ((anoA < anoF) || (anoA == anoF && mesA < mesF) || (anoA == anoF && mesA == mesF && diaA <= diaF)) {
        // Apenas escreve no arquivo se for o dia correto para cada modalidade
        
            fprintf(datasTreinos, "Atletismo: %02d/%02d/%04d - %-13s\t", diaA, mesA, anoA, dia_da_semana(diaA, mesA, anoA));
            
            
			if (anoN < anoF) fprintf(datasTreinos, "Natação: %02d/%02d/%04d - %-13s\t", diaN, mesN, anoN, dia_da_semana(diaN, mesN, anoN));
			else 
			{
				if (anoN == anoF && mesN < mesF) fprintf(datasTreinos, "Natação: %02d/%02d/%04d - %-13s\t", diaN, mesN, anoN, dia_da_semana(diaN, mesN, anoN));
				else 
				{
					if (anoN == anoF && mesN == mesF && diaN <= diaF) fprintf(datasTreinos, "Natação: %02d/%02d/%04d - %-13s\t", diaN, mesN, anoN, dia_da_semana(diaN, mesN, anoN));
					else fprintf(datasTreinos, "                                    ");
				}	
			}
				
		if (anoR < anoF) fprintf(datasTreinos, "Rugby: %02d/%02d/%04d - %-13s\t", diaR, mesR, anoR, dia_da_semana(diaR, mesR, anoR));
			else 
			{
				if (anoR == anoF && mesR < mesF) fprintf(datasTreinos, "Rugby: %02d/%02d/%04d - %-13s\t", diaR, mesR, anoR, dia_da_semana(diaR, mesR, anoR));
				else 
				{
					if (anoR == anoF && mesR == mesF && diaR <= diaF) fprintf(datasTreinos, "Rugby: %02d/%02d/%04d - %-13s\t", diaR, mesR, anoR, dia_da_semana(diaR, mesR, anoR));
					else fprintf(datasTreinos, "                                    ");
				}	
			}		
			
		if (anoJ < anoF)  fprintf(datasTreinos, "Judo: %02d/%02d/%04d - %-13s\n", diaJ, mesJ, anoJ, dia_da_semana(diaJ, mesJ, anoJ));
			else 
			{
				if (anoJ == anoF && mesJ < mesF)   fprintf(datasTreinos, "Judo: %02d/%02d/%04d - %-13s\n", diaJ, mesJ, anoJ, dia_da_semana(diaJ, mesJ, anoJ));
				else 
				{
					if (anoJ == anoF && mesJ == mesF && diaJ <= diaF) fprintf(datasTreinos, "Judo: %02d/%02d/%04d - %-13s\n", diaJ, mesJ, anoJ, dia_da_semana(diaJ, mesJ, anoJ));
					else fprintf(datasTreinos, "                                    \n");
				}	
			}			
				
        /*Atualizar as datas de treino para cada modalidade, se for o caso*/
    
            incrementardata(&diaA, &mesA, &anoA, 2);
            incrementardata(&diaN, &mesN, &anoN, 3);
            incrementardata(&diaR, &mesR, &anoR, 5);
            incrementardata(&diaJ, &mesJ, &anoJ, 9);
        }
        
         fclose(datasTreinos);
}   

/*Função dia da semana*/
const char* dia_da_semana(int dia, int mes, int ano) {
    // Array com os nomes dos dias da semana
    static const char* diasSemana[] = {
        "Domingo", "Segunda-feira", "Terça-feira", 
        "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sábado"
    };

    // Cálculo baseado no algoritmo de Zeller para encontrar o dia da semana
    if (mes < 3) {
        mes += 12;
        ano -= 1;
    }

    int k = ano % 100;
    int j = ano / 100;

    int f = dia + 13 * (mes + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
    int diaSemana = f % 7;

    // Ajustando dia da semana para começar de Domingo (0) a Sábado (6)
    diaSemana = (diaSemana + 5) % 7;

    // Verificando se o índice está dentro dos limites do array
    if (diaSemana < 0 || diaSemana > 6) {
        printf("Erro: Índice do dia da semana fora dos limites!\n");
        return NULL;
    }

    return diasSemana[diaSemana];
}

/*Função para calcular quantas vezes as modalidades se encontram*/
	int mmc(int intervalos[], int n) {
	    int i;
		int a = intervalos[0]; // Começa com o primeiro elemento
	    for (i = 1; i < n; i++) {
	        int b = intervalos[i];
	        // Calcula o Máximo Divisor Comum (MDC) usando o algoritmo de Euclides
	        int x = a, y = b;
	        while (y != 0) {
	            int temp = y;
	            y = x % y;
	            x = temp;
	        }
	        int mdc = x;
	        // Calcula o MMC de a e b
	        a = (a * b) / mdc;
    }
    return a;
}

/*Função para calcular quantas vezes as modalidades se encontram e gerar o arquivo DATASCOMUNS.TXT*/
	void processarDatasComuns(int diasporano){
	
		
		int contadorAtletismo = 1, contadorNatacao = 2, contadorRugby = 4, contadorJudo = 8;
		/*Puxar a fórmula MMC para forncer quantas vezes as modalidades se encontram*/
		int intervalos[] = {2, 3, 5, 9};
    	int tamanho = sizeof(intervalos) / sizeof(intervalos[0]);
    	int resultado = mmc(intervalos, tamanho);
		
		FILE *datasComuns = fopen("DATASCOMUNS.TXT", "w");
    		if (datasComuns == NULL) 
			{
        		printf("Erro ao abrir o arquivo DATASCOMUNS.TXT\n");
        		getch();
        		exit (0);
			}
		
		/*topo do txt*/
        fprintf(datasComuns,"---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        fprintf(datasComuns,"                                                       As 4 modalidades se encontram a cada %i dias                                                      \n", resultado);
        fprintf(datasComuns,"---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		fprintf(datasComuns, "             Atletismo                                  Natação                                 Rugby                               Judô                \n");
        fprintf(datasComuns, "          (a cada 2 dias)                           (a cada 3 dias)                        (a cada 5 dias)                    (a cada 9 dias)           \n");
        fprintf(datasComuns,"---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		
		int cont;
    	for (cont = 0; cont < diasporano; cont++) 
		{
        contadorAtletismo = (contadorAtletismo + 1) % 2;
        contadorNatacao = (contadorNatacao + 1) % 3;
        contadorRugby = (contadorRugby + 1) % 5;
        contadorJudo = (contadorJudo + 1) % 9;
        
        if (contadorAtletismo == 0 && contadorNatacao == 0 && contadorRugby == 0 && contadorJudo == 0) 
		{
            fprintf(datasComuns, "Atletismo: %02d/%02d/%04d - %-13s\t", dia, mes, ano, dia_da_semana(dia, mes, ano));
            fprintf(datasComuns, "Natação: %02d/%02d/%04d - %-13s\t", dia, mes, ano, dia_da_semana(dia, mes, ano));
            fprintf(datasComuns, "Rugby: %02d/%02d/%04d - %-13s\t", dia, mes, ano, dia_da_semana(dia, mes, ano));
            fprintf(datasComuns, "Judô: %02d/%02d/%04d - %-13s\n", dia, mes, ano, dia_da_semana(dia, mes, ano));    
        }

        incrementardata(&dia, &mes, &ano, 1);/*Incrementar data para cada dia*/
		}	
	fclose (datasComuns);
}
	
/*Corpo do programa*/
int main()
{
/*1°Passo: Pegar a data*/
	printf("Insira o dia: ");
    scanf("%d", &dia);
    printf("Insira o mes: ");
    scanf("%d", &mes);
    printf("Insira o ano: ");
    scanf("%d", &ano);
    
    printf ("\nA data inserida foi: %2i/%2i/%4i", dia, mes, ano); /*TESTE*/
    getch();
    
/*2°Passo: Verificar se as datas são válidas*/
    if (validardata (dia, mes, ano) == 0) 
	{
    	printf ("\nData inv%clida", 160);
        getch();
        return 1;
	}
	
/*3°Passo: Verificar se a função validardata+bissexto funcionou*/
	if (Bissexto (ano) == 1) /*Caminho 1*/
	{
		printf ("\nEsse ano é Bissexto");
		printf ("\nFevereiro tem %i dias nesse ano", diaspormes[1]); /*TESTE*/
		
		diasporano = 366;
		getch();				
	}
	else /*Caminho 2*/
	{
		printf ("\nEsse ano não é Bissexto");
		printf ("\nFevereiro tem %i dias nesse ano", diaspormes[1]); /*TESTE*/
		
		diasporano = 365;
		getch();
	}
	printf ("\nEsse ano tem %i dias", diasporano); /*TESTE*/
	getch(); 
	
/*4° Passo: A partir da data inicial definir uma data final*/
	calcularDataFutura(); 
	system ("cls");
	printf ("\nEssa é a data inicial %2d/%2d/%4d", dia, mes, ano);
	printf ("\nEssa é a data final %2d/%2d/%4d", diaF, mesF, anoF); /*TESTE*/
	getch();

/*5° Passo: Processar o arquivo DatasTreinos.txt*/
	processarTreinos();
	
/*6° Passo: Processar o arquivo DatasComuns.txt*/
	printf ("\nEssa é a data inicial %2d/%2d/%4d", dia, mes, ano);
	getch();
	
	processarDatasComuns(diasporano);


/*7° Passo: Abrir os dois arquivos procesados*/	
	system ("Notepad DATASTREINOS.TXT");
	system ("Notepad DATASCOMUNS.TXT");
	getch();
	
    return 0;
}
