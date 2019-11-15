#!/usr/bin/env python
# coding: utf-8

# In[7]:


import threading 
x = 0


# In[8]:


def increment(): 
    global x 
    x += 5


# In[9]:


def thread_task(lock,sem): 
    for _ in range(100): 
        sem.acquire()
        lock.acquire() 
        increment() 
        lock.release()
        sem.release()


# In[10]:


def main_task(): 
    global x 
    x = 0
  
    lock = threading.Lock() 
    sem = threading.Semaphore()
  
    t1 = threading.Thread(target=thread_task, args=(lock,sem)) 
    t2 = threading.Thread(target=thread_task, args=(lock,sem)) 
  
    t1.start() 
    t2.start() 

    t1.join() 
    t2.join() 


# In[11]:


if __name__ == "__main__": 
    for i in range(10): 
        main_task() 
        print("Iteration {0}: x = {1}".format(i,x))


# In[ ]:





# In[ ]:





# In[ ]:




