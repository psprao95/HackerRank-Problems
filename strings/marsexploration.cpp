#include <bits/stdc++.h>

using namespace std;

// Complete the marsExploration function below.
int marsExploration(string s) {
    int count=0;
int n=s.size();
vector<int> arr{'S','O','S'};
for(int i=0;i<n;i++)
{
    if(s[i]!=arr[i%3])
    {
        count++;
    }
}
return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
