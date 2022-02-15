/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** Circuit
*/

#pragma once

#include <map>
#include <vector>
#include "component/Component.hpp"
#include "component/InputComponent.hpp"
#include "component/OutputComponent.hpp"

namespace nts {
    class Circuit : public Component {
        public:
            Circuit(std::string model, std::size_t nbPins);
            ~Circuit() = default;

            void simulate(std::size_t tick);
            void dump() const override;
            IComponent &createComponent(const std::string &model, std::string name);
            void setInputState(const std::string &name, Tristate state);
            void printInOut() const;

        protected:
            std::map<std::string, std::unique_ptr<IComponent>> _components;
            std::vector<InputComponent*> _inputs;
            std::vector<OutputComponent*> _outputs;

            void addUpdatedPinsToUpdate(std::vector<IComponent*> &update, IComponent &comp);

        private:
    };
}