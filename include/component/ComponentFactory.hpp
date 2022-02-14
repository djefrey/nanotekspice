/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-jeffrey.winkler
** File description:
** ComponentFactory
*/

#pragma once

#include <map>
#include <memory>
#include <functional>
#include "component/IComponent.hpp"

namespace nts {
    class ComponentFactory {
        static std::unique_ptr<ComponentFactory> instance;
        static const std::map<std::string, std::function<std::unique_ptr<IComponent>(void)>> componentList;

        public:
            ~ComponentFactory() = default;

            static ComponentFactory &get();
            std::unique_ptr<IComponent> createComponent(const std::string &model);

        protected:
            ComponentFactory() = default;
    };
}