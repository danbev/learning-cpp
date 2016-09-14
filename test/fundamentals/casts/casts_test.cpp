#include <gtest/gtest.h>
#include <iostream>
#include <typeinfo>
#include "casts.cpp"

using namespace std;

TEST(Casts, cast) {
    Base* b = cast();
    EXPECT_EQ("derived", b->name()) << "normal cast should succeed ";
}

TEST(Casts, static_cast) {
    Base* b = new Base();
    Derived* d = static_cast<Derived*>(b);
    EXPECT_EQ("base", d->name()) << "static_cast can downcast but no checks will be performed";
    EXPECT_EQ("dname", d->dname());
    Base* c = static_cast<Base*>(d);
    EXPECT_EQ("base", c->name()) << "static_cast can upcast";
}

TEST(Casts, dynamic_cast_to_base_class) {
    Derived* d = new Derived();
    Base* b = dynamic_cast<Base*>(d);
    EXPECT_EQ("derived", b->name()) << "dynamic_cast from derived to base should succeed. ";
}

TEST(Casts, dynamic_cast_to_derived_class) {
    Base* b = new Base();
    Derived* d = dynamic_cast<Derived*>(b);
    EXPECT_EQ(nullptr, d) << "dynamic_cast from base to derived should not succeed. ";
}

TEST(Casts, typeinfo) {
    Base* b = new Base();
    EXPECT_NE(nullptr, typeid(*b).name());
    EXPECT_EQ(typeid(Base), typeid(*b)) << "both should be of the same type";
}

TEST(Casts, const_cast) {
    int n = 10;
    const int* nr = &n;
    int* nr2 = const_cast<int*>(nr);
    *nr2 += 1;
    EXPECT_EQ(11, *nr2) << "const_cast should allow for modifying a pointer";
}

TEST(Casts, reinterpret_cast) {
    int* i1 = new int(24);
    void* v = reinterpret_cast<void*>(i1);
    int* i2 = reinterpret_cast<int*>(v);
    EXPECT_EQ(24, *i2) << "const_cast should allow for modifying a pointer";
    int a = 10;
    char b = reinterpret_cast<int>(a);
}
