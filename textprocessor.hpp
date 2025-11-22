#pragma once
#include <string>
#include <vector>

class TextProcessor
{
public:
    TextProcessor() = default;
    ~TextProcessor() = default;
    std::string converter_texto_letra_miniscula(const std::string& texto);
    //converte um texto que contenha letra maiuscula tudo em minuscula
    std::string remover_pontuacao(const std::string& texto);
    //remove todas as pontuações do texto
    std::vector<std::string> quebrar_texto_para_lista(const std::string& texto);
    //transforma o texto em uma lista de palavras
};
