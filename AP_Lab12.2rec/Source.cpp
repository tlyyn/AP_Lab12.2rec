#include <iostream>

struct Elem {
    int info;
    Elem* link;
};

int Count(Elem* L) {
    if (L == nullptr) {
        return 0;
    }
    else {
        return 1 + Count(L->link);
    }
}

void Swap(Elem*& L) {
    if (L != nullptr && L->link != nullptr) {
        if (L->info > L->link->info) {
            std::swap(L->info, L->link->info);
        }
        Swap(L->link);
    }
}

void SortList(Elem*& L) {
    if (L == nullptr || L->link == nullptr) {
        return;
    }
    Swap(L);
    SortList(L->link);
}

void PrintList(Elem* L) {
    if (L != nullptr) {
        std::cout << L->info << " ";
        PrintList(L->link);
    }
    else {
        std::cout << std::endl;
    }
}

void AddToList(Elem*& L, int value) {
    if (L == nullptr) {
        L = new Elem;
        L->info = value;
        L->link = nullptr;
    }
    else {
        AddToList(L->link, value);
    }
}

int main() {
    Elem* L = nullptr;
    AddToList(L, 6);
    AddToList(L, 2);
    AddToList(L, 8);
    AddToList(L, 3);
    AddToList(L, 9);
    AddToList(L, 3);
    std::cout << "Original List: ";
    PrintList(L);
    SortList(L);
    std::cout << "Sorted List: ";
    PrintList(L);
    return 0;
}
