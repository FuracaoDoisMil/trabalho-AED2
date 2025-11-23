#pragma once
#include <string>
#include "indice.hpp"

class Serializer
{
private:
    Indice& indice;

public:
    Serializer(Indice& ind);
    ~Serializer() = default;

    void salvar_indice(const std::string& caminho_arquivo);
    void carregar_indice(const std::string& caminho_arquivo);
    
};
