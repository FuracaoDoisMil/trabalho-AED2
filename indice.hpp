#pragma once
#include <vector>
#include <string>
#include <unordered_map>

class Indice
{
private:

    std::unordered_map<std::string, std::vector<int>> indice_invertido;
    //Ele pega a palavra e mostra em qual arquivo está. Por exemplo:
    //"gato" --> [documento1.txt]
    //"praia" --> [documento1.txt, documento2.txt, documento98.txt]
    //palavra --> documento


    std::unordered_map<std::string, int> mapa_arquivo_para_id;

    std::vector<std::string> mapa_id_para_arquivo;

    int proximo_id_disponivel;
    
    std::string diretorio_base;

public:

    // construtor padrão
    Indice();

    // destrutor (STL limpa tudo sozinha)
    ~Indice() = default;

    // retorna o ID do arquivo; se não existir, cria um novo
    int obter_id_arquivo(const std::string& nome_arquivo);

    // adiciona uma palavra ao índice invertido
    void adicionar_palavra(const std::string& palavra, const std::string& nome_arquivo);

    // retorna a lista de documentos onde a palavra aparece
    const std::vector<int>& obter_documentos_da_palavra(const std::string& palavra) const;

    // GETTERS para o serializador (somente leitura)
    const std::unordered_map<std::string, std::vector<int>>& get_indice_invertido() const;
    const std::unordered_map<std::string, int>& get_mapa_arquivo_para_id() const;
    const std::vector<std::string>& get_mapa_id_para_arquivo() const;

    // define e obtém o diretório base indexado
    void definir_diretorio_base(const std::string& caminho);
    const std::string& obter_diretorio_base() const;

};