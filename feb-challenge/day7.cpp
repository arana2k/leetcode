// DAY 7(389. Find the Difference)=============================================================================================

//METHOD(BITWISE OPERATION (USE OF XOR))

char findTheDifference(string s, string t) {
        char c = 0;
        for(char cs: s) c ^= cs;
        for(char ct: t) c ^= ct;
        return c;
    }
};
