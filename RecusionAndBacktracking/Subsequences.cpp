#include<bits/stdc++.h>


void getSequence(int i, string s, string output, vector<string> &f)
    {
        if(i >= s.length())
        {
            f.push_back(output);
            return;
        }
        getSequence(i+1, s, output, f);

        char element = s[i];
        output += element;
        //getSequence(nums,output,index+1,ans);
        getSequence(i+1, s, output, f);

    }
    

vector<string> generateSubsequences(string s)
{
    // Write your code here.
    vector<string> f;
    string output;
    getSequence(0, s, output, f);
    return f;
}