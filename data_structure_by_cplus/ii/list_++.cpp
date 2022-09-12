// 迭代器的后置和前置++
// 后置++
const self operator++() {
    self tmp = *this;
    ++this;
    return tmp;
}

// 前置++
self& operator++() {
    node = (link_type)(node.next());
    return *this;
}

// 迭代器实现*操作--访问data
self& operator*() {
    return (*node).data;
}