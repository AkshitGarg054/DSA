class Robot {
public:
    int index = 0;
    bool moved = false; 
    vector<vector<int>> pos; // pre-compute the positions (only boundaries)

    Robot(int width, int height) {
        for(int x = 0; x < width; x++) {
            pos.push_back({x, 0, 0}); // East -> 0
        }

        for(int y = 1; y < height; y++) {
            pos.push_back({width - 1, y, 1}); // North -> 1
        }

        for(int x = width - 2; x >= 0; x--) {
            pos.push_back({x, height - 1, 2}); // West -> 2
        }

        for(int y = height - 2; y > 0; y--) {
            pos.push_back({0, y, 3}); // South -> 4
        }

        // pos = {{0, 0, East(0)}, ....}
        pos[0][2] = 3; // make it south when it again comes to (0, 0) after moving
    }
    
    void step(int num) {
        moved = true;
        index = (index + num) % pos.size();
    }
    
    vector<int> getPos() {
        return {pos[index][0], pos[index][1]};
    }
    
    string getDir() {   
        if(!moved) return "East";
        int d = pos[index][2];
        if(d == 0) return "East";
        else if(d == 1) return "North";
        else if(d == 2) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */