#pragma once

#include <cstdlib>

template <typename T>
class Simple_array {
    public:
        explicit Simple_array(size_t size = 8) {
            this -> begin = new T[size];
            end = begin + size;
            next = begin;
        }

        Simple_array(size_t size, T * arr) {
            this -> begin = new T[size];
            for (T *p = begin + size - 1, *pa = arr + size - 1; pa >= arr; --p, --pa)
                *p = *pa;
            end = begin + size;
            next = begin + size;
        }

        Simple_array(size_t size, T a) {
            this -> begin = new T[size];
            for (T *p = begin + size - 1; p != begin; --p)
                *p = a;
            end = begin + size;
            next = begin + size;
        }

        Simple_array(Simple_array const & a) {
            size_t size = a.end - a.begin;
            this -> begin = new T[size];
            for (size_t i = 0; i < size; ++i)
                begin[i] = a.begin[i];
            end = begin + size;
            next = begin + size;
        }

        Simple_array(Simple_array && a) : begin(a.begin), end(a.end), next(a.next) {
            begin = nullptr;
        }

        Simple_array & operator=(Simple_array const & a) {
            if (&a == this)
                return *this;
            this -> ~Simple_array();
            size_t size = a.end - a.begin;
            this -> begin = new T[size];
            for (size_t i = 0; i < size; ++i)
                begin[i] = a.begin[i];
            end = begin + size;
            next = begin + size;

            return *this;
        }

        ~Simple_array() {
            delete [] this -> begin;
        }

        void push(T & elem) {
            if (next == end)
                realloc();
            *(next++) = elem;
        }

        bool pop() {
            if (next != begin) {
                --next;
                return true;
            }
            else
                return false;
        }
        
        T * pick() {
            if (next != begin)
                return next - 1;
            else
                return nullptr;
        }

        T const * pick() const {
            if (next != begin)
                return next - 1;
            else
                return nullptr;
        }

        size_t capacity() const {
            return end - next;
        }

        size_t size() const {
            return next - begin;
        }

        T & operator[](size_t i) {
            while(i >= end - begin) {
                realloc();
                next = begin + i + 1;
            }
            return *(begin + i);
        }

        T const operator[](size_t i) const {
            return *(begin + i);
        }

    private:
        T *begin;
        T *end;
        T *next;

        void realloc() {
            size_t n = end - begin;
            T *temp = new T[n * 2];
            for (T *p = temp, *pa = begin; pa < end; ++p, ++pa)
                *p = *pa;
            delete [] begin;
            begin = temp;
            end = begin + 2 * n;
            next = begin + n;
        }
};
