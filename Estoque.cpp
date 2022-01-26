#include <string>

#include "Estoque.hpp"

void Estoque::add_mercadoria(const std::string &mercadoria, unsigned int qtd)
{
}

void Estoque::sub_mercadoria(const std::string &mercadoria, unsigned int qtd)
{
    Mercadoria merc = *new Mercadoria(mercadoria, qtd);
    int existe = 0;

    for (int i = 0; i < estoque.size(); i++)
    {
        if (estoque[i].nome == mercadoria)
        {
            existe = 1;
            if (qtd > estoque[i].quantidade)
            {
                std::cout << mercadoria << " insuficiente" << std::endl;
            }
            else
            {
                estoque[i].quantidade -= qtd;
            }
        }
    }

    if (existe == 0)
        std::cout << mercadoria << " inexistente" << std::endl;
}
/**
     * \brief Informa a quantidade da mercadoria 's' no estoque.
     *
     * \param s O nome da mercadoria de interesse.
     *
     * \return Zero, se 's' nao estiver presente no estoque, ou a quantidade
     * de 's', caso contrario.
     */
unsigned int Estoque::get_qtd(const std::string &mercadoria) const
{
    int retorno = 0;

    for (int i = 0; i < estoque.size(); i++)
    {
        if (estoque[i].nome == mercadoria)
        {
            retorno = estoque[i].quantidade;
        }
    }

    return retorno;
}
/**
     * \brief Imprime a lista das mercadorias presentes no estoque.
     *
     * \details
     * Esta funcao produz uma saida da seguinte forma:
     *
     * mercadora1, qtd1
     * mercadora2, qtd2
     * ...
     * mercadorian, qtdn
     *
     * Sendo "mercadoriax" o nome de uma mercadoria, e "qtdx" a quantidade
     * daquela mercadoria. As mercadorias devem ser impressas em ordem
     * alfabetica. O nome da mercadoria deve ser seguido por uma virgula, e
     * entao por um espaco, e entao pela quantidade da mercadoria. Note que esta
     * saida eh um arquivo CSV (comma separated values) valido.
     */
void Estoque::imprime_estoque() const
{

    for (int i = 0; i < estoqueOrdenado.size(); i++)
    {

        for (int j = 0; j < estoque.size(); j++)
        {
            if (estoqueOrdenado[i] == estoque[j].nome)
            {
                std::cout << estoque[j].nome << ", " << estoque[j].quantidade
                          << std::endl;
            }
        }
    }
}

Estoque &Estoque::operator+=(const Estoque &rhs)
{
    for (int i = 0; i < rhs.estoque.size(); i++)
    {
        int adicionou = 0;
        for (int j = 0; j < this->estoque.size(); j++)
        {
            if (rhs.estoque[i].nome == this->estoque[j].nome)
            {
                this->estoque[j].quantidade += rhs.estoque[i].quantidade;
                adicionou++;
            }
        }
        if (adicionou == 0)
        {
            this->estoque.push_back(rhs.estoque[i]);
            this->estoqueOrdenado.push_back(rhs.estoque[i].nome);
            sort(estoqueOrdenado.begin(), estoqueOrdenado.end());
        }
    }
    return *this;
}

Estoque &Estoque::operator-=(const Estoque &rhs)
{
    for (int i = 0; i < rhs.estoque.size(); i++)
    {
        for (int j = 0; j < this->estoque.size(); j++)
        {
            if (rhs.estoque[i].nome == this->estoque[j].nome)
            {
                this->estoque[j].quantidade -= rhs.estoque[i].quantidade;
            }
        }
    }
    return *this;
}

bool operator<(Estoque &lhs, Estoque &rhs)
{

    for (int i = 0; i < lhs.estoque.size(); i++)
    {
        bool existe = false, ehMaior = false;
        for (int j = 0; j < rhs.estoque.size(); j++)
        {
            if (lhs.estoque[i].nome == rhs.estoque[j].nome)
            {
                existe = true;
                if (lhs.estoque[i].quantidade < rhs.estoque[j].quantidade)
                {
                    ehMaior = true;
                }
            }
        }
        if (existe == false || ehMaior == false)
        {
            return false;
        }
    }
    return true;
}

bool operator>(Estoque &lhs, Estoque &rhs)
{
    for (int i = 0; i < rhs.estoque.size(); i++)
    {
        bool existe = false, ehMaior = false;
        for (int j = 0; j < lhs.estoque.size(); j++)
        {
            if (rhs.estoque[i].nome == lhs.estoque[j].nome)
            {
                existe = true;
                if (rhs.estoque[i].quantidade < lhs.estoque[j].quantidade)
                {
                    ehMaior = true;
                }
            }
        }
        if (existe == false || ehMaior == false)
        {
            return false;
        }
    }
    return true;
}