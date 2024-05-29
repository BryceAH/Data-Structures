#include <iostream>
#include <ctime>


using namespace std;


struct BinaryNode{      
    int value;
    int count = 0; // this will go up if there is duplicates of the same value
    BinaryNode *left;
    BinaryNode *right;
};

class Tree{
private:
    BinaryNode *root;

public:

    Tree(){
        root = nullptr;
        srand(time(0)); // used for random number generation 


    }

    void add(string str_value){
        int value = stoi(str_value);
        bool sorted = false;
        BinaryNode *temp = root;
        if (root == nullptr){  // root, if the tree is empty root == nullpointer then the value is placed in the root
            root = new BinaryNode;
            root -> value = value;
            root -> left = nullptr;
            root -> right = nullptr;
            root -> count += 1;
            return;
        }
        while(sorted == false){
            if (value < temp -> value){ // left side of tree, if the left of the parent is empty the it sets the value to the node and generates a left and a right null pointer
                if (temp -> left == nullptr){
                    temp -> left = new BinaryNode;
                    temp -> left -> value = value;
                    temp -> left -> left = nullptr;
                    temp -> left -> right = nullptr;
                    sorted = true;
                }
                temp = temp -> left;
            }

            if (value > temp -> value){ // right side of tree, exact same as left side but flipped
                if (temp -> right == nullptr){
                    temp -> right = new BinaryNode;
                    temp -> right -> value = value;
                    temp -> right -> right = nullptr;
                    temp -> right -> left = nullptr;
                    sorted = true;
                }
                temp = temp -> right;
            }

            if (value == temp -> value){ // increses count if muliple of the same values are added
                temp -> count += 1;
                sorted = true;
            }

        }
    }
    //https://www.youtube.com/watch?v=b_NjndniOqY video i watched to get this idea 
    void display(BinaryNode *BinaryNode) {
        if (BinaryNode != nullptr) {
            display(BinaryNode->left); // steps as far left as it can, starting at the root

            cout << "Value: " << BinaryNode->value << " "
                << "Count: " << BinaryNode->count << " ";
            
            if (BinaryNode->left != nullptr) { // prints the left value if it is not null
                cout << "L: " << BinaryNode->left->value << " ";
            } else {
                cout << "L: null ";
            }
            
            if (BinaryNode->right != nullptr) { // prints the right value if it is not null
                cout << "R: " << BinaryNode->right->value << endl;
            } else {
                cout << "R: null " << endl;
            }

            display(BinaryNode->right); // then steps to the right one 
        }
    }


    BinaryNode* check(BinaryNode *node, int value) { //used with the remove function to check if the value is in the tree
        if (node == nullptr) { // If the node is null, the value is not found in this subtree
            return nullptr;
        }
        if (node -> value == value) { // If the current node's value matches the search value, return the node
            
            return node;
            
        } else if (value < node -> value) { // If the search value is less than the current node's value, search the left subtree
            
            return check(node -> left, value);
            
        } else { // If the search value is greater than the current node's value, search the right subtree
            return check(node -> right, value);
        }
    }

    BinaryNode* parent(BinaryNode* node) {
        if (root == nullptr || root == node) {
            cout << "No parent found for node with value: " << node->value << endl;
            return nullptr;
        }

        BinaryNode* temp = root;
        BinaryNode* parentNode = nullptr;

        while (temp != nullptr) {
            if ((temp->left == node || temp->right == node) && temp->value != node->value) {
                parentNode = temp;
                //cout << "Parent found for node with value: " << node->value << ". Parent value: " << parentNode->value << endl;
                break;
            }
            if (node->value < temp->value) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }

        if (parentNode == nullptr) {
            cout << "No parent found for node with value: " << node->value << endl;
        }

        return parentNode;
    }



