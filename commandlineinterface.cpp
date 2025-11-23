#include <iostream>
#include "commandlineinterface.hpp"

CommandLine::CommandLine()
    : indice(),
      indexer(indice),
      serializer(indice),
      query(indice)
{
    // Aqui no construtor nós apenas inicializamos os objetos.
}

void CommandLine::executar()
{
    int opcao = -1; 
    // variável que controla o menu principal

    while (opcao != 0)
    {
        // mostra menu principal
        std::cout << "\n==== MENU PRINCIPAL ====\n";
        std::cout << "1 - Indexar diretorio\n";
        std::cout << "2 - Buscar palavra\n";
        std::cout << "3 - Salvar indice em arquivo\n";
        std::cout << "4 - Carregar indice de arquivo\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha: ";

        std::cin >> opcao;
        std::cin.ignore();
        // O cin.ignore() limpa o \n que sobra no buffer
        // senão o getline da próxima função lê o ENTER sozinho.

        switch (opcao)
        {
        case 1:
            menu_indexar();
            break;

        case 2:
            menu_buscar();
            break;

        case 3:
            menu_salvar();
            break;

        case 4:
            menu_carregar();
            break;

        case 0:
            std::cout << "Encerrando...\n";
            break;

        default:
            std::cout << "Opcao invalida.\n";
        }
    }
}

void CommandLine::menu_indexar()
{
    std::string dir;

    std::cout << "Digite o caminho do diretorio: ";
    std::getline(std::cin, dir);
    // lê o diretório digitado pelo usuário

    indice.definir_diretorio_base(dir);
    // salva o caminho no objeto Indice

    indexer.varrer_diretorio(dir);
    // o Indexer lê todos os arquivos do diretório e monta o índice invertido

    std::cout << "Indexacao concluida!\n";
}

void CommandLine::menu_buscar()
{
    std::string consulta;

    std::cout << "Digite a consulta: ";
    std::getline(std::cin, consulta);
    // pega o texto da busca (pode ter várias palavras)

    auto resultados = query.buscar(consulta);
    // busca no índice invertido todos os arquivos que contém TODAS as palavras

    if (resultados.empty())
    {
        std::cout << "Nenhum arquivo encontrado.\n";
        return;
    }

    // mostra ao usuário os arquivos encontrados
    std::cout << "Arquivos encontrados:\n";
    for (const auto& arq : resultados)
        std::cout << " - " << arq << "\n";
}

void CommandLine::menu_salvar()
{
    std::string arq;

    std::cout << "Caminho para salvar o indice: ";
    std::getline(std::cin, arq);
    // usuário escolhe onde salvar

    serializer.salvar_indice(arq);
    // cria o arquivo com todo o índice invertido

    std::cout << "Indice salvo.\n";
}

void CommandLine::menu_carregar()
{
    std::string arq;

    std::cout << "Caminho do arquivo de indice: ";
    std::getline(std::cin, arq);
    // usuário informa qual arquivo contém o índice salvo

    serializer.carregar_indice(arq);
    // o Serializer lê o arquivo e recria o índice invertido dentro do objeto Indice

    std::cout << "Indice carregado.\n";
}
