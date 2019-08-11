#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {
    int n = s.size();
    vector<bool> arr(n,false);
    for(int i=0;i<n;i++)
    {
        if(s[i]==' ')
        {
            continue;
        }
        else if(s[i]>='a'&&s[i]<='z')
        {
            arr[s[i]-'a']=true;
        }
        else
        {
arr[s[i]-'A']=true;
        }
    }

    for(int i=0;i<26;i++)
    {
        if(arr[i]==false)
        {
            return "not pangram";
        }
    }
    return "pangram";


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
