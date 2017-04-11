/*
#include<stdio.h>

#include<stdlib.h>
typedef int ElemType;
struct BTreeNode
{
    ElemType data;
    struct BTreeNode* left;
    struct BTreeNode* right;
};

//1、输出二叉树，可在前序遍历的基础上修改。采用广义表格式，元素类型为int
void PrintBTree_int(struct BTreeNode* BT)
{
    if (BT != NULL)
    {
        printf("%d", BT->data); //输出根结点的值
        if (BT->left != NULL || BT->right != NULL)
        {
            printf("(");
            PrintBTree_int(BT->left); //输出左子树
            if (BT->right != NULL)
                printf(",");
            PrintBTree_int(BT->right); //输出右子树
            printf(")");
        }
    }
}

//2、根据数组 a 中 n 个权值建立一棵哈夫曼树，返回树根指针
struct BTreeNode* CreateHuffman(ElemType a[], int n)
{
    int i, j;
    struct BTreeNode **b, *q;
    b = (struct BTreeNode**)malloc(n*sizeof(struct BTreeNode));
    for (i = 0; i < n; i++) //初始化b指针数组，使每个指针元素指向a数组中对应的元素结点
    {
        b[i] = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
        b[i]->data = a[i];
        b[i]->left = b[i]->right = NULL;
    }
    for (i = 1; i < n; i++)//进行 n-1 次循环建立哈夫曼树
    {
        //k1表示森林中具有最小权值的树根结点的下标，k2为次最小的下标
        int k1 = -1, k2;
        for (j = 0; j < n; j++)//让k1初始指向森林中第一棵树，k2指向第二棵
        {
            if (b[j] != NULL && k1 == -1)
            {
                k1 = j;
                continue;
            }
            if (b[j] != NULL)
            {
                k2 = j;
                break;
            }
        }
        for (j = k2; j < n; j++)//从当前森林中求出最小权值树和次最小
        {
            if (b[j] != NULL)
            {
                if (b[j]->data < b[k1]->data)
                {
                    k2 = k1;
                    k1 = j;
                }
                else if (b[j]->data < b[k2]->data)
                    k2 = j;
            }
        }
        //由最小权值树和次最小权值树建立一棵新树，q指向树根结点
        q = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
        ///q = new BTreeNode;
        q->data = b[k1]->data + b[k2]->data;
        q->left = b[k1];
        q->right = b[k2];

        b[k1] = q;//将指向新树的指针赋给b指针数组中k1位置
        b[k2] = NULL;//k2位置为空
    }
    free(b); //删除动态建立的数组b
    ///delete []b;
    return q; //返回整个哈夫曼树的树根指针
}

//3、求哈夫曼树的带权路径长度
ElemType WeightPathLength(struct BTreeNode* FBT, int len)//len初始为0
{
    if (FBT == NULL) //空树返回0
        return 0;
    else
    {
        if (FBT->left == NULL && FBT->right == NULL)//访问到叶子结点
            return FBT->data * len;
        else //访问到非叶子结点，进行递归调用，返回左右子树的带权路径长度之和，len递增
            return WeightPathLength(FBT->left,len+1)+WeightPathLength(FBT->right,len+1);
    }
}

//4、哈夫曼编码（可以根据哈夫曼树带权路径长度的算法基础上进行修改）
void HuffManCoding(struct BTreeNode* FBT, int len)//len初始值为0
{
    static int a[10];//定义静态数组a，保存每个叶子的编码，数组长度至少是树深度减一
    if (FBT != NULL)//访问到叶子结点时输出其保存在数组a中的0和1序列编码
    {
        if (FBT->left == NULL && FBT->right == NULL)
        {
            int i;
            printf("结点权值为%d的编码：", FBT->data);
            for (i = 0; i < len; i++)
                printf("%d", a[i]);
            printf("\n");
        }
        else//访问到非叶子结点时分别向左右子树递归调用，并把分支上的0、1编码保存到数组a
        {   //的对应元素中，向下深入一层时len值增1
            a[len] = 0;
            HuffManCoding(FBT->left, len + 1);
            a[len] = 1;
            HuffManCoding(FBT->right, len + 1);
        }
    }
}

//主函数
int main()
{
    int n, i;
    ElemType* a;
    struct BTreeNode* fbt;
    printf("从键盘输入待构造的哈夫曼树中带权叶子结点数n：");
    while(1)
    {
        scanf("%d", &n);
        if (n > 1)
            break;
        else
            printf("重输n值：");
    }
    a = (ElemType*)malloc(n*sizeof(ElemType));
    printf("从键盘输入%d个整数作为权值：", n);
    for (i = 0; i < n; i++)
        scanf(" %d", &a[i]);
    fbt = CreateHuffman(a, n);
    printf("广义表形式的哈夫曼树：");
    PrintBTree_int(fbt);
    printf("\n");
    printf("哈夫曼树的带权路径长度：");
    printf("%d\n", WeightPathLength(fbt, 0));
    printf("树中每个叶子结点的哈夫曼编码：\n");
    HuffManCoding(fbt, 0);
}
*/
/*
从键盘输入待构造的哈夫曼树中带权叶子结点数n：6
从键盘输入6个整数作为权值：3 9 5 12 6 15
广义表形式的哈夫曼树：50(21(9,12),29(14(6,8(3,5)),15))
哈夫曼树的带权路径长度：122
树中每个叶子结点的哈夫曼编码：
结点权值为9的编码：00
结点权值为12的编码：01
结点权值为6的编码：100
结点权值为3的编码：1010
结点权值为5的编码：1011
结点权值为15的编码：11

Process returned 0 (0x0)   execution time : 22.356 s
Press any key to continue.

*/


