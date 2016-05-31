#include <gtest/gtest.h>
#include <iostream>
#include "casts.cpp"

TEST(Casts, cast) {
    Base* b = cast();
    EXPECT_EQ("derived", b->name()) << "normal cast should succeed ";
}

TEST(Casts, dynamic_cast_to_base_class) {
    Derived* d = new Derived();
    Base* b = dynamic_cast<Base*>(d);
    EXPECT_EQ("derived", b->name()) << "dynamic_cast from derived to base should succeed. ";
}

