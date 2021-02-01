#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main()
{
    // assumed predefined values as suggested
    int nodes = 5;
    int edges = nodes - 1;
    int parkingFees = 10;
    int totalVehicles = 5;

    int i, j, v, u;

    // *using vectors instead of arrays bcoz vectors are dynamic and not fixed sized

    vector<vector<pair<int, int>>> graphMatrix(nodes + 1); // declaring the graph matrix

    vector<bool> visited(nodes + 1, false); // to keep track of visites nodes {false, false, false, ...}

    // capacity of each parking slot kept 1 as suggested, but its working with multiple values also
    vector<int> capacity{0, 1, 1, 1, 1, 1};

    vector<int> answer(totalVehicles + 1, -1); // {0, -1, -1, -1, ...}

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // initializing the graph matrix

    graphMatrix[1].push_back(make_pair(4, 2)); // from 1 (v) to 2 (u), the cost is 4 (w)
    graphMatrix[2].push_back(make_pair(4, 1)); // from 2 (v) to 1 (u), the cost is 4 (w)

    graphMatrix[1].push_back(make_pair(5, 3));
    graphMatrix[3].push_back(make_pair(5, 1));

    graphMatrix[3].push_back(make_pair(3, 4));
    graphMatrix[4].push_back(make_pair(3, 3));

    graphMatrix[2].push_back(make_pair(2, 5));
    graphMatrix[5].push_back(make_pair(2, 2));

    // initializing the queue for first location;
    pq.push(make_pair(0, 1));

    i = 1;
    while ((i <= totalVehicles) && (!pq.empty()))
    {
        // visiting the first node
        v = pq.top().second;
        u = pq.top().first;
        pq.pop();

        if (!visited[v])
        {
            visited[v] = true;
            while ((i <= totalVehicles) && (capacity[v]--))
            {
                answer[i] = u + parkingFees;
                i++;
            }

            for (j = 0; j < graphMatrix[v].size(); j++)
                if (!visited[graphMatrix[v][j].second])
                    pq.push(make_pair(graphMatrix[v][j].first + u, graphMatrix[v][j].second));
        }
    }
    for (i = 1; i <= totalVehicles; i++)
    {
        cout << "The total cost (path cost + parking fees) for vehicle number " << i << " to park is: ";
        cout << answer[i] << endl;
    }
    cout << endl;
    return 0;
}

/* OUTPUT:-

The total cost (path cost + parking fees) for vehicle number 1 to park is: 10                                                                    
The total cost (path cost + parking fees) for vehicle number 2 to park is: 14                                                                    
The total cost (path cost + parking fees) for vehicle number 3 to park is: 15                                                                    
The total cost (path cost + parking fees) for vehicle number 4 to park is: 16                                                                    
The total cost (path cost + parking fees) for vehicle number 5 to park is: 18

*/