    void remove_node(int value, Hash& H){
        cout << endl;
        cout << "Hash being deleted: "<< value << " Word: " << H.hash_to_string(to_string(value)) << endl << endl;

        bool exist = false;
        BinaryNode *node_deleted = check(getRoot(),value);

        if (node_deleted != nullptr){
            BinaryNode* parentNode = parent(node_deleted); //find parent node
            if (parentNode != nullptr) {
                if (node_deleted->left == nullptr & node_deleted->right == nullptr) //this node is a leaf
                {
                    if (parentNode->left == node_deleted)
                    {
                        parentNode->left = nullptr;
                        //cout << "Deleting child of: " << parentNode->value << endl;
                        delete node_deleted;
                    }
                    else if (parentNode->right == node_deleted)
                    {
                        parentNode->right = nullptr;
                        //cout << "Deleting child of: " << parentNode->value << endl;
                        delete node_deleted;
                    }
                    
                }
                else if (node_deleted->left==nullptr or node_deleted->right==nullptr) // has only one child
                {
                    if (parentNode->right->value == node_deleted->value)
                    {
                        if (node_deleted->right != nullptr)
                        {
                            parentNode->right = node_deleted->right;
                            delete node_deleted;
                        }
                        else if (node_deleted->left != nullptr)
                        {
                            parentNode->right = node_deleted->left;
                            delete node_deleted;   
                        }
                    }
                    
                    

                        }   
        else // this node has two children
        {
            ////////////////////////////////////
            BinaryNode *succsessor = parentNode;
            BinaryNode *succsessorParent = nullptr; // Add a pointer to keep track of the parent of the successor
            bool sub_found = false;
            if (parentNode->right->value == node_deleted->value) // figure out if value being deleted is on the right or left side of the node
            {
                succsessor = parentNode->right; // node that is going to be replaced
                succsessorParent = succsessor; // Initialize the successor parent
                succsessor = succsessor->right; // steps right once

                while (sub_found != true)
                {
                    if (succsessor->left == nullptr) // then steps as far left as it can till it finds the smallest value
                    {
                        //cout << "node being subbed: " << succsessor->value << endl;
                        sub_found = true;
                        break;
                    }
                    else
                    {
                        succsessorParent = succsessor; // Update the successor parent before moving left
                        succsessor = succsessor->left;
                    }
                }

                parentNode->right->value = succsessor->value;

                if (succsessorParent->left == succsessor) // handle deletion of the successor node
                {
                    succsessorParent->left = succsessor->right;
                }
                else if (succsessorParent->right == succsessor)
                {
                    succsessorParent->right = succsessor->right;
                }

                delete succsessor;
            } 
            if (parentNode != nullptr && parentNode->left != nullptr && parentNode->left->value == node_deleted->value) // figure out if value being deleted is on the left side of the node
            {
                succsessor = parentNode->left; // node that is going to be replaced
                succsessorParent = succsessor; // Initialize the successor parent
                succsessor = succsessor->right; // steps right once

                while (!sub_found)
                {
                    if (succsessor->left == nullptr) // then steps as far left as it can till it finds the smallest value
                    {
                        sub_found = true;
                        break;
                    }
                    else
                    {
                        succsessorParent = succsessor; // Update the successor parent before moving left
                        succsessor = succsessor->left;
                    }
                }

                parentNode->left->value = succsessor->value;

                if (succsessorParent->left == succsessor) // handle deletion of the successor node
                {
                    succsessorParent->left = succsessor->right;
                }
                else if (succsessorParent->right == succsessor)
                {
                    succsessorParent->right = succsessor->right;
                }

                delete succsessor;
            }


        }

                    }
                    
                }
                else{
                cout << "\n"<<"================"<< "\n"<<"does not exsist"<<"\n"<<"================"<<"\n\n";

                }
                

            }


    BinaryNode* getRoot(){ //  used to give the display function the root
    return root;
}  

    int random(){
            int max = 10;
            int random_number = rand() % max;
            return random_number;

    }
};
