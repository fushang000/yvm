#ifndef INFRASTRUCTURE_RBTREE_H
#define INFRASTRUCTURE_RBTREE_H

#include <type_traits>

template<typename _KeyType, typename _ValueType>
class RBTree {
public:
	struct Node {
		explicit Node() :left(nullptr), right(nullptr), parent(nullptr) {}

		Node * left;
		Node * right;
		Node * parent;

		_KeyType key;
		_ValueType value;
		bool black;
	};
public:
	explicit RBTree() {
		root = nullptr;
	}
	void put(const _KeyType key, const _ValueType value);

	void remove(const _KeyType key);

	Node * minNode(Node * start);

private:
	void insertFixup(Node * current);
	void deleteFixup(Node * current);

	void rotateLeft(Node *node);
	void rotateRight(Node * node);

private:
	void transplant(Node *u, Node * v);
private:
	inline bool isRed(Node * node) const {
		return node->black == false;
	}
	inline bool isBlack(Node *node) const {
		return node->black == true;
	}
	inline bool exist(Node *node) const {
		return node != nullptr;
	}
private:
	Node * root;
};

template<typename _KeyType, typename _ValueType>
void RBTree<_KeyType, _ValueType>::put(const _KeyType key, const _ValueType value) {
	Node * traverse = root;
	Node * validNode = nullptr;
	bool insertLeft = false;

	while (traverse != nullptr) {
		if (key == traverse->key) {
			traverse->value = value;
			return;
		}
		else if (key < traverse->key) {
			validNode = traverse;
			insertLeft = true;
			traverse = traverse->left;
		}
		else if (key > traverse->key) {
			validNode = traverse;
			insertLeft = false;
			traverse = traverse->right;
		}
	}


	Node * newNode = new Node();
	newNode->parent = validNode;

	if (root == nullptr) {
		//if the tree was empty
		root = newNode;
	}
	else {
		if (insertLeft) {
			validNode->left = newNode;
		}
		else {
			validNode->right = newNode;
		}
	}
	newNode->black = false;
	newNode->key = key;
	newNode->value = value;
	insertFixup(newNode);
}

template<typename _KeyType, typename _ValueType>
void RBTree<_KeyType, _ValueType>::insertFixup(Node * current) {
	/*if (current->parent == nullptr) {
		current->black = true;
	}
	else if (current->parent->black) {
		//nop
	}
	else {*/
		while (current->parent && current->parent->black == false) {
			if (current->parent->parent->left == current->parent) {
				//if the father node is the left child of its father
				Node * uncle = current->parent->parent->right;
				if (uncle && uncle->black == false) {
					//case 1
					current->parent->black = true;
					uncle->black = true;
					current->parent->parent->black = false;
					current = current->parent->parent;
				}
				else if (current == current->parent->right) {
					//case 2
					current = current->parent;
					rotateLeft(current);
				}
				else if (current == current->parent->left) {
					//case 3
					current->parent->black = true;
					current->parent->parent->black = false;
					rotateRight(current->parent->parent);
				}
				else {
					static_assert(true, "should not reach here");
				}
			}
			else {
				//otherwise, the father node is the right child of its father
				Node * uncle = current->parent->parent->left;
				if (uncle && uncle->black == false) {
					//case 1
					current->parent->black = true;
					uncle->black = true;
					current->parent->parent->black = false;
					current = current->parent->parent;
				}
				else if (current == current->parent->left) {
					//case 2
					current = current->parent;
					rotateRight(current);
				}
				else if (current == current->parent->right) {
					//case 3
					current->parent->black = true;
					current->parent->parent->black = false;
					rotateLeft(current->parent->parent);
				}
				else {
					static_assert(true, "should not reach here");
				}
			}

		}
		root->black = true;
	//}
}

template<typename _KeyType, typename _ValueType>
void RBTree<_KeyType, _ValueType>::remove(const _KeyType key) {
	if (root == nullptr) {
		return;
	}

	Node * traverse = root;

	while (traverse != nullptr) {
		if (key == traverse->key) {
			break;
		}
		else if (key < traverse->key) {
			traverse = traverse->left;
		}
		else if (key > traverse->key) {
			traverse = traverse->right;
		}
	}

	//if the specified key does not exist
	if (traverse == nullptr) {
		return;
	}

	Node * temp = traverse;
	Node * successor = nullptr;
	bool originalColor = temp->black;
	if (traverse->left == nullptr && traverse->right == nullptr) {
		if (traverse == root) {
			root = nullptr;
			delete temp;
			return;
		}
		else {
			if (traverse->parent->left == traverse) {
				traverse->parent->left = nullptr;
				delete temp;
				return;
			}
			else if (traverse->parent->right == traverse) {
				traverse->parent->right = nullptr;
				delete temp;
				return;
			}
		}
	}
	else if (traverse->left == nullptr && traverse->right != nullptr) {
		successor = traverse->right;
		transplant(traverse, traverse->right);
		delete traverse;
		return;
	}
	else if (traverse->right == nullptr && traverse->left != nullptr) {
		successor = traverse->left;
		transplant(traverse, traverse->left);
		delete temp;
		return;
	}
	else {
		temp = minNode(traverse->right);
		originalColor = temp->black;
		successor = temp->right;

		if (temp->parent != traverse) {
			if (temp->right) {
				transplant(temp, temp->right);
			}
			else {
				if (temp->parent->right == temp) {
					temp->parent->right == nullptr;
				}
				else {
					temp->parent->left = nullptr;
				}
			}
			temp->right = traverse->right;
			temp->right->parent = temp;
		}
		transplant(traverse, temp);
		temp->left = traverse->left;
		temp->left->parent = temp;
		temp->black = traverse->black;
	}
	if (successor && originalColor == true) {
		deleteFixup(successor);
	}
	delete traverse;
}

