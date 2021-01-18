/*721:����һ���б� accounts��ÿ��Ԫ�� accounts[i]?��һ���ַ����б����е�һ��Ԫ�� accounts[i][0]?��?���� (name)������Ԫ���� emails ��ʾ���˻��������ַ��
���ڣ�������ϲ���Щ�˻�����������˻�����һЩ��ͬ�������ַ���������˻��ض�����ͬһ���ˡ���ע�⣬��ʹ�����˻�������ͬ�����ƣ�����Ҳ�������ڲ�ͬ���ˣ���Ϊ���ǿ��ܾ�����ͬ�����ơ�һ�����������ӵ�������������˻������������˻���������ͬ�����ơ�
�ϲ��˻��󣬰����¸�ʽ�����˻���ÿ���˻��ĵ�һ��Ԫ�������ƣ�����Ԫ���ǰ��ַ� ASCII ˳�����е������ַ���˻��������������˳�򷵻ء�
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

    //��ͼ
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

