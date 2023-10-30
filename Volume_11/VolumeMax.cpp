#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int min_height = height[0];
        int max_height = height[height.size() - 1];

        if(min_height > max_height){
            min_height = max_height;

        }//if
    
       
        int w = height.size() - 1;
        int max_area = min_height * w;

      
        return max_area;
    }
};

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
     //vector<int> height = {7, 8, 6, 2, 5, 4, 8, 3, 1};
    Solution solution;
    int maxWater = solution.maxArea(height);

    cout << "A maior área possível é: " << maxWater << endl;

    return 0;
}

/*
Em resumo, este código percorre o array de alturas, mantendo duas variáveis para acompanhar a menor e a maior altura e seus índices correspondentes.
 Ele calcula a área do contêiner formado por essas alturas a cada iteração e atualiza a área máxima se uma área maior for encontrada. O algoritmo é projetado para
  encontrar a maior área possível entre duas alturas no array.
  */