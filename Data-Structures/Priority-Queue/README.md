# Functionalities implemented:
* <b>isEmpty:</b> The function to  know if our Queue is empty or not right now. 
* <b>enqueue:</b> Enters an element in the queue. 
* <b>peek:</b> Returns the element at top of the Queue. Queue remains unchanged.
* <b>dequeue:</b> removes an element from the queue. 
* <b>displayQueue:</b> Displays all the elements in a space separated manner of the queue to a given out file, "cout" if you want to write to standard out. 

# Some important points:
* We have only one option can that is variable size Priority Queue for right now.
* pop returns nothing so if you want to use something like <b>a = q.dequeue();</b>, it will throw errors. You should first use peek in that case and than use pop.
* The default separator for the displayQueue is " " but you can use whatever you want. 

# Code Snippets for Examples:
* To make a priority queue:
        
        PriorityQueue<int, false> pq;
        
* To insert something in queue:

        int priority = x; // x is the value of priority here.
        // Basically, priority is an int quantity.
        pq.enqueue(key, priority);

* To see the peek(element that will be dequeued.):
        
        int p = pq.peek();
 
* Dequeue an element:
    
        pq.dequeue();
        
 * Display Queue:
 
        pq.displayQueue(cout); // With default separation of " "
        // OR
        pq.displayQueue(cout, "\n"); // With user defined sparation.
