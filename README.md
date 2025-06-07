# 📅 Calculadora de Cronograma de Treinos
Este projeto, desenvolvido em Linguagem C, é uma aplicação que calcula e organiza o cronograma de treinos para quatro modalidades esportivas de um clube (atletismo, natação, rugby e judô) ao longo de um ano.  A partir de uma data inicial fornecida pelo usuário, o programa determina e gera relatórios com os dias de treino de cada modalidade e as datas em que todos os atletas treinam simultaneamente. 

## 🎯 Objetivo do Projeto
O objetivo principal é aplicar conceitos de lógica de programação e manipulação de dados em Linguagem C para resolver um problema prático de agendamento.  O programa valida datas, considera anos bissextos e gera arquivos de texto com relatórios claros e organizados. 

## ✨ Funcionalidades
Validação de Data de Entrada: O programa solicita uma data inicial (dia, mês, ano) e verifica se ela é válida antes de iniciar os cálculos. 
Cálculo de Ano Bissexto: Leva em conta se o ano do período analisado é bissexto para ajustar os cálculos de datas corretamente. 
Geração de Cronogramas Individuais: Calcula as datas de treino para cada modalidade com base em seus intervalos específicos: 
Atletismo: a cada 2 dias
Natação: a cada 3 dias
Rugby: a cada 5 dias
Judô: a cada 9 dias
Identificação de Datas Comuns: O programa calcula o Mínimo Múltiplo Comum (MMC) dos intervalos para descobrir a frequência com que todas as modalidades treinam juntas e lista essas datas. 

Exportação de Relatórios: Ao final do processamento, dois arquivos de texto são gerados: 

DATASTREINOS.TXT: Um relatório completo com todas as datas de treino de todas as modalidades ao longo de um ano. 
DATASCOMUNS.TXT: Um relatório simplificado, mostrando apenas as datas em que todos os quatro times se encontram. 

## 🛠️ Tecnologias Utilizadas
Linguagem: C;
Bibliotecas Padrão: stdio.h, stdlib.h, string.h, conio.h;
Compilador: Desenvolvido e testado no Dev-C++ 5.11.

## 🚀 Como Executar
Compilação: Compile o arquivo main.c utilizando um compilador C. Se estiver usando o GCC, o comando é:
gcc "main (1).c" -o calendario.exe
Execução: Rode o arquivo executável gerado: ./calendario.exe
Interação: O programa solicitará que você insira uma data inicial (dia, mês e ano).
Resultados: Após a inserção de uma data válida, o programa irá processar os dados e, ao final, abrirá automaticamente os dois arquivos de relatório gerados (DATASTREINOS.TXT e DATASCOMUNS.TXT) no Bloco de Notas.

## 🧠 Conclusões e Aprendizados
A construção deste projeto permitiu aprofundar conhecimentos em áreas cruciais da programação em C, como:

Lógica Algorítmica: Desenvolver o raciocínio para manipular datas, incrementá-las em laços e verificar condições complexas.
Modularização: Organizar o código em funções bem definidas (validardata, Bissexto, processarTreinos), tornando-o mais limpo e de fácil manutenção.
Manipulação de Arquivos: Praticar a criação, escrita e formatação de arquivos de texto (.TXT) para apresentar dados de forma clara ao usuário final.
Matemática Aplicada: Utilizar o cálculo de MMC para resolver um requisito funcional do problema.
