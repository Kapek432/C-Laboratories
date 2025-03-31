#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits.h>
#include <utility> // std::exchange
using namespace std;

#include "simpleString.h"



// przypisanie wartości do zmiennej statycznej
std::size_t SimpleString::instances_=0;
// metoda zwracająca value_ z dodanym '\0'
char* SimpleString::c_str() const
{
    delete[] buffer_;
    buffer_ = new char[size_ + 1];
    std::memcpy(buffer_, data_, size_);
    buffer_[size_] = '\0';
    return buffer_;
}
// kontruktor przyjmujący tekst i dokonujący jego "głęboką" kopię
SimpleString::SimpleString(const char* text):size_(std::strlen(text)), capacity_(size_), buffer_(nullptr)
{
    data_ = new char[size_];
    std::memcpy(data_, text, size_);
    instances_++;
}
// konstruktor kopiujący, wykonujący "głęboką" kopię,
SimpleString::SimpleString(const SimpleString& text): size_(text.size_), capacity_(text.capacity_), buffer_(nullptr)
{
    data_ = new char[size_];
    std::memcpy(data_, text.data_, size_);
    instances_++;

}
// destruktor
SimpleString::~SimpleString()
{
    delete[] data_;
    delete[] buffer_;
    instances_--;
}
// ustawia nową zawartosc, dokonującej głębokiej kopii
void SimpleString::assign(const char* text)
{
    if (!text) return;
    size_ = std::strlen(text);
    capacity_ = size_;
    delete[] data_;
    delete[] buffer_;
    data_ = new char[size_];
    std::memcpy(data_, text, size_);
    buffer_ = nullptr;
}
// Sprawdza czy są równe
bool SimpleString::equal_to(const SimpleString& other, bool case_sensitive) const {
    if (size_ != other.size_) {
        return false;
    }
    if (case_sensitive) {
        return std::equal(data_, data_ + size_, other.data_);
    } else {
        return std::equal(data_, data_ + size_, other.data_, [](const char& a, const char& b) {
            return std::tolower(a) == std::tolower(b);
        });
    }
}
// Zwraca substring od zadanej pozycji i o okreslonej dlugosci
SimpleString SimpleString::substr(const std::size_t pos, const std::size_t count) const
{
    if (pos >= size_) { return SimpleString(); }
    size_t count_ = std::min(count, size_ - pos);
    char* subdata = new char[count_+1];
    std::memcpy(subdata, data_ + pos, count_);
    subdata[count_] = '\0';



    SimpleString result(subdata);
    delete[] subdata;
    return result;
}
// dodaje na koniec
void SimpleString::append(const SimpleString& other)
{
    size_t new_size = size_ + other.size_;
    if (new_size > capacity_) {
        capacity_ = new_size;
        char* new_data = new char[new_size];
        std::memcpy(new_data, data_, size_);
        delete[] data_;
        data_ = new_data;
    }
    std::memcpy(data_ + size_, other.data_, other.size_);
    size_ = new_size;
}
// porównuje w okreslony sposob
int SimpleString::compare(const SimpleString& other, const bool case_sensitive) const
{
    if (equal_to(other, case_sensitive)) return 0;
    if (case_sensitive)
    {
        return std::strcmp(data_, other.data_);
    }
    else
    {
        for (std::size_t i = 0; i < std::min(size_,other.size_); i++)
        {
            char c1 = std::tolower(data_[i]);
            char c2 = std::tolower(other.data_[i]);
            if (c1!=c2)
            {
                return c1-c2;
            }
        }
        if (size_<other.size_)
        {
            return -1;
        }
        else if (size_>other.size_)
        {
            return 1;
        }
    }
    return 0;
}
// Kontruktor przenoszący
SimpleString::SimpleString(SimpleString&& other) noexcept: size_(other.size_), capacity_(other.capacity_), data_(other.data_), buffer_(other.buffer_)
{
    other.data_ = nullptr;
    other.capacity_ = 0;
    other.size_ = 0;
    other.buffer_ = nullptr;
}







