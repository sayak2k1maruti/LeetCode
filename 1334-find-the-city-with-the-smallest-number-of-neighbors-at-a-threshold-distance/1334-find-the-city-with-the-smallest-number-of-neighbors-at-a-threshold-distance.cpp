class Solution {
public:
    void insert_into_city_map(map<int, vector<pair<int, int>>>& city_map,
                              int city1, int city2, int weight) {
        city_map[city1].push_back(make_pair(city2, weight));
        city_map[city2].push_back(make_pair(city1, weight));
    }
    void find_city_count(map<int, vector<pair<int, int>>>& city_map,
                         map<int, bool>& visited_city, int source_city,
                         int threshold, set<int>& city_count) {
        if (visited_city[source_city])  return;
        if (threshold < 0)  return;
        city_count.insert(source_city);
        visited_city[source_city] = true;
        for (auto it : city_map[source_city]) {
            find_city_count(city_map, visited_city, it.first,
                            threshold - it.second, city_count);
        }
        visited_city[source_city] = false;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        map<int, vector<pair<int, int>>> city_map;
        for (int i = 0 ; i < n; i++){
            city_map[i] = vector<pair<int,int>>();
        }
        map<int, bool> visited_city;
        for (auto it : edges) {
            insert_into_city_map(city_map, it[0], it[1], it[2]);
        }
        int city_count = INT_MAX;
        int city = INT_MIN;
        for (auto it : city_map) {
            set<int> _count;
            find_city_count(city_map, visited_city, it.first, distanceThreshold,_count);
            int c = _count.size();
            if (c < city_count) {
                city_count = c;
                city = it.first;
            } else if (c == city_count)
                city = max(city, it.first);
        }
        return city;
    }
};