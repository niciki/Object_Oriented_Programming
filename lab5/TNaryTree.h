#ifndef TNARYTREE_H
#define TNARYTREE_H

#include "TNaryTree_item.h"
#include "Iterator.h"

template <class T>
class TNaryTree {
    public:
        // Инициализация дерева с указанием размера
        TNaryTree(int n);
        // Полное копирование дерева 
        TNaryTree(const TNaryTree<T>& other);
        // Добавление или обновление вершины в дереве согласно заданному пути.
        // Путь задается строкой вида: "cbccbccc", 
        // где 'c' - старший ребенок, 'b' - младший брат
        // последний символ строки - вершина, которую нужно добавить или обновить.
        // Пустой путь "" означает добавление/обновление корня дерева.
        // Если какой-то вершины в tree_path не существует, 
        //  то функция должна бросить исключение std::invalid_argument
        // Если вершину нельзя добавить из за переполнения,
        //  то функция должна бросить исключение std::out_of_range
        void Update(T &&polygon, std::string &&tree_path = "");
        // Удаление поддерева
        void Clear(std::string &&tree_path = "");
        // Проверка наличия в дереве вершин
        bool Empty();
        // Подсчет суммарной площади поддерева
        double Area(std::string &&tree_path);
        int size();
        // Вывод дерева в формате вложенных списков, где каждый вложенный список является:
        // "S0: [S1: [S3, S4: [S5, S6]], S2]", где Si - площадь фигуры
        std::shared_ptr<Item<T>> Tree_root();
        std::shared_ptr<Item<T>> Tree_end();
        template <class A>
        friend std::ostream& operator<<(std::ostream& os, const TNaryTree<A>& tree);
        Iterator<Item<T>, T> begin();
        Iterator<Item<T>, T> end();
        virtual ~TNaryTree();
    private:
        int curr_number;
        int max_number;
        std::shared_ptr<Item<T>> root;
        std::shared_ptr<Item<T>> fin;
};

#endif
