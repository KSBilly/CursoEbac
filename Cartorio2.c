#include <stdio.h> //incluido biblioteca de comunicação com usuario
#include <stdlib.h> //incluido espaço para alocação de memoria
#include <locale.h> //incluido alocação de caracteres por região
#include <string.h>

int cadastro()//novas funções podem ser criadas para dividir o programa em etapas o tornando mais leve e funcional
{
	char arquivo[40];//variavel por onde vamos puxar os dados do usuario
	char cpf[40];//principal variavel escolhida pelo programador para encontrar os dados do usuario
	char nome [40];//dados do usuario
	char sobrenome [40];
	char cargo [40];
	
	printf("digite o CPF do Usuário: ");
	scanf("%s", cpf);//%s preencher a variavel STRING com as informações inseridas pelo usuario
	
	strcpy(arquivo, cpf);//copia o cpf dentro da variavel arquivo; a ordem em que as variaveis é colocada interfere no resultado
	
	FILE *file; //cria o arquivo no banco de dados
	file=fopen(arquivo,"w");// W significa que um novo arquivo vai ser escrito
	fprintf(file,cpf); //comando parecido com pritf porem ao inves de exibir o texto ao usuario o texto é salvo no arquivo
	fclose(file);
	
	file=fopen(arquivo,"a");//abre o arquivo e "A" atualiza com os dados inseridos
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome do Usuário: ");
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
	
	printf("digite o cargo do Usuário: ");
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
	
	printf("digite o CPF do Usuário: ");
	scanf ("%s", cpf);
	
	FILE* file;
	file=fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf ("Usuário não cadastrado\n");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
	printf("\nEssas são as informações do Usuário!\n");
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
	
	printf ("Digite o CPF do Usuário que deseja deletar: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file!=NULL)
	{
	printf("Usuário deletado!\n");
	system ("pause");
	}
	else
	{
	printf("Arquivo não encontrado\n");
	system("pause");
	}
	fclose(file);
	remove(cpf);
}

int main()//função principal
{
int opcao=0;
int repetir=1;
	
for (repetir=1;repetir=1;) //ciclo de repetição
{

	system ("cls");

	setlocale(LC_ALL, "portuguese"); //opção de linguagem selecionada BRASIL

	printf("### Cartório da Ebac ###\n\n"); //PRINTF acompanhado de PARENTESES E ASPAS adiciona textos na tela de usuario 
	printf("Olá, por favor, selecione uma opção:\n\n"); //frase de boas vindas
	printf("\t1.Cadastro de Usuário \n"); //opções selecionaveis pelo usuário
	printf("\t2.Consulta de Usuário\n");
	printf("\t3.Excluir Usuário \n"); //fim das opções selecionaveis pelo usuário
	printf("\t4.Sair do sistema.\n");
	printf("Opção:");

	scanf("%d", &opcao); // "%d permite o usuario digitar um numero inteiro""& transforma a variavel"

	system("cls"); //limpa a tela de usuario

	switch (opcao)//comando que facilita as opções de seleção 
	{
		case 1:
		 	cadastro();//voce pode chamar uma função ao colocar ";" ao final da função
		 	break;
		case 2:
			consulta();
			break;
		case 3:
			deletar();
			break;
		case 4:
			printf("obrigado por usar nossos serviços, até a proxima");
			return 0;
			break;
		default:
			printf ("Opção invalida\n");
			system ("pause");
			break;
	}
}
}
