//
// entity.cpp
// Created by simon on 9/03/18.
//

#include <iostream>
#include "Entity.h"

template<>
struct smart_pimpl::pimpl<Entity>::Impl {
    Impl(int N = 0) :
        n{ N }
    {}

    virtual auto secret() -> void {
        std::cout << "hello, my baby." << std::endl;
    }

    int n;
};

Entity::Entity(int n) :
    Base(n)
{
}

auto Entity::get_n() -> int
{
    return impl()->n;
}

auto Entity::mult(int m) -> int
{
    return impl()->n * m;
}

auto Entity::set_n(int m) -> void
{
    impl()->n = m;
}

auto Entity::speak() -> void
{
    std::cout << "hello i am holding " << impl()->n << std::endl;
}

Entity::Entity(smart_pimpl::EntityPtr<Entity> p) :
    Base(std::forward<decltype(p)>(p))
{
}

template <typename T>
auto Entity::make_squared_entity(int m) -> Entity
{
    return Entity(smart_pimpl::make_ptr<smart_pimpl::EntityPtr<Entity>, T>(m * m));
}

auto Entity::secret() -> void
{
    impl()->secret();
}


