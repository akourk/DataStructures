
#ifndef AVLTREE_H_
#define AVLTREE_H_
#include <iostream>
using namespace std;


template <class T>
struct AvlNode
{
   T element;
   AvlNode   *left;
   AvlNode   *right;
   int       height;
};

template <class T>
class AvlTree{
private:
	AvlNode<T>* root;
	void insert( T& x, AvlNode<T> *& t );
	void inOrderT(AvlNode<T>*);
	void preOrderT(AvlNode<T>*);
	void rotateWithLeftChild( AvlNode<T> * & k2 );
	void rotateWithRightChild( AvlNode<T> * & k2 );
	void doubleWithLeftChild( AvlNode<T> * & k3 );
	void doubleWithRightChild( AvlNode<T> * & k3 );
	int height(AvlNode<T>*);

public:
	AvlTree(){
		root = NULL;
	}
	void preOrderT(){preOrderT(root);}
	void inOrderT(){inOrderT(root);}
	int height(){height(root);}
	void insert( T &x){insert(x, root);}
};

template <class T>
void AvlTree<T>::inOrderT(AvlNode<T>* p){
	if(p!=NULL){
		inOrderT(p->left);
		cout<<p->element;
		inOrderT(p->right);
	}
}
template <class T>
void AvlTree<T>::preOrderT(AvlNode<T>* p){
	if(p!=NULL){
		cout<<p->element;
		preOrderT(p->left);
		preOrderT(p->right);
	}
}

template <class T>
int AvlTree<T>::height( AvlNode<T> *t)
{
	return t == NULL ? -1 : t->height;
}

/**
 * Rotate binary tree node with left child.
 * For AVL trees, this is a single rotation for case 1.
 * Update heights, then set new root.
 */
template <class T>
void AvlTree<T>::rotateWithLeftChild( AvlNode<T> * & k2 )
{
   AvlNode<T> *k1 = k2->left;
   k2->left = k1->right;
   k1->right = k2;
   k2->height = max( height( k2->left ), height( k2->right ))+1;
   k1->height = max( height( k1->left ), k2->height ) + 1;
   k2 = k1;
}

/**
 * Rotate binary tree node with left child.
 * For AVL trees, this is a single rotation for case 1.
 * Update heights, then set new root.
 */
template <class T>
void AvlTree<T>::rotateWithRightChild( AvlNode<T> * & k2 )
{
   AvlNode<T> *k1 = k2->right;
   k2->right = k1->left;
   k1->left = k2;
   k2->height = max( height( k2->right ), height( k2->left ))+1;
   k1->height = max( height( k1->right ), k2->height ) + 1;
   k2 = k1;
}

/**
 * Double rotate binary tree node: first left child.
 * with its right child; then node k3 with new left child.
 * For AVL trees, this is a double rotation for case 2.
 * Update heights, then set new root.
 */
template <class T>
void AvlTree<T>::doubleWithLeftChild( AvlNode<T> * & k3 )
{
   rotateWithRightChild( k3->left );
   rotateWithLeftChild( k3 );
}

template <class T>
void AvlTree<T>::doubleWithRightChild( AvlNode<T> * & k3 )
{
   rotateWithLeftChild( k3->right );
   rotateWithRightChild( k3 );
}

/* Internal method to insert into a subtree.
 * x is the item to insert.
 * t is the node that roots the tree.
 */
template <class T>
void AvlTree<T>::insert( T &x, AvlNode<T> *&t )
{
   if( t == NULL ){
     t = new AvlNode<T>();
     t->element = x;
     t->right = NULL;
     t->left = NULL;
     t->height = 0;
   }else if( x < t->element )
   {
     insert( x, t->left );
     if( height( t->left ) - height( t->right ) == 2 )
       if( x < t->left->element )
           rotateWithLeftChild( t );
       else
           doubleWithLeftChild( t );
   }
   else if( t->element < x )
   {
       insert( x, t->right );
       if( height( t->right ) - height( t->left ) == 2 )
          if( t->right->element < x )
             rotateWithRightChild( t );
          else
             doubleWithRightChild( t );
    }
    else
       ;  // Duplicate; do nothing
    t->height = max( height( t->left ), height( t->right ) ) + 1;
}

#endif AVLTREE_H_

