#pragma once
#include <string>
#include <vector>
#include "indice.hpp"
#include "textprocessor.hpp"

class QueryProcessor
{
private:
    Indice& indice;
    TextProcessor processor;

public:
    QueryProcessor(Indice& ind);
    ~QueryProcessor() = default;

    std::vector<std::string> buscar(const std::string& consulta);
};
