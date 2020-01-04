<h2> LRU-Cache</h2>
Designed and implemented a data structure for LRU (Least
Recently Used) cache.The LRU Cache will be initialized with an integer corresponding to its
capacity in the constructor. Capacity indicates the maximum number
of unique keys it can hold at a time.
<br><br>Operations Supported :<br><br>
<ul>
<li><b>get(key)</b> : Get the value (will always be positive) of the key if the key
exists in the cache, otherwise return -1.</li>
<li><b>set(key, value)</b>: Set or insert the value if the key is not already
present. When the cache reaches its capacity, it should invalidate the
least recently used item before inserting the new item.</li></ul>
