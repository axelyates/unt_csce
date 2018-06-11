/************************************************
                                                |
Name:       Axel Yates                          |
Class:      CSCE3110                            |
Assignment: Program 5 - BFS Graphs              |
                                                |
************************************************/

#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

class Graph{

    private:

        int V;
        list<int> *adj;

    public:

        Graph(int V){

            this->V = V;
            adj = new list<int>[V];

        }
        void addEdge(int v, int w);
        void BFS(int s, bool visited[]);
        Graph getTranspose();
        void print(int s);
	bool isConnected();
};
void Graph::addEdge(int v, int w){

    adj[v].push_back(w);
    adj[w].push_back(v);

}
void Graph::BFS(int s, bool visited[]){

    list<int> q;
    list<int>::iterator i;
    visited[s] = true;
    q.push_back(s);
    while (!q.empty()){

        s = q.front();
        cout << s << " ";
        q.pop_front();

        for(i = adj[s].begin(); i != adj[s].end(); ++i){

            if(!visited[*i]){

                visited[*i] = true;
                q.push_back(*i);

            }
        }
    }
}
Graph Graph::getTranspose(){

    Graph g(V);
    for (int v = 0; v < V; v++){

        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i){

            g.adj[*i].push_back(v);

        }
    }
    return g;
}
bool Graph::isConnected(){

    bool visited[V];

    for (int i = 0; i < V; i++){

        visited[i] = false;

    }
    BFS(0, visited);
    for (int i = 0; i < V; i++){

        if (visited[i] == false){

            return false;

        }
    }
    Graph gr = getTranspose();
    for(int i = 0; i < V; i++){

        visited[i] = false;

    }
    gr.BFS(0, visited);
    for (int i = 0; i < V; i++){
    
        if (visited[i] == false){
            
            return false;

        }
    }
    return true;
}
void Graph::print(int s){
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
int main(){


    ifstream my_file;
    my_file.open("graph.txt");
    int c = my_file.get();
    string star;
    string nova;
    string hue;

    if(my_file.is_open()){

        while(getline(my_file,star)){

            nova = star;

        }
    }

    my_file.close();

    hue = nova.substr(0, 2);

    stringstream final(hue);

    int x = 0;

    final >> x;

    int in;
    int node;

    Graph test(x+1);
    test.addEdge(0, 1);
    char line[1000];
    int add_me = 0;

    while(cin >> in){

        node = in;
        cin.get(line, 1000);

        for(int i = 0; i < 200; i++){

            if(line[i] == 48){//48 is the ascii value for 0

                add_me = 0;
                test.addEdge(node, add_me);

            }
            if(line[i] == 49){//49 is the ascii value for 1

                add_me = 1;
                test.addEdge(node, add_me);

            }
            if(line[i] == 50){//50 is the ascii value for 2

                add_me = 2;
                test.addEdge(node, add_me);

            }
            if(line[i] == 51){//51 is the ascii value for 3

                add_me = 3;
                test.addEdge(node, add_me);

            }
            if(line[i] == 52){//52 is the ascii value for 4

                add_me = 4;
                test.addEdge(node, add_me);

            }
            if(line[i] == 53){//53 is the ascii value for 5

                add_me = 5;
                test.addEdge(node, add_me);

            }
            if(line[i] == 54){//54 is the ascii value for 6

                add_me = 6;
                test.addEdge(node, add_me);

            }
            if(line[i] == 55){//55 is the ascii value for 7

                add_me = 7;
                test.addEdge(node, add_me);

            }
            if(line[i] == 56){//56 is the ascii value for 8

                add_me = 8;
                test.addEdge(node, add_me);

            }
            if(line[i] == 57){//57 is the ascii value for 9

                add_me = 9;
                test.addEdge(node, add_me);

            }
        }//end for loop

        add_me = 0;

    }

    if(test.isConnected()){

        cout << "Graph is connected" << endl;
        test.print(1);

    }
    else{

        cout << "Graph is not connected, could not complete full BFS." << endl;

    }

    return 0;
}
