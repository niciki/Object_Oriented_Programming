#include "TNaryTree.h"
#include <string>
#include <stdexcept>

TNaryTree::TNaryTree(int n) {
    max_number = n;
    curr_number = 0;
    root = nullptr;
};

bool TNaryTree::Empty(){
    return curr_number ? 0 : 1;
}

void TNaryTree::Update(Rectangle &&polygon, std::string &&tree_path){
    if(tree_path != "" && curr_number == 0){
        throw std::invalid_argument("Error, there is not a root value\n");
        return;
    } else if(tree_path == "" && curr_number == 0){
        Item* q = new Item(polygon);
        root = q; 
        curr_number++;
    } else if(curr_number + 1 > max_number){
        throw std::out_of_range("Current number of elements equals maximal number of elements in tree\n");
        return;
    } else {
        Item* tmp = root;
        for(int i = 0; i < tree_path.length() - 1; i++){
            if(tree_path[i] == 'b'){
                if(tmp->bro == nullptr){
                    throw std::invalid_argument("Path does not exist\n");
                    return;
                }
                tmp = tmp->bro;
            } else if(tree_path[i] == 'c'){
                if(tmp->son == nullptr){
                    throw std::invalid_argument("Path does not exist\n");
                    return;
                }
                tmp = tmp->son;
            } else {
                throw std::invalid_argument("Error in path\n");
                return;
            }
        }
        Item* item = new Item(polygon);
        if(tree_path.back() == 'b'){
            tmp->bro = item;
            this->curr_number++;
        } else if(tree_path.back() == 'c'){
            tmp->son = item;
            this->curr_number++;
        } else {
            throw std::invalid_argument("Error in path\n");
            return;
        }
    }
}

Item* copy(Item* root){
    if(!root){
        return nullptr;
    }
    Item *root_copy = new Item(root);
    root_copy->bro = copy(root->bro);
    root_copy->son = copy(root->son);
    return root_copy; 
}

TNaryTree::TNaryTree(const TNaryTree& other){
    curr_number = 0;
    max_number = other.max_number;
    root = copy(other.root);
    curr_number = other.curr_number;
;}

int TNaryTree::size(){
    return curr_number;
}

int clear(Item* node) {
    if (!node) {
        return 0;
    }
    int temp_res = clear(node->bro) + clear(node->son) + 1;
    delete node;
    return temp_res;
}

void TNaryTree::Clear(std::string &&tree_path){
    Item* prev_tmp = nullptr;
    Item* tmp = root;
    if (tree_path.empty()) {
        clear(root);
        curr_number = 0;
        root = nullptr;
        return;
    }
    for(int i = 0; i < tree_path.length(); i++){
        if(tree_path[i] == 'b'){
            if(tmp->bro == nullptr){
                throw std::invalid_argument("Path does not exist\n");
                return;
            }
            prev_tmp = tmp;
            tmp = tmp->bro;
        } else if(tree_path[i] == 'c'){
            if(tmp->son == nullptr){
                throw std::invalid_argument("Path does not exist\n");
                return;
            }
            prev_tmp = tmp;
            tmp = tmp->son;
        } else {
            throw std::invalid_argument("Error in path\n");
            return;
        }
    }
    if (tmp == prev_tmp->son) {
        prev_tmp->son = nullptr;
    } else {
        prev_tmp->bro = nullptr;
    }
    curr_number -= clear(tmp);
}

double area(Item* node){
    if(!node){
        return 0;
    }
    return node->Area() + area(node->bro) + area(node->son);
}

double TNaryTree::Area(std::string &&tree_path){
    Item* tmp = root;
    for(int i = 0; i < tree_path.length(); i++){
        if(tree_path[i] == 'b'){
            if(tmp->bro == nullptr){
                throw std::invalid_argument("Path does not exist\n");
                return -1;
            }
            tmp = tmp->bro;
        } else if(tree_path[i] == 'c'){
            if(tmp->son == nullptr){
                throw std::invalid_argument("Path does not exist\n");
                return -1;
            }
            tmp = tmp->son;
        } else {
            throw std::invalid_argument("Error in path\n");
            return -1;
        }
    }
    return area(tmp);
}

// Вывод дерева в формате вложенных списков, где каждый вложенный список является:
// "S0: [S1: [S3, S4: [S5, S6]], S2]", где Si - площадь фигуры

void print(std::ostream& os, Item* node){
    if(!node){
        return;
    }
    if(node->son){
        //os <<  <<node->pentagon.GetArea() <<  : ]" << 
        os << node->Area() << ": [";
        print(os, node->son);
        if(node->bro){
            if(node->bro){
                os << ", ";
                print(os, node->bro);
            }
        }
        os << "]";
    } else if (node->bro) {
       os << node->Area() << ": [";
        print(os, node->bro);
        if(node->son){
            if(node->son){
                os << ", ";
                print(os, node->son);
            }
        }
        os << "]";
    }
    else {
        os << node->Area();
    }
}

std::ostream& operator<<(std::ostream& os, const TNaryTree& tree){
    print(os, tree.root);
    os << "\n";
}

TNaryTree::~TNaryTree(){
    this->Clear();
};
