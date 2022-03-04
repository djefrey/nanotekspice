/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Tristate
*/

#include "Tristate.hpp"
#include "NTS.hpp"

nts::Tristate nts::Gates::not_gate(nts::Tristate a)
{
    if (a == UNDEFINED)
        return UNDEFINED;
    else
        return a == TRUE ? FALSE : TRUE;
}

nts::Tristate nts::Gates::and_gate(nts::Tristate a, nts::Tristate b)
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

nts::Tristate nts::Gates::or_gate(nts::Tristate a, nts::Tristate b)
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

nts::Tristate nts::Gates::nand_gate(nts::Tristate a, nts::Tristate b)
{
    return not_gate(and_gate(a, b));
}

nts::Tristate nts::Gates::nor_gate(nts::Tristate a, nts::Tristate b)
{
    return not_gate(or_gate(a, b));
}

nts::Tristate nts::Gates::xor_gate(nts::Tristate a, nts::Tristate b)
{
    return and_gate(or_gate(a, b), nand_gate(a, b));
}

nts::Tristate nts::Gates::get_state_from_char(char c)
{
    switch (c) {
        case '0':
            return FALSE;
        case '1':
            return TRUE;
        case 'U':
            return UNDEFINED;
        default:
            throw nts::NtsError("get_state_from_char()", "Invalid char");
    }
}

std::size_t nts::Gates::statesToInt(nts::Tristate states[], std::size_t nbStates)
{
    std::size_t val = 0;

    for (std::size_t i = 0; i < nbStates; i++) {
        if (states[i] == UNDEFINED)
            throw InvalidStateError();
        if (states[i] == TRUE)
            val |= (1 << i);
    }
    return val;
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