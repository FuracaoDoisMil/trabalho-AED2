# trabalho-AED2
1-Descrição do Projeto

Este projeto implementa um sistema completo de indexação e busca textual, capaz de:

1.0-Ler todos os arquivos de texto dentro de um diretório.
1.1-Processar o conteúdo (normalizando, removendo pontuação e quebrando palavras).
1.2-Criar um índice invertido, que relaciona palavras → arquivos onde aparecem.
1.3-Salvar e carregar esse índice de/para disco.
1.4-Permitir buscas do usuário no formato de consulta textual (uma ou mais palavras).
1.5-Retornar os arquivos que contém todas as palavras buscadas (interseção).
1.6-Esse trabalho demonstra:
1.7-Manipulação de arquivos e diretórios (<filesystem>, <fstream>).
1.8-Estruturas de dados (hash tables, vetores).
1.9-Lógica de indexação e consulta.
1.10-Modularização em C++ com múltiplas classes.
1.11-Reutilização e integração entre componentes.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
2-Arquitetura do Projeto

O projeto é dividido em módulos, cada um com uma responsabilidade específica:

2.0-Indice

Gerencia:
2.0.0-Índice invertido
2.0.1-Mapa arquivo → ID
2.0.2-Mapa ID → arquivo
2.0.3-Diretório base

Métodos principais:

2.0.4-adicionar_palavra()
2.0.5-obter_id_arquivo()
2.0.6-get_indice_invertido()
2.0.7-get_mapa_id_para_arquivo()

2.1-TextProcessor

Responsável por preprocessar o texto:
2.1.0-Converter para minúsculas
2.1.1-Remover pontuação
2.1.2-Quebrar texto em lista de palavras

2.2-Indexer

Responsável por:
2.2.0-Percorrer um diretório
2.2.1-Abrir arquivos
2.2.2-Ler conteúdo
2.2.3-Quebrar em palavras
2.2.4-Inserir tudo no índice invertido através de Indice::adicionar_palavra()

2.3-Serializer

Permite:
2.3.0-Salvar o índice para disco
2.3.1-Carregar um índice salvo e reconstruí-lo no objeto Indice

2.4-QueryProcessor

2.4.0-Recebe uma consulta do usuário e:
2.4.1-Normaliza o texto da consulta
2.4.2-Separa em palavras
2.4.3-Procura cada palavra no índice invertido
2.4.4-Faz interseção dos documentos
2.4.5-Retorna os arquivos onde TODAS as palavras aparecem

2.5-CommandLineInterface

Menu interativo que permite:
2.5.0-Indexar diretório
2.5.1-Buscar palavras
2.5.2-Salvar índice
2.5.3-Carregar índice
2.5.4-É a interface principal usada pelo usuário.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
3-Compilação

O projeto já possui um Makefile, então basta digitar:
para windows:
*mingw32-make*

Isso irá gerar o executável:

*programa.exe*


Se estiver no Linux:

*make*

Após compilar, execute:

*./programa*

Você verá o seguinte menu:

==== MENU PRINCIPAL ====
1 - Indexar diretorio
2 - Buscar palavra
3 - Salvar indice em arquivo
4 - Carregar indice de arquivo
0 - Sair

Exemplos:
1) Indexar um diretório
Escolha: 1
Digite o caminho do diretorio: C:/Users/Gustavo/Documentos/textos
Indexacao concluida!

2) Buscar palavras
Escolha: 2
Digite a consulta: botafogo o maior

Arquivos encontrados:
 - teste1.txt
 - teste89.txt

3) Salvar o índice em um arquivo
Escolha: 3
Caminho para salvar o indice: C:/Users/Gustavo/indice_salvo.txt
Indice salvo.

4) Carregar um índice já salvo
Escolha: 4
Caminho do arquivo de indice: C:/Users/Gustavo/indice_salvo.txt
Indice carregado.

5) Sair do programa
Escolha: 0
Encerrando...
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/trabalho-AED2
│
├── indice.hpp / indice.cpp
├── textprocessor.hpp / textprocessor.cpp
├── indexer.hpp / indexer.cpp
├── serializer.hpp / serializer.cpp
├── querryprocessor.hpp / querryprocessor.cpp
├── commandlineinterface.hpp / commandlineinterface.cpp
├── main.cpp
├── makefile
└── README.md

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*Autores*

Trabalho desenvolvido para a disciplina AED2 – Análise e Estrutura de Dados, por:

*Gustavo Madeira Meneghelo*
*Luis Fernando Beani Moreira*
