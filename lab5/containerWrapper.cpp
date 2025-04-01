#include <algorithm> // std::sort, std::find, std::copy
#include <iterator> // std::distance, std::advance, std::back_inserter
#include <limits>   // std::numeric_limits<size_t>::max()
#include <numeric>  // std::accumulate()
#include <vector>

using namespace std;

#include "containerWrapper.h"



/// VectorWrapper
//Push back
void VectorWrapper::push_back(const value_type& el)
{
    impl_.push_back(el);
}
//Insert
void VectorWrapper::insert(const value_type& el, std::size_t position)
{
    if (position > impl_.size())
        throw std::out_of_range("Position out of range");
    impl_.insert(impl_.begin() + position, el);
}
//Push front
void VectorWrapper::push_front(const value_type& el)
{
    impl_.insert(impl_.begin(), el);
}
//Size
std::size_t VectorWrapper::size() const
{
    return impl_.size();
}
//At
VectorWrapper::value_type& VectorWrapper::at (std::size_t position)
{
    if (position >= impl_.size())
        throw std::out_of_range("Position out of range");
    return impl_.at(position);
}
//Sort
void VectorWrapper::sort()
{
    std::sort(impl_.begin(), impl_.end());
}
//Erase
void VectorWrapper::erase(std::size_t position)
{
    if (position >= impl_.size())
        throw std::out_of_range("Position out of range");
    impl_.erase(impl_.begin() + position);
}
//Count
VectorWrapper::value_type VectorWrapper::count() const
{
    return std::accumulate(impl_.begin(), impl_.end(), static_cast<value_type>(0));
}
//Find
std::size_t VectorWrapper::find(const value_type& needle) const
{
    auto it = std::find(impl_.begin(), impl_.end(), needle);
    if (it == impl_.end())
        return std::numeric_limits<std::size_t>::max();
    return std::distance(impl_.begin(), it);
}
//Pop front
VectorWrapper::value_type VectorWrapper::pop_front()
{
    if (impl_.empty())
        throw std::out_of_range("Empty vector container");
    value_type front = impl_.front();
    impl_.erase(impl_.begin());
    return front;
}
//Pop back
VectorWrapper::value_type  VectorWrapper::pop_back()
{
    if (impl_.empty())
        throw std::out_of_range("Empty vector container");
    value_type back = impl_.back();
    impl_.pop_back();
    return back;
}



/// ListWrapper
//Push back
void ListWrapper::push_back(const value_type& el)
{
    impl_.push_back(el);
}
//Insert
void ListWrapper::insert(const value_type& el, std::size_t position)
{
    if (position > impl_.size())
        throw std::out_of_range("Position out of range");
    auto it = impl_.begin();
    std::advance(it, position);
    impl_.insert(it, el);
}
//Push front
void ListWrapper::push_front(const value_type& el)
{
    impl_.insert(impl_.begin(), el);
}
//Size
std::size_t ListWrapper::size() const
{
    return impl_.size();
}
//At
ListWrapper::value_type& ListWrapper::at (std::size_t position)
{
    if (position >= impl_.size())
        throw std::out_of_range("Position out of range");
    auto it = impl_.begin();
    std::advance(it, position);
    return *it;
}
//Sort
void ListWrapper::sort()
{
    impl_.sort();
}
//Erase
void ListWrapper::erase(std::size_t position)
{
    if (position >= impl_.size())
        throw std::out_of_range("Position out of range");
    auto it = impl_.begin();
    std::advance(it, position);
    impl_.erase(it);
}
//Count
ListWrapper::value_type ListWrapper::count() const
{
    return std::accumulate(impl_.begin(), impl_.end(), static_cast<value_type>(0));
}
//Find
std::size_t ListWrapper::find(const value_type& needle) const
{
    auto it = std::find(impl_.begin(), impl_.end(), needle);
    if (it == impl_.end())
        return std::numeric_limits<std::size_t>::max();
    return std::distance(impl_.begin(), it);
}
//Pop front
ListWrapper::value_type ListWrapper::pop_front()
{
    if (impl_.empty())
        throw std::out_of_range("Empty list container");
    value_type front = impl_.front();
    impl_.erase(impl_.begin());
    return front;
}
//Pop back
ListWrapper::value_type  ListWrapper::pop_back()
{
    if (impl_.empty())
        throw std::out_of_range("Empty list container");
    value_type back = impl_.back();
    impl_.pop_back();
    return back;
}



/// DequeWrapper
//Push back
void DequeWrapper::push_back(const value_type& el)
{
    impl_.push_back(el);
}
//Insert
void DequeWrapper::insert(const value_type& el, std::size_t position)
{
    if (position > impl_.size())
        throw std::out_of_range("Position out of range");
    impl_.push_front(el);
}
//Push front
void DequeWrapper::push_front(const value_type& el)
{
    impl_.insert(impl_.begin(), el);
}
//Size
std::size_t DequeWrapper::size() const
{
    return impl_.size();
}
//At
DequeWrapper::value_type& DequeWrapper::at (std::size_t position)
{
    if (position >= impl_.size())
        throw std::out_of_range("Position out of range");
    auto it = impl_.begin();
    std::advance(it, position);
    return *it;
}
//Sort
void DequeWrapper::sort()
{
    std::sort(impl_.begin(), impl_.end());
}
//Erase
void DequeWrapper::erase(std::size_t position)
{
    if (position >= impl_.size())
        throw std::out_of_range("Position out of range");
    auto it = impl_.begin();
    std::advance(it, position);
    impl_.erase(it);
}
//Count
DequeWrapper::value_type DequeWrapper::count() const
{
    return std::accumulate(impl_.begin(), impl_.end(), static_cast<value_type>(0));
}
//Find
std::size_t DequeWrapper::find(const value_type& needle) const
{
    auto it = std::find(impl_.begin(), impl_.end(), needle);
    if (it == impl_.end())
        return std::numeric_limits<std::size_t>::max();
    return std::distance(impl_.begin(), it);
}
//Pop front
DequeWrapper::value_type DequeWrapper::pop_front()
{
    if (impl_.empty())
        throw std::out_of_range("Empty list container");
    auto front = impl_.front();
    impl_.pop_front();
    return front;
}
//Pop back
DequeWrapper::value_type  DequeWrapper::pop_back()
{
    if (impl_.empty())
        throw std::out_of_range("Empty list container");
    value_type back = impl_.back();
    impl_.pop_back();
    return back;
}



IContainerWrapper::~IContainerWrapper() = default;
