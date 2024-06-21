#pragma once
#include <algorithm>

#include "MySort/Core/PreDefined.hpp"

namespace mysort
{
template <class _It, class _Pr = std::less<>>
void selectionSort(_It _begin, _It _end, const _Pr& _pred = {})
{
    YWARNING("Selection Sort requires forward iterator. Skip sorting.");
}

template <class _It, class _Pr = std::less<>>
    requires std::forward_iterator<_It>
void selectionSort(_It _begin, _It _end, const _Pr& _pred = {})
{
    if (_begin == _end) {
        return;
    }

    for (_It i = _begin; std::next(i) != _end; ++i) {
        _It selected = i;
        for (_It j = std::next(i); j != _end; ++j) {
            if (_pred(*j, *selected)) {
                selected = j;
            }
        }
        if (selected != i) {
            std::iter_swap(selected, i);
        }
    }
}
}  // namespace mysort