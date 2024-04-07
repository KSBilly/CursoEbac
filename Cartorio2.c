#include <stdio.h> //incluido biblioteca de comunica��o com usuario
#include <stdlib.h> //incluido espa�o para aloca��o de memoria
#include <locale.h> //incluido aloca��o de caracteres por regi�o
#include <string.h>

int cadastro()//novas fun��es podem ser criadas para dividir o programa em etapas o tornando mais leve e funcional
{
	char arquivo[40];//variavel por onde vamos puxar os dados do usuario
	char cpf[40];//principal variavel escolhida pelo programador para encontrar os dados do usuario
	char nome [40];//dados do usuario
	char sobrenome [40];
	char cargo [40];
	
	printf("digite o CPF do Usu�rio: ");
	scanf("%s", cpf);//%s preencher a variavel STRING com as informa��es inseridas pelo usuario
	
	strcpy(arquivo, cpf);//copia o cpf dentro da variavel arquivo; a ordem em que as variaveis � colocada interfere no resultado
	
	FILE *file; //cria o arquivo no banco de dados
	file=fopen(arquivo,"w");// W significa que um novo arquivo vai ser escrito
	fprintf(file,cpf); //comando parecido com pritf porem ao inves de exibir o texto ao usuario o texto � salvo no arquivo
	fclose(file);
	
	file=fopen(arquivo,"a");//abre o arquivo e "A" atualiza com os dados inseridos
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome do Usu�rio: ");
	scanf("%s", nome);
	
	file=fopen(arquivo,"a");
	fprintf(file, nome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
		
	printf ("digite o sobrenome: ");
	scanf("%s", sobrenome);
	
	file=fopen (arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file=fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo do Usu�rio: ");
	scanf("%s", cargo);
	
	file=fopen (arquivo, "a");
	fprintf (file, cargo);
	fclose(file);
}
int consulta()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o CPF do Usu�rio: ");
	scanf ("%s", cpf);
	
	FILE* file;
	file=fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf ("Usu�rio n�o cadastrado\n");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
	printf("\nEssas s�o as informa��es do Usu�rio!\n");
	printf("%s", conteudo);
	printf("\n\n");
	}
	system ("pause");
	fclose (file);
}

int deletar()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	
	printf ("Digite o CPF do Usu�rio que deseja deletar: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file!=NULL)
	{
	printf("Usu�rio deletado!\n");
	system ("pause");
	}
	else
	{
	printf("Arquivo n�o encontrado\n");
	system("pause");
	}
	fclose(file);
	remove(cpf);
}

int main()//fun��o principal
{
int opcao=0;
int repetir=1;
	
for (repetir=1;repetir=1;) //ciclo de repeti��o
{

	system ("cls");

	setlocale(LC_ALL, "portuguese"); //op��o de linguagem selecionada BRASIL

	printf("### Cart�rio da Ebac ###\n\n"); //PRINTF acompanhado de PARENTESES E ASPAS adiciona textos na tela de usuario 
	printf("Ol�, por favor, selecione uma op��o:\n\n"); //frase de boas vindas
	printf("\t1.Cadastro de Usu�rio \n"); //op��es selecionaveis pelo usu�rio
	printf("\t2.Consulta de Usu�rio\n");
	printf("\t3.Excluir Usu�rio \n"); //fim das op��es selecionaveis pelo usu�rio
	printf("\t4.Sair do sistema.\n");
	printf("Op��o:");

	scanf("%d", &opcao); // "%d permite o usuario digitar um numero inteiro""& transforma a variavel"

	system("cls"); //limpa a tela de usuario

	switch (opcao)//comando que facilita as op��es de sele��o 
	{
		case 1:
		 	cadastro();//voce pode chamar uma fun��o ao colocar ";" ao final da fun��o
		 	break;
		case 2:
			consulta();
			break;
		case 3:
			deletar();
			break;
		case 4:
			printf("obrigado por usar nossos servi�os, at� a proxima");
			return 0;
			break;
		default:
			printf ("Op��o invalida\n");
			system ("pause");
			break;
	}
}
}
