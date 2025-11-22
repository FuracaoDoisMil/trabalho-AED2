#include <iostream>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include "indice.hpp"

Indice::Indice(){
    proximo_id_disponivel = 0;
    diretorio_base = "";
}

int Indice::obter_id_arquivo(const std::string& nome_arquivo){
    if (this->mapa_arquivo_para_id.count(nome_arquivo) > 0)
    //verifica se o nome_arquivo(chave) já esta dentro do mapa_arquivo_para_id
    //se caso estiver ele retorna o id(valor)
    {
        return this->mapa_arquivo_para_id[nome_arquivo];
    }else{
        //se caso não estiver dentro da tabela hash, ele adiciona
        //adiciona o nome_arquivo(chave) na tabela junto com seu id(valor)
        //adiciona o nome_arquivo(chave) no vetor id_para_arquivo
        //e retorna o id(valor) do nome_arquivo(chave)
        this->mapa_arquivo_para_id.insert({nome_arquivo, this->proximo_id_disponivel});
        this->mapa_id_para_arquivo.push_back(nome_arquivo);
        this->proximo_id_disponivel++;
        return this->proximo_id_disponivel-1;
    }
}

void Indice::adicionar_palavra(const std::string& palavra, const std::string& nome_arquivo){
    int id = obter_id_arquivo(nome_arquivo);
    //gera o id para o arquivo
    if (this->indice_invertido.count(palavra) > 0)
    //verifica se a palavra já existe, se caso ela existir:
    {
        std::vector<int>&lista = this->indice_invertido[palavra];
        //vetor que recebo todos os ids dos arquivos que possui a palavra
        bool existe = false;
        for (int id_lista : lista)
        {
            if (id_lista == id)
            //verifica se os ids são iguais, se caso for,
            //termina a execução do metodo
            {
                existe = true;
                break;
            }
            
        }
        
        if (!existe)
        //se caso não existir, adiciona o id na lista
        {
            lista.push_back(id);
        }
        
        
        
    }else{
        //se caso a palavra não estiver no nosso indice,
        //ela é adicionado junto com o id gerado anteriormente
        this->indice_invertido[palavra] = {id};
    }
    
}
//GETTERS///////////////////////////////////////////////
const std::unordered_map<std::string, std::vector<int>>& Indice::get_indice_invertido() const{
    return this->indice_invertido;
}
const std::unordered_map<std::string, int>& Indice::get_mapa_arquivo_para_id() const{
    return this->mapa_arquivo_para_id;
}

const std::vector<std::string>& Indice::get_mapa_id_para_arquivo() const{
    return this->mapa_id_para_arquivo;
}
const std::string& Indice::obter_diretorio_base() const{
    return this->diretorio_base;
}
////////////////////////////////////////////////////////

void Indice::definir_diretorio_base(const std::string& caminho){
    //recebe o caminho do arquivo
    this->diretorio_base = caminho;
}
