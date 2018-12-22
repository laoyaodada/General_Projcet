
#include "Object.h"
#include <cstdlib>
#include <iostream>

namespace LYlib {

void* Object::operator new(size_t size) throw() {
    printf("this new\n");
    return malloc(size);
}
void Object::operator delete(void* p) {
    printf("this delete\n");
    free(p);
}
void* Object::operator new[](size_t size) throw() { return malloc(size); }
void Object::operator delete[](void* p) { free(p); }
Object::~Object() {}

}  // namespace LYlib