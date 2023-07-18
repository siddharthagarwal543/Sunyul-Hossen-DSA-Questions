//Problem link:https://leetcode.com/problems/evaluate-division/
#include <unordered_map>
#include <vector>
#include <string>
#include <utility>

class Solution {
public:
    double dfs(const std::string& start, const std::string& target, std::unordered_map<std::string, std::vector<std::pair<std::string, double>>>& adj, std::unordered_map<std::string, bool>& visited) {
        if (start == target)
            return 1.0;
        
        visited[start] = true;
        
        for (const auto& neighbor : adj[start]) {
            const std::string& next = neighbor.first;
            double weight = neighbor.second;
            
            if (!visited[next]) {
                double result = dfs(next, target, adj, visited);
                if (result != -1.0)
                    return weight * result;
            }
        }
        
        return -1.0;
    }
    
    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values, std::vector<std::vector<std::string>>& queries) {
        std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> adj;
        
        // Build the adjacency list
        for (int i = 0; i < equations.size(); i++) {
            const std::string& A = equations[i][0];
            const std::string& B = equations[i][1];
            double value = values[i];
            
            adj[A].emplace_back(B, value);
            adj[B].emplace_back(A, 1.0 / value);
        }
        
        std::vector<double> results;
        
        for (const auto& query : queries) {
            const std::string& dividend = query[0];
            const std::string& divisor = query[1];
            
            if (adj.find(dividend) == adj.end() || adj.find(divisor) == adj.end()) {
                results.push_back(-1.0);
            } else {
                std::unordered_map<std::string, bool> visited;
                double result = dfs(dividend, divisor, adj, visited);
                results.push_back(result);
            }
        }
        
        return results;
    }
};
