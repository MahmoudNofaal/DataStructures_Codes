# 🌳 Tree Data Structures and Algorithms 🌳

## Important Info About Trees

Welcome to the world of trees! This file contains essential information and codes related to trees and their various types.

🚧 **Note:** This section is currently under construction. Stay tuned for updates!

### Rules for Trees 📜

- **Maximum Nodes at Level:** `2^L`
- **Maximum Nodes in a Binary Tree:** `2^(h+1) - 1`

### Binary Tree Traversal 🚶‍♂️

- **Pre-Order:** `root -> left -> right`
- **In-Order:** `left -> root -> right`
- **Post-Order:** `left -> right -> root`

### Insertion Rule ✏️

After inserting the first element (root):
- If the new element is greater than the current node, insert it to the right.
- If the new element is less than or equal to the current node, insert it to the left.

To Get Maximum Element: Traverse to the rightmost node.  
To Get Minimum Element: Traverse to the leftmost node.

### Deletion 🗑️

**First Case:** Deleting Leaves
- Simply remove them.

**Second Case:** Deleting Nodes with One Child
- Delete the node, then link its child with the node before it.

**Third Case:** Deleting Nodes with Two Children
- Replace the node with the minimum element from its right subtree.

### Finding Successor 🌟

- If the node `x` has a right subtree, its successor is the minimum element in that subtree.
- If there's no right subtree, the successor is the right child of its parent if it exists.
- If there's no right subtree and it's the right child of its parent, the successor is the left child of its parent.
- *Predecessor is vice versa to Successor.*

---

This file is a work in progress. More content will be added soon. 🚀
