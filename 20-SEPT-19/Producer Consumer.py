#!/usr/bin/env python
# coding: utf-8

# In[13]:


import random, time, threading 
from threading import BoundedSemaphore ,Thread


# In[14]:


max_items = 5


# In[15]:


container = BoundedSemaphore(max_items)


# In[16]:


def producer(nloops):
    for i in range(nloops):
        time.sleep(random.randrange(2, 5))
        print(time.ctime(), end=": ")
        try:
            container.release()
            print("Produced an item.")
        except ValueError:
            print("Full, skipping.")
            
def consumer(nloops):
    for i in range(nloops):
        time.sleep(random.randrange(2, 5))
        print(time.ctime(), end=": ")   
        if container.acquire(False):
            print("Consumed an item.")
        else:
            print("Empty, skipping.")
            


# In[17]:


threads = []


# In[18]:


nloops = random.randrange(3, 6)


# In[19]:


print("Starting with %s items." % max_items)


# In[20]:


threads.append(Thread(target=producer, args=(nloops,)))
threads.append(Thread(target=consumer, args=(random.randrange(nloops, nloops+max_items+2),)))


# In[21]:


for thread in threads: 
    thread.start()
for thread in threads:
    thread.join()
print("All done.")


# In[ ]:




