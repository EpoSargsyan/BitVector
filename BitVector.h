#ifndef BITVECTOR_H
#define BITVECTOR_H

#include <iostream>

class BitVector {
public:
    BitVector();
    BitVector(const int&);
    BitVector(const BitVector&);
    BitVector(BitVector&&);
    ~BitVector();

public:
    void set(const size_t&, const bool);
    int get(const int&);
    const int size() const;
    void clear();

public:
    int& operator[](const int&);
    const int& operator[](const int&) const;
    BitVector& operator=(const BitVector&);
    BitVector& operator=(BitVector&&);

public:
    friend std::ostream& operator<<(std::ostream& stream, const BitVector& rhs) {
        for (int i = rhs.size() - 1; i >= 0 ; --i) {
            stream << rhs.m_arr[i];
        } 
        return stream;
    }


private:
    void resize(const int&);

private:
    int* m_arr;
    size_t m_size;
};

#endif // BITVECTOR_H