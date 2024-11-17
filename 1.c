#include<stdio.h>
#include<stdlib.h>

// khai bao cau truc node
struct Node {
    int data;
    struct Node *next;
};

// ham tao node moi
struct Node* taoNode(int x) {
    struct Node *p;
    p = (struct Node*)malloc(sizeof(struct Node));
    p->data = x;
    p->next = NULL;
    return p;
}

// ham in danh sach
void inDS(struct Node *node) {
    struct Node *p = node;
    printf("\nDanh sach: ");
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

// ham xoa dau
struct Node* xoaDau(struct Node *node) {
    // kiem tra ds rong
    if(node == NULL) {
        printf("\nDanh sach rong!");
        return NULL;
    }
    struct Node *p = node;
    node = node->next;
    free(p);
    return node;
}

// ham xoa cuoi
struct Node* xoaCuoi(struct Node *node) {
    // kiem tra ds rong
    if(node == NULL) {
        printf("\nDanh sach rong!");
        return NULL;
    }
    
    // neu chi co 1 ptu
    if(node->next == NULL) {
        free(node);
        return NULL;
    }
    
    struct Node *p = node;
    // tim node cuoi
    while(p->next->next != NULL) {
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
    return node;
}

// ham xoa sau node q
struct Node* xoaSau(struct Node *node, int x) {
    // kiem tra ds rong
    if(node == NULL) {
        printf("\nDanh sach rong!");
        return NULL;
    }
    
    struct Node *p = node;
    // tim node co gia tri x
    while(p != NULL && p->data != x) {
        p = p->next;
    }
    
    if(p == NULL) {
        printf("\nKhong tim thay node can xoa!");
        return node;
    }
    
    if(p->next == NULL) {
        printf("\nKhong co node sau de xoa!");
        return node;
    }
    
    struct Node *q = p->next;
    p->next = q->next;
    free(q);
    return node;
}

int main() {
    struct Node *node = NULL;
    
    // tao ds mau: 1 2 3 4 5
    node = taoNode(1);
    node->next = taoNode(2);
    node->next->next = taoNode(3);
    node->next->next->next = taoNode(4);
    node->next->next->next->next = taoNode(5);
    
    printf("\nDanh sach ban dau:");
    inDS(node);
    
    printf("\n\nXoa dau:");// test xoa node dau
    node = xoaDau(node);
    inDS(node);
    
    printf("\n\nXoa cuoi:");// test xoa node cuoi
    node = xoaCuoi(node);
    inDS(node);
    
    printf("\n\nXoa sau node co gia tri 2:");// test xoa node sau
    node = xoaSau(node, 2);
    inDS(node);
    
    printf("\n");
    return 0;
}