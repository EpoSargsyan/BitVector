#include "BitVector.h"

BitVector::BitVector() {
    this->m_arr = nullptr;
    this->m_size = 0;
}

BitVector::BitVector(const int& size) {
    this->m_arr = new int[size];
}

BitVector::BitVector(const BitVector& rhs) {
    this->clear();
    this->m_arr = new int[rhs.m_size];
    this->m_size = rhs.m_size;

    for (int i = 0; i < this->m_size; ++i) {
        this->m_arr[i] = rhs[i]; 
    }
}

BitVector::BitVector(BitVector&& rhs) {
    this->clear();
    this->m_arr = rhs.m_arr;
    this->m_size = rhs.m_size;
    rhs.m_arr = nullptr;
    rhs.m_size = 0;
}

BitVector::~BitVector() {
    clear();
}

void BitVector::clear() {
    delete this->m_arr;
    this->m_size = 0;
    this->m_arr = nullptr;
}

BitVector& BitVector::operator=(const BitVector& rhs) {
    this->clear();
    this->m_arr = new int[rhs.m_size];
    this->m_size = rhs.m_size;

    for (int i = 0; i < this->m_size; ++i) {
        this->m_arr[i] = rhs[i]; 
    }
    return *this;
}

BitVector& BitVector::operator=(BitVector&& rhs) {
    if (this == &rhs) { return *this; }
    this->clear();
    this->m_arr = rhs.m_arr;
    this->m_size = rhs.m_size;
    rhs.m_arr = nullptr;
    rhs.m_size = 0;
    return *this;
}

int& BitVector::operator[](const int& index) {
    return this->m_arr[index];
}

const int& BitVector::operator[](const int& index) const {
    return this->m_arr[index];
}

void BitVector::resize(const int& new_size) {
    int* changed_arr = new int[new_size];
    for (int i = 0; i < this->m_size; ++i) {
        changed_arr[i] = this->m_arr[i];
    }

    clear();

    this->m_arr = new int[new_size];
    this->m_arr = changed_arr;
    this->m_size = new_size;
    changed_arr = nullptr;
}

const int BitVector::size() const {
    return this->m_size;
}

void BitVector::set(const size_t& index, const bool value) {
    if (index > this->m_size) { resize(index + 1); }
    this->m_arr[index] = value;
}

int BitVector::get(const int& index) {
    return this->m_arr[index];
}