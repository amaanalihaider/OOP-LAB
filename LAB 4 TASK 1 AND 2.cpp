#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
  
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    Node* Reverse(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        Node* prev = nullptr;
        Node* curr = head;
        Node* forward = nullptr;
        while (curr != nullptr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
};

bool search(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == key) {
            return true;  // Key found
        }
        current = current->next;
    }
    return false;  // Key not found
}

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertInMiddle(Node* &head, int position, int data) {
    if (position == 1) {
        insertAtHead(head, data);
        return;
    }
    Node* temp = head;
    int count = 1;
    while (count < position - 1 && temp != nullptr) {
        temp = temp->next;
        count++;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds" << endl;
        return;
    }
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* findMid(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    Node* ans = new Node(0); // dummy node
    Node* temp = ans;

    while (left != nullptr && right != nullptr) {
        if (left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        } else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != nullptr) {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right != nullptr) {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;
}

Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = nullptr;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main() {
    Node* head = nullptr; // Initialize head pointer
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    print(head);
    
    insertInMiddle(head, 1, 0);
    print(head);

    Node* nodeinstance = new Node(0);
    head = nodeinstance->Reverse(head);
    cout<<"Reversed version"<<endl;
    print(head);

    int keyToSearch = 2;
    if (search(head, keyToSearch)) {
        cout << "Key " << keyToSearch << " found in the linked list." << endl;
    } else {
        cout << "Key " << keyToSearch << " not found in the linked list." << endl;
    }

    cout << endl;
    cout << "Now the Sorting and Merging part" << endl;

    Node* head2 = nullptr;
    insertAtHead(head2, 3);
    insertAtHead(head2, 7);
    insertAtHead(head2, 1);
    insertAtHead(head2, 2);
    insertAtHead(head2, 6);
    insertAtHead(head2, 4);
    insertAtHead(head2, 5);

    cout << "Original list: ";
    print(head2);

    head2 = mergeSort(head2);

    cout << "Sorted list: ";
    print(head2);

    return 0;
}
