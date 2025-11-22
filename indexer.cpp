#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include "indexer.hpp"
#include "indice.hpp"
#include "textprocessor.hpp"


Indexer::Indexer(Indice& ind)
    :indice(ind)
{

}


