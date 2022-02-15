/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** main
*/

#include <iostream>
#include "NTS.hpp"

int main(void)
{
    try {
        nts::NTS nts;

        return nts.run();
    } catch(const nts::NtsError &err) {
        std::cout << err.what() << std::endl;
        return 84;
    }
}
