class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars(n);  // pair: (position, time to reach target)
        
        for (int i = 0; i < n; ++i) {
            double time = (double)(target - position[i]) / speed[i];
            cars[i] = {position[i], time};
        }
        
        // Sort cars by starting position descending (closest to target first)
        sort(cars.rbegin(), cars.rend());
        
        int fleets = 0;
        double currentFleetTime = 0;
        
        for (auto& car : cars) {
            if (car.second > currentFleetTime) {
                // New fleet forms if this car takes longer than current fleet
                fleets++;
                currentFleetTime = car.second;
            }
            // Otherwise, this car joins the fleet with currentFleetTime
        }
        
        return fleets;
    }
};
