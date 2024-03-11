
/******************************************************************************
 * MODULE     : scheme.hpp
 * DESCRIPTION: scheme data
 * COPYRIGHT  : (C) 2024    Darcy Shen
 *******************************************************************************
 * This software falls under the GNU general public license version 3 or later.
 * It comes WITHOUT ANY WARRANTY WHATSOEVER. For details, see the file LICENSE
 * in the root directory or <http://www.gnu.org/licenses/gpl-3.0.html>.
 ******************************************************************************/

#include "tree.hpp"

namespace moebius {
namespace data {

/**
 * @brief parse string as scheme tree
 *
 * @param s
 * @return scheme_tree
 */
scheme_tree string_to_scheme_tree (string s);

/**
 * @brief parse block as scheme tree
 *
 * @param s
 * @return scheme_tree
 */
scheme_tree block_to_scheme_tree (string s);

/**
 * @brief serialize scheme tree to string
 *
 * @param t
 * @return string
 */
string scheme_tree_to_string (scheme_tree t);

/**
 * @brief serialize scheme tree to block
 *
 * @param t
 * @return string
 */
string scheme_tree_to_block (scheme_tree t);

tree scheme_tree_to_tree (scheme_tree t, hashmap<string, int> codes, bool flag);

tree scheme_tree_to_tree (scheme_tree t);

/**
 * @brief convert scheme tree to tree
 *
 * @param t
 * @param version
 * @return tree
 */
tree scheme_tree_to_tree (scheme_tree t, string version);

scheme_tree tree_to_scheme_tree (tree t);

tree scheme_to_tree (string s);

string tree_to_scheme (tree t);

/**
 * @brief convert scheme document (.stm) to tree
 *
 * @param s
 * @return tree
 */
tree scheme_document_to_tree (string s);
} // namespace data
} // namespace moebius
