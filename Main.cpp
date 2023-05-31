#include "Graph.cpp"

int main() {
    int n, m;
    std::cout << "number of vertices: ";
    std::cin >> n;
    std::cout << "number of edges: ";
    std::cin >> m;

    Graph graph(n);
    // for (int i = 0; i < n; i++) {
    //     graph.addNode(i);
    // }
    for (int i = 0; i < m; i++) {
        int e, v;
        std::cin >> e >> v;
        graph.addEdge(e, v, 1);
    }

    bool isTree = graph.checkTree();
    
    if(isTree){
        std::cout << "Տրված գրաֆը ծառ է" << std::endl;
        std::cout << "Տրված գրաֆում ցանկացած երկու գագաթ միացված են ճիշտ մեկ ճանապարհով" << std::endl;
        std::cout << "Տրված գրաֆը կապակցված է, և կողերի քանակը հավասար գագաթների քանակ - 1" << std::endl;
        std::cout << "Տրված գրաֆը չունի ցիկլ, և կողերի քանակը հավասար գագաթների քանակ - 1" << std::endl;
        std::cout << "Տրված գրաֆը չունի ցիկլ և գրաֆի ցանկացած երկու ոչ հարևան u և v գագաթների համար G + uv գրաֆն ունի ճիշտ մեկ ցիկլ" << std::endl;
        std::cout << graph.getLeavesCount() << std::endl;
    }
    else{
        std::cout << "Տրված գրաֆը ծառ չէ" << std::endl;
    }
    return 0;
}