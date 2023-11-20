#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca reponsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários do sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //Copiando dados cpf para arquivo
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria e escreve "modo "w" de write significa escrever"
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre arquivo no modo de atualização "a"
	fprintf(file, ","); //insere a vírgula após cpf digitado pelo usuário
	fclose(file); //fecha arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coleta nome digitado pelo usuário
	scanf("%s", nome); // %s "string"
	
	file = fopen(arquivo, "a"); // abre arquivo no modo de atualização
	fprintf(file, nome); // salva o nome digitado pelo usuário em file
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a"); // abre arquivo no modo de atualização "a
	fprintf(file, ","); // salva a vírgula após nome do arquivo
	fclose(file); // fecha arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // Solicita ao usuário digite o sobrenome
	scanf("%s", sobrenome); // refere-se sobrenome a string
	
	file = fopen(arquivo, "a"); // abre arquivo no modo de atualização
	fprintf(file, sobrenome); // salva em file
	fclose(file); // fecha arquivo
	
	file = fopen(arquivo, "a"); //abre arquivo no modo de atualização
	fprintf(file, ","); // salva a virgula após nome do arquivo
	fclose(file); // fecha arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // Solicita ao usuário digitar o cargo
	scanf("%s", cargo); // tipo de dado string
	
	file = fopen(arquivo, "a"); // abre arquivo no modo atualização "a"
	fprintf(file, cargo); // salva dados em file
	fclose(file);	// fecha arquivo
	system("pause"); // pausa para o usuário ver na tela o campo a ser digitado	
}


int consulta() // função consultar usuário cadastrado
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; // var cpf tipo string com até 40 caractere
	char conteudo[200]; // var conteúdo até no máximo 200 caractere
	
	printf("Digite o CPF  a ser consultado: "); // solicita ao usuário o cpf (que é como o id, que identifica o usuário)
	scanf("%s", cpf); // cpf tipo string
	
	FILE *file; //busca todos os dados
	file = fopen(cpf, "r"); // arquivo file cpf no modo de leitura "r" read
	
	if(file == NULL) // se o arquivo digitado pelo usuário for nulo
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n"); //mensagem de usuário não encontrado
	}
	
	while(fgets(conteudo, 200, file) != NULL) // fgets obtém... 200 = num máximo da busca no arquivo file
											  // enquanto a busca por todos os conteúdos for diferente de nullo ou houver dado
	{
		printf("\nEssas são as informações do usuário: "); // mostra informações do arquivo
		printf("%s", conteudo); // tipo string
		printf("\n\n"); // pula duas linhas
	}

	system("pause"); // pausa o sistema para visualizar as informações		
}


int deletar() // função deletar ou "apagar" em português
{
	char cpf[40]; // var cpf até 40 caracteres
	
	printf("Digite o CPF do usuário a ser deletado: "); //mensagem para o usuário digitar cpf
	scanf("%s", cpf); // tipo string
	remove(cpf); // apaga arquivo
	
	FILE *file; // busca todos os dados 
	file = fopen(cpf, "r"); // abre arquivo no modo read "r" "leitura"
	
	if(file == NULL) // caso o arquivo seja nulo 
	{
		printf("Usuário não se encontra no sistema!.\n"); // mensagem de usuário não encontrado para apagar ou "já foi apagado"
		system("pause"); // pausa
	}
}


int main() // função principal "primeira a ser executada"
{
	int opcao=0; // var opcao igual a zero
	int laco=1; // var laco igual a um
	for(laco=1; laco=1;) // laço for "para inicio, fim" como início é igual ao fim, laço infinito....
	{
		system("cls"); //executa o comando do terminal cls que limpa a tela
	
		setlocale(LC_ALL, "Portuguese"); //seleciona idioma regional "exibição correta dos caracteres com acento"
	
		printf("### Cartório da EBAC ###\n\n"); //título do menu do sistema
		printf("Escolha a opção desejada do menu:\n\n"); // opção de escolha 
		printf("\t1 - Registrar nomes\n"); // opção 1 (o \t apenas tabula)
		printf("\t2 - Consultar nomes\n"); // opção 2
		printf("\t3 - Deletar nomes\n\n"); // opção 3
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");
	
		scanf("%d", &opcao); // define opção escolhida pelo usuário
		system("cls"); // limpa a tela
				
		switch(opcao) //inicia a seleção do menu
		{
			case 1:
				registro(); // chamada de funções (executa a função registro se escolhido)
				break; // parada (corta o laço)
			
			case 2:
				consulta(); // executa função consulta se opcao = 2
				break; // finaliza o laço for aqui se executado
				
			case 3:
				deletar(); // executa deletar se opcao = 3
				break; // break no laço for
				
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
				
			default:
				printf("Esta opção não esta disponível!\n"); // se opcao for algo diferente de 1, 2, 3
				system("pause"); //pausa
				break; // break no laço
		}	
	}			
}

