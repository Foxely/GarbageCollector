/*
** EPITECH PROJECT, 2018
** cpp_d02a
** File description:
** ex01
*/

#ifndef GENERIC_LIST_H
#define GENERIC_LIST_H

#ifdef __cplusplus
    #include <functional>
    typedef std::function<void(void *)> value_destroyer_t;
#else
    typedef void (*value_destroyer_t)(void *value);
#endif

#ifdef __cplusplus
   extern "C" {
#endif

/*
** Types
*/

#include <stdbool.h>


typedef struct node
{
    void        *value;
    struct node *next;
}   node_t;

struct list
{
    node_t *p_head;
    node_t *p_tail;
    unsigned int u_size;
    value_destroyer_t dtor;
};
typedef struct list list_t;

/*
** Functions
*/

/* Informations */

unsigned int    list_get_size(list_t *p_list);
bool            list_is_empty(list_t *p_list);

typedef void    (*value_displayer_t)(void *value);

void            list_init(list_t *p_list, value_destroyer_t destroyer);
void            list_dump(list_t *p_list, value_displayer_t val_disp);
node_t *list_create_node(void *p_elem);

/* Modification */

bool    list_add_elem_at_front(list_t *front_ptr, void *elem);
bool    list_add_elem_at_back(list_t *front_ptr, void *elem);
bool    list_add_elem_at_position(list_t *front_ptr, void *elem,
                                            unsigned int position);

bool    list_del_elem_at_front(list_t *front_ptr);
bool    list_del_elem_at_back(list_t *front_ptr);
bool    list_del_elem_at_position(list_t *front_ptr, unsigned int position);
bool    list_del_node(list_t *front_ptr, node_t *node_ptr);

void    list_clear(list_t *front_ptr);
void    list_clear_call(list_t *p_list, value_destroyer_t dtor);

/* Value Access */

void    *list_get_elem_at_front(list_t *p_list);
void    *list_get_elem_at_back(list_t *p_list);
void    *list_get_elem_at_position(list_t *p_list, unsigned int position);

/* Node Access */

typedef int (*value_comparator_t)(void *first, void *second);

node_t  *list_get_first_node_with_value(list_t *p_list, void *value,
                                        value_comparator_t val_comp);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
    #include <functional>
    namespace Tek
    {
        template<typename T>
        struct ListNode
        {
            T data;
        };

        template<typename T>
        class List
        {
            public:
            class iterator
            {
                public:
                    typedef iterator self_type;
                    typedef T value_type;
                    typedef T& reference;
                    typedef T* pointer;
                    typedef std::forward_iterator_tag iterator_category;
                    typedef int difference_type;
                    
                    iterator(node_t *ptr) : m_ptr(ptr)
                    {
                        if (m_ptr)
                            m_pData = static_cast<ListNode<T>*>(m_ptr->value);
                    }

                    iterator() : m_ptr(m_pList.p_head)
                    {
                        if (m_ptr)
                            m_pData = static_cast<ListNode<T>*>(m_ptr->value);
                    }

                    self_type& operator++()
                    {
                        m_ptr = m_ptr->next;
                        if (m_ptr)
                            m_pData = static_cast<ListNode<T>*>(m_ptr->value);
                        return *this;
                    }

                    self_type operator++(int junk)
                    {
                        self_type it = *this;
                        ++*this;
                        return it;
                    }

                    reference operator*()
                    {
                        return m_pData->data;
                    }

                    pointer operator->()
                    {
                        return m_pData->data;
                    }

                    bool operator==(const self_type& rhs)
                    {
                        return m_ptr == rhs.m_ptr;
                    }

                    bool operator!=(const self_type& rhs)
                    {
                        return m_ptr != rhs.m_ptr;
                    }

                private:
                    node_t *m_ptr;
                    ListNode<T> *m_pData;
            };

            private:
                using func_destroyer = std::function<void(T&)>;
            
            public:
                explicit List()
                {
                    m_pDestroyer = 0;
                    using std::placeholders::_1;
                    list_init(&m_pList, std::bind(&Tek::List<T>::clear_internal, this, _1));
                }

                explicit List(func_destroyer pDestroyer)
                {
                    m_pDestroyer = pDestroyer;
                    using std::placeholders::_1;
                    list_init(&m_pList, std::bind(&Tek::List<T>::clear_internal, this, _1));
                }

                ~List()
                {
                    list_clear(&m_pList);
                }

                bool push_back(T pElem)
                {
                    ListNode<T>* pNode = new ListNode<T>;
                    pNode->data = pElem;
                    return list_add_elem_at_back(&m_pList, pNode);
                }

                bool push_front(T pElem)
                {
                    ListNode<T>* pNode = new ListNode<T>;
                    pNode->data = pElem;
                    return list_add_elem_at_front(&m_pList, pNode);
                }

                bool remove_back()
                {
                    return list_del_elem_at_back(&m_pList);
                }

                bool remove_front()
                {
                    return list_del_elem_at_front(&m_pList);
                }

                bool remove(unsigned int uPos)
                {
                    return list_del_elem_at_position(&m_pList, uPos);
                }

                bool insert(unsigned int uPos, T pElem)
                {
                    ListNode<T>* pData = new ListNode<T>;
                    pData->data = pElem;
                    return list_add_elem_at_position(&m_pList, pData, uPos);
                }

                void dump(std::function<void(T&)> printer)
                {
                    if (list_is_empty(&m_pList))
                        return;
                    node_t *pTmp = m_pList.p_head;
                    while (pTmp != NULL) {
                        ListNode<T> *pData = static_cast<ListNode<T>*>(pTmp->value);
                        printer(pData->data);
                        pTmp = pTmp->next;
                    }
                }

                iterator begin()
                {
                    return iterator(m_pList.p_head);
                }

                iterator end()
                {
                    return iterator(0);
                }

            private:
                list_t m_pList;
                func_destroyer m_pDestroyer;

                void clear_internal(void *pData)
                {
                    ListNode<T>* pNode = static_cast<ListNode<T>*>(pData);
                    if (m_pDestroyer)
                        m_pDestroyer(pNode->data);
                    delete(pNode);
                }
        };
    } // namespace Tek

#define FREE(ptr) delete(ptr);

#else
#define FREE(ptr) free(ptr);
    
#endif

#endif