#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
int N = 10000;
struct node{
    int val, height;
    node *l, *r;
    node(int val = 0, node *l = NULL, node *r = NULL) : val(val), height(0), l(l), r(r) {}
};
node *root = NULL;
int height(node *t){
    if(t == NULL)return -1;
    return t->height;
}
void updataheight(node *t){
    t->height = max(height(t->l), height(t->r)) + 1;
}
void rotateWithLson(node *&k2){
    node *k1 = k2->l;
    k2->l = k1->r;
    k1->r = k2;
    updataheight(k2);
    updataheight(k1);
    k2 = k1;
}
void rotateWithRson(node *&k1){
    node *k2 = k1->r;
    k1->r = k2->l;
    k2->l = k1;
    updataheight(k1);
    updataheight(k2);
    k1 = k2;
}
void doubleWithLson(node *&k3){
    rotateWithRson(k3->l);
    rotateWithLson(k3);
}
void doubleWithRson(node *&k3){
    rotateWithLson(k3->r);
    rotateWithRson(k3);
}
void balance(node *&t){
    if (t == NULL)return;
    if (height(t->l) - height(t->r) > 1){
        if (height(t->l->l) >= height(t->l->r))
            rotateWithLson(t);
        else
            doubleWithLson(t);
    }
    else if (height(t->r) - height(t->l) > 1){
        if (height(t->r->r) >= height(t->r->l))
            rotateWithRson(t);
        else
            doubleWithRson(t);
    }
    t->height = max(height(t->l), height(t->r)) + 1;
}
void insert(node *&t, int val){
    if (t == NULL)t = new node(val, NULL, NULL);
    else if (val < t->val)insert(t->l, val);
    else if (val > t->val)insert(t->r, val);
    balance(t);
}
void order(){
    queue<node *> q;
    while (!q.empty())
    q.pop();
    q.push(root);
    while (!q.empty()){
        node *t = q.front();
        q.pop();
        printf("%d ", t->val);
        if (t->l != NULL)
            q.push(t->l);
        if (t->r != NULL)
            q.push(t->r);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        int val;
        scanf("%d", &val);
        insert(root, val);
    }
    order();
    return 0;
}
