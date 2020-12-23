# Functionalities implemented:
* <b>isEmpty:</b> The function to  know if our Queue is empty or not right now. 
* <b>push:</b> Pushes data into the Queue. 
* <b>peek:</b> Returns the element at top of the Queue. Just shows use the element and does not remove it.
* <b>pop:</b> pops out an element from the stack. 
* <b>displayStack:</b> Displays all the elements in a space separated manner of the queue to a given out file, "cout" if you want to write to standard out. 

# Some important points:
* You can either have start with a given capacity or leave it to the code. 
* <b>If the first half storage of the queue gets empty, we just remove it and shorten our queue for memory management. </b>
* pop returns nothing so if you want to use something like <b>a = q.pop();</b>, it will throw errors. You should first use peek in that case and than use pop.
* The default separator for the displayStack is " " but you can use whatever you want. 
