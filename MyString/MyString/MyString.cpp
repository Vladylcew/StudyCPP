#include <iostream>
#include <array>

class string {
public:
    size_t size() {
        return m_size;
    }

    size_t capacity() {
        return m_capacity

    }
private:
    size_t m_size;
    union {
        class {
            std::unique_ptr<char[]> m_data;
            size_t m_capacity;
        } m_large;
        std::array<char, sizeof(m_large)> m_small;
    };
};
