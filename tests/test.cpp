//
// Created by simon on 7/03/18.
//

#include <iostream>

#include "test.h"

template<>
struct my_base::Impl {
    explicit Impl(int N = 0) : n{ N } {}

    virtual auto secret() -> int
    {
        return 13;
    }

    int n;
};

struct SecretImpl : public my_base::Impl {
    explicit SecretImpl (int n) : Impl(n) {}

    auto secret() -> int override
    {
        return 42;
    }
};

Test::Test(int n) :
    Base(n)
{

}

auto Test::get_n() -> int
{
    return impl()->n;
}

auto Test::set_n(int m) -> void
{
    impl()->n = m;
}

auto Test::mult(int m) -> int
{
    return impl()->n * m;
}

auto Test::secret() -> int
{
    return impl()->secret();
}

auto Test::speak() -> void
{
    std::cout << "hello i am test" << std::endl;
}

auto Test::make_squared(int m) -> Test
{
    return Test(Base::make_impl_of(m * m));
}

auto Test::make_secret(int m) -> Test
{
    return Test(Base::make_impl_of<SecretImpl>(m));
}

Test::Test(Base::Ptr p) :
    Base(std::forward<Base::Ptr>(p))
{

}

