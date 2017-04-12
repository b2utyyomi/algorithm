/*
#include<iostream>
#include<cstdio>
using namespace std;
#define TOTAL 20

int HeapInsert(int *heap, int n, int num){
    heap[n] = num;
    int i = n;
    int j = (n-1)/2;
    while(j>=0 && i!=0){
        if(heap[j]<=num)
            break;
        heap[i] = heap[j];
        i = j;
        j = (i-1)/2;
    }
    heap[i] = num;
    return 0;
}
int heapadjust(int *heap, int top, int n){
    int j = 2*top+1;
    int temp = heap[top];
    while(j<n){
        if(heap[j+1]<heap[j] && j+1<n){
            j++;
        }
        if(heap[j] >= temp)
            break;
        heap[top] = heap[j];
        top = j;
        j = 2*top+1;

    }
    heap[top] = temp;
    return 0;
}
int HeapDelete(int *heap, int n){
    heap[0] = heap[n-1];
    heapadjust(heap, 0, n-1);
}

int CreatHeap(int *array, int n){
    for(int i=(n-2)/2; i>=0; i--){
        heapadjust(array, i, n);
    }
    return 0;
}
int HeapSort(int *heap, int n){
    for(int i=n-1; i>0; i--){
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        heapadjust(heap, 0, i);
    }
}
int main()
{
    int heap[TOTAL];
    int num;
    int i;

    ///先输入一半的数据，对输入的数组建堆。
    printf("输入Total/2个数据：\n");
    for (i = 0; i < TOTAL / 2; i++)
        scanf("%d", &heap[i]);

    CreatHeap(heap, TOTAL / 2);

    ///检验是否建堆成功。
    printf("建堆后：\n");
    for (i = 0; i < TOTAL / 2; i++)
        printf("%-3d", heap[i]);
    putchar('\n');

    ///向已建好的堆中插入数据，并重组为堆。
    printf("继续输入Total/4个数据：\n");
    for (i = TOTAL / 2; i < TOTAL / 2 + TOTAL / 4; i++)
    {
        scanf("%d", &num);
        HeapInsert(heap, i, num);
    }

    ///检验是否插入成功。
    printf("重组为堆之后：\n");
    for (i = 0; i < TOTAL / 2 + TOTAL / 4; i++)
        printf("%-3d", heap[i]);
    putchar('\n');

    ///删除堆顶元素Total/4次。
    printf("删除Total/4个数据：\n");
    for (i = 0; i < TOTAL / 4; i++)
        HeapDelete(heap, TOTAL / 2 + TOTAL / 4 - i);

    ///检验是否删除成功。
    for (i = 0; i < TOTAL / 2; i++)
        printf("%-3d", heap[i]);
    putchar('\n');

    ///向堆中插满数据，进行堆排序。
    printf("继续输入Total/2个数据：\n");
    for (i = TOTAL / 2; i < TOTAL; i++)
    {
        scanf("%d", &num);
        HeapInsert(heap, i, num);
    }

    HeapSort(heap, TOTAL);
    printf("排序后：\n");
    for (i = 0; i < TOTAL; i++)
        printf("%-3d ", heap[i]);
    putchar('\n');
    for (i = 0; i < 6; i++)
        scanf("%d", &heap[i]);

    CreatHeap(heap, 6);

    ///检验是否建堆成功。
    printf("建堆后：\n");
    for (i = 0; i <6; i++)
        printf("%-3d", heap[i]);
    return 0;
}
*/
/*
#include<iostream>
#include<cstdio>
#define total 20
using namespace std;
int heap[20];

int heapinsert(int *heap, int n, int num){
    heap[n] = num;
    int i = n;
    int j = (n-1)/2;
    while(j>=0 && i!=0){
        if(heap[j]<=num)
            break;
        heap[i] = heap[j];
        i = j;
        j = (i-1)/2;
    }
    heap[i] = num;
    return 0;
}
int heapadjust(int *heap, int top, int n){
    int j = 2*top+1;
    int temp = heap[top];
    while(j<n){
        if(heap[j+1]< heap[j] && j+1<n){
            j++;
        }
        if(temp <= heap[j])
        break;
        heap[top] = heap[j];
        top = j;
        j = 2*top+1;
    }
    heap[top] = temp;
    return 0;
}
int heapdelete(int *heap, int n){
    heap[0] = heap[n-1];
    heapadjust(heap, 0, n-1);
    return 0;
}
int heapcreate(int *heap, int n){
    for(int i=(n-2)>>1; i>=0; i--){
         heapadjust(heap, i, n);
    }
    return 0;
}
int heapsort(int *heap, int n){
    for(int i=n-1; i>0; i--){
        int temp;
        temp = heap[i];
        heap[i] = heap[0];
        heap[0] = temp;
        heapadjust(heap, 0, i);
    }
    return 0;
}
int main()
{
    int heap[total];
    int num;
    int i;

    ///先输入一半的数据，对输入的数组建堆。
    printf("输入Total/2个数据：\n");
    for (i = 0; i < total/ 2; i++)
        scanf("%d", &heap[i]);

    heapcreate(heap, total / 2);

    ///检验是否建堆成功。
    printf("建堆后：\n");
    for (i = 0; i < total / 2; i++)
        printf("%-3d", heap[i]);
    putchar('\n');

    ///向已建好的堆中插入数据，并重组为堆。
    printf("继续输入Total/4个数据：\n");
    for (i = total / 2; i < total / 2 + total / 4; i++)
    {
        scanf("%d", &num);
        heapinsert(heap, i, num);
    }

    ///检验是否插入成功。
    printf("重组为堆之后：\n");
    for (i = 0; i < total/ 2 + total / 4; i++)
        printf("%-3d", heap[i]);
    putchar('\n');

    ///删除堆顶元素Total/4次。
    printf("删除Total/4个数据：\n");
    for (i = 0; i < total / 4; i++)
        heapdelete(heap, total / 2 + total/ 4 - i);

    ///检验是否删除成功。
    for (i = 0; i < total / 2; i++)
        printf("%-3d", heap[i]);
    putchar('\n');

    ///向堆中插满数据，进行堆排序。
    printf("继续输入Total/2个数据：\n");
    for (i = total / 2; i < total; i++)
    {
        scanf("%d", &num);
        heapinsert(heap, i, num);
    }

    heapsort(heap, total);
    printf("排序后：\n");
    for (i = 0; i < total; i++)
        printf("%-3d ", heap[i]);
    putchar('\n');
    return 0;
}
*/
/**********
堆内的元素并不一定数组下标顺序来排序的！！很多的初学者会错误的认为大/小根堆中

　　　　下标为1就是第一大/小，2是第二大/小……
**********/
/*
#include<iostream>
using namespace std;
const int total = 20;

void heapinsert(int *heap,int i, int num){/// shift up
    int j = (i-1)/2;
    heap[i] = num;
    while(j>=0 && i!=0){
        if(heap[j]<num)
            break;
        heap[i] = heap[j];
        i = j;
        j = (i-1)/2;
    }
    heap[i] = num;
}

void heapadjust(int *heap, int top, int n){
    int j = 2*top+1;
    int temp = heap[top];
    while(j<n){
        if(j+1<n && heap[j+1]<heap[j]){
            j++;
        }
        if(heap[j]> temp){
            break;
        }
        heap[top] = heap[j];
        top = j;
        j = 2*top+1;
    }
    heap[top] = temp;
}
void heapdelete(int *heap, int n){
    heap[0] = heap[n-1];
    heapadjust(heap, 0, n-1);
}

void heapcreate(int *heap, int n){
    for(int i=(n-2)/2; i>=0; i--){
        heapadjust(heap, i, n);
    }
}
 int main(int argc, char const *argv[]) {
     int heap[100];
     for(int i=0; i<total/2; i++){
         cin >> heap[i];
     }
     heapcreate(heap, total/2);
     for(int i=0; i<total/2; i++){
         cout << heap[i] << ' ';
     }
     cout << endl;
     for(int i=total/2; i<total/2+total/4; i++){
         cin >> heap[i];
         heapinsert(heap, i, heap[i]);
     }
     for(int i=0; i<total/2+total/4; i++){
         cout << heap[i] << ' ';
     }
     cout << endl;

     for(int i=0; i<total/4; i++){
        heapdelete(heap, total/2+total/4-i);
     }

     for(int i=0; i<total/2; i++){
         cout << heap[i] << ' ';
     }
     cout << endl;
     return 0;
 }
*/
/*
///heap
#include<iostream>
using namespace std;

void heap_insert(int *heap, int i, int num){
    int j = (i-1)>>1;
    heap[i] = num;
    while(j>=0 && i!=0){
        if(heap[j] < num)
            break;
        heap[i] = heap[j];
        i = j;
        j = (i-1)>>1;
    }
    heap[i] = num;
}

void heap_adjust(int *heap, int top, int n){
    int j = 2*top+1;
    int temp = heap[top];
    while(j<n){
        if(j+1<n && heap[j+1]<heap[j])
            j++;
        if(heap[j]>=temp)
            break;
        heap[top] = heap[j];
        top = j;
        j = 2*top+1;
    }
    heap[top] = temp;
}

void heap_delete(int *heap, int n){
    heap[0] = heap[n-1];
    heap_adjust(heap, 0, n-1);
}

void heap_create(int *heap, int n){
    for(int i=(n-2)/2; i>=0; i--){
        heap_adjust(heap, i, n);
    }
}

void heap_sort(int *heap, int n){
    for(int i=n-1; i>=0; i--){
        int temp = heap[i];
        heap[i] = heap[0];
        heap[0] = temp;
        heap_adjust(heap, 0, i);
    }
}

int main(){
    int heap[100];
    int n;
    cin >> n;
    ///对给出的一棵完全二叉树 进行自底向上的堆调整  建小顶堆
    cout << "Create1: " ;
    for(int i=0; i<n; i++){
        cin >> heap[i];
    }
    heap_create(heap, n);
    for(int i=0; i<n; i++){
        cout << heap[i] << ' ';
    }
    cout << endl;

    cout << "Create2: ";
    ///动态插入  小顶堆
    for(int i=0; i<n; i++){
        cin >> heap[i];
        heap_insert(heap, i, heap[i]);///shift_up
    }
    for(int i=0; i<n; i++){
        cout << heap[i] << ' ';
    }
    cout << endl;
    cout << "heap_delete: ";
    heap_delete(heap, n);
    for(int i=0; i<n-1; i++){
        cout << heap[i] << ' ';
    }
    cout << endl;
    cout << "heap_sort: ";
    heap_sort(heap, n-1);
    for(int i=0; i<n-1; i++){
        cout << heap[i] << ' ';
    }
    return 0;
}
*/
/****
6
Create1: 9 3 2 1 8 7
1 3 2 9 8 7
Create2: 9 3 2 1 8 7
1 2 3 9 8 7
heap_delete: 2 7 3 9 8
heap_sort: 9 8 7 3 2
Process returned 0 (0x0)   execution time : 61.704 s
Press any key to continue.

****/

