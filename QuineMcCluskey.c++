#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <iterator>

using namespace std;

// Function to convert an integer to a binary string representation
string intToBinary(int num, int vars) {
    return bitset<10>(num).to_string().substr(10 - vars);
}

// Function to count the number of 1s in a binary string
int countOnes(const string& binary) {
    return count(binary.begin(), binary.end(), '1');
}

// Function to check if two binary strings differ by exactly one bit
bool differByOneBit(const string& a, const string& b) {
    int diffCount = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            diffCount++;
            if (diffCount > 1) return false;
        }
    }
    return diffCount == 1;
}

// Function to combine two binary strings that differ by one bit
string combine(const string& a, const string& b) {
    string result = a;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            result[i] = '-';
        }
    }
    return result;
}

// Function to check if a string is already in a vector of pairs
bool isInVectorOfPairs(const vector<pair<string, vector<int>>>& vec, const string& str) {
    for (const auto& p : vec) {
        if (p.first == str) {
            return true;
        }
    }
    return false;
}

// Function to check if a binary string covers a minterm
bool covers(const string& binary, int minterm) {
    string mintermBinary = intToBinary(minterm, binary.size());
    for (int i = 0; i < binary.size(); ++i) {
        if (binary[i] != '-' && binary[i] != mintermBinary[i]) {
            return false;
        }
    }
    return true;
}

// Function to generate all prime implicants using the Quine-McCluskey method
vector<pair<string, vector<int>>> generatePrimeImplicants(const vector<int>& minterms, const vector<int>& dontCares, int vars) {
    vector<pair<string, vector<int>>> allTerms;
    vector<pair<string, vector<int>>> nextTerms;
    unordered_set<string> used;
    vector<pair<string, vector<int>>> primeImplicants;

    // Convert minterms and don't-cares to binary strings
    for (int minterm : minterms) {
        allTerms.push_back({intToBinary(minterm, vars), {minterm}});
    }
    for (int dontCare : dontCares) {
        allTerms.push_back({intToBinary(dontCare, vars), {dontCare}});
    }

    int iteration = 0;
    while (!allTerms.empty()) {
        vector<bool> combined(allTerms.size(), false);
        nextTerms.clear();

        // Print the current group of terms
        cout << "\n\n";
        cout << "Group No.       Minterms        Binary of Minterms\n";
        cout << "==================================================\n";
        unordered_map<int, vector<pair<string, vector<int>>>> groups;
        for (const auto& term : allTerms) {
            groups[countOnes(term.first)].push_back(term);
        }

        for (const auto& group : groups) {
            cout << "    " << group.first << ":\n";
            for (const auto& term : group.second) {
                cout << "                ";
                for (int minterm : term.second) {
                    cout << minterm << ",";
                }
                cout << "\b \b";
                cout << "        " << term.first << "\n";
            }
            cout << "--------------------------------------------------\n";
        }

        // Combine terms that differ by one bit
        for (int i = 0; i < allTerms.size(); ++i) {
            for (int j = i + 1; j < allTerms.size(); ++j) {
                if (differByOneBit(allTerms[i].first, allTerms[j].first)) {
                    string combinedTerm = combine(allTerms[i].first, allTerms[j].first);
                    vector<int> combinedMinterms = allTerms[i].second;
                    combinedMinterms.insert(combinedMinterms.end(), allTerms[j].second.begin(), allTerms[j].second.end());
                    sort(combinedMinterms.begin(), combinedMinterms.end());
                    combinedMinterms.erase(unique(combinedMinterms.begin(), combinedMinterms.end()), combinedMinterms.end());

                    if (!isInVectorOfPairs(nextTerms, combinedTerm)) {
                        nextTerms.push_back({combinedTerm, combinedMinterms});
                    }
                    combined[i] = true;
                    combined[j] = true;
                }
            }
        }

        // Mark terms that cannot be combined further as prime implicants
        for (int i = 0; i < allTerms.size(); ++i) {
            if (!combined[i] && used.find(allTerms[i].first) == used.end()) {
                primeImplicants.push_back(allTerms[i]);
                used.insert(allTerms[i].first);
            }
        }

        // Print unmarked prime implicants
        if (nextTerms.empty()) {
            cout << "Unmarked elements(Prime Implicants) of this table: None\n\n";
        } else {
            cout << "Unmarked elements(Prime Implicants) of this table: ";
            for (const auto& term : primeImplicants) {
                if (!isInVectorOfPairs(nextTerms, term.first)) {
                    cout << term.first << ", ";
                }
            }
            cout << "\n\n";
        }

        allTerms = nextTerms;
        iteration++;
    }

    return primeImplicants;
}

