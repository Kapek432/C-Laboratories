#ifndef CONTAINER_WRAPPER_H
#define CONTAINER_WRAPPER_H


#include <vector>
#include <list>
#include <deque>
#include <cstddef> // std::size_t
#include <cstdint> // std::int64_t


/// @brief Klasa abstrakcyjna `IContainerWrapper`, wszystkie metody czysto virtualne powinny być zaimplementowane
class IContainerWrapper
{
public:
    using value_type = std::int64_t;

    virtual ~IContainerWrapper() = 0;

    virtual void push_back(const value_type& element) = 0;
    virtual void push_front(const value_type& element) = 0;

    virtual void insert(const value_type& element, std::size_t position) = 0;

    virtual std::size_t size() const = 0;

    virtual value_type& at(std::size_t position) = 0;

    virtual void sort() = 0;

    virtual void erase(std::size_t position) = 0;

    virtual value_type count() const = 0;

    virtual std::size_t find(const value_type& needle) const = 0;

    virtual value_type pop_front() = 0;
    virtual value_type pop_back() = 0;
};

/// @brief Klasa ktora nic nie robi - aby sie kompilowalo
class LazyContainerWrapper: IContainerWrapper
{
public:
    LazyContainerWrapper() = default;
    LazyContainerWrapper(const value_type /*elements*/[], std::size_t /*N*/) {}

    void push_back(const value_type& /*element*/) override {}
    void push_front(const value_type& /*element*/) override {}

    void insert(const value_type& /*element*/, std::size_t /*position*/) override {}

    std::size_t size() const override { return {}; }

    value_type& at(std::size_t /*position*/) override
    {
        static value_type zero{};
        return zero;
    }

    void sort() override {}

    void erase(std::size_t /*position*/) override {}

    value_type count() const override { return {}; }
    std::size_t find(const value_type& /*needle*/) const override { return {}; }

    value_type pop_front() override { return {}; }
    value_type pop_back() override { return {}; }
};

/// @brief Wrapper do std::vector
class VectorWrapper: IContainerWrapper
{
public:
    using value_type = IContainerWrapper::value_type;

    VectorWrapper() = default;
    VectorWrapper(const value_type arr[], std::size_t size): impl_(arr, arr + size) {}
    void push_back(const value_type& el) override;
    void push_front(const value_type& el) override;
    void insert(const value_type& el, std::size_t position) override;
    std::size_t size() const override;
    value_type& at(std::size_t position) override;
    void sort() override;
    void erase(std::size_t position) override;
    value_type count() const override;
    std::size_t find(const value_type& needle) const override;
    value_type pop_front() override;
    value_type pop_back() override;
    ~VectorWrapper() = default;


protected: // lub private: zaleznie czy po VectorWrapper bedzie dziedziczyc VectorPreallocatedWrapper czy nie
    std::vector<value_type> impl_;
};

/// @brief Wrapper do std::vector, ktory dokonuje pre-allokacji w konstruktorze
class VectorPreallocatedWrapper: public VectorWrapper /// lub mozna dziedziczyc po IContainerWrapper
{
    constexpr static std::size_t preallocationSize = 1'000'000;

public:
    VectorPreallocatedWrapper()
    {
        impl_.reserve(preallocationSize/2);
    }
    VectorPreallocatedWrapper(const value_type arr[], std::size_t size): VectorWrapper(arr, size)
    {
        impl_.reserve(std::max(size, preallocationSize));
    }
};

/// @brief Wrapper do std::list
class ListWrapper: IContainerWrapper
{
public:
    ListWrapper() = default;
    ListWrapper(const value_type arr[], std::size_t size): impl_(arr, arr + size) {}
    void push_back(const value_type& el) override;
    void push_front(const value_type& el) override;
    void insert(const value_type& el, std::size_t position) override;
    std::size_t size() const override;
    value_type& at(std::size_t position) override;
    void sort() override;
    void erase(std::size_t position) override;
    value_type count() const override;
    std::size_t find(const value_type& needle) const override;
    value_type pop_front() override;
    value_type pop_back() override;
    ~ListWrapper() = default;

private:
    std::list<value_type> impl_;
};

/// @brief Wrapper do std::deque
class DequeWrapper: IContainerWrapper
{
public:
    DequeWrapper() = default;
    DequeWrapper(const value_type arr[], std::size_t size): impl_(arr, arr + size) {}
    void push_back(const value_type& el) override;
    void push_front(const value_type& el) override;
    void insert(const value_type& el, std::size_t position) override;
    std::size_t size() const override;
    value_type& at(std::size_t position) override;
    void sort() override;
    void erase(std::size_t position) override;
    value_type count() const override;
    std::size_t find(const value_type& needle) const override;
    value_type pop_front() override;
    value_type pop_back() override;
    ~DequeWrapper() = default;

private:
    std::deque<value_type> impl_;
};

/// @brief Alias typu, ktory bedzie podlegac testom 
//using ContainerWrapper = LazyContainerWrapper;
//using ContainerWrapper = VectorWrapper;
//using ContainerWrapper = VectorPreallocatedWrapper;
//using ContainerWrapper = ListWrapper;
using ContainerWrapper = DequeWrapper;

#endif // CONTAINER_WRAPPER_H
