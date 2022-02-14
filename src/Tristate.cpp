/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Tristate
*/

#include "Tristate.hpp"

nts::Tristate nts::not_gate(nts::Tristate a)
{
    if (a == UNDEFINED)
        return UNDEFINED;
    else
        return a == TRUE ? FALSE : TRUE;
}

nts::Tristate nts::and_gate(nts::Tristate a, nts::Tristate b)
{
    if (a != UNDEFINED && b != UNDEFINED)
        return a && b ? TRUE : FALSE;
    else if (a == UNDEFINED && b != UNDEFINED)
        return b == FALSE ? FALSE : UNDEFINED;
    else if (a != UNDEFINED && b == UNDEFINED)
        return a == FALSE ? FALSE : UNDEFINED;
    else
        return UNDEFINED;
}

nts::Tristate nts::or_gate(nts::Tristate a, nts::Tristate b)
{
    if (a != UNDEFINED && b != UNDEFINED)
        return a || b ? TRUE : FALSE;
    else if (a == UNDEFINED && b != UNDEFINED)
        return b == TRUE ? TRUE : UNDEFINED;
    else if (a != UNDEFINED && b == UNDEFINED)
        return a == TRUE ? TRUE : UNDEFINED;
    else
        return UNDEFINED;
}

nts::Tristate nts::nand_gate(nts::Tristate a, nts::Tristate b)
{
    return not_gate(and_gate(a, b));
}

nts::Tristate nts::nor_gate(nts::Tristate a, nts::Tristate b)
{
    return not_gate(or_gate(a, b));
}

nts::Tristate nts::xor_gate(nts::Tristate a, nts::Tristate b)
{
    return and_gate(or_gate(a, b), nand_gate(a, b));
}

std::ostream &nts::operator<<(std::ostream &s, nts::Tristate value)
{
    switch (value) {
        case nts::Tristate::TRUE:
            s << "1";
            break;
        case nts::Tristate::FALSE:
            s << "0";
            break;
        case nts::Tristate::UNDEFINED:
            s << "U";
            break;
    }
    return s;
}