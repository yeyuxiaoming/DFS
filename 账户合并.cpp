/*721:给定一个列表 accounts，每个元素 accounts[i]?是一个字符串列表，其中第一个元素 accounts[i][0]?是?名称 (name)，其余元素是 emails 表示该账户的邮箱地址。
现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。
合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是按字符 ASCII 顺序排列的邮箱地址。账户本身可以以任意顺序返回。
*/
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,vector<string>> Graph = BuildGraph(accounts);
        unordered_set<string> visited;
        vector<vector<string>> res;
        for(auto &account : accounts) {
            vector<string> emails;
            DFS(Graph,visited,account[1],emails);
            if(emails.empty()) continue;
            sort(emails.begin(),emails.end());
            emails.insert(emails.begin(),account[0]);
            res.push_back(emails);
        }
        return res;
    }

    //建图
    unordered_map<string,vector<string>> BuildGraph(vector<vector<string>>& accounts) {
        unordered_map<string,vector<string>> Graph;
        for(auto &account : accounts) {
            string master = account[1];
            unordered_set<string> uset(account.begin() + 2,account.end());
            for(auto &email : uset) {
                Graph[email].push_back(master);
                Graph[master].push_back(email);
            } 
        }
        return Graph;
    }

    void DFS(unordered_map<string,vector<string>> &graph,unordered_set<string> &visited,string &email,vector<string> &emails) {
        if(visited.count(email)) return ;
        visited.insert(email);
        emails.push_back(email);
        for(auto &neighbor : graph[email]) {
            DFS(graph,visited,neighbor,emails);
        }
    }
};

