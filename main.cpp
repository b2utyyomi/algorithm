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

//1�����������������ǰ������Ļ������޸ġ����ù�����ʽ��Ԫ������Ϊint
void PrintBTree_int(struct BTreeNode* BT)
{
    if (BT != NULL)
    {
        printf("%d", BT->data); //���������ֵ
        if (BT->left != NULL || BT->right != NULL)
        {
            printf("(");
            PrintBTree_int(BT->left); //���������
            if (BT->right != NULL)
                printf(",");
            PrintBTree_int(BT->right); //���������
            printf(")");
        }
    }
}

//2���������� a �� n ��Ȩֵ����һ�ù�����������������ָ��
struct BTreeNode* CreateHuffman(ElemType a[], int n)
{
    int i, j;
    struct BTreeNode **b, *q;
    b = (struct BTreeNode**)malloc(n*sizeof(struct BTreeNode));
    for (i = 0; i < n; i++) //��ʼ��bָ�����飬ʹÿ��ָ��Ԫ��ָ��a�����ж�Ӧ��Ԫ�ؽ��
    {
        b[i] = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
        b[i]->data = a[i];
        b[i]->left = b[i]->right = NULL;
    }
    for (i = 1; i < n; i++)//���� n-1 ��ѭ��������������
    {
        //k1��ʾɭ���о�����СȨֵ�����������±꣬k2Ϊ����С���±�
        int k1 = -1, k2;
        for (j = 0; j < n; j++)//��k1��ʼָ��ɭ���е�һ������k2ָ��ڶ���
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
        for (j = k2; j < n; j++)//�ӵ�ǰɭ���������СȨֵ���ʹ���С
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
        //����СȨֵ���ʹ���СȨֵ������һ��������qָ���������
        q = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
        ///q = new BTreeNode;
        q->data = b[k1]->data + b[k2]->data;
        q->left = b[k1];
        q->right = b[k2];

        b[k1] = q;//��ָ��������ָ�븳��bָ��������k1λ��
        b[k2] = NULL;//k2λ��Ϊ��
    }
    free(b); //ɾ����̬����������b
    ///delete []b;
    return q; //����������������������ָ��
}

//3������������Ĵ�Ȩ·������
ElemType WeightPathLength(struct BTreeNode* FBT, int len)//len��ʼΪ0
{
    if (FBT == NULL) //��������0
        return 0;
    else
    {
        if (FBT->left == NULL && FBT->right == NULL)//���ʵ�Ҷ�ӽ��
            return FBT->data * len;
        else //���ʵ���Ҷ�ӽ�㣬���еݹ���ã��������������Ĵ�Ȩ·������֮�ͣ�len����
            return WeightPathLength(FBT->left,len+1)+WeightPathLength(FBT->right,len+1);
    }
}

//4�����������루���Ը��ݹ���������Ȩ·�����ȵ��㷨�����Ͻ����޸ģ�
void HuffManCoding(struct BTreeNode* FBT, int len)//len��ʼֵΪ0
{
    static int a[10];//���徲̬����a������ÿ��Ҷ�ӵı��룬���鳤������������ȼ�һ
    if (FBT != NULL)//���ʵ�Ҷ�ӽ��ʱ����䱣��������a�е�0��1���б���
    {
        if (FBT->left == NULL && FBT->right == NULL)
        {
            int i;
            printf("���ȨֵΪ%d�ı��룺", FBT->data);
            for (i = 0; i < len; i++)
                printf("%d", a[i]);
            printf("\n");
        }
        else//���ʵ���Ҷ�ӽ��ʱ�ֱ������������ݹ���ã����ѷ�֧�ϵ�0��1���뱣�浽����a
        {   //�Ķ�ӦԪ���У���������һ��ʱlenֵ��1
            a[len] = 0;
            HuffManCoding(FBT->left, len + 1);
            a[len] = 1;
            HuffManCoding(FBT->right, len + 1);
        }
    }
}

