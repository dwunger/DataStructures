// Goal: Formalize consistent grammatical construction for logical operators
// Validate construction in code.
#include <stdio.h>
#include <stdbool.h>

bool AND(bool input1, bool input2);
bool NOT(bool input);
int main(void) 
{
    // ===AND===
    puts("===AND===");
    // Expected: 
    // 0 1 0 1
    // 0 0 1 1
    // 0 0 0 1

    printf("%d %d %d %d\n%d %d %d %d\n%d %d %d %d\n", 0, 1, 0, 1,
                                                      0, 0, 1, 1,
                                                      AND(0,0), AND(1,0),
                                                      AND(0,1), AND(1,1));


    // ===NOT===
    puts("===NOT===");
    // Expected:
    // 0 1
    // 1 0
    
    printf("%d %d\n%d %d\n", 0, 1, NOT(0), NOT(1));



    return 0;
}


bool NOT(bool input)
{
    // [TRUE] <- IF input IS NOT [TRUE]
    // [RESULT] <- [conditional qualifier] [operator] [argument]
    // Grammar:
    // [Adj.] <- [Conj.] [Adj.] [V.]

    if (input != true) {
        return true;
    }

    return false;
    // Idiomatic C:
    // return !input;
}


bool AND(bool input1, bool input2)
{
    // [TRUE] <- IF input1 AND input2 ARE [TRUE] 
    // [RESULT] <- [condition qualifier] [operator] [argument(s)] 
    // Grammar:
    // [Adj.] <- [Conj.] [Adj(s).] [V.]
    
    // Construction:
    // IF input1 AND input2
    // AND creates a dependency
    // So input2 is nested in input1
    if (input1) {
        if (input2) {
            return true;
        }
    } 
    return false; 
    
    // Idiomatic C: 
    // return (input1 && input2);
}
    



