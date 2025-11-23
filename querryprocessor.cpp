#include "querryprocessor.hpp"
#include "indice.hpp"
#include "textprocessor.hpp"
#include <unordered_set>
#include <algorithm>
#include <iostream>

QueryProcessor::QueryProcessor(Indice& ind)
    : indice(ind)
{
}

std::vector<std::string> QueryProcessor::buscar(const std::string& consulta)
{
    std::string texto = processor.converter_texto_letra_miniscula(consulta);
    //normaliza o texto, deixando todas as letras maiúsculas em minúsculas

    texto = processor.remover_pontuacao(texto);
    //remove toda a pontuação do texto (vírgula, ponto, exclamação, etc)

    std::vector<std::string> palavras = processor.quebrar_texto_para_lista(texto);
    //quebra o texto em palavras separadas e guarda todas em um vetor

    if (palavras.empty()) return {};
    //se após normalizar e quebrar o texto, não sobrar nenhuma palavra, encerra e retorna vazio

    const auto& indice_invertido = indice.get_indice_invertido();
    //pega o índice invertido para poder consultar as palavras mapeadas para seus IDs

    const auto& mapa_id_para_arquivo = indice.get_mapa_id_para_arquivo();
    //pega o mapa que converte ID → nome do arquivo

    bool primeira = true;
    //flag que indica se estamos lidando com a primeira palavra da busca

    std::unordered_set<int> resultado_set;
    //estrutura que vai guardar os IDs dos arquivos que possuem TODAS as palavras da consulta

    //para cada palavra da consulta, fazemos a interseção dos arquivos onde elas aparecem
    for (const std::string& palavra : palavras)
    {
        auto it = indice_invertido.find(palavra);
        //procura no índice invertido se essa palavra existe e retorna um iterador para ela

        if (it == indice_invertido.end())
        //se find() não encontrar a palavra, significa que nenhum arquivo possui essa palavra
        //então não existe resultado possível para a consulta → retorna vazio
            return {};

        const std::vector<int>& lista_ids = it->second;
        //pega o vetor contendo todos os IDs dos arquivos que possuem essa palavra

        if (primeira)
        //se for a primeira palavra da busca, não existe interseção ainda
        {
            resultado_set.reserve(lista_ids.size());
            //reserva memória para ser mais eficiente

            for (int id : lista_ids)
                resultado_set.insert(id);
                //adiciona TODOS os IDs dessa primeira palavra (base para as próximas interseções)

            primeira = false;
            //marca que a próxima palavra já não será mais a primeira
        }
        else
        {
            //para as palavras seguintes precisamos fazer interseção de IDs

            std::unordered_set<int> temp;
            temp.reserve(lista_ids.size());
            //tabela hash temporária que contém APENAS os IDs da palavra atual

            for (int id : lista_ids)
                temp.insert(id);
                //insere os IDs da palavra atual

            //agora removemos do resultado_set todos os IDs que NÃO aparecem na palavra atual
            for (auto it2 = resultado_set.begin(); it2 != resultado_set.end(); )
            {
                if (temp.find(*it2) == temp.end())
                    //se o ID atual NÃO aparece na tabela temp,
                    //significa que esse arquivo não tem todas as palavras → remove
                    it2 = resultado_set.erase(it2);
                else
                    //se existir em ambas, mantém no conjunto
                    ++it2;
            }

            if (resultado_set.empty())
                //se depois da interseção não sobrar nenhum arquivo, já pode encerrar e retornar vazio
                return {};
        }
    }

    //converter IDs restantes do conjunto → vetor
    std::vector<int> resultado_ids;
    resultado_ids.reserve(resultado_set.size());

    for (int id : resultado_set)
        resultado_ids.push_back(id);
        //passa os IDs para um vetor normal para podermos ordenar

    std::sort(resultado_ids.begin(), resultado_ids.end());
    //ordena os IDs (apenas para melhorar a apresentação dos resultados)

    std::vector<std::string> resultados;
    resultados.reserve(resultado_ids.size());
    //vetor final que vai guardar os nomes dos arquivos

    for (int id : resultado_ids)
    {
        if (id >= 0 && id < (int)mapa_id_para_arquivo.size())
            resultados.push_back(mapa_id_para_arquivo[id]);
            //converte cada ID encontrado em seu respectivo nome de arquivo
    }

    return resultados;
    //retorna a lista dos nomes dos arquivos encontrados
}
