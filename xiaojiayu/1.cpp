/*************************************************************************
	> File Name: 1.cpp
	> Author:    orange
	> Mail:      huiyi950512@gmail.com
	> Created Time: 2018年03月29日 星期四 17时01分53秒
 ************************************************************************/

#include <iostream>
using namespace std;
#include <inttypes.h>
#include <vector>
using namespace std;

struct Segment {
    int64_t start, length;
};

void input(vector<vector<Segment>>& segments)
{
    // write your cool code here
    int n;
    cin>>n;
    for(int i = 0 ; i < n;i++)
    {
        int k;
        cin>>k;
        for(int j = 0 ; i < k;i++)
        {
            cin>>segments[i].Segment[i].start;
        }
    }
    segments.push_back(vector<Segment>(1,2)); 
}

vector<Segment> merge(vector<vector<Segment>> segments) 
{
    // write your cool code here
}

void output(const vector<Segment>& result)
{
    // write your cool code here
}

int main(int argc, char** argv)
{
    vector<vector<Segment>> segments;
    input(segments);
    auto result = merge(segments);
    output(result);
    return 0;
}
