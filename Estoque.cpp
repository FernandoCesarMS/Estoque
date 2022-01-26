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
}