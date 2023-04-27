#include "pch.h"
#include "CppUnitTest.h"
#include "../Ap_Lab12.2rec/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingLinkedListTest
{
    TEST_CLASS(SortingLinkedListTest)
    {
    public:

        TEST_METHOD(TestSortList)
        {
            Elem* L = nullptr;
            AddToList(L, 6);
            AddToList(L, 2);
            AddToList(L, 8);
            AddToList(L, 3);
            AddToList(L, 9);
            AddToList(L, 3);

            // Before sorting
            Assert::AreEqual(6, Count(L));
            Assert::AreEqual(6, L->info);
            Assert::AreEqual(2, L->link->info);
            Assert::AreEqual(8, L->link->link->info);
            Assert::AreEqual(3, L->link->link->link->info);
            Assert::AreEqual(9, L->link->link->link->link->info);
            Assert::AreEqual(3, L->link->link->link->link->link->info);

            SortList(L);

            // After sorting
            Assert::AreEqual(6, Count(L));
            Assert::AreEqual(2, L->info);
            Assert::AreEqual(3, L->link->info);
            Assert::AreEqual(3, L->link->link->info);
            Assert::AreEqual(6, L->link->link->link->info);
            Assert::AreEqual(8, L->link->link->link->link->info);
            Assert::AreEqual(9, L->link->link->link->link->link->info);
        }

    };
}
