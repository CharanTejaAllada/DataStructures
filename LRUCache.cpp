class LRUCache 
{
public:
	std::vector<std::pair<int, int>> cache;
	int cap;

	LRUCache(int capacity) 
	{
		cap = capacity;
	}

	int get(int key)
	{
		auto itr = cache.begin();

		for (int i = 0; i<cache.size();i++)
		{
			if (cache[i].first == key)
			{
				int tmp = cache[i].second;
				cache.erase(itr);
				cache.push_back({ key,tmp });
				return tmp;
			}
			itr++;
		}
		return -1;
	}

	std::vector<std::pair<int, int>>::iterator find(int key)
	{
		auto cacheItr = cache.begin();

		for (auto it : cache)
		{
			if (it.first == key)
				return cacheItr;
			cacheItr++;
		}

		return cache.end();
	}

	void put(int key, int value)
	{
		auto it = find(key);

		if (it == cache.end())
		{
			if (cache.size() == cap)
			{
				cache.erase(cache.begin());
			}
		}

		else
		{
			cache.erase(it);	
		}
		cache.push_back({ key,value });
	}
};

int main()
{
	LRUCache cache(2);
	std::cout << cache.get(2) << std::endl;
	cache.put(2, 6);
	std::cout<<cache.get(1)<<std::endl;
	cache.put(1, 5);
	cache.put(1, 2);
	std::cout << cache.get(1) << std::endl;
	std::cout << cache.get(2) << std::endl;

	return 0;
}
