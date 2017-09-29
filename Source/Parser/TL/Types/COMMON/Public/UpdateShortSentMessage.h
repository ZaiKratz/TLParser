#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Private/MessageMedia.h"
#include "../../../Types/Private/MessageEntity.h"
#include "../../../Types/Common/Public/Updates.h"

//begin namespace block
namespace COMMON
{
class UpdateShortSentMessage : public TLBaseObject
{
public:
	UpdateShortSentMessage();
	UpdateShortSentMessage(bool out, int32 id, int32 pts, int32 pts_count, FDateTime date, PRIVATE::MessageMedia* media, TArray<PRIVATE::MessageEntity*> entities);

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

	PRIVATE::MessageMedia*  Getmedia() const
	{
		 return this->media;
	}

	TArray<PRIVATE::MessageEntity*>  Getentities() const
	{
		 return this->entities;
	}

private:
	bool out;
	 int32 id;
	 int32 pts;
	 int32 pts_count;
	 FDateTime date;
	 PRIVATE::MessageMedia* media;
	 TArray<PRIVATE::MessageEntity*> entities;
};
} //end namespace block
