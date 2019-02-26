#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

struct PrimeSubTree
{
    int val;
    int val2;
    vector<PrimeSubTree *> child;
};

PrimeSubTree *newNode(int val)
{
    PrimeSubTree *temp = new PrimeSubTree;
    temp->val = val;
    return temp;
}

void printVectors(string name, vector<int> gVector)
{
    cout << name << ": ";

    for (int i = 0; i < gVector.size(); i++)
    {
        cout << gVector[i] << " ";
    }
    cout << endl;
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}

int countPrimes(PrimeSubTree *node)
{
    int cnt = 0;
    if (node == NULL)
    {
        return 0;
    }
    queue<PrimeSubTree *> q;
    q.push(node);
    while (!q.empty())
    {
        int n = q.size();

        while (n > 0)
        {
            PrimeSubTree *p = q.front();
            q.pop();
            if (isPrime(p->val))
                cnt++;

            for (int i = 0; i < p->child.size(); i++)
                q.push(p->child[i]);
            n--;
        }
    }
    return cnt;
}

void levelOrderTree(PrimeSubTree *root)
{

    if (root == NULL)
    {
        cout << "\nEmpty Tree";
    }

    queue<PrimeSubTree *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();

        while (n > 0)
        {
            PrimeSubTree *p = q.front();
            q.pop();
            cout << p->val << " ";

            for (int i = 0; i < p->child.size(); i++)
                q.push(p->child[i]);
            n--;
        }

        cout << endl;
    }
}

PrimeSubTree *findNode(PrimeSubTree *root, int val)
{
    PrimeSubTree *node;
    if (root == NULL)
    {
        cout << "\nEmpty Tree";
        exit(0);
    }
    else
    {
        if (root->val == val)
        {
            node = root;
            return node;
        }
        else
        {
            queue<PrimeSubTree *> q;
            q.push(root);
            while (!q.empty())
            {
                int n = q.size();
                while (n > 0)
                {
                    PrimeSubTree *p = q.front();
                    q.pop();
                    if (p->val == val)
                    {
                        node = p;
                        return node;
                    }
                    else
                    {
                        for (int i = 0; i < p->child.size(); i++)
                            q.push(p->child[i]);
                    }
                    n--;
                }
            }
        }
    }
    return node;
}

PrimeSubTree *ModifyTree(PrimeSubTree *root, unordered_map<int, int> map)
{
    // for(auto it: map){
    //     //cout<<"\n "<<it.first<<" sec "<<it.second<<endl;
    //     cout<<"\n itf "<<it.first<<" tree val "<<findNode(root,it.first)->val<<" sec "<<it.second<<endl;
    //     findNode(root,it.first)->val = it.second;
    // }

    if (root == NULL)
    {
        cout << "\nEmpty Tree";
    }

    queue<PrimeSubTree *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();

        while (n > 0)
        {
            PrimeSubTree *p = q.front();
            q.pop();
            p->val = map.at(p->val);
            for (int i = 0; i < p->child.size(); i++)
                q.push(p->child[i]);
            n--;
        }
    }


    return root;
}

