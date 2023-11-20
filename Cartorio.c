#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca repons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios do sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //Copiando dados cpf para arquivo
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria e escreve "modo "w" de write significa escrever"
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre arquivo no modo de atualiza��o "a"
	fprintf(file, ","); //insere a v�rgula ap�s cpf digitado pelo usu�rio
	fclose(file); //fecha arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coleta nome digitado pelo usu�rio
	scanf("%s", nome); // %s "string"
	
	file = fopen(arquivo, "a"); // abre arquivo no modo de atualiza��o
	fprintf(file, nome); // salva o nome digitado pelo usu�rio em file
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a"); // abre arquivo no modo de atualiza��o "a
	fprintf(file, ","); // salva a v�rgula ap�s nome do arquivo
	fclose(file); // fecha arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // Solicita ao usu�rio digite o sobrenome
	scanf("%s", sobrenome); // refere-se sobrenome a string
	
	file = fopen(arquivo, "a"); // abre arquivo no modo de atualiza��o
	fprintf(file, sobrenome); // salva em file
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a"); //abre arquivo no modo de atualiza��o
	fprintf(file, ","); // salva a virgula ap�s nome do arquivo
	fclose(file); // fecha arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // Solicita ao usu�rio digitar o cargo
	scanf("%s", cargo); // tipo de dado string
	
	file = fopen(arquivo, "a"); // abre arquivo no modo atualiza��o "a"
	fprintf(file, cargo); // salva dados em file
	fclose(file);	// fecha arquivo
	system("pause"); // pausa para o usu�rio ver na tela o campo a ser digitado	
}


int consulta() // fun��o consultar usu�rio cadastrado
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; // var cpf tipo string com at� 40 caractere
	char conteudo[200]; // var conte�do at� no m�ximo 200 caractere
	
	printf("Digite o CPF  a ser consultado: "); // solicita ao usu�rio o cpf (que � como o id, que identifica o usu�rio)
	scanf("%s", cpf); // cpf tipo string
	
	FILE *file; //busca todos os dados
	file = fopen(cpf, "r"); // arquivo file cpf no modo de leitura "r" read
	
	if(file == NULL) // se o arquivo digitado pelo usu�rio for nulo
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n"); //mensagem de usu�rio n�o encontrado
	}
	
	while(fgets(conteudo, 200, file) != NULL) // fgets obt�m... 200 = num m�ximo da busca no arquivo file
											  // enquanto a busca por todos os conte�dos for diferente de nullo ou houver dado
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); // mostra informa��es do arquivo
		printf("%s", conteudo); // tipo string
		printf("\n\n"); // pula duas linhas
	}

	system("pause"); // pausa o sistema para visualizar as informa��es		
}


int deletar() // fun��o deletar ou "apagar" em portugu�s
{
	char cpf[40]; // var cpf at� 40 caracteres
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //mensagem para o usu�rio digitar cpf
	scanf("%s", cpf); // tipo string
	remove(cpf); // apaga arquivo
	
	FILE *file; // busca todos os dados 
	file = fopen(cpf, "r"); // abre arquivo no modo read "r" "leitura"
	
	if(file == NULL) // caso o arquivo seja nulo 
	{
		printf("Usu�rio n�o se encontra no sistema!.\n"); // mensagem de usu�rio n�o encontrado para apagar ou "j� foi apagado"
		system("pause"); // pausa
	}
}


int main() // fun��o principal "primeira a ser executada"
{
	int opcao=0; // var opcao igual a zero
	int laco=1; // var laco igual a um
	for(laco=1; laco=1;) // la�o for "para inicio, fim" como in�cio � igual ao fim, la�o infinito....
	{
		system("cls"); //executa o comando do terminal cls que limpa a tela
	
		setlocale(LC_ALL, "Portuguese"); //seleciona idioma regional "exibi��o correta dos caracteres com acento"
	
		printf("### Cart�rio da EBAC ###\n\n"); //t�tulo do menu do sistema
		printf("Escolha a op��o desejada do menu:\n\n"); // op��o de escolha 
		printf("\t1 - Registrar nomes\n"); // op��o 1 (o \t apenas tabula)
		printf("\t2 - Consultar nomes\n"); // op��o 2
		printf("\t3 - Deletar nomes\n\n"); // op��o 3
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");
	
		scanf("%d", &opcao); // define op��o escolhida pelo usu�rio
		system("cls"); // limpa a tela
				
		switch(opcao) //inicia a sele��o do menu
		{
			case 1:
				registro(); // chamada de fun��es (executa a fun��o registro se escolhido)
				break; // parada (corta o la�o)
			
			case 2:
				consulta(); // executa fun��o consulta se opcao = 2
				break; // finaliza o la�o for aqui se executado
				
			case 3:
				deletar(); // executa deletar se opcao = 3
				break; // break no la�o for
				
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
				
			default:
				printf("Esta op��o n�o esta dispon�vel!\n"); // se opcao for algo diferente de 1, 2, 3
				system("pause"); //pausa
				break; // break no la�o
		}	
	}			
}

