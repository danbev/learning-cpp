#include <memory>
#include <string>

/**
 * Allows for the destructor for an object to be automatically called
 * when the pointers scope is destroyed.
 * If a auto_ptr is assigned to another pointer the first one will use ownership
 * and be invalid.
 */
std::auto_ptr<std::string> autoPointer() {
    return std::auto_ptr<std::string>(new std::string("bajja"));
}

/**
 * Like auto_ptr also has the concept of ownership, but instead of crashing
 * there will be a compile time error if you try to assign a pointer of this
 * type to another pointer.
 */
std::unique_ptr<std::string> uniquePointer() {
    return std::unique_ptr<std::string>(new std::string("bajja"));
}

/**
 * A shared pointer uses reference counting and when the count is 
 * zero the pointed to objects destructor will be run.
 */ 
std::shared_ptr<std::string> sharedPointer() {
    return std::shared_ptr<std::string>(new std::string("bajja"));
}

