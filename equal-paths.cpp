#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
static int pathLength(Node* n);

bool equalPaths(Node * root)
{
    // Add your code below
    if(root == nullptr){
      return true;
    }
    return pathLength(root)>=0;

}

static int pathLength(Node* n){
  if(n->left== nullptr && n->right == nullptr){
    return 0;
  }
  if(n->left == nullptr){
    int r = pathLength(n->right);
    return (r<0)?-1:r+1;
  }
  if(n->right == nullptr){
    int l = pathLength(n->left);
    return (l<0)?-1:l+1;
  }
  int l = pathLength(n->left);
  int r = pathLength(n->right);
  if(l<0||r<0||l!=r){
    return -1;
  }
  return l+1;
}

