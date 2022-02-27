/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** main
*/

#include <iostream>
#include "NTS.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Invalid args" << std::endl;
        return 84;
    }
    try {
        nts::NTS nts{std::string(av[1])};

        return nts.run();
    } catch(const nts::NtsError &err) {
        std::cerr << err.what() << std::endl;
        return 84;
    }
}