template<typename _KeyType, typename _ValueType>
void RBTree<_KeyType, _ValueType>::deleteFixup(Node * current) {
	while (current && current->black == true && current != root ) {
		if (current == current->parent->left) {
			Node * brother = current->parent->right;
			if (isRed(brother)) {
				brother->black = true;
				current->parent->black = false;
				rotateLeft(current->parent);
				brother = current->parent->right;
			}
			else if (exist(brother->left) && exist(brother->right) &&
				isBlack(brother) && isBlack(brother->left) && isBlack(brother->right)) {
				brother->black = false;
				current = current->parent;
			}
			else if (exist(brother->left) && exist(brother->right) &&
				isRed(brother->left) && isBlack(brother->right)) {
				brother->left->black = true;
				brother->black = false;
				rotateRight(brother);
				brother = current->parent->right;
			}
			else if (exist(brother->right) &&
				isBlack(brother) &&
				isRed(brother->right)) {
				brother->black = current->parent->black;
				current->parent->black = true;
				brother->right->black = true;
				rotateLeft(current->parent);
				current = root;
			}
		}
		else {
			Node * brother = current->parent->left;
			if (isRed(brother)) {
				brother->black = true;
				current->parent->black = false;
				rotateRight(current->parent);
				brother = current->parent->left;
			}
			else if (exist(brother->left) && exist(brother->right) &&
				isBlack(brother) && isBlack(brother->left) && isBlack(brother->right)) {
				brother->black = false;
				current = current->parent;
			}
			else if (exist(brother->left) && exist(brother->right) &&
				isRed(brother->right) && isBlack(brother->left)) {
				brother->right->black = true;
				brother->black = false;
				rotateLeft(brother);
				brother = current->parent->left;
			}
			else if (exist(brother->left) &&
				isBlack(brother) &&
				isRed(brother->left)) {
				brother->black = current->parent->black;
				current->parent->black = true;
				brother->left->black = true;
				rotateRight(current->parent);
				current = root;
			}
		}
		current->black = true;
	}
}

template<typename _KeyType, typename _ValueType>
typename RBTree<_KeyType, _ValueType>::Node * RBTree<_KeyType, _ValueType>::minNode(Node * start) {
	if (root == nullptr) {
		return nullptr;
	}

	Node *temp = start;

	while (temp->left != nullptr) {
		temp = temp->left;
	}
	return temp;
}

template<typename _KeyType, typename _ValueType>
void RBTree<_KeyType, _ValueType>::rotateLeft(Node * node) {
	Node * rightNode = node->right;
	node->right = rightNode->left;
	if (rightNode->left != nullptr) {
		rightNode->left->parent = node;
	}
	rightNode->parent = node->parent;

	if (node->parent == nullptr) {
		root = rightNode;
	}
	else if (node->parent->left == node) {
		node->parent->left = rightNode;
	}
	else {
		node->parent->right = rightNode;
	}
	rightNode->left = node;
	node->parent = rightNode;
}

template<typename _KeyType, typename _ValueType>
void RBTree<_KeyType, _ValueType>::rotateRight(Node * node) {
	Node * leftNode = node->left;
	node->left = leftNode->right;
	if (leftNode->right != nullptr) {
		leftNode->right->parent = node;
	}

	leftNode->parent = node->parent;

	if (node->parent == nullptr) {
		root = leftNode;
	}
	else if (node->parent->right == node) {
		node->parent->right = leftNode;
	}
	else {
		node->parent->left = leftNode;
	}
	leftNode->right = node;
	node->parent = leftNode;
}

template<typename _KeyType, typename _ValueType>
void RBTree<_KeyType, _ValueType>::transplant(Node * u, Node * v) {
	if (u->parent == nullptr) {
		root = v;
	}
	else if (u->parent->left == u) {
		u->parent->left = v;
	}
	else {
		u->parent->right = v;
	}
	v->parent = u->parent;
}


#endif //INFRASTRUCTURE_RBTREE_H