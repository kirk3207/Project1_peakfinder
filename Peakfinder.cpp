#include<iostream>
#include<fstream>
#include<queue>
#include<string>
#include<sstream>
using namespace std;

void clear(queue<string> &q)
{
    queue<string> empty;
    swap(q,empty);
}

int main()
{
    ifstream fin;
    ofstream fout;
    queue<string> ans;
    int row, col;
    int peak=2147483648*(-1);
    int now,numofpeak;
    stringstream s;
    string nowString;
    fin.open("matrix.data");

    fin>>row>>col;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            fin>>now;
            if(now>peak)
            {
                numofpeak=0;
                clear(ans);
                s.str("");
                s.clear();
                peak=now;
                numofpeak+=1;
                s<<i<<" "<<j;
                nowString=s.str();
                ans.push(nowString);
            }
            else if(now==peak)
            {
                numofpeak++;
                s.str("");
                s.clear();
                s<<i<<" "<<j;
                nowString=s.str();
                ans.push(nowString);
            }
            else if(now<peak)
            {

            }
        }
    }

    fin.close();

    while(!ans.empty())
    {
        cout<<ans.front()<<endl;
        ans.pop();
    }
    cout<<peak<<endl<<numofpeak<<endl;
    cout<<ans.size()<<endl;
    return 0;

}
