//
// Created by simon on 7/03/18.
//

#ifndef SMART_PIMPL_VALUE_H
#define SMART_PIMPL_VALUE_H

#include <string>

#include <smart_pimpl/smart_pimpl.hpp>

#ifdef e
#define my_base SmartPimpl::Pimpl<Test>::Entity
#endif

#ifdef r
#define my_base SmartPimpl::Pimpl<Test>::Reference
#endif

#ifdef v
#define my_base SmartPimpl::Pimpl<Test>::Value
#endif

class Test : my_base {
public:
    Test() = default;
    explicit Test(int n);

    auto get_n() -> int;
    auto set_n(int m) -> void;

    auto mult(int m) -> int;

    auto secret() -> int;
    virtual auto speak() -> void;

    static auto make_squared(int m) -> Test;
    static auto make_secret(int m) -> Test;

private:
    explicit Test(Ptr p);
};


#endif //SMART_PIMPL_VALUE_H
