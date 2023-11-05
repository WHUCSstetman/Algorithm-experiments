#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Employee {
    string name;
    int score;
    vector<Employee*> subordinates;
};
//动态规划求最大解
pair<int, int> maxPartyScore(Employee* employee) {
    if (employee == nullptr) {
        return {0, 0};
    }

    int sumNotIncludingEmployee = 0;
    int sumIncludingEmployee = employee->score;

    for (Employee* subordinate : employee->subordinates) {
        auto subordinateResult = maxPartyScore(subordinate);
        sumNotIncludingEmployee += max(subordinateResult.first, subordinateResult.second);
        sumIncludingEmployee += subordinateResult.first;
    }

    return {sumNotIncludingEmployee, sumIncludingEmployee};
}
//处理输入的括号式成为树的形式
Employee* buildEmployeeHierarchy(const string& expression, size_t& index) {
    Employee* root = nullptr;
    Employee* currentEmployee = nullptr;
    string name;
    int score = 0;

    while (index < expression.length()) {
        char currentChar = expression[index++];

        if (currentChar == '(') {
            if (currentEmployee == nullptr) {
                currentEmployee = new Employee;
                currentEmployee->name = name;
                currentEmployee->score = score;
                score = 0;
            } else {
                currentEmployee->subordinates.push_back(buildEmployeeHierarchy(expression, index));
            }
        } else if (currentChar == ')') {
            return currentEmployee;
        } else if (currentChar >= '0' && currentChar <= '9') {
            score = score * 10 + (currentChar - '0');
        } else {
            name += currentChar;
        }
    }

    return root;
}

void outputPartyMembers(Employee* employee, bool include) {
    if (employee == nullptr) {
        return;
    }

    if (include) {
        cout << employee->name << " ";
    }

    for (Employee* subordinate : employee->subordinates) {
        outputPartyMembers(subordinate, !include);
    }
}

int main() {

    string inputExpression;
    cin>>inputExpression;
    size_t index = 1;  //跳过第一个（
    Employee* root = buildEmployeeHierarchy(inputExpression, index);


    auto result = maxPartyScore(root);


    std::cout << "Maximum Party Score: " << std::max(result.first, result.second) << std::endl;
    std::cout << "Party Members: ";
    outputPartyMembers(root, result.second > result.first);


    return 0;
}
