/** \file drd_info_test.cpp
 *  \copyright GPLv3
 *  \details Unitests for drd data structure
 *  \author jingkaimori
 *  \date   2024
 */

#include "moe_doctests.hpp"
#include "moebius/drd/drd_info.hpp"
#include "tree_helper.hpp"

using namespace moebius;

using moebius::drd::drd_info;

TEST_CASE ("drd initialize macro") {
  drd_info test_drd ("test");
  test_drd->heuristic_init_macro (
      "test-macro",
      tree (MACRO, "arg1", "arg2",
            tree (CONCAT, tree (ARG, "arg1"), " text ", tree (ARG, "arg2"))));
  tree_label test_macro_label= make_tree_label ("test-macro");
  CHECK_EQ (test_drd->get_arity_base (test_macro_label), 2);
  CHECK_EQ (test_drd->get_arity_extra (test_macro_label), 0);
  CHECK_EQ (test_drd->get_arity_mode (test_macro_label), ARITY_NORMAL);
  CHECK_EQ (test_drd->get_nr_indices (test_macro_label), 2);
}