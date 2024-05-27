#include <iostream>
#include <list>

// Функция для удаления последнего элемента со значением меньшим 15
void removeLastLessThan15(std::list<int>& lst) {
    if (lst.empty()) {
        return;  // Если список пуст, ничего не делаем
    }

    auto it = lst.end();
    --it;  // Переходим к последнему элементу

    while (it != lst.begin()) {
        if (*it < 15) {
            it = lst.erase(it);  // Удаляем элемент, если его значение меньше 15
            break;
        }
        else {
            --it;  // Переходим к предыдущему элементу
        }
    }

    // Проверяем первый элемент
    if (*it < 15) {
        lst.erase(it);  // Удаляем первый элемент, если его значение меньше 15
    }
}

// Функция для вывода содержимого списка
void printList(const std::list<int>& lst) {
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    std::list<int> myList = { 10, 5, 20, 30, 25 };

    // Удаляем последний элемент со значением меньшим 15
    removeLastLessThan15(myList);

    // Выводим содержимое списка
    std::cout << "Список после удаления последнего элемента < 15:" << std::endl;
    printList(myList);

    return 0;
}
