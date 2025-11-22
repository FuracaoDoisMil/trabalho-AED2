#include <string>
#include <vector>
#include "textprocessor.hpp"

std::string converter_texto_letra_miniscula(const std::string& texto){
    std::string texto_minusculo;
    //variavel que vai receber o texto minusculo
    texto_minusculo.reserve(texto.size());
    //reserva o espaço necessario na memoria, deixando o programa mais eficiente

    for (char letra : texto)
    {
        if (letra >= 'A' && letra <= 'Z')
        //verifica se a letra é maiuscula(dentro do intervalo entre 65 a 90), se caso for:
        {
            letra = letra+32;
            //soma a letra com o 32, assim de acordo com a tabela ascci, transforma a letra maiuscula em minuscula(dentro do intervalo entre 97 a 122)
            texto_minusculo.push_back(letra);
            //adiciona letra para a variavel texto_minusculo
        }else{
            //se caso não for:
            texto_minusculo.push_back(letra);
            //adiciona letra para a variavel texto_minusculo
        }
        
    }
    
    return texto_minusculo;
}

std::string remover_pontuacao(const std::string& texto){
    std::string remover;
    //variavel que vai receber o texto sem pontuação

    remover.reserve(texto.size());
    //reserva o espaço necessario na memoria, deixando o programa mais eficiente
    for (char letra : texto)
    {
        if ((letra >= 'A' && letra <='Z') || (letra >= 'a' && letra <= 'z') || (letra == 32))
        //verifica se a letra é diferente de pontuação, se caso for:
        {
            remover.push_back(letra);
            //adiciona letra para a variavel remover
        }
        //se caso não for, ignora e passa para proxima letra
    }
    
    return remover;
}

std::vector<std::string> quebrar_texto_para_lista(const std::string& texto){
    std::vector<std::string> lista_palavras;
    //vetor que vai receber as palavras quebradas
    std::string palavra;
    //variavel que vai receber as palavras
    for (char letra : texto)
    {
        if (letra != 32)
        //verifica se letra é diferente de espaço, se caso for:
        {
            palavra.push_back(letra);
            //adiciona letra para a variavel palavra
        }else if(letra == 32){
            //se caso for um espaço:
            if (!palavra.empty())
            //verifica se palavra é vazio, para garantir que não adicione isso na lista de palavras: ("")
            {
                lista_palavras.push_back(palavra);
                //adiciona letra para a string
            }
            
            palavra.clear();
            //limpa a variavel palavra
        }
    }
    if (!palavra.empty())
    //essa verificação garante que seja insirido a ultima palavra do texto
    {
        lista_palavras.push_back(palavra);
        //adiciona letra para a string
    }
    return lista_palavras;
}
