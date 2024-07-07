#include<iostream>
#include<vector>
using namespace std;
class RoundRobin
{
private:
    vector<string>nodes;
    int current;
public:
    RoundRobin():current(0){}
    void addNode(const string &node)
    {
        nodes.push_back(node);
    }
    void removeNode(const string &node)
    {
        for(auto a=nodes.begin();a!=nodes.end();++a)
            {
            if(*a==node)
            {
                nodes.erase(a);
                break;
            }
        }
    }
    string routeRequest()
    {
        if(nodes.empty())
        {
            return "No nodes available";
        }
        string nextNode=nodes[current];
        current=(current+1)%nodes.size();
        return nextNode;
    }
};

int main() {
    RoundRobin lb;
    lb.addNode("node1");
    lb.addNode("node2");
    lb.addNode("node3");
    cout<<"Routing requests:\n";
    for(int i=0;i<5;i++)
    {
        cout<<"Request routed to: "<<lb.routeRequest()<<endl;
    }
    lb.removeNode("node2");

    cout<<"\nAfter removing node2, routing requests:\n";
    for(int i=0;i<5;i++)
    {
        cout<<"Request routed to: "<<lb.routeRequest()<<endl;
    }

    return 0;
}
