#include <fstream>
#include <iostream>
#include "serializer.hpp"
#include "indice.hpp"

Serializer::Serializer(Indice& ind)
    : indice(ind)
{
}

void Serializer::salvar_indice(const std::string& caminho_arquivo)
{
    std::ofstream arquivo(caminho_arquivo);
    //abre o caminho para um arquivo em modo de escrita
    if (!arquivo.is_open())
    //verifica se o arquivo foi aberto corretamente, caso não foi:
    {
        std::cout << "Erro ao abrir arquivo para salvar!" << std::endl;
        return;
        //encerra o metodo
    }

    for (const auto& par : indice.get_indice_invertido())
    {
        const std::string& palavra = par.first;
        const std::vector<int>& lista_ids = par.second;
        

        for (int id : lista_ids)
        {
            const std::string& nome = indice.get_mapa_id_para_arquivo()[id];
            arquivo << palavra << " " << nome << "\n";
        }
    }

    arquivo.close();
}

void Serializer::carregar_indice(const std::string& caminho_arquivo)
{
    std::ifstream arq(caminho_arquivo);

    if (!arq.is_open()) {
        std::cout << "Erro ao abrir arquivo para carregar!\n";
        return;
    }

    std::string palavra, nome_arquivo;

    // LÊ DO JEITO SIMPLES:
    // palavra nome_arquivo
    while (arq >> palavra >> nome_arquivo)
    {
        indice.adicionar_palavra(palavra, nome_arquivo);
    }

    arq.close();
}
