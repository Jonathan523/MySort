#pragma once
#ifndef ABSTRACTVECTOR_HPP
#define ABSTRACTVECTOR_HPP
#include <cstddef>
#include <iterator>

template <typename T>
class AbstractVector
{
public:
    // 虚析构函数
    virtual ~AbstractVector()
    {
    }

    // 纯虚函数，获取向量大小
    virtual std::size_t size() const = 0;

    // 纯虚函数，获取指定索引的元素（可修改）
    virtual T& get(std::size_t index) = 0;

    // 纯虚函数，获取指定索引的元素（只读）
    virtual const T& get(std::size_t index) const = 0;

    // 纯虚函数，设置指定索引的元素
    virtual void set(std::size_t index, const T& value) = 0;

    // 纯虚函数，打印向量内容
    virtual void print() const = 0;

    // 纯虚函数，获取最大值
    virtual T max() const = 0;

    // 纯虚函数，获取最小值
    virtual T min() const = 0;

    // 纯虚函数，向向量尾部添加元素
    virtual void push_back(const T& value) = 0;

    // 纯虚函数，删除向量尾部元素
    virtual void pop_back() = 0;

    // 纯虚函数，在指定位置插入元素
    virtual void insert(std::size_t index, const T& value) = 0;

    // 纯虚函数，删除指定位置的元素
    virtual void erase(std::size_t index) = 0;

    // 纯虚函数，清空向量
    virtual void clear() = 0;

    // 纯虚函数，判断向量是否为空
    virtual bool empty() const = 0;

    virtual bool operator==(const AbstractVector<T>& other) const
    {
        if (size() != other.size())
            return false;
        for (std::size_t i = 0; i < size(); ++i) {
            if (get(i) != other.get(i))
                return false;
        }
        return true;
    }

    virtual bool operator!=(const AbstractVector<T>& other) const
    {
        return !(*this == other);
    }

    // 嵌套迭代器类
    class Iterator
    {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        // 默认构造函数
        Iterator() : m_vector(nullptr), m_pos(0)
        {
        }

        // 参数化构造函数
        Iterator(AbstractVector<T>& vec, std::size_t pos) : m_vector(&vec), m_pos(pos)
        {
        }

        // 解引用运算符
        reference operator*() const
        {
            return m_vector->get(m_pos);
        }

        // 指针访问运算符
        pointer operator->() const
        {
            return &m_vector->get(m_pos);
        }

        // 前置递增运算符
        Iterator& operator++()
        {
            ++m_pos;
            return *this;
        }

        // 后置递增运算符
        Iterator operator++(int)
        {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        // 前置递减运算符
        Iterator& operator--()
        {
            --m_pos;
            return *this;
        }

        // 后置递减运算符
        Iterator operator--(int)
        {
            Iterator temp = *this;
            --(*this);
            return temp;
        }

        // 加法运算符
        Iterator operator+(difference_type n) const
        {
            return Iterator(*m_vector, m_pos + n);
        }

        // 减法运算符
        Iterator operator-(difference_type n) const
        {
            return Iterator(*m_vector, m_pos - n);
        }

        // 迭代器差运算符
        difference_type operator-(const Iterator& other) const
        {
            return m_pos - other.m_pos;
        }

        // 加等于运算符
        Iterator& operator+=(difference_type n)
        {
            m_pos += n;
            return *this;
        }

        // 减等于运算符
        Iterator& operator-=(difference_type n)
        {
            m_pos -= n;
            return *this;
        }

        // 下标运算符
        reference operator[](difference_type n) const
        {
            return m_vector->get(m_pos + n);
        }

        // 比较运算符
        bool operator<(const Iterator& other) const
        {
            return m_pos < other.m_pos;
        }
        bool operator>(const Iterator& other) const
        {
            return m_pos > other.m_pos;
        }
        bool operator<=(const Iterator& other) const
        {
            return m_pos <= other.m_pos;
        }
        bool operator>=(const Iterator& other) const
        {
            return m_pos >= other.m_pos;
        }

        // 相等和不相等比较运算符
        bool operator==(const Iterator& other) const
        {
            return m_vector == other.m_vector && m_pos == other.m_pos;
        }
        bool operator!=(const Iterator& other) const
        {
            return !(*this == other);
        }

        // 非成员函数来支持 difference_type + Iterator 操作
        friend Iterator operator+(difference_type n, const Iterator& it)
        {
            return it + n;
        }

    private:
        AbstractVector<T>* m_vector;
        std::size_t m_pos;
    };

