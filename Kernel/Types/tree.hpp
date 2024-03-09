/** \file tree.hpp
 *  \copyright GPLv3
 *  \details tree
 *  \author Darcy Shen
 *  \date   2024
 */

#pragma once

#include "observer.hpp"

using lolly::data::A;
using lolly::data::is_atomic;

inline int
hash (tree t) {
  if (is_atomic<observer> (t)) return hash (t->label);
  else return t->op ^ hash (A<observer> (t));
}

inline int
hash (array<tree> a) {
  int i, h= 0, n= N (a);
  for (i= 0; i < n; i++) {
    h= (h << 7) + (h >> 25);
    h= h + hash (a[i]);
  }
  return h;
}

inline int
right_index (tree t) {
  return is_atomic (t) ? N (t->label) : 1;
}
