#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char, vector<char>> adjList;
        unordered_map<char, int> indegree;
        // Step 1: Add all unique characters to adjacency list
        for (auto &word : words) for (auto &ch : word) adjList[ch];
        // Build edges from adjacent words
        for (int i = 0; i < words.size() - 1; i++) {
            string &w1 = words[i], &w2 = words[i + 1];
            int len = min(w1.size(), w2.size());
            bool foundDifference = false;
            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    if (find(adjList[w1[j]].begin(), adjList[w1[j]].end(), w2[j]) == adjList[w1[j]].end()) {
                        adjList[w1[j]].push_back(w2[j]); // c1 -> c2
                        indegree[w2[j]]++;
                    }
                    foundDifference = true;
                    break;
                }
            }
            // Edge case: invalid order (prefix issue)
            if (!foundDifference && w1.size() > w2.size()) return "";
            //abcd abc
        }
        queue<char> q;
        for (auto &p : adjList) if (indegree[p.first] == 0) q.push(p.first);
        string order;
        while (!q.empty()) {
            char node = q.front();
            q.pop();
            order += node;
            for (char nei : adjList[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) q.push(nei);
            }
        }
        // Cycle detection
        if (order.size() != adjList.size()) return "";
        return order;
    }
};