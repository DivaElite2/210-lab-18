//Lateefah Camacho
//210-lab-18
//vscode


#include <iostream>
#include <string>
using namespace std;

// struct for the linked list
struct ReviewNode{
    double rating ;
    string comment;
    ReviewNode* next;

};

int main()
{
    ReviewNode* head = nullptr;
    ReviewNode* tail = nullptr;
    int methodChoice;
    char continueChoice;
    int reviewCount = 0;
    double totalRating = 0.0;

    //Get the insertion from user
cout << "Which linked list method should we use?" << endl;
    cout << "    [1] New nodes are added at the head of the linked list" << endl;
    cout << "    [2] New nodes are added at the tail of the linked list" << endl;
    cout << "    Choice: ";
    cin >> methodChoice;
    cin.ignore();

    // start input loop
       char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        // Get review data
        double rating;
        cout << "Enter review rating 0-5: ";
        cin >> rating;
        cin.ignore();
        
        string comment;
        cout << "Enter review comments: ";
        getline(cin, comment);
        
        // Create new node
        ReviewNode* newNode = new ReviewNode{rating, comment, nullptr};
        
        // Add to list
        if (head == nullptr) { // First node
            head = tail = newNode;
        } else if (methodChoice == 1) { // Add at head
            newNode->next = head;
            head = newNode;
        } else { // Add at tail
            tail->next = newNode;
            tail = newNode;
        }
        
        reviewCount++;
        totalRating += rating;
        
        // Continue Y/ N
        cout << "Enter another review? Y/N: ";
        cin >> choice;
        cin.ignore();
    }
   // Display reviews
    cout << "Outputting all reviews:\n";
    ReviewNode* current = head;
    for (int i = 1; current != nullptr; i++) {
        cout << "    > Review #" << i << ": " << current->rating 
             << ": " << current->comment << endl;
        current = current->next;
    }

// Show average
    if (reviewCount > 0) {
        cout << "    > Average: " << (totalRating / reviewCount) << endl;
    }


    return 0;
}


