//  main.cpp
//  DSA_2
//  Created by Aiman Moufid on 9/16/25.
#include <iostream>
using namespace std;
struct Commit
{
    int hash;
    string message;
    Commit* next;
    Commit(int h, const std::string& msg) : hash(h), message(msg),
    next(nullptr) {}
};

class CommitHistory
{
    private:
        Commit* head;
    public:
        CommitHistory() : head(nullptr) {}
        void commit(const std::string& message); // append
        void log() const;// display all
        void reset(); // Delete last commit
        static CommitHistory merge(const CommitHistory& branch1, const CommitHistory& branch2);
        ~CommitHistory();
};


void CommitHistory::commit(const std::string& message)
{
    int hash = rand() % 10000; // Simulated hash
    Commit* newnodes = new Commit(hash, message);
    if (head == nullptr)
    {
        head = newnodes;
    }
    else
    {
        Commit* temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newnodes;
    }
}

void CommitHistory::log() const {
//display all commits with the arrow between them: commit1 <-commit2<-
    Commit* temp = head;
    cout << endl;
    while(temp != nullptr)
    {
        cout << temp->message << " <-- ";
        temp = temp->next;
    }
    cout << endl;
}

void CommitHistory::reset() {
    // delete the last node, release memory. Display message: Last commit removed (reset).
    Commit* temp = head;
    while(temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    cout << endl << "Last Commit Removed: " << temp->next->message << endl;
    delete temp->next;
    temp->next = nullptr;
}

CommitHistory CommitHistory::merge(const CommitHistory& branch1, const
CommitHistory& branch2) {
/*Create a new linked list that will have a first branch followed by branch 2.
Create all new nodes so that original branch 1 and branch 2 are not
touched.
Display a message "Branches merged.” when done!
Return new branch (linked list)*/
    CommitHistory mergedlists;
    mergedlists.head = nullptr;
    Commit* current = branch1.head;
    while (current != nullptr)
    {
        mergedlists.commit(current->message);
        current = current->next;
    }
    current = branch2.head;
    while (current != nullptr)
    {
        mergedlists.commit(current->message);
        current = current->next;
    }
    cout << endl << "Branches Merged" << endl;
    return mergedlists;
}

CommitHistory::~CommitHistory() {
//Release all memory
    Commit* current = head;
        while (current != nullptr)
        {
            Commit* nextnode = current->next;
            delete current;
            current = nextnode;
        }
}


int main()
{
    srand(time(0)); // For random hash generation
    CommitHistory master;
    master.commit("Initial commit");
    master.commit("Add README");
    master.commit("Implement login system");
    CommitHistory featureBranch;
    featureBranch.commit("Start feature X");
    featureBranch.commit("Fix bug in feature X");
    cout << "\n== Master Branch ==";
    master.log();
    cout << "\n== Feature Branch ==";
    featureBranch.log();
    cout << "\n== Reset last commit on master ==";
    master.reset();
    master.log();
    cout << "\n== Merged History ==";
    CommitHistory merged = CommitHistory::merge(master, featureBranch);
    merged.reset();
    merged.log();
    cout << "\n== Master Branch Unchanged after merge==";
    master.log();
    cout << "\n== Feature Branch Unchanged after merge==";
    featureBranch.log();
    return 0;
    
}
