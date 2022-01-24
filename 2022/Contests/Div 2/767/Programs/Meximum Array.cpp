#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    vector <int> frequency(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        frequency[A[i]]++;
    }

    int array_mex = 0;
    for(int i = 0; i <= no_of_elements; i++)
    {
        if(frequency[i] == 0)
        {
            array_mex = i;
            break;
        }
    }

    set <int> all_elements, unseen;
    for(int i = 0; i <= array_mex; i++)
    {
        all_elements.insert(i);
    }
    unseen = all_elements;

    vector <int> answer;
    int mex_after_here = array_mex;
    for(int i = 1; i <= no_of_elements; i++)
    {
        frequency[A[i]]--;

        if(unseen.find(A[i]) != unseen.end())
        {
            unseen.erase(A[i]);
        }

        if(frequency[A[i]] == 0)
        {
            mex_after_here = min(mex_after_here, A[i]);
        }
        
        if(*(unseen.begin()) == array_mex)
        {
            answer.push_back(array_mex);
            array_mex = mex_after_here;

            unseen = all_elements;
        }
    }

    cout << answer.size() << "\n";
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