//������
int main()
{
    int n, i;
    ElemType* a;
    struct BTreeNode* fbt;
    printf("�Ӽ������������Ĺ��������д�ȨҶ�ӽ����n��");
    while(1)
    {
        scanf("%d", &n);
        if (n > 1)
            break;
        else
            printf("����nֵ��");
    }
    a = (ElemType*)malloc(n*sizeof(ElemType));
    printf("�Ӽ�������%d��������ΪȨֵ��", n);
    for (i = 0; i < n; i++)
        scanf(" %d", &a[i]);
    fbt = CreateHuffman(a, n);
    printf("�������ʽ�Ĺ���������");
    PrintBTree_int(fbt);
    printf("\n");
    printf("���������Ĵ�Ȩ·�����ȣ�");
    printf("%d\n", WeightPathLength(fbt, 0));
    printf("����ÿ��Ҷ�ӽ��Ĺ��������룺\n");
    HuffManCoding(fbt, 0);
}
*/
/*
�Ӽ������������Ĺ��������д�ȨҶ�ӽ����n��6
�Ӽ�������6��������ΪȨֵ��3 9 5 12 6 15
�������ʽ�Ĺ���������50(21(9,12),29(14(6,8(3,5)),15))
���������Ĵ�Ȩ·�����ȣ�122
����ÿ��Ҷ�ӽ��Ĺ��������룺
���ȨֵΪ9�ı��룺00
���ȨֵΪ12�ı��룺01
���ȨֵΪ6�ı��룺100
���ȨֵΪ3�ı��룺1010
���ȨֵΪ5�ı��룺1011
���ȨֵΪ15�ı��룺11

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
        int k1 = -1, k2;  ///k1���븳ֵ ��ΪҪ����ѭ����ʱ�� ��k1Ϊ��ʼ��ʱ��ֵ ������k1 ֱ�Ӷ�k2��ֵ


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
        else{///++lenΪɶ���� ��˵��� �ʹ�1�Ƿ��ص���һ��Ͳ���
            return weight_path_length(t->lchild, len+1)+weight_path_length(t->rchild, len+1);
        }///��Ϊlen�Ѿ����� ���Եݹ��ʱ�� Ҫע�����ĳЩ��������
    }///ÿ���ص���һ��һ�� len�Ͷ�Ӹ�1 ���������� �ǺǺǺ���
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

//1�����������������ǰ������Ļ������޸ġ����ù�����ʽ��Ԫ������Ϊint
void PrintBTree_int(struct BTreeNode* BT)
{
    if (BT != NULL)
    {
        printf("%d", BT->data); //���������ֵ
        if (BT->left != NULL || BT->right != NULL)
        {
            printf("(");
            PrintBTree_int(BT->left); //���������
            if (BT->right != NULL)
                printf(",");
            PrintBTree_int(BT->right); //���������
            printf(")");
        }
    }
}

//2���������� a �� n ��Ȩֵ����һ�ù�����������������ָ��
struct BTreeNode* CreateHuffman(ElemType a[], int n)
{
    int i, j;
    struct BTreeNode **b, *q;
    b = (struct BTreeNode**)malloc(n*sizeof(struct BTreeNode));
    for (i = 0; i < n; i++) //��ʼ��bָ�����飬ʹÿ��ָ��Ԫ��ָ��a�����ж�Ӧ��Ԫ�ؽ��
    {
        b[i] = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
        b[i]->data = a[i];
        b[i]->left = b[i]->right = NULL;
    }
    for (i = 1; i < n; i++)//���� n-1 ��ѭ��������������
    {
        //k1��ʾɭ���о�����СȨֵ�����������±꣬k2Ϊ����С���±�
        int k1 = -1, k2;
        for (j = 0; j < n; j++)//��k1��ʼָ��ɭ���е�һ������k2ָ��ڶ���
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
        for (j = k2; j < n; j++)//�ӵ�ǰɭ���������СȨֵ���ʹ���С
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
        //����СȨֵ���ʹ���СȨֵ������һ��������qָ���������
        q = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
        ///q = new BTreeNode;
        q->data = b[k1]->data + b[k2]->data;
        q->left = b[k1];
        q->right = b[k2];

        b[k1] = q;//��ָ��������ָ�븳��bָ��������k1λ��
        b[k2] = NULL;//k2λ��Ϊ��
    }
    free(b); //ɾ����̬����������b
    ///delete []b;
    return q; //����������������������ָ��
}

//3������������Ĵ�Ȩ·������
ElemType WeightPathLength(struct BTreeNode* FBT, int len)//len��ʼΪ0
{
    if (FBT == NULL) //��������0
        return 0;
    else
    {
        if (FBT->left == NULL && FBT->right == NULL)//���ʵ�Ҷ�ӽ��
            return FBT->data * len;
        else //���ʵ���Ҷ�ӽ�㣬���еݹ���ã��������������Ĵ�Ȩ·������֮�ͣ�len����
            return WeightPathLength(FBT->left,len+1)+WeightPathLength(FBT->right,len+1);
    }
}

//4�����������루���Ը��ݹ���������Ȩ·�����ȵ��㷨�����Ͻ����޸ģ�
void HuffManCoding(struct BTreeNode* FBT, int len)//len��ʼֵΪ0
{
    static int a[10];//���徲̬����a������ÿ��Ҷ�ӵı��룬���鳤������������ȼ�һ
    if (FBT != NULL)//���ʵ�Ҷ�ӽ��ʱ����䱣��������a�е�0��1���б���
    {
        if (FBT->left == NULL && FBT->right == NULL)
        {
            int i;
            printf("���ȨֵΪ%d�ı��룺", FBT->data);
            for (i = 0; i < len; i++)
                printf("%d", a[i]);
            printf("\n");
        }
        else//���ʵ���Ҷ�ӽ��ʱ�ֱ������������ݹ���ã����ѷ�֧�ϵ�0��1���뱣�浽����a
        {   //�Ķ�ӦԪ���У���������һ��ʱlenֵ��1
            a[len] = 0;
            HuffManCoding(FBT->left, len + 1);
            a[len] = 1;
            HuffManCoding(FBT->right, len + 1);
        }
    }
}

//������
int main()
{
    int n, i;
    ElemType* a;
    struct BTreeNode* fbt;
    printf("�Ӽ������������Ĺ��������д�ȨҶ�ӽ����n��");
    while(1)
    {
        scanf("%d", &n);
        if (n > 1)
            break;
        else
            printf("����nֵ��");
    }
    a = (ElemType*)malloc(n*sizeof(ElemType));
    printf("�Ӽ�������%d��������ΪȨֵ��", n);
    for (i = 0; i < n; i++)
        scanf(" %d", &a[i]);
    fbt = CreateHuffman(a, n);
    printf("�������ʽ�Ĺ���������");
    PrintBTree_int(fbt);
    printf("\n");
    printf("���������Ĵ�Ȩ·�����ȣ�");
    printf("%d\n", WeightPathLength(fbt, 0));
    printf("����ÿ��Ҷ�ӽ��Ĺ��������룺\n");
    HuffManCoding(fbt, 0);
}
*/
/*
�Ӽ������������Ĺ��������д�ȨҶ�ӽ����n��6
�Ӽ�������6��������ΪȨֵ��3 9 5 12 6 15
�������ʽ�Ĺ���������50(21(9,12),29(14(6,8(3,5)),15))
���������Ĵ�Ȩ·�����ȣ�122
����ÿ��Ҷ�ӽ��Ĺ��������룺
���ȨֵΪ9�ı��룺00
���ȨֵΪ12�ı��룺01
���ȨֵΪ6�ı��룺100
���ȨֵΪ3�ı��룺1010
���ȨֵΪ5�ı��룺1011
���ȨֵΪ15�ı��룺11

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
        int k1 = -1, k2;  ///k1���븳ֵ ��ΪҪ����ѭ����ʱ�� ��k1Ϊ��ʼ��ʱ��ֵ ������k1 ֱ�Ӷ�k2��ֵ


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
        else{///++lenΪɶ���� ��˵��� �ʹ�1�Ƿ��ص���һ��Ͳ���
            return weight_path_length(t->lchild, len+1)+weight_path_length(t->rchild, len+1);
        }///��Ϊlen�Ѿ����� ���Եݹ��ʱ�� Ҫע�����ĳЩ��������
    }///ÿ���ص���һ��һ�� len�Ͷ�Ӹ�1 ���������� �ǺǺǺ���
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
len++ == len+1  /// hey hey hey �������ܵȼ۰� ���Գ���
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
