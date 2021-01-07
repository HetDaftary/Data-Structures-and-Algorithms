# Functionalities implemented:
* <b>isEmpty:</b> To see if the stack is empty to not right now.
* <b>push:</b> Pushes data into the Stack. 
* <b>peek:</b> Returns the element at top of the Stack. Just shows use the element and does not remove it.
* <b>pop:</b> pops out an element from the stack. 
* <b>displayStack:</b> Displays all the elements in a space separated manner of the stack to a given out file, "cout" if you want to write to standard out. 

# Some important points:
* You get two choices. <b>You can make a fixed size stack and a variable size stack. </b> 
* The code does not change the size of fixed size stack at any point.
* For variable size stack: <b>The Stack reduces the size if more than half of the Stack is empty while pop call.</b>
* pop returns nothing so if you want to use something like <b>a = stk.pop();</b>, it will throw errors. You should first use peek in that case and than use pop.
* The default separator for the displayStack is " " but you can use whatever you want. 

# Code Snippets for Examples:

* Make a fixed size stack:

        Stack<int, true> stk(5);
        
* Make a Stack with variable size:
        
        Stack<int, false> stk();
        
* Push data to stack:

        stk.push(5);
        
* pop from the stack:

        bool a = stk.pop();
          
* Get the element at peek:

        int a = stk.peek();
        
* display the stack:

        stk.displayStack(cout); // Display with default separation.
        // OR
        stk.displayStack(cout, "\n"); // Display with \n as separation.
