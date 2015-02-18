#pragma once

#include <cstdlib>

template <typename T>
class Array {
    public:
        Array(size_t size = 8) {
            this -> begin = new T[size];
            end = begin + size;
            cap = begin;
        }

        ~Array() {
            delete [] this -> begin;
        }

        void push(T & elem) {
            if (cap == end) {
                size_t n = end - begin;
                T * temp = new T[n * 2];
                for (T *p = temp, *pa = begin; pa < end; ++p, ++pa)
                    *p = *pa;
                delete [] begin;
                begin = temp;
                end = begin + 2 * n;
                cap = begin + n;
            }
            *(cap++) = elem;
        }

        bool pop() {
            if (cap != begin) {
                --cap;
                return true;
            }
            else
                return false;
        }
        
        T * pick() {
            if (cap != begin)
                return cap - 1;
            else
                return nullptr;
        }

        size_t capacity() {
            return end - cap;
        }

        T & operator[](size_t i) {
            return *(begin + i);
        }

        T const operator[](size_t i) const {
            return *(begin + i);
        }

    private:
        T * begin;
        T * end;
        T * cap;
};
