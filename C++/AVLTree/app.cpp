
#include <iostream>
#include "avltree.h"

using namespace std;

int main(){
	AvlTree<int> avlTree;
	int x;
	cin>>x;
	while(x!=-1){
		avlTree.insert(x);
		cin>>x;

	}

	avlTree.preOrderT();


	return 0;
}



