#include "TNaryTree.h"
#include "TNaryTree_item.h"
#include <string>
#include <memory>
#include <stdexcept>

template <typename T>
TNaryTree<T>::TNaryTree(int n) {
    max_number = n;
    curr_number = 0;
    root = nullptr;
};

template <typename T>
bool TNaryTree<T>::Empty(){
    return curr_number ? 0 : 1;
}

template <typename T>
void TNaryTree<T>::Update(T &&polygon, std::string &&tree_path){
    if(tree_path != "" && curr_number == 0){
        throw std::invalid_argument("Error, there is not a root value\n");
        return;
    } else if(tree_path == "" && curr_number == 0){
        std::shared_ptr<Item<T>> q(new Item<T>(polygon));
        root = q; 
        curr_number++;
    } else if(curr_number + 1 > max_number){
        throw std::out_of_range("Current number of elements equals maximal number of elements in tree\n");
        return;
    } else {
        std::shared_ptr<Item<T>> tmp = root;
        for(int i = 0; i < tree_path.length() - 1; i++){
            if(tree_path[i] == 'b'){
                std::shared_ptr<Item<T>> q((*tmp).Get_bro());
                if(q == nullptr){
                    throw std::invalid_argument("Path does not exist\n");
                    return;
                }
                tmp = q;
            } else if(tree_path[i] == 'c'){
                std::shared_ptr<Item<T>> q = (*tmp).Get_son();
                if(q == nullptr){
                    throw std::invalid_argument("Path does not exist\n");
                    return;
                }
                tmp = q;
            } else {
                throw std::invalid_argument("Error in path\n");
                return;
            }
        }
        std::shared_ptr<Item<T>> item(new Item<T>(polygon));
        if(tree_path.back() == 'b'){
            /*std::shared_ptr<Item> p = (*tmp).Get_bro();
            p = item;*/
            (*tmp).Set_bro(item);
            curr_number++;
        } else if(tree_path.back() == 'c'){
            /*std::shared_ptr<Item> p = (*tmp).Get_son();
            p = item;*/
            (*tmp).Set_son(item);
            curr_number++;
        } else {
            throw std::invalid_argument("Error in path\n");
            return;
        }
    }
}

template <typename T>
std::shared_ptr<Item<T>> copy(std::shared_ptr<Item<T>> root){
    if(!root){
        return nullptr;
    }
    std::shared_ptr<Item<T>> root_copy(new Item<T>(root));
    (*root_copy).Set_bro(copy((*root).Get_bro()));
    (*root_copy).Set_son(copy((*root).Get_son()));
    return root_copy; 
}

template <typename T>
TNaryTree<T>::TNaryTree(const TNaryTree<T>& other){
    curr_number = 0;
    max_number = other.max_number;
    root = copy(other.root);
    curr_number = other.curr_number;
;}

template <typename T>
int TNaryTree<T>::size(){
    return curr_number;
}

template <typename T>
int clear(std::shared_ptr<Item<T>> node) {
    if (!node) {
        return 0;
    }
    int temp_res = clear((*node).Get_bro()) + clear((*node).Get_son()) + 1;
    return temp_res;
}

template <typename T>
void TNaryTree<T>::Clear(std::string &&tree_path){
    std::shared_ptr<Item<T>> prev_tmp = nullptr;
    std::shared_ptr<Item<T>> tmp;
    tmp = root;
    if (tree_path.empty()) {
        clear(root);
        curr_number = 0;
        root = nullptr;
        return;
    }
    for(int i = 0; i < tree_path.length(); i++){
        if(tree_path[i] == 'b'){
            std::shared_ptr<Item<T>> q((*tmp).Get_bro());
            if(q == nullptr){
                throw std::invalid_argument("Path does not exist\n");
                return;
            }
            prev_tmp = tmp;
            tmp = q;
        } else if(tree_path[i] == 'c'){
            std::shared_ptr<Item<T>> q((*tmp).Get_son());
            if(q == nullptr){
                throw std::invalid_argument("Path does not exist\n");
                return;
            }
            prev_tmp = tmp;
            tmp = q;
        } else {
            throw std::invalid_argument("Error in path\n");
            return;
        }
    }
    if (tmp == (*prev_tmp).Get_son()) {
        (*prev_tmp).Set_son(nullptr);
    } else {
        (*prev_tmp).Set_bro(nullptr);
    }
    curr_number -= clear(tmp);
}

template <typename T>
double area(std::shared_ptr<Item<T>> node){
    if(!node){
        return 0;
    }
    return node->Area() + area((*node).Get_bro()) + area((*node).Get_son());
}

template <typename T>
double TNaryTree<T>::Area(std::string &&tree_path){
    std::shared_ptr<Item<T>> tmp;
    tmp = root;
    for(int i = 0; i < tree_path.length(); i++){
        if(tree_path[i] == 'b'){
            std::shared_ptr<Item<T>> q((*tmp).Get_bro());
            if(q == nullptr){
                throw std::invalid_argument("Path does not exist\n");
                return -1;
            }
            tmp = q;
        } else if(tree_path[i] == 'c'){
            std::shared_ptr<Item<T>> q((*tmp).Get_son());
            if(q == nullptr){
                throw std::invalid_argument("Path does not exist\n");
                return -1;
            }
            tmp = q;
        } else {
            throw std::invalid_argument("Error in path\n");
            return -1;
        }
    }
    return area(tmp);
}

// Вывод дерева в формате вложенных списков, где каждый вложенный список является:
// "S0: [S1: [S3, S4: [S5, S6]], S2]", где Si - площадь фигуры

template <typename T>
void print(std::ostream& os, std::shared_ptr<Item<T>> node){
    if(!node){
        return;
    }
    if((*node).Get_son()){
        //os <<  <<node->pentagon.GetArea() <<  : ]" << 
        os << node->Area() << ": [";
        print(os, (*node).Get_son());
        if((*node).Get_bro()){
            if((*node).Get_bro()){
                os << ", ";
                print(os, (*node).Get_bro());
            }
        }
        os << "]";
    } else if ((*node).Get_bro()) {
       os << node->Area() << ": [";
        print(os, (*node).Get_bro());
        if((*node).Get_son()){
            if((*node).Get_son()){
                os << ", ";
                print(os, (*node).Get_son());
            }
        }
        os << "]";
    }
    else {
        os << node->Area();
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const TNaryTree<T>& tree){
    print(os, tree.root);
    os << "\n";
    return os;
}

template <typename T>
TNaryTree<T>::~TNaryTree(){
    Clear();
};

#include "Rectangle.h"
template class TNaryTree<Rectangle>;
template std::ostream& operator<<(std::ostream& os, const TNaryTree<Rectangle>& stack);