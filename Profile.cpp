#include "Profile.h"

Profile::Profile(const char* n) : followersNum(0), followingNum(0)
{
	setName(n);
}

void Profile::setName(const char* n)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
}

void Profile::setFollowersNum(int num)
{
	followersNum = num;
}

void Profile::setFollowingNum(int num)
{
	followingNum = num;
}

int Profile::getFollowingNum() const
{
	return followingNum;
}

int Profile::getFollowersNum() const
{
	return followersNum;
}

const char* Profile::getName() const
{
	return name;
}

bool Profile::IsFollow(Profile* pPtr)
{
	for (int i = 0; i < followingNum; i++)
		if (pPtr == following[i]) return true;
	
	return false;
}

bool Profile::IsFollowed(Profile* pPtr)
{
	for (int i = 0; i < followersNum; i++)
		if (pPtr == followers[i]) return true;

	return false;
}

void Profile::DeleteFromFollowers(Profile* pPtr)
{
	for (int i = 0; i < followersNum; i++)
	{
		// Make the current prof point to the last prof in the array, then make the last one points to NULL
		if (followers[i] == pPtr)
		{
			followers[i] = followers[followersNum - 1];
			followers[followersNum - 1] = NULL;
			// Decrease the number of the followers profiles
			followersNum--;
			return;
		}
	}

	cout << "The profile does not exist in the followers list\n";
}

void Profile::DeleteFromFollowings(Profile* pPtr)
{
	for (int i = 0; i < followingNum; i++)
	{
		// Make the current prof point to the last prof in the array, then make the last one points to NULL
		if (following[i] == pPtr)
		{
			following[i] = following[followingNum - 1];
			following[followingNum - 1] = NULL;
			// Decrease the number of the following profiles
			followingNum--;
			return;
		}
	}

	cout << "The profile does not exist in the following list\n";
}

void Profile::Unfollow(Profile* pPtr)
{
	for (int i = 0; i < followingNum; i++)
	{
		if (pPtr == following[i])
		{
			// Delete the pPtr from the following list of the current profile
			DeleteFromFollowings(pPtr);

			// Delete the current profile from the followers list of the pPtr profile
			pPtr->DeleteFromFollowers(this);
			return;
		}
	}
}

void Profile::PrintInfo() const
{
	cout << "------- Profile Info ---------" << "\n";
	cout << "Name : " << name << "\n";
	cout << "Followers : " << followersNum << "\n";
	cout << "Following : " << followingNum << "\n";
}

Profile::~Profile()
{
	delete[] name;
}
