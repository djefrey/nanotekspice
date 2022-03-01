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

            void update();
            void dump() const override;
            IComponent &createComponent(const std::string &model, std::string name);
            void setInputState(const std::string &name, Tristate state);
            void printInOut() const;
            void setLink(std::string &name1, std::string &name2, nts::PinId pin1, nts::PinId pin2);

            nts::IComponent &getComponentByName(std::string name) const;

        protected:
            std::map<std::string, std::unique_ptr<IComponent>> _components;
            std::vector<InputComponent*> _inputs;
            std::vector<OutputComponent*> _outputs;

            void insertInput(InputComponent*);
            void insertOutput(OutputComponent*);

        private:
    };
}