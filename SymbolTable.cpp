#pragma once
#include <stdio.h>
#include <tchar.h>
#include "iostream";
#include <vector>;

using namespace std;

template<typename T >
class Node
{ 
public:
    string key;
    typedef Node<T> node_type;
    T val;
public:
 
    node_type* next;
   
    Node(string key, T val, node_type* next)
    {
        this->key = key;
        this->val = val;
        this->next = next;
    }
};

//Node<string> n1;
//Node<int> n2;
//Node<float> n3;

template<typename T>
class SymbolTable
{
private:
    typedef Node<T> node_type;
    node_type* first;
    int node_count = 0;
public:
    SymbolTable() {}   
    void put(string key, T val){
        for (node_type* x = first; x != NULL; x = x->next)
            if (key == x->key)
            {
                x->val = val; 
                return;
            } // Search hit: update val.
        first = new node_type(key, val, first); // Search miss: add new node.
        node_count++;
    }

    T get(string key) 
    { 
        for (node_type* x = first; x != NULL; x = x->next)
            if (key == x->key)
                return x->val; // search hit
        return NULL;
        //return T();
    }
    
    void remove(string key) {}
    bool contains(string key) { return true; }
    bool isEmpty() { return node_count == 0; }
    int size() { return node_count; }
    string min() { return "smallest key"; }
    string max() { return "largest key"; }
    string floor(string key) {
        return "largest key less than or equal to key";
    }
    string ceiling(string key) {
        return "smallest key greater than or equal to key";
    }
    int rank(string key) {
        return 0;// number of keys less than key
    }
    string select(int k) {
        return "key of rank k";
    }
    void removeMin() { //remove smallest key
    }
    void removeMax() { //remove largest key
    }
    int size(string lo, string hi)
    {
        //  number of keys in[lo..hi]
        return 0;
    }

    /*
    Iterable<string> keys(string lo, string hi) keys in[lo..hi], in sorted order
    Iterable<string> keys() all keys in the table, in sorted order
    */
};

SymbolTable<string> st1;
SymbolTable<int> st2;
SymbolTable<float> st3;


void testST()
{
    vector<string> testdata = { "key1","key2", "key3", "key6", "key9", "key8", "key7", "key5", "key4" };
    SymbolTable<string>* st = new SymbolTable<string>();
    for (size_t i = 0; i < testdata.size(); i++)
    {
        st->put(testdata[i], to_string(i));
    }
    cout << "size: " << st->size() <<", is empty? " << st->isEmpty() << endl;
    delete st;
}

void frenquencyCounter()
{
    
    SymbolTable<int> st;
    vector<string> testdata = { "key1","key2", "key3", "key6", "key9", "key8", "key7", "key5", "key4" };
    for (size_t i = 0; i < testdata.size(); i++)
    {
        if (!st.contains(testdata[i])) st.put(testdata[i], i);
        else
        {
            int item = st.get(testdata[i]);
            st.put(testdata[i], item +1);
        }
    }
}
int main()
{   
    testST();
    frenquencyCounter();
    //HouseHeater::testItself();
    return 0;
}