/// AVLtree
#include <iostream>

using namespace std;
typedef struct treenode{
    int data;
    treenode *lchild, *rchild;
    int height;
}*AVLtree, node;

void pre_order(node *t){
    if(t){
        cout << t->data << ' ';
        pre_order(t->lchild);
        pre_order(t->rchild);
    }
}

void in_order(node *t){
    if(t){
        in_order(t->lchild);
        cout << t->data << ' ';
        in_order(t->rchild);
    }
}

int depth(node *t){
    if(!t){
        return 1;
    }
    return max(depth(t->lchild), depth(t->rchild))+1;
}

///LL -> R_Rotate
node *R_Rotate(node *t1){
    node *t2 = t1->lchild;
    t1->lchild = t2->rchild;
    t2->rchild = t1;

    t1->height = depth(t1);
    t2->height = depth(t2);
    return t2;
}

///RR -> L_Rotate
node *L_Rotate(node *t1){
    node *t2 = t1->rchild;
    t1->rchild = t2->lchild;
    t2->lchild = t1;

    t1->height = depth(t1);
    t2->height = depth(t2);
    return t2;
}
///LR -> LR
node *LR(node *t1){
    node *t2 = t1->lchild;
    t2 = L_Rotate(t2);
    t1->lchild = t2;
    return R_Rotate(t1);
}
///RL -> RL
node *RL(node *t1){
    node *t2 = t1->rchild;
    t2 = R_Rotate(t2);
    t1->rchild = t2;
    return L_Rotate(t1);
}
/*
node *AVL_insert(node *t, int e){
    cout << "1" << endl;
    if(t == NULL){
        t = new node;
        t->lchild = NULL;
        t->rchild = NULL;
        t->data = e;
        t->height = 0;
        cout << "2" << endl;

    }
    else if(e <= t->data){

        t->lchild = AVL_insert(t->lchild, e);

        if(depth(t->lchild)- depth(t->rchild) == 2){
            if(e < t->lchild->data){
                t = R_Rotate(t);
            }
            else{
                cout << "LR" << endl;
                t = LR(t);
            }
        }
    }
    else if(e > t->data){
        t->rchild = AVL_insert(t->rchild, e);
        if(t->rchild->height - t->lchild->height == 2){
            if(e > t->rchild->data){
                t = L_Rotate(t);
            }
            else{
                t = RL(t);
            }
        }
    }

    t->height = depth(t);
    return t;
}
*/
AVLtree AVL_insert(AVLtree *T, int e)
{
    if (*T == NULL)
    {
        *T = new node;

        (*T)->data = e;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        (*T)->height = 0;
    }
    else if(e < (*T)->data)
    {
        (*T)->lchild =AVL_insert(&(*T)->lchild,e);

        if (depth((*T)->lchild) - depth((*T)->rchild) == 2)
        {
            if (e < (*T)->lchild->data)
            {
                *T = R_Rotate(*T);
            }
            else
            {
                cout << "LR" << endl;
                *T = LR(*T);
            }
        }
    }
    else if(e > (*T)->data)
    {
        (*T)->rchild =AVL_insert(&(*T)->rchild,e);
        if (depth((*T)->rchild) - depth((*T)->lchild) == 2)
        {
            if (e > (*T)->rchild->data)
            {
                *T = L_Rotate(*T);
            }
            else
            {
                *T = RL(*T);
            }
        }
    }

    (*T)->height = depth(*T) ;
    return *T;
}

int main(){
    node *t = NULL;
    int n, s;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        t = AVL_insert(&t, s);
    }

    cout << "pre_order: ";
    pre_order(t);
    cout << endl;
    cout << "in_order: ";
    in_order(t);
    cout << endl;
    return 0;
}






