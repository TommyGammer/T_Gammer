#include <iostream>
using namespace std;

struct node {
    string name;
    int id;
    node *next;
};

bool listCreated = false;
node *head = NULL;

/* Creates a start pointer that points to null and sets the listCreated variable to true */

void createList() {
    head = NULL;
    listCreated = true;
}

/* Creates a new node and adds it to the end of the list */
  
void addNodeAtEnd(int id) {
    node *temp, *temp2;
    temp = new node;
    cout << "Please enter the name of the person: ";
    cin >> temp->name;
    temp->id = id;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
      temp2 = head;
      while (temp2->next != NULL) {
          temp2 = temp2->next;
      }
      temp2->next = temp;
    }   
}

/* Creates a new node and adds it to the start of the list */

void addNodeAtBeginning(int id) {
    node *temp, *temp2;
    temp = new node;
    cout << "Please enter the name of the person: ";
    cin >> temp->name;
    temp->id = id;
  
    temp2 = head;
    head = temp;
    head->next = temp2;
}

/* Creates a new node and adds it to the middle of the list */

void addNodeInMiddle(int id) {
    node *temp, *temp2, *prev;
    temp = new node;
    cout << "Please enter the name of the person: ";
    cin >> temp->name;
    temp->id = id;
    temp2 = head;
    prev = NULL;
  
    while (temp2->id < temp->id) {
        prev = temp2;
        temp2 = temp2->next;
    }
    prev->next = temp;
    temp->next = temp2;
}

/* Combines the three add node functions and checks which one to use based on the id user input */

void addNode() {
    int id;
    cout << "Please enter the ID of the person: ";
    cin >> id;

    node *temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Node with ID " << id << " already exists. Please enter a different ID." << endl;
            return;
        }
        temp = temp->next;
    }

    node *curr = head;
    if (head == nullptr) {
        addNodeAtBeginning(id);
        return;
    }
    if (curr->id > id) {
        addNodeAtBeginning(id);
        return;
    }
    while (curr->next != nullptr) {
        if (curr->id < id && curr->next->id > id) {
            addNodeInMiddle(id);
            return;
        }
        curr = curr->next;
    }
    if (curr->next == nullptr && curr->id < id) {
        addNodeAtEnd(id);
    }
}

/* Deletes a node from the list based on the id user input */

void deleteNode(int id) {
    if (head->id == id) {
        node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    node *prev = head;
    node *curr = head->next;

    while (curr != NULL && curr->id != id) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Node with ID " << id << " not found." << endl;
        return;
    }

    prev->next = curr->next;
    delete curr;
}

/* Prints the list in ascending order */

void displayList() {
    node *temp = head;
    while (temp != NULL) {
        cout << "Name: " << temp->name << ", ID: " << temp->id << endl;
        temp = temp->next;
    }
}

/* Modifies a single node in the list based on the id user input */

void modifyNode(int id, string newName) {
    node *temp = head;
    while (temp != NULL && temp->id != id) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Node with ID " << id << " not found." << endl;
        return;
    }
    temp->name = newName;
}

/* Purges the entire linked list */

void purgeList() {
    node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
  cout << "List purged." << endl;
}

/* Searches for a node in the list based on the id user input and displays the contents */

void searchForNode(int id) {
    node *temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Node found: Name:  " << temp->name << ", ID:  " << temp->id << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Node with ID " << id << " not found." << endl;
}

/* Displays the menu and prompts the user to select an option */

int main() {
    int selection = 0;
    bool quit = false;

    do {
        cout << "\n========= Main Menu =========\n" << endl;
        cout << "\t1. Create Linked List\n" << endl;
        cout << "\t2. Add Node\n" << endl;
        cout << "\t3. Delete Node\n" << endl;
        cout << "\t4. Display Linked List\n" << endl;
        cout << "\t5. Modify Node\n" << endl;
        cout << "\t6. Purge Entire List\n" << endl;
        cout << "\t7. Search for Node\n" << endl;
        cout << "\t8. Quit\n" << endl;
        cout << "=============================\n" << endl;
        cout << "Please enter your selection: ";
        cin >> selection;

        switch (selection) {
            case 1:
                createList();
                break;
            case 2: {
                if (listCreated == false){
                    cout << "List not created. Please create a list first." << endl;
                    break;
                }
                addNode();
                break;
            }
            case 3: {
                if (listCreated == false){
                    cout << "List not created. Please create a list first." << endl;
                    break;
                }  else if (head == NULL) {
                    cout << "List is empty." << endl;
                    break;
                }
                int id;
                cout << "Enter ID to delete: ";
                cin >> id;
                deleteNode(id);
                break;
            }
            case 4:
              if (listCreated == false){
                  cout << "List not created. Please create a list first." << endl;
                  break;
              }  else if (head == NULL) {
                  cout << "List is empty." << endl;
                  break;
              }
                displayList();
                break;
            case 5: {
              if (listCreated == false){
                  cout << "List not created. Please create a list first." << endl;
                  break;
              }  else if (head == NULL) {
                  cout << "List is empty." << endl;
                  break;
              }
                int id;
                string newName;
                cout << "Enter ID of node to modify: ";
                cin >> id;
                cout << "Enter new name: ";
                cin >> newName;
                modifyNode(id, newName);
                break;
            }
            case 6:
              if (listCreated == false){
                  cout << "List not created. Please create a list first." << endl;
                  break;
              }  else if (head == NULL) {
                  cout << "List is empty." << endl;
                  break;
              }
                purgeList();
                break;
            case 7: {
              if (listCreated == false){
                  cout << "List not created. Please create a list first." << endl;
                  break;
              }  else if (head == NULL) {
                  cout << "List is empty." << endl;
                  break;
              }
                int id;
                cout << "Enter ID to search: ";
                cin >> id;
                searchForNode(id);
                break;
            }
            case 8:
                cout << "\nGoodbye!" << endl;
                quit = true;
                break;
            default:
                cout << "Error: Invalid selection. Please try again." << endl;
        }
    } while (!quit);

    return 0;
}
