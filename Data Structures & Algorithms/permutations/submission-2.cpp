class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        vector<int> current_path;
        
        // mask = 0 means "000..." in binary (no elements are used yet)
        backtrack(nums, current_path, 0); 
        return res;
    }

    void backtrack(const vector<int>& nums, vector<int>& current_path, int mask) {
        // 1. BASE CASE: The path is full
        if (current_path.size() == nums.size()) {
            res.push_back(current_path);
            return;
        }

        // 2. FIND CHOICES: Look at every single element in the array
        for (int i = 0; i < nums.size(); i++) {
            
            // Check the i-th bit. If it's 1, we've already used nums[i]. Skip it.
            if ((mask & (1 << i)) != 0) {
                continue; 
            }

            // 3. DO: Add the available number to our path
            current_path.push_back(nums[i]);
            
            // 4. EXPLORE: Recurse. 
            // We turn ON the i-th bit using bitwise OR: (mask | (1 << i))
            // We pass this new mask by value, which is a massive optimization.
            backtrack(nums, current_path, mask | (1 << i));

            // 5. UNDO: Remove the number from our path to try the next one
            current_path.pop_back();
            
            // Note: We don't need to explicitly "Undo" the mask because we passed 
            // `mask | (1 << i)` by value into the function. The local `mask` 
            // in this stack frame remains unchanged!
        }
    }
};

/*
void backtrack(State state) {
    // 1. BASE CASE (When do I stop?)
    if (is_goal(state)) {
        add_to_results(state);
        return;
    }

    // 2. FIND CHOICES (What are my valid options right now?)
    for (Choice choice : get_valid_choices(state)) {
        
        // 3. DO (Make the choice)
        apply(choice, state);
        
        // 4. EXPLORE (Recurse to the next node)
        backtrack(state);
        
        // 5. UNDO (Revert the choice to clean the slate)
        remove(choice, state);
    }
}
*/