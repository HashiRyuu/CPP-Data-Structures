#include "setFunctions.h"
#include "set.h"
#include "set.cpp"
#include <cmath>

//Lab2

using namespace std;
// Returns a set that is the Union of the two sets s1 and s2
Set<char> setUnion(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;
	int len = s1.cardinality();
	int len2 = s2.cardinality();
	// Add your code here
	if(len != 0 && len2 != 0)
	{
		for(int i = 0; i < len; ++i)
			result.insertElement(s1[i]);

		for(int i = 0; i < len2; ++i)
			result.insertElement(s2[i]);
	}

	return result;
}

// Returns a set that is the intersection of the two sets s1 and s2
Set<char> setIntersection(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;
	
	// Add your code here
	int len = s1.cardinality();
	for(int i = 0; i < len; ++i)
	{
		if(s2.isElement(s1[i]))
			result.insertElement(s1[i]);
	}

	return result;
}

// Returns a set that is the s1 - s2
Set<char> setDiff(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;

	// Add your code here
	int len = s1.cardinality();
	for(int i = 0; i < len; ++i)
	{
		if(!(s2.isElement(s1[i])))
			result.insertElement(s1[i]);
	}

	return result;
}

// Returns a set that is the symetric difference of the two sets s1 and s2
Set<char> setSymDiff(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;

	// Add your code here
	Set<char> A = setDiff(s1, s2);
	Set<char> B = setDiff(s2, s1);
	int len = A.cardinality();
	int len2 = B.cardinality();

	for(int i = 0; i < len; ++i)
		result.insertElement(A[i]);

	for(int i = 0; i < len2; ++i)
		result.insertElement(B[i]);


	return result;
}

// Returns true if s1 is a subset of s2
bool isSubSet(const Set<char>& s1, const Set<char>& s2)
{
	// Add your code here and return the correct truth value
	for (int i = 0; i < s1.cardinality(); ++i) 
	{
        if (!s2.isElement(s1[i])) 
		{
            return false;
        }
	}
	return true;
}

// Returns true if s1 is a proper subset of s2
bool isProperSubSet(const Set<char>& s1, const Set<char>& s2)
{
	// Add your code here and return the correct truth value
    if (s1.cardinality() >= s2.cardinality()) 
        return false;

	if(!isSubSet(s1, s2))
		return false;

	return true;
}

// Returns the Power Set of set s as a set of sets
Set<Set<char>> PowerSet(const Set<char>& s)
{
	Set<Set<char>> result;

    // Create the empty
    Set<char> emptySet;
    result.insertElement(emptySet);

    int len = s.cardinality();

    // Generate subsets of size 1
    for (int i = 0; i < len; ++i)
    {
        Set<char> subset;
        subset.insertElement(s[i]);
        result.insertElement(subset);
    }


    // Generate subsets of size 2
	for (int size = 2; size <= len; ++size)//counting how mant size are there
	{
		for (int i = 0; i < len; ++i)
		{  
			for (int j = 1; j < size; ++j)
			{
				Set<char> subset; 
				subset.insertElement(s[i]);
				subset.insertElement(s[j]);
				result.insertElement(subset);
			}   
		}
	}

	// Generate subsets of size  3, ...,n
	for (int size = 3; size <= len; ++size)
	{
		for (int i = 0; i < len; ++i)
		{
			Set<char> subset;
			subset.insertElement(s[i]);
			for (int j = i + 1; j < size; ++j)
			{
				subset.insertElement(s[j]);
			}
			result.insertElement(subset);
		}
	}

	return result;
}

// Returns true if the sets in p make up a Partition of set s
bool isPartition(const Set<Set<char>>& p, const Set<char>& s)
{
	// Add your code here and return the correct truth value
	int len = p.cardinality();
	for(int i = 0; i < len; ++i)
	{
		int len2 = p[i].cardinality();
		for(int j = 0; j < len2; ++j)
		{
			if(p[i][j] == s[i])
				return false;
		}
	}

	return true;
}
