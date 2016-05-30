#include <memory>
#include <string>

/**
 * Allows for the destructor for an object to be automatically called
 * when the pointers scope is destroyed.
 */
std::auto_ptr<std::string> autoPointer() {
    return std::auto_ptr<std::string>(new std::string("bajja"));
}

std::unique_ptr<std::string> uniquePointer() {
    return std::unique_ptr<std::string>(new std::string("bajja"));
}

