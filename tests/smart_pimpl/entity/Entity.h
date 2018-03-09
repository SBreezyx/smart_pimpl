//
// entity.h
// Created by simon on 9/03/18.
//

#ifndef SMART_PIMPL_ENTITY_H
#define SMART_PIMPL_ENTITY_H

#include <smart_pimpl/pimpl.hpp>
#include <iostream>

using Base = smart_pimpl::pimpl<entity>::Entity;
using Impl = smart_pimpl::pimpl<entity>::Impl;



class Entity : smart_pimpl::pimpl<Entity>::Entity {
public:
    Entity() = default;
    explicit Entity(int n);
    auto get_n() -> int;
    auto set_n(int m) -> void;

    auto mult(int m) -> int;

    auto secret() -> void;

    virtual auto speak() -> void;

    template <typename T>
    static auto make_squared_entity(int m) -> Entity;

private:
    explicit Entity(smart_pimpl::EntityPtr<Entity> p);
};


#endif // SMART_PIMPL_ENTITY_H
