#include "Graph.cpp"
#include <string>
#include <fstream>
#include <limits>

int main() {

    int optionSelected;

    std::cout << "Եթե ցանկանում եք կարդալ գրաֆիկը ֆայլից, մուտքագրեք 1, հակառակ դեպքում 2՝ այն տերմինալում մուտքագրելու համար: ";
    std::cin >> optionSelected;

    Graph* graph;
    if(optionSelected == 2){
        int n, m;
        std::cout << "գագաթների քանակը: ";
        std::cin >> n;
        std::cout << "կողերի քանակը: ";
        std::cin >> m;

        graph = new Graph(n);
        // for (int i = 0; i < n; i++) {
        //     graph.addNode(i);
        // }
        for (int i = 0; i < m; i++) {
            int e, v;
            std::cin >> e >> v;
            graph->addEdge(e, v, 1);
        }
    }
    else if(optionSelected == 1){
        std::string filePath;
        std::cout << "Մուտքագրեք ֆայլը: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, filePath);
        std::ifstream inputFile(filePath); // Open the input file
        if (!inputFile.is_open()) {
            std::cout << "Չհաջողվեց բացել մուտքային ֆայլը" << std::endl;
            return 0;
        }

        int n, m;
        inputFile >> n;
        inputFile >> m;

        graph = new Graph(n);
        // for (int i = 0; i < n; i++) {
        //     graph.addNode(i);
        // }
        for (int i = 0; i < m; i++) {
            int e, v;
            inputFile >> e >> v;
            graph->addEdge(e, v, 1);
        }

        inputFile.close(); // Close the input file
    }
    else{
        std::cout << "Խնդրում ենք մուտքագրել վավեր տարբերակ" << std::endl;
        return -1;
    }

    bool isTree = graph->checkTree();
    
    if(isTree){
        std::cout << "Տրված գրաֆը ծառ է" << std::endl;
        std::cout << "Տրված գրաֆում ցանկացած երկու գագաթ միացված են ճիշտ մեկ ճանապարհով" << std::endl;
        std::cout << "Տրված գրաֆը կապակցված է, և կողերի քանակը հավասար գագաթների քանակ - 1" << std::endl;
        std::cout << "Տրված գրաֆը չունի ցիկլ, և կողերի քանակը հավասար գագաթների քանակ - 1" << std::endl;
        std::cout << "Տրված գրաֆը չունի ցիկլ և գրաֆի ցանկացած երկու ոչ հարևան u և v գագաթների համար G + uv գրաֆն ունի ճիշտ մեկ ցիկլ" << std::endl;
        std::cout << graph->getLeavesCount() << std::endl;
    }
    else{
        std::cout << "Տրված գրաֆը ծառ չէ" << std::endl;
    }
    delete graph;
    return 0;
}