#include<iostream>
using namespace std;

typedef struct treenode{
    int data;
    treenode *lchild;
    treenode *rchild;
}node, *Tree;
int a[100];

node * create_huffman_tree(int n){
    node *b[100], *q;
    for(int i=0; i<n; i++){
        b[i] = new node;
        b[i]->data = a[i];
        b[i]->lchild = NULL;
        b[i]->rchild = NULL;
    }
    for(int i=0; i<n-1; i++){
        int k1 = -1, k2;  ///k1必须赋值 因为要控制循环的时候 若k1为初始化时的值 则跳过k1 直接对k2赋值


        for(int j=0; j<n; j++){

            if(b[j] && k1 == -1){
                k1 = j;
                continue;
            }
            if(b[j]){
                k2 = j;
                break;
            }
        }
        for(int j=k2; j<n; j++){
            if(b[j]){
                if(b[j]->data < b[k1]->data){
                    k2 = k1;
                    k1 = j;
                }
                else if(b[j]->data < b[k2]->data){
                    k2 = j;
                }
            }
        }
        q = new node;
        q->lchild = b[k1];
        q->rchild = b[k2];
        q->data = b[k1]->data + b[k2]->data;
        b[k1] = q;
        b[k2] = NULL;
    }
    return q;
}
void print_huffman_tree(node *t){
    if(t){
            cout << t->data;
        if(t->lchild || t->rchild){
            cout << "(";
            if(t->lchild){
                print_huffman_tree(t->lchild);
            }
            cout << ",";
            if(t->rchild){
                print_huffman_tree(t->rchild);
            }
            cout << ")";
        }
    }
}
int weight_path_length(node *t, int len)
{
    if(t)
    {
        if(t->lchild==NULL && t->rchild == NULL){
            ///cout << "*********************************" << endl;
            ///cout << len << endl;
            ///cout << t->data * len << endl;
            return t->data * len;
        }
        else{///++len为啥不行 不说别的 就从1那返回到上一层就不行
            return weight_path_length(t->lchild, len+1)+weight_path_length(t->rchild, len+1);
        }///因为len已经变了 所以递归的时候 要注意控制某些东西不变
    }///每返回到上一层一次 len就多加个1 终于明白了 呵呵呵呵哒
    return 0;
}
int huffman_code(node *t, int len){
    static int aa[100];
    if(t){
        if(t->lchild == NULL && t->rchild == NULL){
            for(int i=0; i<len; i++){
                cout << aa[i] ;
            }
            cout << endl;
        }

        if(t->lchild){
            aa[len] = 0;
            huffman_code(t->lchild, len+1);
        }
        if(t->rchild){
            aa[len] = 1;
            huffman_code(t->rchild, len+1);
        }
        /*else{
            aa[len] = 0;
            huffman_code(t->lchild, len+1);
            aa[len] = 1;
            huffman_code(t->rchild, len+1);
        }*/
    }
    ///return len;
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    cin >> a[i];
    node *tree;
    tree = create_huffman_tree(n);
    print_huffman_tree(tree);
    cout << endl;
    cout << weight_path_length(tree, 0) << endl;
   /* int len = */huffman_code(tree, 0);
    /*for(int i=0; i<len; i++){
        cout << aa[i] << endl;
    }*/

    return 0;
}
/*
4
4 2 1 3
*/
/*
len++ == len+1
4
4 2 1 3
10(4,6(3(1,2),3))
*********************************
1-------->4
4
*********************************
3--------->1
3
*********************************
3--------->2
6
*********************************
2--------->3
6
19

Process returned 0 (0x0)   execution time : 10.204 s
Press any key to continue.

*/
/*
++len
4
4 2 1 3
10(4,6(3(1,2),3))
*********************************
1-------->4
4
*********************************
4--------->1
4
*********************************
5------->2
10
*********************************
4    -----> 3
12
30

Process returned 0 (0x0)   execution time : 7.864 s
Press any key to continue.

*/
/*
#include<stdio.h>

#include<stdlib.h>
typedef int ElemType;
struct BTreeNode
{
    ElemType data;
    struct BTreeNode* left;
    struct BTreeNode* right;
};

//1、输出二叉树，可在前序遍历的基础上修改。采用广义表格式，元素类型为int
void PrintBTree_int(struct BTreeNode* BT)
{
    if (BT != NULL)
    {
        printf("%d", BT->data); //输出根结点的值
        if (BT->left != NULL || BT->right != NULL)
        {
            printf("(");
            PrintBTree_int(BT->left); //输出左子树
            if (BT->right != NULL)
                printf(",");
            PrintBTree_int(BT->right); //输出右子树
            printf(")");
        }
    }
}

//2、根据数组 a 中 n 个权值建立一棵哈夫曼树，返回树根指针
struct BTreeNode* CreateHuffman(ElemType a[], int n)
{
    int i, j;
    struct BTreeNode **b, *q;
    b = (struct BTreeNode**)malloc(n*sizeof(struct BTreeNode));
    for (i = 0; i < n; i++) //初始化b指针数组，使每个指针元素指向a数组中对应的元素结点
    {
        b[i] = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
        b[i]->data = a[i];
        b[i]->left = b[i]->right = NULL;
    }
    for (i = 1; i < n; i++)//进行 n-1 次循环建立哈夫曼树
    {
        //k1表示森林中具有最小权值的树根结点的下标，k2为次最小的下标
        int k1 = -1, k2;
        for (j = 0; j < n; j++)//让k1初始指向森林中第一棵树，k2指向第二棵
        {
            if (b[j] != NULL && k1 == -1)
            {
                k1 = j;
                continue;
            }
            if (b[j] != NULL)
            {
                k2 = j;
                break;
            }
        }
        for (j = k2; j < n; j++)//从当前森林中求出最小权值树和次最小
        {
            if (b[j] != NULL)
            {
                if (b[j]->data < b[k1]->data)
                {
                    k2 = k1;
                    k1 = j;
                }
                else if (b[j]->data < b[k2]->data)
                    k2 = j;
            }
        }
        //由最小权值树和次最小权值树建立一棵新树，q指向树根结点
        q = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
        ///q = new BTreeNode;
        q->data = b[k1]->data + b[k2]->data;
        q->left = b[k1];
        q->right = b[k2];

        b[k1] = q;//将指向新树的指针赋给b指针数组中k1位置
        b[k2] = NULL;//k2位置为空
    }
    free(b); //删除动态建立的数组b
    ///delete []b;
    return q; //返回整个哈夫曼树的树根指针
}

//3、求哈夫曼树的带权路径长度
ElemType WeightPathLength(struct BTreeNode* FBT, int len)//len初始为0
{
    if (FBT == NULL) //空树返回0
        return 0;
    else
    {
        if (FBT->left == NULL && FBT->right == NULL)//访问到叶子结点
            return FBT->data * len;
        else //访问到非叶子结点，进行递归调用，返回左右子树的带权路径长度之和，len递增
            return WeightPathLength(FBT->left,len+1)+WeightPathLength(FBT->right,len+1);
    }
}

//4、哈夫曼编码（可以根据哈夫曼树带权路径长度的算法基础上进行修改）
void HuffManCoding(struct BTreeNode* FBT, int len)//len初始值为0
{
    static int a[10];//定义静态数组a，保存每个叶子的编码，数组长度至少是树深度减一
    if (FBT != NULL)//访问到叶子结点时输出其保存在数组a中的0和1序列编码
    {
        if (FBT->left == NULL && FBT->right == NULL)
        {
            int i;
            printf("结点权值为%d的编码：", FBT->data);
            for (i = 0; i < len; i++)
                printf("%d", a[i]);
            printf("\n");
        }
        else//访问到非叶子结点时分别向左右子树递归调用，并把分支上的0、1编码保存到数组a
        {   //的对应元素中，向下深入一层时len值增1
            a[len] = 0;
            HuffManCoding(FBT->left, len + 1);
            a[len] = 1;
            HuffManCoding(FBT->right, len + 1);
        }
    }
}

//主函数
int main()
{
    int n, i;
    ElemType* a;
    struct BTreeNode* fbt;
    printf("从键盘输入待构造的哈夫曼树中带权叶子结点数n：");
    while(1)
    {
        scanf("%d", &n);
        if (n > 1)
            break;
        else
            printf("重输n值：");
    }
    a = (ElemType*)malloc(n*sizeof(ElemType));
    printf("从键盘输入%d个整数作为权值：", n);
    for (i = 0; i < n; i++)
        scanf(" %d", &a[i]);
    fbt = CreateHuffman(a, n);
    printf("广义表形式的哈夫曼树：");
    PrintBTree_int(fbt);
    printf("\n");
    printf("哈夫曼树的带权路径长度：");
    printf("%d\n", WeightPathLength(fbt, 0));
    printf("树中每个叶子结点的哈夫曼编码：\n");
    HuffManCoding(fbt, 0);
}
*/
/*
从键盘输入待构造的哈夫曼树中带权叶子结点数n：6
从键盘输入6个整数作为权值：3 9 5 12 6 15
广义表形式的哈夫曼树：50(21(9,12),29(14(6,8(3,5)),15))
哈夫曼树的带权路径长度：122
树中每个叶子结点的哈夫曼编码：
结点权值为9的编码：00
结点权值为12的编码：01
结点权值为6的编码：100
结点权值为3的编码：1010
结点权值为5的编码：1011
结点权值为15的编码：11

Process returned 0 (0x0)   execution time : 22.356 s
Press any key to continue.

*/


