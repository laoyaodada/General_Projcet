#include "Exception.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

namespace LYlib {
void Exception::init(const char* message, const char* file, int line) {
    m_message = strdup(message);
    if (NULL != file) {
        char sl[16] = {0};
        sprintf(sl, "%d", line);
        m_location = static_cast<char*>(malloc(strlen(file) + strlen(sl) + 2));
        if (NULL != m_location) {
            m_location = strcpy(m_location, file);
            m_location = strcat(m_location, ":");
            m_location = strcat(m_location, sl);
        }
    } else {
        m_location = NULL;
    }
}

Exception::Exception(const char* message) {
    init(message, NULL, 0);
}
Exception::Exception(const char* file, int line) {
    init(NULL, file, line);
}
Exception::Exception(const char* message, const char* file, int line) {
    init(message, file, line);
}
Exception::Exception(const Exception& e) {
    m_message  = strdup(e.m_message);
    m_location = strdup(e.m_location);
}
Exception& Exception::operator=(const Exception& e) {
    if (this != &e) {
        free(m_message);
        free(m_location);
        m_message  = strdup(e.m_message);
        m_location = strdup(e.m_location);
    }
    return *this;
}
const char* Exception::get_message() const {
    return m_message;
}
const char* Exception::get_location() const {
    return m_location;
}
Exception::~Exception() {
    free(m_message);
    free(m_location);
}
}  // namespace LYlib
