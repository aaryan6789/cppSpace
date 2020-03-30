#include "_linked_list.h"

using namespace std;

int LinkedList::listLength() {
    int count = 0;
    node* current = this->head;

    while(current != NULL){
        count++;
        current = current->next;
    }

    cout << "List Length : " << count << endl;
    return count;
}

void LinkedList::printList() {
    node* current = this->head;

    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
    return;
}