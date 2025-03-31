#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef> // std::size_t
#include <cstring>

class SimpleString
{
protected:
    static std::size_t instances_;
    char* data_ = nullptr;
    std::size_t size_ = 0;
    std::size_t capacity_ = 0;
    mutable char* buffer_ = nullptr; // buffer potzrebny do dodawania \0
    static constexpr std::size_t npos = static_cast<std::size_t>(-1); // maksyamalna wartość typu size_t
public:
    auto size() const { return size_; }
    auto capacity() const { return capacity_; }
    auto data() const { return data_; }
    static auto instances() { return instances_; }
    char* c_str() const;
    SimpleString(): data_(nullptr), size_(0), capacity_(0), buffer_(nullptr)
    {
        instances_++;
    }
    SimpleString(const char* text);
    SimpleString(const SimpleString& text);
    ~SimpleString();
    void assign(const char* text);
    bool equal_to(const SimpleString& other, bool case_sensitive=true) const;
    void append(const SimpleString& other);
    SimpleString substr(const std::size_t pos=0, std::size_t count=npos) const;
    int compare(const SimpleString& other, bool case_sensitive=true) const;
    SimpleString(SimpleString&& other) noexcept;

private:
    // TODO: ...
};

#endif // MATRIX_H
