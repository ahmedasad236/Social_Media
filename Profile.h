#pragma once
#include <iostream>
#include <cstring>
#define Max_Followers_Following 1000
using namespace std;

class Profile
{
private:
	char* name;
	int followersNum;
	int followingNum;
protected:
	Profile* followers[Max_Followers_Following];
	Profile* following[Max_Followers_Following];
public:
	Profile(const char* n);
	
	//Setters & Getters
	void setName(const char* n);
	void setFollowersNum(int num);
	void setFollowingNum(int num);
	int getFollowingNum() const;
	int getFollowersNum() const;
	const char* getName() const;

	//Profile Functions
	bool IsFollow(Profile*);
	bool IsFollowed(Profile*);
	void DeleteFromFollowers(Profile*);
	void DeleteFromFollowings(Profile*);
	//Virtual Functions
	virtual void AddToFollowers(Profile*) = 0;
	virtual void AddToFollowing(Profile*) = 0;
	virtual void Follow(Profile*) = 0;
	virtual void Unfollow(Profile*);
	virtual void PrintInfo() const;
	virtual ~Profile();
};

