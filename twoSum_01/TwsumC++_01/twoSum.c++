class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result; // Vetor para armazenar os índices dos números que somam ao alvo

        // Iteração através dos elementos do vetor "nums" usando um iterador
        for (auto it1 = nums.begin(); it1 != nums.end(); ++it1) {
            // Procura o segundo número necessário para atingir o alvo
            auto it2 = find(it1 + 1, nums.end(), target - *it1);

            // Verifica se o segundo número foi encontrado
            if (it2 != nums.end()) {
                // Calcula os índices e os adiciona ao vetor "result"
                result.push_back(it1 - nums.begin());
                result.push_back(it2 - nums.begin());
                break; // Sai do loop, pois encontramos a solução
            }
        }

        return result; // Retorna o vetor com os índices dos números que somam ao alvo
    }
};