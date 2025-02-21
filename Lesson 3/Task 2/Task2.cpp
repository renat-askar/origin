#include <iostream>
#include <catch2/catch_all.hpp>

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};

class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {       
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

TEST_CASE("Empty")
{
    List emptyList{};
    REQUIRE(emptyList.Empty());
    emptyList.PushBack(1);
    REQUIRE(!emptyList.Empty());
    emptyList.PopBack();
    REQUIRE(emptyList.Empty());
    emptyList.PushFront(-1);
    emptyList.PushFront(-2);
    emptyList.Clear();
    REQUIRE(emptyList.Empty());
}

TEST_CASE("Size")
{
    List sizeList{};
    sizeList.PushBack(0);
    sizeList.PushBack(1);
    sizeList.PushBack(2);
    sizeList.PushFront(0);
    sizeList.PushFront(-2);
    sizeList.PushFront(-3);
    sizeList.PopBack();
    sizeList.PopFront();
    REQUIRE(sizeList.Size() == 4);
}

TEST_CASE("Clear")
{
    List clearList{};
    clearList.PushBack(1);
    clearList.PushBack(2);
    clearList.PushBack(3);
    clearList.PushFront(0);
    clearList.PushFront(-1);
    clearList.PushFront(-2);
    clearList.PopBack();
    clearList.PopFront();
    clearList.Clear();
    REQUIRE(clearList.Size() == 0);
}

TEST_CASE("PushBack")
{
    List list{};
    list.PushBack(1);
    REQUIRE(1 == list.PopBack());
    list.PushBack(0);
    list.PushBack(2);
    REQUIRE(list.Size() == 2);
    REQUIRE(0 == list.PopFront());
}

TEST_CASE("PushFront")
{
    List list{};
    list.PushFront(-1);
    REQUIRE(-1 == list.PopBack());
    list.PushFront(-2);
    list.PushFront(-4);
    REQUIRE(list.Size() == 2);
    REQUIRE(-4 == list.PopFront());
}

TEST_CASE("PopBack")
{
    List list{};
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    REQUIRE(list.PopBack() == 3);
    REQUIRE(list.Size() == 2);
    REQUIRE(list.PopBack());
    REQUIRE(list.PopBack());
    REQUIRE(list.Empty());
    REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
}

TEST_CASE("PopFront")
{
    List list{};
    list.PushBack(1);
    list.PushBack(2);
    list.PushBack(3);
    REQUIRE(list.PopFront() == 1);
    REQUIRE(list.Size() == 2);
    REQUIRE(list.PopFront());
    REQUIRE(list.PopFront());
    REQUIRE(list.Empty());
    REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
}
