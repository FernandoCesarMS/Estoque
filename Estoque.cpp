#include <string>

#include "Estoque.hpp"

void Estoque::add_mercadoria(const std::string &mercadoria, unsigned int qtd)
{
}

void Estoque::sub_mercadoria(const std::string &mercadoria, unsigned int qtd)
{
}

unsigned int Estoque::get_qtd(const std::string &mercadoria) const
{
}

void Estoque::imprime_estoque() const
{
}

Estoque &Estoque::operator+=(const Estoque &rhs)
{
}

Estoque &Estoque::operator-=(const Estoque &rhs)
{
}

bool operator<(Estoque &lhs, Estoque &rhs)
{
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