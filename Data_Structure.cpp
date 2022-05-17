#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};    
    
    static void printLinkedList(SinglyLinkedListNode head) {
        var node = head;
        while(node != null){
            Console.WriteLine(node.data);
            node = node.next;
        }
    }

    static SinglyLinkedListNode insertNodeAtTail(SinglyLinkedListNode head, int data) {
        if(head == null){
            head = new SinglyLinkedListNode(data);
        }else{
            SinglyLinkedListNode node = head;
            while(node.next != null){
                node = node.next;
            }
            node.next = new SinglyLinkedListNode(data);
        }
        return head;
    }

    SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
        // newNode->data = data;
        // newNode->next = NULL;
        
        if(llist == NULL){
            llist = newNode;
        }else{
            newNode->next = llist;
            llist = newNode;
        }
        return llist;
    }

    SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
        SinglyLinkedListNode* temp = llist;
        int number = 0;
        
        while(temp != NULL && number < position - 1){
            temp = temp->next;
            number++;
        }
        
        SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
        return llist;
    }

    SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* llist, int position) {
        if (llist == NULL){
            return NULL;
        }
        if(position == 0){
            llist = llist->next;        
            return llist;
        }
        SinglyLinkedListNode* aux = llist;
        for (int i = 0; i < position - 1; i++) {
            aux = aux->next;
        }
        aux->next = aux->next->next;
        return llist;
    }

    void reversePrint(SinglyLinkedListNode* llist) {
        if(llist->next == NULL){
            cout << llist->data << endl;
        }else{
            reversePrint(llist->next);
            cout << llist->data << endl;
        }
    }

    SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
        if(llist == NULL){
            return llist;
        }else{
            SinglyLinkedListNode* prev = llist;
            SinglyLinkedListNode* aux = llist->next;
            llist->next = NULL;
            
            while(aux){
                SinglyLinkedListNode* newNode = aux->next;
                aux->next = prev;
                prev = aux;
                aux = newNode;
            }
            
            return prev;
        }
    }

    bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
        SinglyLinkedListNode* aux1 = head1;
        SinglyLinkedListNode* aux2 = head2;
            
        while(aux1->next != NULL && aux2->next != NULL){
            if(aux1->data != aux2->data){
                return false;
            }
            aux1 = aux1->next;
            aux2 = aux2->next;
        }
        
        if(aux1->next != NULL && aux2->next != NULL){
            return false;
        }
        
        return true;
    }

    int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
        SinglyLinkedListNode* fast = llist;
        SinglyLinkedListNode* slow = llist;
            
        int pos = 0;
        while (pos < positionFromTail) {
            fast = fast->next;
            pos++;
        }
        while (fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow->data;
    }

    SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
        SinglyLinkedListNode* aux = llist;
        if(aux == NULL){
            return llist;
        }
        while(aux->next != NULL){
            if(aux->data == aux->next->data){
                aux->next = aux->next->next;
            }else{
                aux = aux->next;
            }
        }
        return llist;
    }

    bool has_cycle(SinglyLinkedListNode* head) {
        int count = 1000;
        while(count) {
            if (!(head)) return false;
            head = head->next;
            count--;
        }
        return true;
    }

   
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *tempB; 
    while(head1 != NULL){ 
        tempB = head2; 
        while(tempB!=NULL){ 
            if(tempB == head1){ 
                return tempB->data; 
            } 
            tempB = tempB->next; 
        } 
        head1 = head1->next; 
    } 
    
    return head1->data;
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *p = head1;
    SinglyLinkedListNode *q = head2;
    SinglyLinkedListNode *r = head1;
    
    if(head1==NULL)
    {
        return head2;
    }
    else if(head2==NULL)
    {
        return head1;
    }

    if (head1->data <= head2->data)  
    {  
        r = head1;  
        r->next = mergeLists(head1->next, head2);  
    }  
    else
    {  
        r = head2;  
        r->next = mergeLists(head1, head2->next);  
    }  
    return r;
}

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* nuevo = new DoublyLinkedListNode(data);
    nuevo->data = data;
    nuevo->next = nuevo->prev = NULL;
    
    if(llist == NULL){
        return nuevo;
    }else{
        
        if(llist->data > data){
            nuevo->next = llist;
            llist->prev = nuevo;
            return nuevo;
        }
        
        DoublyLinkedListNode* aux = llist;
        while(aux->next != NULL && aux->next->data < data){
            aux = aux->next;
        }
        
        if(aux->next == NULL){
            aux->next = nuevo;
            nuevo->prev = aux;
            return llist;
        }
        
        nuevo->next = aux->next;
        aux->next->prev = nuevo;
        nuevo->prev = aux;
        aux->next = nuevo;
        return llist;
    }
}