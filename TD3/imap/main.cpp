#include <iostream>
#include <vector>
#include <map>

using namespace std;

void countFrequencyBruteForce(const vector<int> &numbers)
{
    vector<bool> visited (numbers.size(), false);
    for (size_t i=0; i < numbers.size(); i++){
        if (visited[i]){
            continue;
        }
        int count = 1;
        for (size_t j=i+1; j < numbers.size(); j++){
           if (numbers[i] == numbers[j]){
            count++;
            visited[j] = true;
            }
        }
        cout << numbers[i] << ": " << count << " times" << endl;
    }
}

map<int, int> countFrequencyOptimal(const vector<int> &numbers)
{
    map<int, int> frequencyMap;
    for (const int &num : numbers){
        frequencyMap[num]++;
    }
    return frequencyMap;
}

int main()
{
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};

    cout << "Frequency (Brute Force):" << endl;
    countFrequencyBruteForce(numbers);

    cout << "\nFrequency (Optimal):" << endl;
    map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);

    for (const auto &entry : frequencyMapOptimal)
    {
        cout << entry.first << ": " << entry.second << " times" << endl;
    }

    return 0;
}