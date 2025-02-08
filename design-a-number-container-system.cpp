
class NumberContainers {
public:
  unordered_map<int, int> indexToNumber;
  unordered_map<int, set<int>> numberToIndices;
  NumberContainers() {}

  void change(int index, int number) {
    if (indexToNumber.count(index)) {
      int prevNumber = indexToNumber[index];
      numberToIndices[prevNumber].erase(index);
      if (numberToIndices[prevNumber].empty()) {
        numberToIndices.erase(prevNumber);
      }
    }
    indexToNumber[index] = number;
    numberToIndices[number].insert(index);
  }

  int find(int number) {
    return numberToIndices.count(number) ? *numberToIndices[number].begin() : -1;
  }
};
