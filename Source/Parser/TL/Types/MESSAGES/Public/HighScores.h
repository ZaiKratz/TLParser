#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/HighScore.h"
#include "../../../Types/Common/Public/User.h"

//begin namespace block
namespace MESSAGES
{
class HighScores : public TLBaseObject
{
public:
	HighScores();
	HighScores(TArray<COMMON::HighScore*> scores, TArray<COMMON::User*> users);

	~HighScores();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<COMMON::HighScore*>  Getscores() const
	{
		 return this->scores;
	}

	TArray<COMMON::User*>  Getusers() const
	{
		 return this->users;
	}

private:
	TArray<COMMON::HighScore*> scores;
	 TArray<COMMON::User*> users;
};
} //end namespace block
