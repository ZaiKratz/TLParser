#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class HighScore : public TLBaseObject
{
public:
	HighScore();
	HighScore(int32 pos, int32 user_id, int32 score);

	~HighScore();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	int32 Getpos() const
	{
		 return this->pos;
	}

	int32 GetUserId() const
	{
		 return this->user_id;
	}

	int32 Getscore() const
	{
		 return this->score;
	}

private:
	int32 pos;
	 int32 user_id;
	 int32 score;
};
} //end namespace block