#include<iostream>
using namespace std;

typedef struct treenode{
    int data;
    treenode *lchild;
    treenode *rchild;
}node, *Tree;
int a[100];

node * create_huffman_tree(int n){
    node *b[100], *q;
    for(int i=0; i<n; i++){
        b[i] = new node;
        b[i]->data = a[i];
        b[i]->lchild = NULL;
        b[i]->rchild = NULL;
    }
    for(int i=0; i<n-1; i++){
        int k1 = -1, k2;  ///k1必须赋值 因为要控制循环的时候 若k1为初始化时的值 则跳过k1 直接对k2赋值


        for(int j=0; j<n; j++){

            if(b[j] && k1 == -1){
                k1 = j;
                continue;
            }
            if(b[j]){
                k2 = j;
                break;
            }
        }
        for(int j=k2; j<n; j++){
            if(b[j]){
                if(b[j]->data < b[k1]->data){
                    k2 = k1;
                    k1 = j;
                }
                else if(b[j]->data < b[k2]->data){
                    k2 = j;
                }
            }
        }
        q = new node;
        q->lchild = b[k1];
        q->rchild = b[k2];
        q->data = b[k1]->data + b[k2]->data;
        b[k1] = q;
        b[k2] = NULL;
    }
    return q;
}
void print_huffman_tree(node *t){
    if(t){
            cout << t->data;
        if(t->lchild || t->rchild){
            cout << "(";
            if(t->lchild){
                print_huffman_tree(t->lchild);
            }
            cout << ",";
            if(t->rchild){
                print_huffman_tree(t->rchild);
            }
            cout << ")";
        }
    }
}
int weight_path_length(node *t, int len)
{
    if(t)
    {
        if(t->lchild==NULL && t->rchild == NULL){
            ///cout << "*********************************" << endl;
            ///cout << len << endl;
            ///cout << t->data * len << endl;
            return t->data * len;
        }
        else{///++len为啥不行 不说别的 就从1那返回到上一层就不行
            return weight_path_length(t->lchild, len+1)+weight_path_length(t->rchild, len+1);
        }///因为len已经变了 所以递归的时候 要注意控制某些东西不变
    }///每返回到上一层一次 len就多加个1 终于明白了 呵呵呵呵哒
    return 0;
}
int huffman_code(node *t, int len){
    static int aa[100];
    if(t){
        if(t->lchild == NULL && t->rchild == NULL){
            for(int i=0; i<len; i++){
                cout << aa[i] ;
            }
            cout << endl;
        }

        if(t->lchild){
            aa[len] = 0;
            huffman_code(t->lchild, len+1);
        }
        if(t->rchild){
            aa[len] = 1;
            huffman_code(t->rchild, len+1);
        }
        /*else{
            aa[len] = 0;
            huffman_code(t->lchild, len+1);
            aa[len] = 1;
            huffman_code(t->rchild, len+1);
        }*/
    }
    ///return len;
}
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    cin >> a[i];
    node *tree;
    tree = create_huffman_tree(n);
    print_huffman_tree(tree);
    cout << endl;
    cout << weight_path_length(tree, 0) << endl;
   /* int len = */huffman_code(tree, 0);
    /*for(int i=0; i<len; i++){
        cout << aa[i] << endl;
    }*/

    return 0;
}
/*
4
4 2 1 3
*/
/*
len++ == len+1  /// hey hey hey 他俩哪能等价啊 又脑抽了
4
4 2 1 3
10(4,6(3(1,2),3))
*********************************
1-------->4
4
*********************************
3--------->1
3
*********************************
3--------->2
6
*********************************
2--------->3
6
19

Process returned 0 (0x0)   execution time : 10.204 s
Press any key to continue.

*/
/*
++len
4
4 2 1 3
10(4,6(3(1,2),3))
*********************************
1-------->4
4
*********************************
4--------->1
4
*********************************
5------->2
10
*********************************
4    -----> 3
12
30

Process returned 0 (0x0)   execution time : 7.864 s
Press any key to continue.

*/

/*
++len
4
4 2 1 3
10(4,6(3(1,2),3))
19
0
0100
01001
0101

Process returned 0 (0x0)   execution time : 5.017 s
Press any key to continue.

*/
