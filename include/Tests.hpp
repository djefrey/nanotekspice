/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Tests
*/

#pragma once

#include <criterion/criterion.h>
#include "component/Circuit.hpp"

using namespace nts;

void init_circuit(nts::Circuit &circuit, const std::string path);
void assert_output(nts::Circuit &circuit, std::string name, Tristate value);
void simulate(nts::Circuit &circuit, std::size_t &tick);