PrimeSubTree *CreateTree(unordered_map<int, int> nodeVal, vector<int> nodes, vector<int> first, vector<int> second, vector<int> values)
{

    PrimeSubTree *root = NULL;
    if ((first.size() != second.size()) || (nodes.size() != values.size()))
    {
        cout << "\n"<< nodes.size();
        cout << "\n Invalid parameters";
        exit(0);
    }
    else
    {

        queue<int> check;
        check.push(nodes[0]);
        cout << "\n initial queue front: " << check.front() << endl;

        while (!check.empty() || first.size() != 0)
        {
            if (check.empty())
            {
                check.push(first[0]);
            }
            if (root == NULL)
            {
                int numb = check.front();
                // cout<<"\n queue front: "<<check.front()<<endl;
                check.pop();
                root = newNode(numb);
                for (int j = 0; j < first.size(); j++)
                {
                    cout << "\n queue front: " << check.front() << endl;
                    if (first[j] == numb)
                    {
                        root->child.push_back(newNode(second[j]));
                        check.push(second[j]);
                        first.erase(first.begin() + j);
                        for (auto x : first)
                            cout << " " << x;
                        cout << "\n";
                        second.erase(second.begin() + j);
                        for (auto x : second)
                            cout << " " << x;
                        cout << "\n";
                        j = 0;
                    }
                    if (second[j] == numb)
                    {
                        root->child.push_back(newNode(first[j]));
                        check.push(first[j]);
                        first.erase(first.begin() + j);
                        for (auto x : first)
                            cout << " " << x;
                        cout << "\n";
                        second.erase(second.begin() + j);
                        for (auto x : second)
                            cout << " " << x;
                        cout << "\n";
                        j = 0;
                    }
                }
            }
            else
            {
                int numb = check.front();
                check.pop();
                PrimeSubTree *temp = findNode(root, numb);
                for (int j = 0; j < first.size(); j++)
                {
                    cout << "\n queue front: " << check.front() << endl;
                    if (first[j] == numb)
                    {
                        temp->child.push_back(newNode(second[j]));
                        check.push(second[j]);
                        first.erase(first.begin() + j);
                        for (auto x : first)
                            cout << " " << x;
                        cout << "\n";
                        second.erase(second.begin() + j);
                        for (auto x : second)
                            cout << " " << x;
                        cout << "\n";
                        j = 0;
                    }
                    if (second[j] == numb)
                    {
                        temp->child.push_back(newNode(first[j]));
                        check.push(first[j]);
                        first.erase(first.begin() + j);
                        for (auto x : first)
                            cout << " " << x;
                        cout << "\n";
                        second.erase(second.begin() + j);
                        for (auto x : second)
                            cout << " " << x;
                        cout << "\n";
                        j = 0;
                    }
                }
            }
        }
    }

    return root;
}

vector<int> primeQuery(int n, vector<int> first, vector<int> second, vector<int> values, vector<int> queries)
{
    vector<int> ans;
    set<int> node;
    vector<int> nodes;
    unordered_map<int, int> nodeVal;
    for (int i = 0; i < first.size() || i < second.size(); i++)
    {
        node.insert(first[i]);
        node.insert(second[i]);
    }

    set<int>::iterator it = node.begin();

    while (it != node.end())
    {
        nodes.push_back(*it);
        it++;
    }
    for (int i = 0; i < nodes.size(); i++)
    {
        nodeVal.insert({nodes[i], values[i]});
    }
    PrimeSubTree *root = CreateTree(nodeVal, nodes, first, second, values);
    levelOrderTree(root);
    PrimeSubTree *root1 = ModifyTree(root, nodeVal);
    levelOrderTree(root1);

    for (int i = 0; i < queries.size(); i++)
    {
        ans.push_back(countPrimes(findNode(root, queries[i])));
    }
    vector<int> ans1;
    for (int i = 0; i < queries.size(); i++)
    {
        ans1.push_back(countPrimes(findNode(root1, nodeVal.at(queries[i]))));
    }
    cout<<endl;
    return ans1;
}

int main()
{
    int n, fn, sn, vn, qn;
    set<int> node;
    vector<int> nodes;
    vector<int> first;
    vector<int> second;
    vector<int> values;
    vector<int> queries;
    vector<int> ans;
    cin >> n;

    int temp;
    cin >> fn;
    for (int i = 0; i < fn; i++)
    {
        cin >> temp;
        first.push_back(temp);
        temp = 0;
    }
    cin >> sn;
    for (int i = 0; i < sn; i++)
    {
        cin >> temp;
        second.push_back(temp);
        temp = 0;
    }
    cin >> vn;
    for (int i = 0; i < vn; i++)
    {
        cin >> temp;
        values.push_back(temp);
        temp = 0;
    }

    cin >> qn;
    for (int i = 0; i < qn; i++)
    {
        cin >> temp;
        queries.push_back(temp);
        temp = 0;
    }

    printVectors("First", first);
    printVectors("Second", second);
    printVectors("Values", values);
    printVectors("Queries", queries);
    ans = primeQuery(n, first, second, values, queries);
    printVectors("Answers", ans);
}
