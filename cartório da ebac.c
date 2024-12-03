#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //bliblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string // string são conjuntos de variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação de variáveis/string // lembrando que string é um juntos de variáveis
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string. %s é usado toda vez que precisa salvar uma string/variável
	
	strcpy(arquivo, cpf); // é responsável por copiar os valores das string
	
	FILE *file; //criar o arquivo 
	file = fopen(arquivo, "w"); //criar o arquivo e o "w" significa escrever, que ele vai criar um novo arquivo e já vai escrever.
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fclose é responsável por fechar o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");//"a" é responsável por atualizar o arquivo já existente que criamos com "w"
	fprintf(file,nome);
	fclose(file);
	
		file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
		file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale (LC_ALL, "Portuguese"); //definindo a linguagem 
	
	 char cpf[40];
	 char conteudo[200];
	 
	 printf("Digite o CPF a ser consultado: ");
	 scanf("%s",cpf);
	 
	 FILE *file;
	 file = fopen(cpf, "r"); // "r" é para o computador ler o arquivo
	 
	 if(file == NULL)
	 {
	 	printf("Não foi possivel localizar o arquivo:\n");
	 }
	 
	 while(fgets(conteudo, 200, file) != NULL)
	 {
	 	printf("\n Essas são as informações do usuário: ");
	 	printf("%s", conteudo);
	 	printf("\n\n");
	 }
	 
	 system("pause");
}

int deletar()
{
	 char cpf[40];
	 
	 printf("Digite o CPF do usuário a ser deletado: \n");
	 scanf("%s",cpf);
	 
	 remove(cpf);
	 
	 FILE *file;
	 file = fopen(cpf, "r"); //"r" é para ler 
	 
	 if(file == NULL )
	 {
	 	printf("o usuáro não se encontrta no sistema! \n");
	 	system("pause");
	 }
}

int main()
{
	
	int opcao=0; //definindo as variáveis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls");// "cls" é responsável por limpar a tela
	
	
	setlocale (LC_ALL, "Portuguese"); //definindo a linguagem 
	
	printf("### Cartório da ebac ###\n\n"); //inicio do menu
	printf("escolha a opção desejada do menu:\n\n");
	printf("\t1 - registrar nomes\n");
	printf("\t2 - consultar nomes \n");
	printf("\t3 - Deletar nomes\n"); 
	printf("opção: "); //fim do menu 
	
	scanf("%d", &opcao);// armazenando a escolha do usuário 
	system("cls");
	
	switch(opcao)
	{
		case 1:
		registro(); //chamada de funções
		break; 
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		default:
			printf("essa opção não está disponível\n");
		system("pause");
		break;
	
	
	}
}
}
