#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace COMMON
{
class UpdateShortSentMessage : public TLBaseObject
{
public:
	UpdateShortSentMessage();
	UpdateShortSentMessage(bool out, int32 id, int32 pts, int32 pts_count, FDateTime date, TLBaseObject* media, TArray<TLBaseObject*> entities);

	~UpdateShortSentMessage();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getout() const
	{
		 return this->out;
	}

	int32 Getid() const
	{
		 return this->id;
	}

	int32 Getpts() const
	{
		 return this->pts;
	}

	int32 GetPtsCount() const
	{
		 return this->pts_count;
	}

	FDateTime Getdate() const
	{
		 return this->date;
	}

	TLBaseObject*  Getmedia() const
	{
		 return this->media;
	}

	TArray<TLBaseObject*>  Getentities() const
	{
		 return this->entities;
	}

private:
	bool out;
	 int32 id;
	 int32 pts;
	 int32 pts_count;
	 FDateTime date;
	 TLBaseObject* media;
	 TArray<TLBaseObject*> entities;
};
} //end namespace block