// Function to simplify the expression using Petrick's method
vector<string> petrickMethod(const vector<vector<int>>& table, const vector<string>& primeImplicants) {
    vector<vector<int>> products(1);
    products[0].reserve(table[0].size());

    for (const auto& row : table) {
        vector<vector<int>> newProducts;

        for (const auto& product : products) {
            for (int col : row) {
                vector<int> newProduct = product;
                newProduct.push_back(col);
                sort(newProduct.begin(), newProduct.end());
                newProduct.erase(unique(newProduct.begin(), newProduct.end()), newProduct.end());
                newProducts.push_back(newProduct);
            }
        }

        products = move(newProducts);
    }

    auto it = min_element(products.begin(), products.end(),
                          [](const vector<int>& a, const vector<int>& b) { return a.size() < b.size(); });

    vector<string> result;
    for (int index : *it) {
        result.push_back(primeImplicants[index]);
    }

    return result;
}

// Function to print the final result in Sum-of-Products form
void printResult(const vector<string>& result) {
    if (result.empty()) {
        cout << "F = 0" << endl;
        return;
    }

    cout << "F = ";
    for (int i = 0; i < result.size(); ++i) {
        if (i > 0) {
            cout << " + ";
        }

        for (int j = 0; j < result[i].size(); ++j) {
            if (result[i][j] == '0') {
                cout << char('A' + j) << "'";
            } else if (result[i][j] == '1') {
                cout << char('A' + j);
            }
        }
    }
    cout << endl;
}

int main() {
    int numVariables;
    vector<int> minterms;
    vector<int> dontCares;

    // Input the number of variables
    cout << "Enter the number of variables: ";
    cin >> numVariables;

    // Input minterm numbers
    cout << "Enter minterm numbers (-1 for end): ";
    int num;
    while (cin >> num && num != -1) {
        minterms.push_back(num);
    }

    // Input don't-care term numbers
    cout << "Enter don't-care term numbers (-1 for end): ";
    while (cin >> num && num != -1) {
        dontCares.push_back(num);
    }

    // Generate prime implicants
    vector<pair<string, vector<int>>> primeImplicants = generatePrimeImplicants(minterms, dontCares, numVariables);

    cout << "\n";
    // Print all prime implicants
    cout << "All Prime Implicants: ";
    for (const auto& implicant : primeImplicants) {
        cout << implicant.first << ", ";
    }
    cout << "\n\n";

    // Print the prime implicants chart
    cout << "Prime Implicants chart:\n\n";
    cout << "    Minterms    | ";
    for (int minterm : minterms) {
        cout << minterm << "  ";
    }
    cout << "\n==================================\n";

    // Construct and print the prime implicants chart
    vector<vector<int>> primeImplicantChart(minterms.size());
    for (int i = 0; i < primeImplicants.size(); ++i) {
        cout << primeImplicants[i].first << "       | ";
        for (int j = 0; j < minterms.size(); ++j) {
            if (covers(primeImplicants[i].first, minterms[j])) {
                primeImplicantChart[j].push_back(i);
                cout << "X  ";
            } else {
                cout << "   ";
            }
        }
        cout << "\n----------------------------------\n";
    }

    // Apply Petrick's method to find essential prime implicants
    vector<string> result = petrickMethod(primeImplicantChart, 
        [&primeImplicants](const vector<pair<string, vector<int>>>& vec) -> vector<string> {
            vector<string> result;
            for (const auto& pair : vec) {
                result.push_back(pair.first);
            }
            return result;
        }(primeImplicants));

    // Print essential prime implicants
    cout << "Essential Prime Implicants: ";
    for (const auto& implicant : result) {
        cout << implicant << ", ";
    }
    cout << "\n\n";

    // Print the final minimized Sum-of-Products form
    cout << "Solution: ";
    printResult(result);

    // Wait for the user to press enter before exiting
    cout << "\nPress enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
