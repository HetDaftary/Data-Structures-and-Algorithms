# Functionalities implemented:
* <b>push:</b> Pushes data into the Stack. 
* <b>peek:</b> Returns the element at top of the Stack. Just shows use the element and does not remove it.
* <b>pop:</b> pops out an element from the stack. 
* <b>displayStack:</b> Displays all the elements in a space separated manner of the stack to a given out file, "cout" if you want to write to standard out. 

# Some important points:
* You can have two choices when making a Stack so you can choose if you want to start with a given capacity or leave the memory management to the code. 
* <b>The Stack reduces the size if more than half of the Stack is empty while pop call.</b>
* pop returns nothing so if you want to use something like <b>a = stk.pop();</b>, it will throw errors. You should first use peek in that case and than use pop. 
