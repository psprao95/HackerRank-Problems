#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
bool validate(int,int,int,int);
int dfs(vector<string>&,int ,int , int , int ,int );
// Complete the countLuck function below.
string countLuck(vector<string> matrix, int k) {
    int n=matrix.size();
    int m=matrix[0].size();
for(int i=0;
i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(matrix[i][j]=='M' &&dfs(matrix,i,j,n,m,0)==k)
        {
            return "Impressed";
        }
    }
}
return "Oops!";

}

int dfs(vector<string>&res,int i,int j,  int n,int m,int k)
{
    if(!validate(i,j,n,m) || res[i][j]=='X')
    {
        return 0;
    }

    if(res[i][j]=='*')
    {
        return k;
    }

    res[i][j]='X';

    int p=(validate(i,j+1,n,m)&&res[i][j+1]!='X')
    + (validate(i,j-1,n,m)&&res[i][j-1]!='X')+
    (validate(i+1,j,n,m)&&res[i+1][j]!='X')+
    (validate(i-1,j,n,m)&&res[i-1][j]!='X');
    k+=p>1?1:0;
    int x,y,w,z;x=dfs(res,i+1,j,n,m,k);
    y=dfs(res,i-1,j,n,m,k);
    z=dfs(res,i,j+1,n,m,k);
    w=dfs(res,i,j-1,n,m,k);
    return max(x,max(y,max(w,z)));



}

bool validate(int i,int j,int n,int m)
{
    return i>=0 &&i<n && j>=0 && j<m;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<string> matrix(n);

        for (int i = 0; i < n; i++) {
            string matrix_item;
            getline(cin, matrix_item);

            matrix[i] = matrix_item;
        }

        int k;
        cin >> k;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = countLuck(matrix, k);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
