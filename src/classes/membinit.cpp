// clang++ -std=c++11 -stdlib=libc++ membinit.cpp -o membinit
#include <iostream>

class MemberInit {
    private:
        char * name;
    public:
        MemberInit(char *n ) : name(n) {}
            char * getName() {
            return name;
        }
};

using namespace std;

int main(void) {
    char name[] = "testing";
    char * n = name;
    MemberInit t = MemberInit(name);
    cout << t.getName() << endl;
    // value initialization
    std::string s1 {}; 
    std::string s2 = std::string{};
    cout << "s1=" << s1<< endl;
    cout << "s2=" << s2<< endl;
    // direct initialization
    std::string s3 ("s3 value");
    std::string s4 = std::string("s4 value");
    cout << "s3=" << s3<< endl;
    cout << "s4=" << s4<< endl;
    // copy intitialization 
    std::string s5 = "s5 value";
    cout << "s5=" << s5 << endl;
    return 0;
}
