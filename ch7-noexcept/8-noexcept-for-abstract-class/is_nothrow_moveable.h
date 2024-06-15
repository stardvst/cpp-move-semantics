#pragma once

#include <type_traits>

template <typename Base>
struct Wrapper : Base
{
  using Base::Base;
  void print() const override {} // must implement all pure virtual functions
};

template <typename T>
static constexpr inline bool is_nothrow_movable_v = std::is_nothrow_move_constructible_v<Wrapper<T>>;