    // 嵌套 const 迭代器类
    class ConstIterator
    {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = const T*;
        using reference = const T&;

        // 默认构造函数
        ConstIterator() : m_vector(nullptr), m_pos(0)
        {
        }

        // 参数化构造函数
        ConstIterator(const AbstractVector<T>& vec, std::size_t pos) : m_vector(&vec), m_pos(pos)
        {
        }

        // 解引用运算符
        reference operator*() const
        {
            return m_vector->get(m_pos);
        }

        // 指针访问运算符
        pointer operator->() const
        {
            return &m_vector->get(m_pos);
        }

        // 前置递增运算符
        ConstIterator& operator++()
        {
            ++m_pos;
            return *this;
        }

        // 后置递增运算符
        ConstIterator operator++(int)
        {
            ConstIterator temp = *this;
            ++(*this);
            return temp;
        }

        // 前置递减运算符
        ConstIterator& operator--()
        {
            --m_pos;
            return *this;
        }

        // 后置递减运算符
        ConstIterator operator--(int)
        {
            ConstIterator temp = *this;
            --(*this);
            return temp;
        }

        // 加法运算符
        ConstIterator operator+(difference_type n) const
        {
            return ConstIterator(*m_vector, m_pos + n);
        }

        // 减法运算符
        ConstIterator operator-(difference_type n) const
        {
            return ConstIterator(*m_vector, m_pos - n);
        }

        // 迭代器差运算符
        difference_type operator-(const ConstIterator& other) const
        {
            return m_pos - other.m_pos;
        }

        // 加等于运算符
        ConstIterator& operator+=(difference_type n)
        {
            m_pos += n;
            return *this;
        }

        // 减等于运算符
        ConstIterator& operator-=(difference_type n)
        {
            m_pos -= n;
            return *this;
        }

        // 下标运算符
        reference operator[](difference_type n) const
        {
            return m_vector->get(m_pos + n);
        }

        // 比较运算符
        bool operator<(const ConstIterator& other) const
        {
            return m_pos < other.m_pos;
        }
        bool operator>(const ConstIterator& other) const
        {
            return m_pos > other.m_pos;
        }
        bool operator<=(const ConstIterator& other) const
        {
            return m_pos <= other.m_pos;
        }
        bool operator>=(const ConstIterator& other) const
        {
            return m_pos >= other.m_pos;
        }

        // 相等和不相等比较运算符
        bool operator==(const ConstIterator& other) const
        {
            return m_vector == other.m_vector && m_pos == other.m_pos;
        }
        bool operator!=(const ConstIterator& other) const
        {
            return !(*this == other);
        }

        // 非成员函数来支持 difference_type + ConstIterator 操作
        friend ConstIterator operator+(difference_type n, const ConstIterator& it)
        {
            return it + n;
        }

    private:
        const AbstractVector<T>* m_vector;
        std::size_t m_pos;
    };

    // begin 和 end 方法
    Iterator begin()
    {
        return Iterator(*this, 0);
    }

    Iterator end()
    {
        return Iterator(*this, size());
    }

    ConstIterator begin() const
    {
        return ConstIterator(*this, 0);
    }

    ConstIterator end() const
    {
        return ConstIterator(*this, size());
    }
};

#endif  // ABSTRACTVECTOR_HPP
