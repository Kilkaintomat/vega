x#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

template<typename T>
int findElement(const std::vector<T>& vec, const T& element) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == element) {
            return i;  // Возвращаем индекс найденного элемента
        }
    }
    return -1;  // Возвращаем -1, если элемент не найден
}




struct Node {
    float key;
    vector<int> id;
    vector<int> size;
    //map <int, int> data;
    int volum;
    Node* left;
    Node* right;

    Node(float value,  vector<int> values,int value2 , vector<int>  values2) {
        key = value;
        id = values;
        volum = value2;
        size = values2;
        left = nullptr;
        right = nullptr;
    }
};

// Функция для добавления нового узла в дерево
Node* insertNode(Node* root, float value, vector<int> values, int value2 , vector<int>  values2) {
    if (root == nullptr) {
        root = new Node(value, values, value2, values2);
    } else if (value < root->key) {
        root->left = insertNode(root->left, value, values, value2, values2);
    } else {
        root->right = insertNode(root->right, value, values, value2, values2);
    }
    return root;
}

// Функция для удаления узла из дерева
Node* deleteNode(Node* root, float value) {
    if (root == nullptr) {
        return root;
    } else if (value < root->key) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->key) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = root->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

// Функция для изменения значения узла
// void modifyNode(Node* root, int oldValue, int newValue, vector<int> newValues) {
//     if (root == nullptr) {
//         return;
//     } else if (oldValue < root->key) {
//         modifyNode(root->left, oldValue, newValue, newValues);
//     } else if (oldValue > root->key) {
//         modifyNode(root->right, oldValue, newValue, newValues);
//     } else {
//         root->key = newValue;
//         root->data = newValues;
//     }
// }

// Функция для поиска значения в дереве
Node* searchNode(Node* root, float value) {
    if (root == nullptr || root->key == value) {
        return root;
    }
    if (value < root->key) {
        return searchNode(root->left, value);
    }
    return searchNode(root->right, value);
}

// Функция для вывода содержимого дерева (инфиксный обход)
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << "Key: " << root->key << ", Data: ";
    for (int val : root->id) {
        cout << val << " ";
    }
    cout << endl;
    inorderTraversal(root->right);
}



Node* modifyMode(Node*root, float price ,int id2, int newsize = 0, string flag){
     Node* root1 = searchNode(root, price);

     if (flag == "delete"){
        int i = findElement(root1->id, id2);

        root1 -> volum-= root1->size[i]; 

        auto it  = (root1->size).begin() + i;
        (root1->size).erase(it);

        auto it  = (root1->id).begin() + i;
        (root1->id).erase(it);

        if (root1->volum <= 0 )
            return deleteNode(root, price);
        return root;    
}
    if(flag == "added"){
        if (root1 == nullptr){
            vector<int> v, w; v.push_back(id2), w.push_back(newsize);   
            return insertNode(root, price, v, newsize, w); }   
        root1 -> volum += newsize;
        root1 -> id.push_back(id2);
        root1 -> size.push_back(newsize);
        return root;
            }
    if(flag == "changed"){
        int none; 
    }

}
// Пример использования
int main() {
    Node* root_ask = nullptr;
    Node* root_bid = nullptr;

    // Добавление узлов
    root_ask = insertNode(root_ask, 5, {1, 2, 3}, 4,{1,2,3});
    

    
    return 0;
}
