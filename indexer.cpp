#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include "indexer.hpp"
#include "indice.hpp"
#include "textprocessor.hpp"

namespace fs = std::filesystem;

//inicia o construtor do indice
Indexer::Indexer(Indice& ind)
    :indice(ind)
{

}

void Indexer::varrer_diretorio(const std::string& diretorio){
    
    for (const auto& entrada :fs::directory_iterator(diretorio))
    //iterador que pega todo tipo de arquivo do diretorio para verificação
    {
        if (entrada.is_regular_file() && entrada.path().extension() == ".txt")
        //verifica se o arquivo é regular e verifica se é .txt, se caso for:
        {
            std::string caminho = entrada.path().string();
            indexar_arquivo(caminho);
            //é passado o caminho para o metodo indexar_arquivo
        }
        
    }
    
}

void Indexer::indexar_arquivo(const std::string& diretorio){
    std::ifstream arquivo(diretorio);
    //abre o arquivo de acordo com o diretorio, em modo de leitura

    if (!arquivo.is_open())
    //verifica se o arquivo foi aberto com sucesso, se caso não foi:
    {
        std::cout<<"Erro na abertura do arquivo"<<std::endl;
        //exibe uma mensagem de erro e finaliza o metodo;
        return;
    }
    
    std::string texto((std::istreambuf_iterator<char>(arquivo)),std::istreambuf_iterator<char>());
    //se caso foi aberto com sucesso, a gente pega essa variavel texto e atribui nela o texto dentro do arquivo caractere por caractere do começo ao fim 

    texto = this->processor.converter_texto_letra_miniscula(texto);
    //converte o texto para transformar todas as letras minusculas
    texto = this->processor.remover_pontuacao(texto);
    //converte o texto para remover todas as pontuações do texto
    auto palavras = this->processor.quebrar_texto_para_lista(texto);
    //transforma o texto em uma lista de palavras
    std::string nome_arquivo = fs::path(diretorio).filename().string();
    //extrai apenas o nome do arquivo ex: "texto1.txt" a partir do caminho completo.
    for (const std::string& palavra : palavras)
    {
        this->indice.adicionar_palavra(palavra, nome_arquivo);
        //adiciona palavra por palavra no indice + nome do arquivo
    }
    
    arquivo.close();
}
