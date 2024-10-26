#pragma once
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "AbstractVector.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
class Vector : public AbstractVector<T>
{
public:
    // 默认构造函数
    Vector() = default;
    // 构造函数，根据给定大小初始化向量
    Vector(std::size_t size) : m_data(size)
    {
    }

    // 构造函数，从迭代器范围初始化向量
    template <typename InputIt>
    Vector(InputIt first, InputIt last) : m_data(first, last)
    {
    }

    // 获取向量大小
    std::size_t size() const override
    {
        return m_data.size();
    }

    // 获取指定索引的元素（可修改）
    T& get(std::size_t index) override
    {
        if (index >= m_data.size())
            throw std::out_of_range("Index out of range");
        return m_data[index];
    }

    // 获取指定索引的元素（只读）
    const T& get(std::size_t index) const override
    {
        if (index >= m_data.size())
            throw std::out_of_range("Index out of range");
        return m_data[index];
    }

    // 设置指定索引的元素
    void set(std::size_t index, const T& value) override
    {
        if (index >= m_data.size())
            throw std::out_of_range("Index out of range");
        m_data[index] = value;
    }

    // 向向量尾部添加元素
    void push_back(const T& value) override
    {
        m_data.push_back(value);
    }

    // 删除向量尾部元素
    void pop_back() override
    {
        if (m_data.empty())
            throw std::runtime_error("Vector is empty");
        m_data.pop_back();
    }

    // 在指定位置插入元素
    void insert(std::size_t index, const T& value) override
    {
        if (index > m_data.size())
            throw std::out_of_range("Index out of range");
        m_data.insert(m_data.begin() + index, value);
    }

    // 删除指定位置的元素
    void erase(std::size_t index) override
    {
        if (index >= m_data.size())
            throw std::out_of_range("Index out of range");
        m_data.erase(m_data.begin() + index);
    }

    // 打印向量内容
    void print() const override
    {
        for (const auto& element : m_data) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    // 清空向量
    void clear() override
    {
        m_data.clear();
    }

    // 判断向量是否为空
    bool empty() const override
    {
        return m_data.empty();
    }

    // 获取向量中的最大值
    T max() const override
    {
        if (m_data.empty())
            throw std::runtime_error("Vector is empty");
        return *std::max_element(m_data.begin(), m_data.end());
    }

    // 获取向量中的最小值
    T min() const override
    {
        if (m_data.empty())
            throw std::runtime_error("Vector is empty");
        return *std::min_element(m_data.begin(), m_data.end());
    }

private:
    std::vector<T> m_data;  // 使用 std::vector 实现动态数组
};

#endif  // VECTOR_HPP
