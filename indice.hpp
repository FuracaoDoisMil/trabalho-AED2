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
    //É uma tabela hash que guarda e busca a relação: nome do arquivo -> id numerico
    //Exemplos: "documento1.txt" -> 0, "cachorros.txt" -> 1, "receita_macarrao.txt" -> 2


    std::vector<std::string> mapa_id_para_arquivo;
    //Este vetor serve para descobrir qual arquivo corresponde a um ID.
    //Exemplo: 0 -> documento1.txt, 1 -> receita.txt, 2 -> carro.txt 

    int proximo_id_disponivel;
    //Adiciona um id para o documento
    
    std::string diretorio_base;
    //guardar o diretorio do arquivo para indexar

public:
    Indice();

    ~Indice() = default;

    int obter_id_arquivo(const std::string& nome_arquivo);
    //Cria um id para o arquivo

    void adicionar_palavra(const std::string& palavra, const std::string& nome_arquivo);
    //Adiciona uma palavra ao indice invertido de um arquivo

    const std::unordered_map<std::string, std::vector<int>>& get_indice_invertido() const;
    //A função dele é só retornar o indice invertido, só para leitura, ele não modifica nada!

    const std::unordered_map<std::string, int>& get_mapa_arquivo_para_id() const;
    //A função dele é só retornar o mapa de arquivo para id, só para leitura, ele não modifica nada!

    const std::vector<std::string>& get_mapa_id_para_arquivo() const;
    //A função dele é só retornar o mapa de id para arquivo, só para leitura, ele não modifica nada!

    void definir_diretorio_base(const std::string& caminho);

    const std::string& obter_diretorio_base() const;
    //Ele apenas guarda o caminho do diretório onde estão os arquivos que serão indexados
};
