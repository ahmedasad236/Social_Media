#include "TwitterProfile.h"

TwitterProfile::TwitterProfile(const char* n) : Profile(n), tweets(0), IsPrivate(0)
{}

void TwitterProfile::setPrivate(bool p)
{
	IsPrivate = p;
}

void TwitterProfile::setTweets(int num)
{
	tweets = num;
}

bool TwitterProfile::getPrivacy() const
{
	return IsPrivate;
}

int TwitterProfile::getTweets() const
{
	return tweets;
}

void TwitterProfile::AddToFollowers(Profile*pPtr)
{
	// Check if the profile is a twitter profile
	TwitterProfile* prof = dynamic_cast<TwitterProfile*>(pPtr);
	if (prof == NULL)
	{
		cout << "Error : It is not a twitter Profile :(\n";
		return;
	}
	int followersNum = getFollowersNum();
	followers[followersNum] = pPtr;
	followersNum++;
	setFollowersNum(followersNum);
}

void TwitterProfile::AddToFollowing(Profile* pPtr)
{
	// Check if the profile is a twitter profile
	TwitterProfile* prof = dynamic_cast<TwitterProfile*>(pPtr);
	if (prof == NULL)
	{
		cout << "Error : It is not a twitter Profile :(\n";
		return;
	}
	int followingNum = getFollowingNum();
	following[followingNum] = pPtr;
	followingNum++;
	setFollowingNum(followingNum);
}

void TwitterProfile::Follow(Profile* pPtr)
{
	TwitterProfile* prof = dynamic_cast<TwitterProfile*>(pPtr);
	
	if (prof == NULL)
	{
		cout << "Error : It is not a twitter profile :(\n";
		return;
	}

	if (this->IsPrivate)
	{
		cout << "You have a new follow request from " << prof->getName()
			<< ", Do you want to accept it(y/n)?\n";

		char c;
		cin >> c;
		if (c == 'y' || c == 'Y')
		{
			// Add prof to the followers list of the current profile
			AddToFollowers(prof);

			// Add the current profile to the following list of prof
			prof->AddToFollowing(this);
		}
	}

	else
	{
		AddToFollowers(prof);
		prof->AddToFollowing(this);
	}
}

void TwitterProfile::PrintInfo() const
{
	Profile::PrintInfo();
	cout << "Tweets : " << tweets << "\n";
	cout << (IsPrivate ? "Private" : "Public") << "\n";
	cout << "-----------------------------------\n";
}
