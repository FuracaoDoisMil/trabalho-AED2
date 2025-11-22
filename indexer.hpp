#pragma once
#include <string>
#include "indice.hpp"
#include "textprocessor.hpp"

class Indexer
{
private:
    Indice& indice;
    TextProcessor processor;

public:
    Indexer(Indice& ind);
    ~Indexer()= default;
    
    void varrer_diretorio(const std::string& diretorio);
    void indexar_arquivo(const std::string& diretorio);
};
