#pragma once
#include <string>
#include "indice.hpp"
#include "indexer.hpp"
#include "serializer.hpp"
#include "querryprocessor.hpp"

class CommandLine
{
private:
    Indice indice;
    Indexer indexer;
    Serializer serializer;
    QueryProcessor query;

public:
    CommandLine();

    void executar();
    void menu_indexar();
    void menu_buscar();
    void menu_salvar();
    void menu_carregar();
};
