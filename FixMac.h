#ifndef FIX_MAC_H
#define FIX_MAC_H

#include <string>

namespace std {
    template<> struct char_traits<unsigned int> {
        using char_type = unsigned int;
        using int_type = long;
        using off_type = streamoff;
        using pos_type = streampos;
        using state_type = mbstate_t;
        static void assign(char_type& c1, const char_type& c2) { c1 = c2; }
        static bool eq(const char_type& c1, const char_type& c2) { return c1 == c2; }
        static bool lt(const char_type& c1, const char_type& c2) { return c1 < c2; }
        static int compare(const char_type* s1, const char_type* s2, size_t n) {
            for (size_t i = 0; i < n; ++i) { if (s1[i] < s2[i]) return -1; if (s1[i] > s2[i]) return 1; }
            return 0;
        }
        static size_t length(const char_type* s) { size_t i = 0; while (s[i] != 0) ++i; return i; }
        static const char_type* find(const char_type* s, size_t n, const char_type& a) {
            for (size_t i = 0; i < n; ++i) if (s[i] == a) return s + i; return nullptr;
        }
        static char_type* move(char_type* s1, const char_type* s2, size_t n) { return (char_type*)memmove(s1, s2, n * sizeof(char_type)); }
        static char_type* copy(char_type* s1, const char_type* s2, size_t n) { return (char_type*)memcpy(s1, s2, n * sizeof(char_type)); }
        static char_type* assign(char_type* s, size_t n, char_type a) { for (size_t i = 0; i < n; ++i) s[i] = a; return s; }
        static int_type not_eof(const int_type& i) { return i != eof() ? i : !eof(); }
        static char_type to_char_type(const int_type& i) { return (char_type)i; }
        static int_type to_int_type(const char_type& c) { return (int_type)c; }
        static bool eq_int_type(const int_type& i1, const int_type& i2) { return i1 == i2; }
        static int_type eof() { return -1; }
    };
}

#endif